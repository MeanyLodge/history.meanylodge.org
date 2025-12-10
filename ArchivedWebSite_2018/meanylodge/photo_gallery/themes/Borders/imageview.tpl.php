<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<!--phpalbum <?php print $phpalbum_version;?> -->
 <head>
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
   <!--menu-->
    <table width="100%"><tr>
	<?php  if($show_search_box) { ?>
		<td>
			<form method="GET" action="" style="margin:0px;">
				<table cellspacing="0" cellpadding="0" border="0"><tr>
				<td nowrap><input class="login" type="text" size="20" name="keyword" value="<?php print $search_text?>"/></td>
				<td nowrap>&nbsp;&nbsp;&nbsp;</td>
				<td nowrap><input class="login_btn" type="submit" value="<?php p("ID_SEARCH");?>"/></td>
				</tr></table>
				<input type="hidden" name="cmd" value="albumnew"/>
			</form>
		</td>
	<?php  } ?>
   	<td width="100%" nowrap align="right">
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

   <table width="100%" class="menu">
     <tr>
       <td width="100%">
         <font class="te">
	      <?php  if ( $return_home_url != "") { ?>
	      	      <a class="me" href="http://<?php  print $return_home_url;?>"><?php p("ID_HOME");?></a>&nbsp;|&nbsp;
	      <?php  } ?>
	      <?php  p('ID_ALBUM_NAME');?></font>
	      <?php  foreach( $dir_path as $num => $dir ) {?>
	 		<b>&nbsp;::&nbsp;&nbsp;</b><a  class="me" href="<?php  print $dir['link']; ?>"><?php  print $dir['name']; ?></a>
	      <?php  } ?>
	</td>
	<td align="right" nowrap>
	    <?php  if($prev_link){?>
	        <a class="me" href="<?php  print $prev_link; ?>"><?php p("ID_PREV");?></a>
	    <?php  }else{?>
	        <font class="te"><b><?php p("ID_PREV");?></b></font>
	    <?php }?>
	    &nbsp;&nbsp;&nbsp;
	    <?php  if($next_link){?>
	        <a class="me" href="<?php  print $next_link; ?>"><?php  p("ID_NEXT");?></a>
	    <?php  }else{?>
	        <font class="te"><b><?php p("ID_NEXT");?></b></font>
	    <?php }?>
	    &nbsp;&nbsp;
	</td>
      </tr>
   </table>
<!--main content-->
<div>
 <table width="100%" cellspacing="10" cellpadding="0">
  <tr>
   <td align="center">
   <table cellspacing="0" cellpadding="0">
   <tr>
	<td class="photo">
	 <div style="margin: <?php print $photo_border_size?>px;">
         <?php if($next_link){?><a class="me" href="<?php  print $next_link; ?>"><?php }?>
         	<img alt="<?php  print $short_desc;?>" width="<?php  print $width;?>" height="<?php  print $height;?>" src="<?php  print $image;?>" border="1" style="border-color: #888888;"/><br/>
         <?php if($next_link){?></a><?php }?>
	 </div>
   </td>

   <?php  if($display_shadows=="true"){ ?>
    <td valign="top" background="main.php?cmd=themeimage&var1=shdw_r.png&var2=<?php print $pa_color_map["bg_color"]?>"><img src="main.php?cmd=themeimage&var1=shdw_ru.png&var2=<?php print $pa_color_map["bg_color"]?>"></td>
    </tr>
    <tr>
   	<td align="left" background="main.php?cmd=themeimage&var1=shdw_d.png&var2=<?php print $pa_color_map["bg_color"]?>"><img src="main.php?cmd=themeimage&var1=shdw_ld.png&var2=<?php print $pa_color_map["bg_color"]?>"></td>
   	<td><img src="main.php?cmd=themeimage&var1=shdw_rd.png&var2=<?php print $pa_color_map["bg_color"]?>"></td>
   <?php }?>
   
   </tr>
   </table>
    </td>
  </tr>
  <tr>
  	<td align="center">
  		<div>
	     <table cellspacing="0" cellpadding="0" width="<?php  print $total_width;?>">
	       <!--<tr height="5"><td></td></tr>-->
	       <?php  if($short_desc){?>
	       <tr><td width="100%" align="center"><b><font class="photodesc" size="5"><?php  print $short_desc;?></font></b></td></tr>
	       <?php  } ?>
	       <?php  if($long_desc){?>
	       <tr><td width="100%" align="center"><font class="photodesc"><?php  print $long_desc?></font></td></tr>
	       <?php  } ?>
	     </table>
	   </div>
    </td>
  <tr>
 </table>
 <table width="100%"><tr><td align="center"><?php  print $parameters; ?></td></tr></table>
</div>
<?php  if($disable_bottom_nextprev=="false"){?>
<div>
  <table width="100%" class="menu">
    <tr>
    	<td width="100%" align="right">
	    <?php  if($prev_link){?>
	        <a class="me" href="<?php  print $prev_link; ?>"><?php p("ID_PREV");?></a>
	    <?php  }else{?>
	        <font class="te"><b><?php p("ID_PREV");?></b></font>
	    <?php }?>
	    &nbsp;&nbsp;&nbsp;
	    <?php  if($next_link){?>
	        <a class="me" href="<?php  print $next_link; ?>"><?php p("ID_NEXT");?></a>
	    <?php  }else{?>
	        <font class="te"><b><?php p("ID_NEXT");?></b></font>
	    <?php }?>
	    &nbsp;&nbsp; 
	</td>
    </tr>
  </table>
</div>  
<?php  } ?>
<?php  if( $post_ecard_link ){ ?>
<a class="me" href="<?php print $post_ecard_link?>"><?php p("ID_WRITE_ECARD");?></a>&nbsp;&nbsp;&nbsp;&nbsp;
<?php  } ?>
<?php  if( $post_comment_link ){ ?>
	<a class="me" href="<?php print $post_comment_link?>"><?php p("ID_ADD_COMMENT");?></a>
<?php  } ?>
<?php  print $ecards;   ?>
<?php  print $comments; ?>
<?php  if( $footer_message ) { ?>
	<table width="100%"><tr height="30"><td valign="bottom" align="center" width="100%">
		<?php  print $footer_message; ?>
		<!-- <font size="2">Powered by <a class="me"href="http://www.phpalbum.net">PHP Photo Album</font></a> -->
	</td></tr></table>
<?php  } ?>

</td></tr></table>
</td></tr></table>
<?php  if($tracking_code) { print $tracking_code; } ?>
<!--end of page -->
</body></html>
