#!/usr/bin/perl -w

use LWP::UserAgent;
use PDA::Pilot;
use Data::Dumper;

#
# clear_pilot.pl: Used to clear the datebook on a pilot for testing purposes.
#

my $port = "/dev/ttyqe";
$port = $ARGV[1] if ($ARGV[1]);
print STDERR "\n>> Press synch now! <<\n\n";
my $DB = "DatebookDB";
my $socket = PDA::Pilot::openPort($port);
my $dlp = PDA::Pilot::accept($socket);
$dlp->delete($DB);
my $db = $dlp->create($DB, 'date', 'DATA', 0, 0);
undef $dlp;
print "done.\n";
