#!/usr/bin/perl -w

#
# WebCal - a web based calendar program.
# Released under the GNU GPL.  A text version of the GPL should have come
# with this program in the file "GPL.txt".
# Copyright 1999 Michael Arndt
#

#
# This script exports mysql database entries into a cal.dat file.
# Run: ./rdb2flat.pl -h for usage.
#
use strict;
use DBI;
use Fcntl ':flock';
use Getopt::Std;

#
# Variables
#
my ($index,$subindex,$idate,$shour,$ehour,$string,$link,$rsec,$notes,$DB,$file,%items,$x);
my ($q,$conn,$db,$user,$pass,$table,$dbh,$sth,$ref,$record,$calendar,$rdb);
use vars qw($opt_d $opt_u $opt_p $opt_t $opt_f $opt_c $opt_r);
my $prog = $0;
$prog =~ s,.*/,,g;

# 
# get command line input
#
&help unless getopts("d:u:p:t:f:c:r:");
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
if ($opt_f) {
	$file = $opt_f;
} else {
	$file = "cal.dat";
}
if ($opt_c) {
	$calendar = $opt_c;
} else {
	$calendar = "public";
}
if ($opt_r) {
	$rdb = $opt_r;
} else {
	$rdb = "mysql";
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
if ($calendar eq "*") {
	if ($rdb eq "mysql") {
		$q = "SELECT cal_name, item_index, subindex, modified, user, idate, shour, ehour, string, link, rsec, notes FROM $table";
	} else {
		$q = "SELECT cal_name, item_index, subindex, modified, cal_user, idate, shour, ehour, string, link, rsec, notes FROM $table";
	}
} else {
	if ($rdb eq "mysql") {
		$q = "SELECT item_index, subindex, modified, user, idate, shour, ehour, string, link, rsec, notes FROM $table WHERE cal_name='$calendar'";
	} else {
		$q = "SELECT item_index, subindex, modified, cal_user, idate, shour, ehour, string, link, rsec, notes FROM $table WHERE cal_name='$calendar'";
	}
}
$sth = $dbh->prepare( $q ) or die $DBI::errstr;
$sth->execute() or die $DBI::errstr;
while ($ref = $sth->fetchrow_hashref()) {
	$index = $ref->{'item_index'};
	$subindex = $ref->{'subindex'};
	$items{$index}{$subindex}{'modified'} = $ref->{'modified'};
	if ($rdb eq "mysql") {
		$items{$index}{$subindex}{'user'} = $ref->{'user'};
	} else {
		$items{$index}{$subindex}{'user'} = $ref->{'cal_user'};
	}
	$items{$index}{$subindex}{'idate'} = $ref->{'idate'};
	$items{$index}{$subindex}{'shour'} = $ref->{'shour'};
	$items{$index}{$subindex}{'ehour'} = $ref->{'ehour'};
	$items{$index}{$subindex}{'string'} = $ref->{'string'};
	$items{$index}{$subindex}{'link'} = $ref->{'link'};
	$items{$index}{$subindex}{'rsec'} = $ref->{'rsec'};
	$items{$index}{$subindex}{'notes'} = $ref->{'notes'};
	if ($calendar eq "*") {
		$items{$index}{$subindex}{'cal_name'} = $ref->{'cal_name'};
	}
}
$sth->finish;
$dbh->disconnect;

open (FILE, ">$file") or die "Error opening $file: $!\n";
$x = 0;
for $index (sort keys %items) {
	for $subindex (sort keys %{ $items{$index} }) {
		if ($calendar eq "*") {
			$record = join '|||', $items{$index}{$subindex}{'cal_name'}, $index, $subindex, $items{$index}{$subindex}{'modified'}, $items{$index}{$subindex}{'user'}, $items{$index}{$subindex}{'idate'}, $items{$index}{$subindex}{'shour'}, $items{$index}{$subindex}{'ehour'}, $items{$index}{$subindex}{'string'}, $items{$index}{$subindex}{'link'}, $items{$index}{$subindex}{'rsec'}, $items{$index}{$subindex}{'notes'}; 
		} else {
			$record = join '|||', $index, $subindex, $items{$index}{$subindex}{'modified'}, $items{$index}{$subindex}{'user'}, $items{$index}{$subindex}{'idate'}, $items{$index}{$subindex}{'shour'}, $items{$index}{$subindex}{'ehour'}, $items{$index}{$subindex}{'string'}, $items{$index}{$subindex}{'link'}, $items{$index}{$subindex}{'rsec'}, $items{$index}{$subindex}{'notes'}; 
		}
	}
	print FILE "$record\n";
	$x++;
}
print "$x rows exported.\n";
close(FILE);

#
# help subroutine
#
sub help {
	print STDERR "Usage: $prog -d <database> -u <database user> -p <password> -t <table name> -f <file> -c <calendar name> -r <rdb type(mysql|postgresql)\n";
	print STDERR "Defaults: $prog -d webcal -u webcal -p webcal -t webcal -f cal.dat -c public -r mysql\n";
	exit; 
}
