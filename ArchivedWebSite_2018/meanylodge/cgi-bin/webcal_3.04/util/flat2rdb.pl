#!/usr/bin/perl -w

#
# WebCal - a web based calendar program.
# Released under the GNU GPL.  A text version of the GPL should have come
# with this program in the file "GPL.txt".
# Copyright 1999 Michael Arndt
#

#
# This script imports a cal.dat file into a relational database(MySQL or PostgreSQL).
# Run: ./flat2rdb -h for usage.
#
use strict;
use DBI;
use Fcntl ':flock';
use Getopt::Std;

#
# Variables
#
my ($index,$subindex,$modified,$cal_user,$idate,$shour,$ehour,$string,$link,$rsec,$notes,$DB);
my ($q,$conn,$db,$user,$pass,$table,$dbh,$sth,$rv,$calendar,$rdb);
use vars qw($opt_d $opt_u $opt_p $opt_t $opt_f $opt_r $opt_c);
my $prog = $0;
$prog =~ s,.*/,,g;

# 
# get command line input
#
&help unless getopts("d:u:p:t:f:r:c");
if ($opt_d) {
	$db = $opt_d;
} else {
	$db = "webcal";
}
if ($opt_u) {
	$user = $opt_u;
} else {
	$user = "webcal";
}
if ($opt_p) {
	$pass = $opt_p;
} else {
	$pass = "webcal";
}
if ($opt_t) {
	$table = $opt_t;
} else {
	$table = "webcal";
}
if ($opt_r) {
	$rdb = $opt_r;
} else {
	$rdb = "mysql"; 
}
if ($opt_f) {
	$DB = $opt_f;
} else {
	$DB = "/var/webcal/public/cal.dat";
}
if (! $opt_c) {
	if ($DB =~ /.*\/(.+)\/cal\.dat/) {
		$calendar = $1;
	} else {
		die "Error: could not determine calendar name\n";
	}
}

#
# go for it
#
if ($rdb eq "mysql") {
	require Mysql;
	$conn = "DBI:mysql:database=$db;host=localhost";
	$dbh = DBI->connect($conn, $user, $pass, {'RaiseError' => 1}) || die $dbh->errstr;
} elsif ($rdb eq "postgresql") {
	$dbh = DBI->connect( "dbi:Pg:dbname=$db", "$user", "$pass" ) or die $DBI::errstr;
} else {
	die "Error: bad rdb type: $rdb\n";
}
open (DB, "<$DB") or die "Error opening cal.dat: $!\n";
flock DB, LOCK_SH or die "Error locking cal.dat: $!\n";
my $x = 0;
while (<DB>) {
	next if /^#/;
	chomp;
	if ($opt_c) {
		($calendar, $index, $subindex, $modified, $cal_user, $idate, $shour, $ehour, $string, $link, $rsec, $notes) = split(/\|{3}/, $_);
	} else {
		($index, $subindex, $modified, $cal_user, $idate, $shour, $ehour, $string, $link, $rsec, $notes) = split(/\|{3}/, $_);
	}
	$string =~ s/'/\\'/g;
	$notes =~ s/'/\\'/g;
	if ($rdb eq "mysql") {
		$q = "INSERT INTO $table ( cal_name, item_index, subindex, modified, user, idate, shour, ehour, string, link, rsec, notes ) VALUES ( '$calendar', '$index', '$subindex', '$modified', '$cal_user', '$idate', '$shour', '$ehour', '$string', '$link', '$rsec', '$notes' )";
	} else {
		$q = "INSERT INTO $table ( cal_name, item_index, subindex, modified, cal_user, idate, shour, ehour, string, link, rsec, notes ) VALUES ( '$calendar', '$index', '$subindex', '$modified', '$cal_user', '$idate', '$shour', '$ehour', '$string', '$link', '$rsec', '$notes' )";
	}
	$sth = $dbh->prepare( $q ) or die $DBI::errstr;
	$rv = $sth->execute() or die $DBI::errstr;
	$x++;
}
print "$x rows inserted.\n";
flock DB, LOCK_UN or die "Error unlocking cal.dat: $!\n";
close(DB);
$dbh->disconnect;

#
# help subroutine
#
sub help {
	print STDERR "Usage: $prog -d <database> -u <database user> -p <password> -t <table name> -f </full/path/to/cal.dat> -r <rdb type(mysql|postgresql)> -c <if calendar name is given as 1st field in data file>\n";
	print STDERR "Defaults: $prog -d webcal -u webcal -p webcal -t webcal -f /var/webcal/public/cal.dat -r mysql\n";
	exit; 
}
