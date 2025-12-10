Current Version: 3.04

What is WebCal?
---------------
WebCal is a simple web browser based calendar program to help you keep track of
your appointments, meetings, birthdays, whatever, etc....

Requirements
------------
-A webserver.
-A Javascript enabled browser.
-Root access to install WebCal and configure your webserver to use it.
-perl, and the CGI.pm perl module.

Features
--------
-Multiple calendars.
-Password protection.
-Private calendars are read/write only with password.
-Public calendars are readable by everyone, writable only with password.
-Open calendars are read/write for everyone.
-File locking ensures data integrity for a flat file back end.
-Option to use relational database back end for calendar data.
-Flexible scheduling allows for easily adding repetitive tasks with only one entry.
-Multiple languages supported.
-Multiple views: Year, Month, Week, or Day.
-Ability to subscribe to other WebCal calendars, and have their contents show
 up in your calendar.
-Administrative control of calendars.
-Runs under mod_perl.
-Email Reminders on Items.
-Can synch with Palm Pilot.

Installation
------------
- If you have an old version of WebCal installed, you can just install new 
  versions right over the top of them.  Database files will be preserved,
  but the scripts will be replaced with the new version.

1) Become superuser: su root
2) unzip and untar the file: tar xvfz webcal_x.x.tar.gz OR 
                             gzcat webcal_x.x.tar.gz | tar xvf -
3) Run the install script: cd webcal_x.x; ./install.sh
4) Answer the questions asked by the install script.
5) If you have database files from a 3.0 or 3.01 install, convert them to
   the proper format using the db_convert.pl script. If you have a database 
   from a version before 3.0, you will have to upgrade to 3.0, then to 3.03.

Special install options:
------------------------
Pass either or both of the following options to install.sh if you are not able 
to perform a normal install.
 
-noroot
  If you do not have access to the root account, use this option.  Will result
  in an unsecure setup, as the database directory will need to be created with 
  world write permission, so that webcal processes can write to it.
  
-nohtaccess
  If you do not have access to the webserver configuration, and are not 
  allowed to use .htaccess files, use this option.  This will only allow you
  to use open calendars which are read/write for everyone, as passwords are 
  disabled.

Un-Installing
-------------
1) Remove all webcal files from your cgi-bin directory
  ex: cd <path_to_your_cgi_dir>;rm webcal*;rm rm -rf protected
2) Remove all database files - usually in /var/webcal
  ex: rm -rf /var/webcal
3) If you were using a relational database, drop the webcal table and
   the webcal user.

Setting up your webserver to use WebCal - IMPORTANT!
----------------------------------------------------
In order to use WebCal, your webserver must be set up to execute CGI scripts 
and allow http authorization in the directory where you installed the scripts.
The following example shows you how to set up your httpd.conf file for an 
Apache webserver.  Note that older versions of Apache would use an access.conf
file for these directives, but more recent versions of Apache have combined the
entire configuration into the single file httpd.conf.  This example assumes you
placed the webcal cgi's in the webserver's cgi-bin/webcal directory, which in 
this case, is located under /opt/httpd.  

<Directory /opt/httpd/cgi-bin/webcal>
AllowOverride AuthConfig
Options ExecCGI
</Directory>

This should give you an idea of what you need to do.  Remeber to restart your
webserver after making changes to the configuration files.

Reminders
---------
WebCal can be set up to send email reminders.  The install script will set up a 
crontab entry which runs every 5 minutes, checking to see if any reminders need to
be sent.  You can also add your own code to the script to enable paging as well as
email.  Users need to set up their email address (and pager info) in their calendar
preferences.  The webcal_remind.pl script uses sendmail for email, and assumes it 
is in /usr/lib/sendmail.  

Utilites
--------
The "util" directory in the distribution tarball has some perl scripts that my be
of help:
  1. db_convert.pl will convert a pre-3.02 (3.0 and 3.01) cal.dat files and mysql
     databases to the current database version.
  2. db_merge.pl will merge 2 cal.dat files together into one.
  3. db_clean.pl will clean out old entries from your calendar data.  Needs manual 
     configuration to work, read the documentation at the top of the script.   
  4. flat2rdb.pl will import a cal.dat file into a relational database (mysql or
     postgresql) set up for WebCal.
  5. rdb2flat.pl will export a relational database (mysql or postgresql) into a 
     cal.dat file.
  6. webcal_synch_client.pl is uses to synch your palm pilot datebook with WebCal.
     See more documentation on this below.

Synching with Palm Pilot
------------------------
You can use the webcal_synch_client.pl script to synch your palm pilot with your
webcal data.  The synch code uses the perl module provided by the pilot-link 
package.  You need to install the pilot-link package, as well as the perl module
that comes with it (PDA::Pilot).  You will also need the following perl modules
installed on the client machine which you do the synch from:
  LWP
  MIME::Base64
  URI
  HTML::Parser
  Bundle::libnet

It seems like a lot of modules, but that last 4 modules are all really there just
to support LWP.

Whenever possible, the synch client favors the WebCal data over the Palm Pilot 
data.  For example, if both entries have changed, then it will use the WebCal
entry.  Also, since not all the types of repeating entries on the Palm Pilot 
are supported by WebCal, the entries that can not be handled by WebCal will be
re-written as single day events in WebCal.  See the documentation at the top
of the webcal_synch_client.pl script for more details.

Run "webcal_synch_client.pl -h" for help on using the synch client.  You will
probably want to set up a .wcsynchrc file if you plan on synching regularly.

Run webcal_synch_client.pl -t to use the client in test mode.  You will see
messages about what would be done with both your webcal and palm pilot data, but
no changes will actually be made.  

Thanks to Sun Microsystems for funding development of the Palm Pilot synch code.

Author and Homepage
--------------------
Author: Michael Arndt 
Email: marndt@bulldog.tzo.org
Home Page: http://bulldog.tzo.org/webcal/webcal.html

You may email me, or the mailing list (see below) for help.  Please limit
questions to WebCal only though, I don't have time to answer general Apache,
Perl, or MySQL questions.  Thanks.

Mailing list
------------
To subscribe: send a message with "subscribe" in the body to:
webcal-request@bulldog.tzo.org 

To unsubscribe: send a message with "unsubscribe" in the body to:
webcal-request@bulldog.tzo.org 

To send messages: webcal@bulldog.tzo.org 

Thanks to:
----------
Sun Microsystems - Funding the development of the Palm Pilot synch code. 

Clay Fandre - Alpha testing, beta testing, feature suggestions.

Rodolfo Pilas - Translating everything for the Spanish version, as well as
doing a lot of testing and making suggestions for improvements.

Eric Binger - Translating to French.

Kaare Rasmussen - Translating to Danish.

Nils Jeppe - Translating to German, along with other miscellaneous feature 
recommendations.

Casiraghi Luigi - Translating to Italian.

Herman Bruyninckx - Translating to Dutch.

Chung-Kie Tung - Translating for the Chinese version, and examples
for improving look of the day view.

Dobrica Pavlinusic - Translating to Croatian.

Miquel Colomer - Translating to Catalan.

Rob Huffstedtler - Example code of calculating the month dates internally,
from which I got some ideas for my implementation.

Jonathan Kozolchyk - Suggestion for highlighting current day, and providing
code to do it.

Jerad Hoff - providing services for the announce list.

Rod Roark - providing the fix to the MSIE CGI refresh problem.

Marcel Trap - Example code for including a "subscribe-to" feature.

Norival Torianto Junior - Translating to Brazilian Portuguese.

and many more....see the CHANGELOG file for more thank-you's!

Terms and conditions of this software
-------------------------------------
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
