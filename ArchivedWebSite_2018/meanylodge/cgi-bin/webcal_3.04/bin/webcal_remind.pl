use strict;
use Time::Local;
use webcal_io;
use webcal_shared;

#
# WebCal - a web based calendar program.
# Released under the GNU GPL.  A text version of the GPL should have come
# with this program in the file "GPL.txt".
# Copyright 1999 Michael Arndt
#
# Last updated for version 3.02
#

#
# location of sendmail
#
my $SENDMAIL = "/usr/lib/sendmail";

#
# How often is this cron running, in seconds
# Default: every 5 minutes, or 600 seconds.
#
my $CRON_FREQ = 300;

#
# global variables
#
my (@dirs,$cal_dat,$time,$CONF_FILE);
my ($all_items_ref,$sub_items_ref,$pers_items_ref);
$::calendar = "";
$ENV{'HTTP_HOST'} = "none";
$CONF_FILE = "${libdir}/webcal_conf.pm";

#
# connect to database (if not using flat files)
# must require the conf file first to get our db access vars
#
require $CONF_FILE or die "error loading $CONF_FILE: $!\n";
&dbh_setup;

#
# look around
#
opendir DIR, $db_dir or die "Could not open dir: $db_dir: $!\n";
@dirs = readdir DIR;
closedir DIR;
for $::calendar (@dirs) {
	next if (! -e "$db_dir/$::calendar/webcal.conf");
	delete $INC{$CONF_FILE} if ($INC{$CONF_FILE});
	require $CONF_FILE or die "error loading $CONF_FILE: $!\n";
	$::DATABASE = "$webcal_conf::DB_DIR/$::calendar/cal.dat";
	($all_items_ref,$sub_items_ref,$pers_items_ref) = &setup_items_hash("rem","0");
	&check($pers_items_ref);
	if ($webcal_conf::MESSAGE_ALL) {
		&check($sub_items_ref);
	}
}
	
#
# disconnect from database (if not using flat files)
#
&dbh_close;
exit;

#
# suboutine to check a hash of items for reminders to be sent
#
sub check {
	my ($ref) = (@_);
	my ($index,$subindex,$date,$stime,$etime,$item,$rsec);
	my ($year,$month,$day,$dow,$hour,$min,$item_time);
	my ($year2,$month2,$day2,$dow2,$time2,$misc_date);
	for $index (sort keys %$ref) {
		for $subindex (sort keys %{ $$ref{$index} }) {
			$date = $$ref{$index}{$subindex}{'idate'};
			$stime = $$ref{$index}{$subindex}{'shour'};
			$etime = $$ref{$index}{$subindex}{'ehour'};
			$item = $$ref{$index}{$subindex}{'string'};
			$rsec = $$ref{$index}{$subindex}{'rsec'};
			if ($item =~ /^<span class=sub-cal>.*<\/span>\s(.*)$/) {
				$item = $1;
			}
			next if (! $rsec);
			# don't want to send rems for the tail end of an item that overlaps days
			if (($subindex % 2) == 0) {
				if (($stime ne "0") && ($etime ne "0") && ($$ref{$index}{'1'}{'shour'} > $$ref{$index}{'2'}{'ehour'})) {
					next;
				}
			}
			$time = time;	
			if ($stime =~ /(\d+)(\d{2})/) {
				$hour = $1;
				$min = $2;
			} else {
				$hour = 0;
				$min = 0;
			}	
			if ($date =~ /(\d{4})(\d{2})(\d{2})/) {
				$year = $1;
				$month = $2;
				$day = $3;
				$year = $year - 1900;	
				$month = $month - 1;	
				$item_time = timelocal "0",$min,$hour,$day,$month,$year;
			} elsif ($date =~ /^(.+?),(.+?),(.+?),(.+)$/) {
				$year = $1;
				$month = $2;
				$day = $3;
				$dow = $4;
				$time2 = $time + $rsec;
				$year2 = ((localtime($time2))[5]) + 1900;
				$month2 = ((localtime($time2))[4]) + 1;
				$month2 = "0" . $month2 if ($month2 !~ /\d{2}/);
				$day2 = (localtime($time2))[3];
				$day2 = "0" . $day2 if ($day2 !~ /\d{2}/);
				$dow2 = localtime($time2);
				$dow2 =~ s/^(\w+).*/$1/;
				$misc_date = "${year2},${month2},${day2},${dow2}";
				if ($misc_date =~ /$date/) {
					$item_time = timelocal "0",$min,$hour,$day2,($month2-1),($year2-1900);
				} else {
					$item_time = 0;
				}
			}
			if ((($time + $rsec) >= $item_time) && (($time + $rsec) < ($item_time + $CRON_FREQ))) {
				&message($item,$rsec,$item_time,$webcal_conf::EMAIL_ADDR) if ($webcal_conf::EMAIL_REM);
				&message2($item,$rsec,$item_time,$webcal_conf::PAGER_ADDR) if ($webcal_conf::PAGE_REM);
			}
		}
	}
}

#
# subroutine to send the email message
#
sub message {
	my ($item,$rsec,$item_time,$email_addr) = (@_);
	my ($pid,$time,$date,$time_string);
	return if (! $email_addr);
	$date = localtime;
	$time = &get_time($rsec);
	$time_string = localtime $item_time;
	$pid = open(MAIL, "|-");
	die "fork() failed: $!\n" unless (defined($pid));
	unless ($pid) {
		exec($SENDMAIL, '-f', '<>', $email_addr);
		die "exec() failed: $!\n";
	}
	print MAIL <<END;
From: WebCal
To: $email_addr
Subject: $::webcal_conf::STRING140

$::webcal_conf::STRING141
$::webcal_conf::STRING142

$::webcal_conf::STRING143: $item
$::webcal_conf::STRING144: $time_string ($time $::webcal_conf::STRING145)
END
	close(MAIL);
	print "$date: email sent to $email_addr about $item\n";
	return 1;
}

#
# subroutine in which code can be added to call another 
# messaging program, for example one to send pages as well.
#
sub message2 {
	my ($item,$rsec,$item_time,$pager_addr) = (@_);
	my ($time,$date,$time_string);
	return if (! $pager_addr);
	$date = localtime;
	# $time = &get_time($rsec);
	# $time_string = localtime $item_time;
	#
	# add code here
	# 
	print "$date: page sent to $pager_addr about $item\n";
	return 1;
}

#
# subroutine to calculate a time string from the number of seconds
#
sub get_time {
	my ($sec) = (@_);
	my ($time);
	if ($sec < 3600) {
		$time = ($sec/60);
		$time .= " $webcal_conf::STRING128";
	} elsif ($sec < 86400) {
		$time = ($sec/3600);
		$time .= " $webcal_conf::STRING129";
	} elsif ($sec < 604800) {
		$time = ($sec/86400);
		$time .= " $webcal_conf::STRING130";
	} else {
		$time = ($sec/604800);
		$time .= " $webcal_conf::STRING131";
	}
	return $time;
}
