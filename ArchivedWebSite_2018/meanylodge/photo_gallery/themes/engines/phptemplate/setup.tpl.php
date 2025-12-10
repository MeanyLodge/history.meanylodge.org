<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
 <head>
   <title><?php  print $site_name;?><?php  print $site_name;?></title>
   <LINK REL="stylesheet" HREF="themes/engines/phptemplate/setup.css" TYPE="text/css">
 </head>
 <body>
   <!--logo-->
   <table cellpadding="0" cellspacing="0">
     <tr>
       <td colspan="2" align="left">
	   <img src="res/logo_setup.png"/>
       </td>
     </tr>
     <tr>
     	<td valign="top" width="40"><?php  print $menu;?></td>
     	<td valign="top"><div class="content"><?php  print $content; ?></div></td>
     </tr>
   </table>
<?php  if( $footer_message ) { ?>
	<table width="100%"><tr height="100"><td valign="bottom" align="center" width="100%">
		<?php  print $footer_message; ?>
		<!-- <font size="2">Powered by <a class="me"href="http://www.phpalbum.net">PHP Photo Album</font></a> -->
	</td></tr></table>
<?php  } ?>
</body></html>
