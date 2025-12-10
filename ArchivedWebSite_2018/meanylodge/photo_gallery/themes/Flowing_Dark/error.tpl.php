<html>
 <!--phpalbum <?php print $phpalbum_version;?> -->
 <head>
   <title><?php  print $site_name;?></title>
   <LINK REL="stylesheet" HREF="<?php print ($stylesheet_link);?>" TYPE="text/css">
 </head>
 <body>
   <!--logo-->
   <table width="100%" cellpadding="0" cellspacing="0">
     <tr>
       <td colspan="4" align="center">
	   <?php print $logo;?>
       </td>
     </tr>
   </table>
   <!--menu-->
   <table width="100%">
     <tr>
       <td width="100%">
         <font class="te">
	      <?php  if ( $return_home_url != "") { ?>
	      	      <a class="me" href="http://<?php  print $return_home_url;?>"><?php p("ID_HOME");?></a>&nbsp;|&nbsp;
	      <?php  } ?>
	      <?php  p('ID_ALBUM_NAME');?></font>
	</td>
	<td nowrap>
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
<!--main content-->
<table width="100%" height="300"><tr><td width="100%" align="center"><h1><?php p("ID_ERROR_PAGE_MESSAGE");?></h1></td></tr></table>
<!-- next/prev page-->

</td></tr></table>
<?php  if( $footer_message ) { ?>
	<table width="100%"><tr height="100"><td valign="bottom" align="center" width="100%">
		<?php  print $footer_message; ?>
		<!-- <font size="2">Powered by <a class="me"href="http://www.phpalbum.net">PHP Photo Album</font></a> -->
	</td></tr></table>
<?php  } ?>
<!--end of page -->
</body></html>
