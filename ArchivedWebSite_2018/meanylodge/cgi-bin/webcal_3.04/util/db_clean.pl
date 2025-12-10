#!/usr/bin/perl 

#
# WebCal - a web based calendar program.
# Released under the GNU GPL.  A text version of the GPL should have come
# with this program in the file "GPL.txt".
# Copyright 1999 Michael Arndt
#

#
# To use this for cleaning out old entries, set the following
# 3 lines, as well as the INTERVAL value.  Then, either run
# periodically by hand, or out of cron on every month, or
# however often you like.  This will clean entries out of
# ALL calendars!!!
#

use lib '/opt/httpd/perl';		# set this to your installation dir
my $libdir = "/opt/httpd/perl";	# set this to your installation dir
my $db_dir = "/var/webcal";		# set this to your database dir

#
# INTERVAL: the number of seconds to wait until deleting an item.
# Default is about 3 months (93 days) worth of seconds.  Items more
# than 3 months old will be deleted!
#
my $INTERVAL = "8035200";			

use strict;
use Time::Local;
use webcal_io;

#
# global variables
#
my (@dirs,$index,$date,$uid,$gid);
my ($year,$month,$day,$dow,$item_time,$current_time,$age);
my ($all_items_ref,$sub_items_ref,$pers_items_ref);
$::calendar = "";
$ENV{'HTTP_HOST'} = "none";
my $CONF_FILE = "${libdir}/webcal_conf.pm";

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
	next if (! -e "$db_dir/$::calendar/cal.dat");
	$::DATABASE = "$webcal_conf::DB_DIR/$::calendar/cal.dat";
	($uid,$gid) = (stat $::DATABASE)[4,5];
	$::TEMPFILE = "$webcal_conf::DB_DIR/$::calendar/cal.tmp.$$";
	($all_items_ref,$sub_items_ref,$pers_items_ref) = &setup_items_hash("all","0");
	for $index (sort keys %$pers_items_ref) {
		$date = $$pers_items_ref{$index}{'1'}{'idate'};
		if ($date =~ /(\d{4})(\d{2})(\d{2})/) {
			$year = $1;
			$month = $2;
			$day = $3;
		} elsif ($date =~ /^(.+?),(.+?),(.+?),(.+)$/) {
			$year = $1;
			$month = $2;
			next if ($year =~ /\.\*/);
			if ($month =~ /\.\*/) {
				$month = 12;
			}
			$day = 31;
		}
		$year = $year - 1900;	
		$month = $month - 1;	
		$item_time = timelocal "0","0","12",$day,$month,$year;
		$current_time = time;
		$age = $current_time - $item_time;
		if ($age > $INTERVAL) {
			&del($index);
		}
	}
	chown $uid, $gid, $::DATABASE;
	chmod 0700, $::DATABASE
}

#
# disconnect from database (if not using flat files)
#
&dbh_close;
exit;
