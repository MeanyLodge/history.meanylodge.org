<?php
  $to = "webmaster@meanylodge.org";
  $from = "sender@meanylodge.meanylodge.org";
  $subject = "Meany Email Notification Request";
  $name = $_POST['name'];
  $email = $_POST['email'];
  $notification = $_POST['notification'];
  $message = "Full Name: $name - Email Address: $email - Notification Type: $notification";


/* PHP form validation: the script checks that the Email field contains a valid email address.
   The function preg_match performs a regular expression match. It's a very powerful PHP function
   to validate form fields and other strings - see PHP manual for details.
*/

/* List of bogus emails - exit; */

if (preg_match("*asd*", $email)) exit;
if (preg_match("*saqz*", $email)) exit;


if (!preg_match("/\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*/", $email))
{
  echo "<h4>Invalid email address</h4>";
  echo "<a href='javascript:history.back(1);'>Back</a>";
} 
/* Sends the mail and outputs the "Thank you" string */
else
{
  mail( $to, $subject, $message, "From: $from" );
  header( "Location: http://www.meanylodge.org/thankyou.html" );
} 

?>

