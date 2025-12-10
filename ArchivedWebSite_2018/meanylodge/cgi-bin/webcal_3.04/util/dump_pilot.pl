#!/usr/bin/perl -w

use PDA::Pilot;
use Data::Dumper;

#
# dump_pilot.pl: Used to dump the contents of all the records in a the pilot 
#                datebook database for testing purposes. 
#

#
# Palm pilot setup
#
$sock = "/dev/ttyqe";
$DB = "DatebookDB";
print STDERR "\n>> Press synch now! <<\n\n";
$socket = PDA::Pilot::openPort($sock);
$dlp = PDA::Pilot::accept($socket);

#
# process data from palm pilot
#
print STDERR "opening connection\n";
$db = $dlp->open($DB);
&setup_db_data($db);
print STDERR "closing connection\n";
$db->close();

#
# subroutine to setup hash of datebook items
#
sub setup_db_data{
	my ($db) = (@_);
	my ($r,$x);
	my ($year,$month,$day,$sh,$sm,$eh,$em,$id,%items);
	$x = 0;
	while ($r = $db->getRecord($x++)) {
		next if (! $r->{'description'});
		print "\nDESCRIPTION: ";
		print "$r->{'description'}\n";
		print "------------\n";
		for $key (sort keys %$r) {
			next if (($key eq "raw") || ($key eq "description"));
			print "key: $key";
			if (($key eq "begin") || ($key eq "end")) {
				print "\n";
				$y = 0;
				for ( @{ $r->{$key} } ) {
					print "  $y: $r->{$key}[$y]\n";
					$y++;
				}
			} elsif  (($key eq "alarm") || ($key eq "repeat")) {
				print "\n";
				for $key2 (sort keys %{ $r->{$key} } ) {
					if (($key2 eq "days") || ($key2 eq "end")) {
						$z = 0;
						print "  $key2\n";
						for (@{ $r->{$key}{$key2} }) {
							print "    $z: $r->{$key}{$key2}[$z]\n";
							$z++;
						}
					} else {
						print "  $key2: $r->{$key}{$key2}\n";
					}
				}
			} else {
				print "  val: $r->{$key}\n";
			}
		}	
		print "\n";
	}
	return 1;
}
