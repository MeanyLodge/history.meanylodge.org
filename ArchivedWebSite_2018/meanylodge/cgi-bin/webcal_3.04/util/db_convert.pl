#!/usr/bin/perl -w

#
# WebCal - a web based calendar program.
# Released under the GNU GPL.  A text version of the GPL should have come
# with this program in the file "GPL.txt".
# Copyright 1999 Michael Arndt
#

#
# script to convert 3.0 or 3.01 database to the current database format.
#

use Getopt::Std;
use strict;

#
# variables
#
use vars qw($opt_b $opt_f $opt_d $opt_u $opt_t $opt_p);
my ($type,$files,$db,$user,$table,$pass);
my $prog = $0;
$prog =~ s,.*/,,g;

&help unless getopts("b:f:d:u:t:p:");

#
# setup
#
$type = $opt_b;
$files = $opt_f;
$db = $opt_d;
$user = $opt_u if $opt_u;
$table = $opt_t if $opt_t;
$pass = $opt_p if $opt_p;

&help if (! $type);

#
# call subroutines
#
if ($type eq "flat") {
	&help if (! $files);
	&flat;
} elsif ($type eq "mysql") {
	&help if ((! $db) || (! $user) || (! $table) || (! $pass));
	&mysql;
} elsif ($type eq "postgresql") {
	&postgresql;
} else {
	die "$prog: bad type: $type\n";
}

#
# subroutine to convert flat files.
#
sub flat {
	my (@dirs,$dir,$file,$backup,@old_db,$new_record);
	my ($index,$date,$shour,$ehour,$item,$link,$rsec);
	if (-f "$files") {
		open(FILE, "<$files") or die "could not open $files: $!\n";
		while (<FILE>) {
   			if ((/^#/) || (/^(.*?\|{3}){6}\w+.*$/)) {
				push(@old_db, $_);
			} else {
				die "hmm...this does not look like an old style cal.dat. Aborting.\n";
			}	
		}
		close (FILE);
		$backup = "$files".".old";
		print "backing up $files to $backup\n";
		system("cp \"$files\" \"$backup\"");
		print "done.\n";
		print "converting $files to new format\n";
		open (FILE, ">$files") or die "could not open $files: $!\n";
		for (@old_db) {
			chomp;
			($index,$date,$shour,$ehour,$item,$link,$rsec) = split(/\|{3}/, $_);
			$new_record = join '|||', $index, "1", "1", "0", $date, $shour, $ehour, $item, $link, $rsec, "0";
			print FILE "$new_record\n";
		} 
		close(FILE);
		print "done.\n";
	} else {
		opendir DIR, $files or die "$prog: could not open dir $files\n";
		@dirs = readdir DIR;
		closedir DIR; 
		for $dir (@dirs) {
			$file = $files . "/" . $dir . "/cal.dat";
			next if ( ! -f "$file" );
			undef @old_db;
			open(FILE, "<$file") or die "could not open $file: $!\n";
			while (<FILE>) {
   				if ((/^#/) || (/^(.*?\|{3}){6}\w+.*$/)) {
					push(@old_db, $_);
				} else {
					die "hmm...this does not look like an old style cal.dat. Aborting.\n";
				}	
			}
			close (FILE);
			$backup = "$file".".old";
			print "backing up $file to $backup\n";
			system("cp \"$file\" \"$backup\"");
			print "done.\n";
			print "converting $file to new format\n";
			open (FILE, ">$file") or die "could not open $file: $!\n";
			for (@old_db) {
				chomp;
				($index,$date,$shour,$ehour,$item,$link,$rsec) = split(/\|{3}/, $_);
				$new_record = join '|||', $index, "1", "1", "0", $date, $shour, $ehour, $item, $link, $rsec, "0";
				print FILE "$new_record\n";
			} 
			close(FILE);
			print "done.\n";
		}
	}
	return 1;
}

#
# subroutine to update a mysql db
#
sub mysql {
	my ($conn,$dbh,$q,$sth,$rv,$ref);
	my (%items,$index);
	require DBI; 
	require Mysql; 
	$conn = "DBI:mysql:database=$db;host=localhost";
	$dbh = DBI->connect($conn, $user, $pass, {'RaiseError' => 1}) || die $dbh->errstr;
	$q = "SELECT cal_name, item_index, idate, shour, ehour, string, link, rsec FROM $table";	
	$sth = $dbh->prepare( $q ) or die $DBI::errstr;
	$sth->execute() or die $DBI::errstr;
	while ($ref = $sth->fetchrow_hashref()) {		
		$index = $ref->{'item_index'};
		$items{$index}{'cal_name'} = $ref->{'cal_name'};
		$items{$index}{'idate'} = $ref->{'idate'};
		$items{$index}{'shour'} = $ref->{'shour'};
		$items{$index}{'ehour'} = $ref->{'ehour'};
		$items{$index}{'string'} = $ref->{'string'};
		$items{$index}{'string'} =~ s/'/\\'/g;
		$items{$index}{'link'} = $ref->{'link'};
		$items{$index}{'rsec'} = $ref->{'rsec'};
	}
	$q = "DROP TABLE $table";
	$sth = $dbh->prepare( $q ) or die $DBI::errstr;
	$rv = $sth->execute or die $DBI::errstr;
	$q = "CREATE TABLE $table (cal_name BLOB NOT NULL, xindex INT UNSIGNED AUTO_INCREMENT PRIMARY KEY, item_index INT UNSIGNED, subindex SMALLINT, modified TINYINT, user TINYBLOB, idate TINYBLOB, shour VARCHAR(4), ehour VARCHAR(4), string BLOB, link BLOB, rsec INT UNSIGNED, notes BLOB )";	
	$sth = $dbh->prepare( $q ) or die $DBI::errstr;
	$rv = $sth->execute or die $DBI::errstr;
	for $index (sort keys %items) {
		my $cal_name = $items{$index}{'cal_name'};
		my $idate = $items{$index}{'idate'};
		my $shour = $items{$index}{'shour'};
		my $ehour = $items{$index}{'ehour'};
		my $string = $items{$index}{'string'};
		my $link = $items{$index}{'link'};
		my $rsec = $items{$index}{'rsec'};
		$q = "INSERT INTO $table ( cal_name, item_index, subindex, modified, user, idate, shour, ehour, string, link, rsec, notes ) VALUES ( '$cal_name', '$index', '1', '1', '0', '$idate', '$shour', '$ehour', '$string', '$link', '$rsec', '0' )";
		$sth = $dbh->prepare( $q ) or die $DBI::errstr;
		$rv = $sth->execute() or die $DBI::errstr;
	}
	$dbh->disconnect;
}
#
# subroutine to update a postgresql db
#
sub postgresql {
	print STDERR "Postgresql databases can not be upgraded, as the entire structure has changed.\n";
	print STDERR "If you do not need to preserve data, delete your postgresql database and re-install webcal.\n";
	die "Contact marndt\@bulldog.tzo.org for help if you have data that you really need to preserve.\n";
}

sub help {
	print <<HELP;
Usage: $prog -b <backend type> -f <directory> [-d <database name>] [-u <db user>] [-t <table>] [-p <password>]
flat file example: $prog -b flat -f /var/webcal
mysql example: $prog -b mysql -d webcal -u webcal -t webcal -p webcal
HELP
	exit;
}
