<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
  <!--phpalbum <?php print $phpalbum_version;?> -->
   <title><?php  print $site_name;?></title>
   <LINK REL="stylesheet" HREF="<?php print ($stylesheet_link);?>" TYPE="text/css">
 </head>
 <body>
 <table width="100%"><tr><td align="center">
 <table class="BODY" cellpadding="5" width="90%"><tr><td>

   <!--logo-->
   <table width="100%" cellpadding="0" cellspacing="0">
     <tr>
       <td colspan="4" align="left">
	   <?php print $logo;?>
       </td>
     </tr>
   </table>
   <table width="100%"><tr>
   	<td width="100%" nowrap align="right">
	  	<?php if($login_enabled && !$logged_in){?>
	  		<a class="me" href="<?php print $login_logout_link;?>"><?php print $login_logout_text?></a>&nbsp;
	  	<?php }?>	
	  	<?php if($logged_in){?>
	  		<a class="me" href="main.php?cmd=setup"><?php p("ID_SETUP");?>&nbsp;</a>
	  	<?php }?>
	</td>
    </tr>
        <?php if($login_clicked){ print "<tr><td colspan=\"2\" width=\"100%\" align=\"right\">".$login_dialog."</td></tr>"; }?>
   </table>

   <!--menu-->
   <table width="100%" class="menu">
     <tr>
       <td width="100%">
         <font class="te">
	      <?php  if ( $return_home_url != "") { ?>
	      	      <a class="me" href="http://<?php  print $return_home_url;?>"><?php p("ID_HOME");?></a>&nbsp;|&nbsp;
	      <?php  } ?>
	      <?php  p('ID_ALBUM_NAME');?></font>
	</td>
      </tr>
   </table>
<!--main content-->
<table width="100%" height="300"><tr><td width="100%" align="center"><h1><?php p("ID_ERROR_PAGE_MESSAGE");?></h1></td></tr></table>
<?php  if( $footer_message ) { ?>
	<table width="100%"><tr height="30"><td valign="bottom" align="center" width="100%">
		<?php  print $footer_message; ?>
		<!-- <font size="2">Powered by <a class="me"href="http://www.phpalbum.net">PHP Photo Album</font></a> -->
	</td></tr></table>
<?php  } ?>

</td></tr></table>
</td></tr></table>
<!--end of page -->
</body></html>
