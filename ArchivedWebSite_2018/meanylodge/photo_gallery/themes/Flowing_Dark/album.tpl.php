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
   	<?php  if($show_search_box) { ?>
		<div style="float: right;">
			<form method="GET" action="" style="margin:0px;">
				<table cellspacing="0" cellpadding="0" border="0"><tr>
				<td nowrap><input class="login" type="text" size="20" name="keyword" value="<?php print $search_text?>"/></td>
				<td nowrap>&nbsp;&nbsp;&nbsp;</td>
				<td nowrap><input class="login_btn" type="submit" value="<?php p("ID_SEARCH");?>"/></td>
				</tr></table>
				<input type="hidden" name="cmd" value="albumnew"/>
			</form>
		</div><br style="margin: 3px;"/>
	<?php  } ?>
   <table width="100%">
     <tr>
       <td width="100%">
         <font class="te">
	      <?php  if ( $return_home_url != "") { ?>
	      	      <a class="me" href="http://<?php  print $return_home_url;?>"><?php p("ID_HOME");?></a>&nbsp;|&nbsp;
	      <?php  } ?>
	      <?php  p('ID_ALBUM_NAME');?></font>
	      <?php  foreach( $dir_path as $num => $dir ) {?>
	 		<a  class="me" href="<?php  print $dir['link']; ?>"><?php  print $dir['name']; ?></a><font class="te">/</font></b>
	      <?php  } ?>
	</td>
	<td nowrap>
	  <?php  foreach( $quality_links as $link){ ?>
  		<?php  if ( $link['actual']) {?>
			<font class="te"><b><?php  print $link['name']; ?></b></font>&nbsp;&nbsp;		
		<?php  } else { ?>
			<a class="me" href="<?php  print $link['link']; ?>"><?php  print $link['name']; ?></a>&nbsp;&nbsp;		
		<?php  } ?>
	  <?php  } ?>
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
   <?php  if($dir_long_desc){ ?>
         <table border="1" cellpadding="15" width="100%">
	   <tr>
	     <td class="boxbody" width="100%">
	       <font class="dirdesc"><?php  print $dir_long_desc; ?>
	       </font>
	     </td>
	   </tr>
	 </table>
   <?php  } ?>
<!--main content-->
<table width="100%"><tr><td width="100%" align="left">
<ul style="margin:0px;padding:0px;list-style-type: none;"><?php  print $directories; ?></ul>
</td></tr></table>
<!-- next/prev page-->
<table width="100%"><tr><td width="100%" align="center">
  <table width="100%">
<?php  if ( $previous_page_link || $next_page_link ) { ?>
    <tr>
    	<td align="right" nowrap>
	    <?php  if($previous_page_link){?>
	        <a class="me" href="<?php  print $previous_page_link; ?>"><?php  p("ID_PREV_PAGE");?></a>
	    <?php  }else{?>
	        <font class="te"><b><?php  print p("ID_PREV_PAGE");?></b></font>
	    <?php }?>
	    &nbsp;&nbsp;&nbsp;
	    <?php  if($next_page_link){?>
	        <a class="me" href="<?php  print $next_page_link; ?>"><?php  p("ID_NEXT_PAGE");?></a>
	    <?php  }else{?>
	        <font class="te"><b><?php p("ID_NEXT_PAGE");?></b></font>
	    <?php }?>
	</td>
    </tr>
<?php  } ?>
    <tr><td width="100%" align="center">
    <ul style="margin:0px;padding:0px;list-style-type: none;"><?php  print $thumbnails; ?></ul>
    </td></tr>
  </table>
<?php  if($disable_bottom_nextprev=="false"){?>
<?php  if ( $previous_page_link || $next_page_link ) { ?>
		<table width="100%"><tr>
    	<td align="right" nowrap>
	    <?php  if($previous_page_link){?>
	        <a class="me" href="<?php  print $previous_page_link; ?>"><?php  p("ID_PREV_PAGE");?></a>
	    <?php  }else{?>
	        <font class="te"><b><?php  print p("ID_PREV_PAGE");?></b></font>
	    <?php }?>
	    &nbsp;&nbsp;&nbsp;
	    <?php  if($next_page_link){?>
	        <a class="me" href="<?php  print $next_page_link; ?>"><?php  p("ID_NEXT_PAGE");?></a>
	    <?php  }else{?>
	        <font class="te"><b><?php p("ID_NEXT_PAGE");?></b></font>
	    <?php }?>
	</td>
    </tr>
	</table>
<?php  } ?>
<?php }?>

</td></tr></table>
<?php  if( $footer_message ) { ?>
	<table width="100%"><tr height="100"><td valign="bottom" align="center" width="100%">
		<?php  print $footer_message; ?>
		<!-- <font size="2">Powered by <a class="me"href="http://www.phpalbum.net">PHP Photo Album</font></a> -->
	</td></tr></table>
<?php  } ?>
<?php  if($tracking_code) { print $tracking_code; } ?>
<!--end of page -->
</body></html>
