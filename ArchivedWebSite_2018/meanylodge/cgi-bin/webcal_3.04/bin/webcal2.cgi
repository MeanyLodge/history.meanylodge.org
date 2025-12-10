use CGI;
use CGI::Carp qw(fatalsToBrowser);
use Time::Local;
use Fcntl ':flock';
use strict;
use webcal_shared;
use webcal_io;

#
# WebCal - a web based calendar program.
# Released under the GNU GPL.  A text version of the GPL should have come
# with this program in the file "GPL.txt".
# Copyright 1999 Michael Arndt
#

#
# variables
#
$::calendar = "";
$::USER = "";
my $date = "";
my $month = "";
my $year = "";
my $day = "";
my $index = "";
my $subindex = "";
my $op = "";
my $return = "";
my $function = "";
my $days = "";
my $pw1 = "";
my $pw2 = "";
my $username = "";
my $url = "";
my $cal_type = "";
my (@args, $cal_user, $trusted, %prefs, @subscribe); 
my ($time, $dow, $misc_date);
my $item_type = "";
my $ch_color = "";
my $current_color = "";
undef %prefs;
undef @subscribe;

# ----------------------------------------------------------
# Main
# ----------------------------------------------------------

#
# take a look at our CGI form input.
#
$::query = new CGI;
@args = $::query->param;
ARG: for (@args) {
	if (/^ITEM_COLOR_(\d+)/) {
		$::webcal_conf::local_item_color{$1} = $::query->param($_);
		next ARG;
	}
	$date = $::query->param($_), next ARG if /date/;
	$month = $::query->param($_), next ARG if /^month$/;
	$year = $::query->param($_), next ARG if /^year$/;
	$day = $::query->param($_), next ARG if /^day$/;
	$index = $::query->param($_), next ARG if /^index$/;
	$subindex = $::query->param($_), next ARG if /^subindex$/;
	$op = $::query->param($_), next ARG if /op/;
	$return = $::query->param($_), next ARG if /return/;
	$::calendar = $::query->param($_), next ARG if /cal/;
	$function = $::query->param($_), next ARG if /function/;
	$days = $::query->param($_), next ARG if /^days$/;
	$prefs{$_} = $::query->param($_), next ARG if (/[A-Z]/);
	$pw1 = $::query->param($_), next ARG if /pw1/;
	$pw2 = $::query->param($_), next ARG if /pw2/;
	$url = $::query->param($_), next ARG if /url/;
	$cal_type = $::query->param($_), next ARG if /type/;
	$username = $::query->param($_), next ARG if /username/;
	@subscribe = $::query->param($_), next ARG if /subscribe/;
	$ch_color = $::query->param($_), next ARG if /ch_color/;
	$current_color = $::query->param($_), next ARG if /current_color/;
}
$::calendar =~ s/\+/ /g;
$::cgi_calendar = $::calendar;
$::cgi_calendar =~ s/ /+/g;
$::USER = $ENV{'REMOTE_USER'};

#
# include the configuration files.  I should add code here to check if we 
# really need to reload this file, instead of just reloading every time.
#
my $inc_file = "${libdir}/webcal_conf.pm";
delete $INC{$inc_file} if ($INC{$inc_file});
require $inc_file or die "Error: $!\n";

#
# get start time if benchmarking
#
if ($::webcal_conf::TIMEIT) {
        require Time::HiRes;
        $::start_time = [ Time::HiRes::gettimeofday() ];
}

#
# Connect to database (if not using flat files)
#
&dbh_setup;

#
# Global Constants that need values from webcal_conf
#
%::MONTHS = ("Jan", "01", "Feb", "02", "Mar", "03", "Apr", "04", "May", "05", "Jun","06", "Jul", "07", "Aug", "08", "Sep", "09", "Oct", "10", "Nov", "11", "Dec", "12");
%::MONTHS_NTOW = ("01", "$::webcal_conf::JANUARY", "02", "$::webcal_conf::FEBRUARY", "03", "$::webcal_conf::MARCH", "04", "$::webcal_conf::APRIL","05", "$::webcal_conf::MAY" , "06", "$::webcal_conf::JUNE", "07", "$::webcal_conf::JULY", "08", "$::webcal_conf::AUGUST", "09", "$::webcal_conf::SEPTEMBER", "10", "$::webcal_conf::OCTOBER", "11", "$::webcal_conf::NOVEMBER", "12", "$::webcal_conf::DECEMBER");
%::MONTHS_WTON = ("$webcal_conf::JANUARY", "01", "$webcal_conf::FEBRUARY", "02", "$webcal_conf::MARCH", "03", "$webcal_conf::APRIL","04", "$webcal_conf::MAY" , "05", "$webcal_conf::JUNE", "06", "$webcal_conf::JULY", "07", "$webcal_conf::AUGUST", "08", "$webcal_conf::SEPTEMBER", "09", "$webcal_conf::OCTOBER", "10", "$webcal_conf::NOVEMBER", "11", "$webcal_conf::DECEMBER", "12");
$::BORDER = 0;

$::DATABASE = "$webcal_conf::DB_DIR/$::calendar/cal.dat";
$::TEMPFILE = "$webcal_conf::DB_DIR/$::calendar/cal.tmp.$$";
$::USERFILE = "$webcal_conf::DB_DIR/$::calendar/.users";

#
# if they didn't really select a calendar from the pulldowns, send 'em back
#
if ($::calendar =~ /^----.*----$/) {
	&start_html("dummy");
	print "<script language=\"JavaScript\">\n";
	print "<!-- Beginning Javascript -\n";
	print "window.location.href='$webcal_conf::WEBCAL'\n";
	print "// - End of JavaScript - -->\n";
	print "</script>\n";
	&end_html;
}

#
# Determine of the user has supplied proper credentials.
#
if ($function eq "newcal") {
	if ($::USER eq "admin") {
		$trusted = 1;
	} else {
		&start_html("plain");
		&error_page("$::webcal_conf::ERROR_STRING29");
	}
} elsif ($::USER eq "admin") {
	$trusted = 1;
} else {
	$trusted = 0;
	open (USERS, "<$::USERFILE") or die "$webcal_conf::ERROR_STRING1 $::USERFILE: $!\n";
	while (<USERS>) {
		chop;
		if ($::USER eq $_) {
			$trusted = 1;
			last;
		}
	}
	close(USERS);
	if (-f "$webcal_conf::DB_DIR/$::calendar/webcal.conf") {
		open (FILE, "<$webcal_conf::DB_DIR/$::calendar/webcal.conf") or die "$webcal_conf::ERROR_STRING28: $!\n";
		flock FILE, LOCK_SH or die "$webcal_conf::ERROR_STRING12 $webcal_conf::DB_DIR/$::calendar/webcal.conf: $!\n";
		while (<FILE>) {
			chomp;
			if (/^\$WRITE_LIST\s=\s'(.*)'/) {
				my @list = split(/\s+/, $1);
				my $write_flag = 0;
				for my $id (@list) {
					$write_flag = 1, last if (($id eq $::USER) || ($id eq "*"));
				}
				$trusted = 1, last if ($write_flag);
			}
		}
		flock FILE, LOCK_UN or die "$webcal_conf::ERROR_STRING13 $webcal_conf::PERSONAL_CONF_FILE: $!\n";
		close (FILE);
	}
}

#
# if they are not trusted, send headers to force a re-login
#
if (!$trusted) {
	print "Status: 401 auth req dude!\n";
	print "WWW-authenticate: Basic realm=\"webcal\"\n";
	print "Content-type: text/plain\n\n";
	goto EXIT;
}

#
# if we are going to redirect the user immediately after making a change, 
# then print a little message to keep them happy in the delay.
#
&start_html($function,$current_color);
if ($return) {
	print "<B>$webcal_conf::STRING23...</B><BR>\n";
}

#
# make sure we really belong in here
#
if (($function) && ($function ne "newcal") && ($::calendar)) {
	if (-e "$webcal_conf::DB_DIR/$::calendar/.open") {
		&error_page("$webcal_conf::ERROR_STRING17");
 	} elsif (-e "$webcal_conf::DB_DIR/$::calendar/.public") {
		&error_page("$webcal_conf::ERROR_STRING17") if (($function ne "data_ops") && ($function !~ /pref|color/));
		&error_page("$webcal_conf::ERROR_STRING29") if (! $webcal_conf::ALLOW_PUBLIC_CAL);
	} elsif (-e "$webcal_conf::DB_DIR/$::calendar/.private") {
		&error_page("$webcal_conf::ERROR_STRING29") if (! $webcal_conf::ALLOW_PRIVATE_CAL);
	} else {
		&error_page("$webcal_conf::ERROR_STRING21");
	}
}

#
# Set up our date information
#
if ($function eq "data_ops") {
	if ($op eq "replace") {
		my @DAYS_IN_MONTH = qw(0 31 28 31 30 31 30 31 31 30 31 30 31);
		if ((($year % 4) == 0) && ((($year % 100) != 0) || (($year % 400) == 0))) {
			$DAYS_IN_MONTH[2]++;
		}
		$month = $::MONTHS_WTON{$month};
		if ($day > $DAYS_IN_MONTH[$month]) {
			&error_page("$webcal_conf::ERROR_STRING32 d:$day m:$month DIM:$DAYS_IN_MONTH[$month]");
		}
		$date = $year.$month.$day;
		$time = timelocal 1,1,1,$day,($month-1),($year-1900);
		$dow = ("Sun","Mon","Tue","Wed","Thu","Fri","Sat")[(localtime($time))[6]];
		$misc_date = "$year,$month,$day,$dow";
	} elsif ($date =~ /(\d{4})(\d{2})(\d{2})/) {
		$year = $1;
		$month = $2;
		$day = $3;
		$time = timelocal 1,1,1,$day,($month-1),($year-1900);
		$dow = localtime($time);
		$dow =~ s/^(\w+).*/$1/;
		$misc_date = "$year,$month,$day,$dow";
	} else {
		&error_page("$webcal_conf::ERROR_STRING14! -> $date");
	}
}

#
# Main decision making section.
#
if ($function eq "newcal") {
	&newcal($username,$op,$pw1,$pw2,$cal_type);
} elsif ($function eq "webyear") {
	&year_view($year);
} elsif ($function eq "webmonth") {
	&month_view($year,$month);
} elsif ($function eq "webweek") {
	&week_view($year,$month,$day);
} elsif ($function eq "webday") {
	&day_view($date);
} elsif ($function eq "notes") {
	&notes($index,$subindex,$date);
} elsif ($function eq "addform") {
	&add_form($date);
} elsif ($function eq "data_ops") {
	if ($op eq "del") {
		&del($index);
	} elsif ($op eq "add") {
		&add($date,$year,$month,$day,$dow,"0","add");
	} elsif ($op eq "replace") {
		&add($date,$year,$month,$day,$dow,$index,"replace");
	} elsif ($op eq "edit") {
		&edit($index,$subindex,$date);
	} else {
		&error_page("$webcal_conf::ERROR_STRING19! op=$op");
	}
} elsif ($function eq "pref") {
	&prefs($url);	
} elsif ($function eq "pref_changes") {
	&pref_changes(\%prefs,@subscribe);	
} elsif ($function eq "color_browser") {
	&color_browser($ch_color,$current_color);
} elsif ($function eq "user") {
	open(FILE, "<$webcal_conf::DB_DIR/$::calendar/.users") or die "$webcal_conf::ERROR_STRING28: $!\n";
	while (<FILE>) {
		chomp;
		$cal_user = $_;
	}
	close(FILE);
	if ($op eq "change") {
		&change("user",$cal_user);
	} elsif ($op eq "change2") {
		&change2("user",$pw1,$pw2,$cal_user);
	} else {
		&error_page("bad option: $op");
	}
} else {
	&error_page("$webcal_conf::ERROR_STRING2: $function");
}

#
# We made our changes, now return to the calling page automatically.
#
if ($return) {
	my $BASE;
	if (-e "$webcal_conf::DB_DIR/$::calendar/.public") {
		$BASE = $webcal_conf::WEBCAL;
	} elsif (-e "$webcal_conf::DB_DIR/$::calendar/.private") {
		$BASE = $webcal_conf::WEBCAL2;
	} else {
		&error_page("$webcal_conf::ERROR_STRING21");
	}
	print "<SCRIPT LANGUAGE=\"JavaScript\">\n";
	print "<!-- Beginning Javascript -\n";
	if ($url) {
		$url =~ s/\|{3}/&/g;
		$url =~ s/---/=/g;
		$url =~ s/ /+/g;
		print "window.location.href='$BASE?${url}'\n";
	} else {
		print "window.location.href='$BASE?function=webday&date=$date&cal=$::cgi_calendar'\n";
	}
	print "// - End of JavaScript - -->\n";
	print "</SCRIPT>\n";
}
&end_html;
goto EXIT;

# ----------------------------------------------------------
# End of main
# ----------------------------------------------------------

EXIT:
