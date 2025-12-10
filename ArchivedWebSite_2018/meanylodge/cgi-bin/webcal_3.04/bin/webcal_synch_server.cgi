use CGI;
use CGI::Carp qw(fatalsToBrowser);
use strict;
use webcal_shared;
use webcal_io;

#
# WebCal - a web based calendar program.
# Released under the GNU GPL.  A text version of the GPL should have come
# with this program in the file "GPL.txt".
# Copyright 2000 Michael Arndt
# Thanks to Sun Microsystems for funding development of the Palm Pilot synch code.
#

#
# variables
#
$::calendar = "";
$::USER = "";
my $function = "";
my @args;

# ----------------------------------------------------------
# Main
# ----------------------------------------------------------

#
# take a look at our CGI form input.
#
$::query = new CGI;
@args = $::query->param;
ARG: for (@args) {
	$::calendar = $::query->param($_), next ARG if /cal/;
	$function = $::query->param($_), next ARG if /function/;
	last if (($function) && ($::calendar));
}
$::calendar =~ s/\+/ /g;
$::cgi_calendar = $::calendar;
$::cgi_calendar =~ s/ /+/g;
$::USER = $ENV{'REMOTE_USER'};

if (! $::calendar) {
	print "Error: No calendar given\n";
	goto EXIT;
}

#
# include the configuration files.  I should add code here to check if we 
# really need to reload this file, instead of just reloading every time.
#
my $inc_file = "${libdir}/webcal_conf.pm";
delete $INC{$inc_file} if ($INC{$inc_file});
require $inc_file or die "Error: $!\n";

#
# Connect to database (if not using flat files)
#
&dbh_setup;

$::DATABASE = "$webcal_conf::DB_DIR/$::calendar/cal.dat";
$::TEMPFILE = "$webcal_conf::DB_DIR/$::calendar/cal.tmp.$$";
$::USERFILE = "$webcal_conf::DB_DIR/$::calendar/.users";

#
# Determine of the user has supplied proper credentials.
#
my $trusted = 0;
open (USERS, "<$::USERFILE") or die "$webcal_conf::ERROR_STRING1 $::USERFILE: $!\n";
while (<USERS>) {
	chop;
	if ($::USER eq $_) {
		$trusted = 1;
		last;
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
# Start the document
#
print "Content-Type: text/html\n\n";

#
# Main decision making section.
#
if ($function eq "get") {
	&get_all;
} elsif ($function eq "add") {
	&synch_add;
} elsif ($function eq "del") {
	&synch_del;
} elsif ($function eq "set_unmod") {
	&set_all_unmodified;
} else {
	print "bad function: $function\n";	
	goto EXIT;
}

#
# subroutine to fetch all the items for a calendar.
#
sub get_all {
	my ($all_items_ref,$sub_items_ref,$pers_items_ref,$index,$subindex);
	($all_items_ref,$sub_items_ref,$pers_items_ref) = &setup_items_hash("all","0");
	for $index (sort keys %$pers_items_ref) {
		for $subindex (sort keys %{ $$pers_items_ref{$index} }) {
			print "pers\n";
			print "$index:$subindex\n";
			print "$$pers_items_ref{$index}{$subindex}{'modified'}\n";
			print "$$pers_items_ref{$index}{$subindex}{'user'}\n";
			print "$$pers_items_ref{$index}{$subindex}{'idate'}\n";
			print "$$pers_items_ref{$index}{$subindex}{'shour'}\n";
			print "$$pers_items_ref{$index}{$subindex}{'ehour'}\n";
			print "$$pers_items_ref{$index}{$subindex}{'string'}\n";
			print "$$pers_items_ref{$index}{$subindex}{'link'}\n";
			print "$$pers_items_ref{$index}{$subindex}{'rsec'}\n";
			print "$$pers_items_ref{$index}{$subindex}{'notes'}\n";
		}
	}
	for $index (sort keys %$sub_items_ref) {
		for $subindex (sort keys %{ $$sub_items_ref{$index} }) {
			print "sub\n";
			print "$index:$subindex\n";
			print "$$sub_items_ref{$index}{$subindex}{'modified'}\n";
			print "$$sub_items_ref{$index}{$subindex}{'user'}\n";
			print "$$sub_items_ref{$index}{$subindex}{'idate'}\n";
			print "$$sub_items_ref{$index}{$subindex}{'shour'}\n";
			print "$$sub_items_ref{$index}{$subindex}{'ehour'}\n";
			print "$$sub_items_ref{$index}{$subindex}{'string'}\n";
			print "$$sub_items_ref{$index}{$subindex}{'link'}\n";
			print "$$sub_items_ref{$index}{$subindex}{'rsec'}\n";
			print "$$sub_items_ref{$index}{$subindex}{'notes'}\n";
		}
	}
	return 1;
}

#
# subroutine to add webcal records
#
sub synch_add {
	my ($index,$subindex,$user,$date,$stime,$etime,$string,$link_string,$rsec,$notes);
	my (@args,%items,$item,%new_index,$tmp_index,%new_items,$next_index);
	@args = $::query->param;
	for (@args) {
		if (/([a-z]+)(\d+)/) {
			$items{$2}{$1} = $::query->param($_);
		}
	}
	$next_index = &get_next_index;
	for $item (sort keys %items) {
		$index    = &input_check($items{$item}{'index'});
		$subindex = &input_check($items{$item}{'subindex'});
		if ($index =~ /([a-z]+)/) {
			if ($new_index{$index}) {
				$index = $new_index{$index};
				print "index $1=$index\n";
			} else {
				$tmp_index = $index;
				$index = $next_index;
				$next_index++;
				print "index $1=$index\n";
				$new_index{$tmp_index} = $index;
			}
		}	
		$new_items{$index}{$subindex}{'user'}        = &input_check($items{$item}{'user'});
		$new_items{$index}{$subindex}{'date'}        = &input_check($items{$item}{'date'});
		$new_items{$index}{$subindex}{'stime'}       = &input_check($items{$item}{'shour'});
		$new_items{$index}{$subindex}{'etime'}       = &input_check($items{$item}{'ehour'});
		$new_items{$index}{$subindex}{'string'}      = &input_check($items{$item}{'string'});
		$new_items{$index}{$subindex}{'link_string'} = &input_check($items{$item}{'link'});
		$new_items{$index}{$subindex}{'rsec'}        = &input_check($items{$item}{'rsec'});
		$new_items{$index}{$subindex}{'notes'}       = &input_check($items{$item}{'notes'});
	}
	for $index (sort {$a <=> $b} keys %new_items) {
		for $subindex (sort {$a <=> $b} keys %{ $new_items{$index} }) {
			&add_record($index,$subindex,$new_items{$index}{$subindex}{'user'},$new_items{$index}{$subindex}{'date'},$new_items{$index}{$subindex}{'stime'},$new_items{$index}{$subindex}{'etime'},$new_items{$index}{$subindex}{'string'},$new_items{$index}{$subindex}{'link_string'},$new_items{$index}{$subindex}{'rsec'},$new_items{$index}{$subindex}{'notes'});
		}
	}
	return 1;
}

#
# subroutine to del webcal records
#
sub synch_del {
	my ($index,@args);
	@args = $::query->param;
	for (@args) {
		if (/index\d+/) {
			$index = $::query->param($_); 
			&del($index);
		}
	}	
	return 1;
}

EXIT:
