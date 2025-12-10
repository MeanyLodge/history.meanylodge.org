#!/usr/bin/perl -w

#
# WebCal - a web based calendar program.
# Released under the GNU GPL.  A text version of the GPL should have come
# with this program in the file "GPL.txt".
# Copyright 1999 Michael Arndt
#

#
# You may need to change path to perl interpreter on 1st line of this file.
#
# This is a simple script to combine 2 webcal database files.  Just give 
# the filenames (full path required if they are both not in current directory).
# The combined database file is sent to STDOUT, so you'll want to redirect it.
#
# Example: 
# ./db_merge.pl /var/webcal/cal1/cal.dat /var/webcal/cal2/cal.dat > cal.dat
#
# Then just move the resulting database file to the directory of your choice
# for the right calendar.
#

$prog = $0;
$prog =~ s,.*/,,;
&help if ($#ARGV != 1);
$file1 = $ARGV[0];
$file2 = $ARGV[1];

open (FILE1, $file1) or die "could not open $file1: $!\n";
open (FILE2, $file2) or die "could not open $file2: $!\n";
$index = 1;
while (<FILE1>) {
	if (/^(\d+)\|{3}.*/) {
		$this_index = $1;
		if (! $indexes{$this_index}) {
			$indexes{$this_index} = $index;
			$index++;
		}
		s/^\d+(\|{3}.*)/$indexes{$this_index}$1/;
		print;
	}
}
close (FILE1);

undef %indexes;
while (<FILE2>) {
	if (/^(\d+)\|{3}.*/) {
		$this_index = $1;
		if (! $indexes{$this_index}) {
			$indexes{$this_index} = $index;
			$index++;
		}
		s/^\d+(\|{3}.*)/$indexes{$this_index}$1/;
		print;
	}
}	

sub help () {
	print "Usage: $prog <db_file1.dat> <db_file2.dat>\n";
	exit; 
}
