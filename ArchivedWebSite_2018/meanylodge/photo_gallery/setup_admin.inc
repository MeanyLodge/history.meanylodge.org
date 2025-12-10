<table><tr><td><h6><?php p("ID_SETUP_MENU_ADMIN");?></h6>
</td></tr>
<tr><td>

<div class="description"><?php p("ID_SETUP_DESC_ADMIN")?></div>

<?php  
  if(!$var2){
	  global $ftp_support;
	  if(!$ftp_support){
	   	print_error(t("ID_MSG_FTP_SUPPORT"));
	  }else{
		if($pa_setup["ftp_server"] && $pa_setup["ftp_server_photos_dir"]){?>
		<form action="main.php" method="post">
		<fieldset><legend><?php p("ID_SETUP_LOGIN")?></legend><div class="form-item">
		<table>
			<?php if($ftp_error){
				echo "<tr><td colspan=\"2\">";
				print_error($ftp_error);
				echo "</td></tr>";
			}?>
			<tr><td><b><?php p("ID_SETUP_FTP_SERVER")?></b></td><td>&nbsp;&nbsp;<?php print $pa_setup["ftp_server"]?></td></tr>
			<tr><td><b><?php p("ID_SETUP_FTP_PHOTO_DIR")?></b></td><td>&nbsp;&nbsp;<?php print $pa_setup["ftp_server_photos_dir"]?></td>			
			<tr><td><b><?php p("ID_USERNAME")?></b></td><td >&nbsp;&nbsp;<input name="p_user" size="15"/></td>
			<tr><td><b><?php p("ID_PASSWORD")?></b></td><td >&nbsp;&nbsp;<input type="password" name="p_pass" size="15"/></td>
			<tr><td colspan="2"><input type="submit" value="<?php p("ID_SETUP_LOGIN")?>"/></td></tr>
		</table>
		<input type="hidden" name="cmd" value="setup"/>
		<input type="hidden" name="var1" value="admin"/>
		<input type="hidden" name="var2" value="login"/>
		</div></fieldset>
		</form>
	<?php }else{
		print_error(t("ID_MSG_SETUP_FTP"));
	  }	

	 }
  }else{ ?>

<fieldset><legend><?php p("ID_SETUP_FTP_SERVER")?>&nbsp;<b><?php print $pa_setup["ftp_server"]?></b></legend><div class="form-item">
	
	<!-- actual directory -->
	<div class="form-item">
	<form action="main.php?cmd=setup&var1=admin&var2=chdir" method="post">
	  	  <label><?php p("ID_SETUP_ACT_DIR")?></label>&nbsp;<?php print $pa_setup["ftp_server_photos_dir"]?>&nbsp;<input size=40 value="<?php print conv_out($p_actdir)?>" name="p_dir"/>&nbsp;&nbsp;<input type="submit" value="Cahnge"/>
	  	  <div class="description"><?php p("ID_SETUP_ACT_DIR_DESC")?></div>
	</form>
	</div>
	
	<!-- upload file -->
	<div class="form-item">
	<form enctype="multipart/form-data" action="main.php?cmd=setup&var1=admin&var2=upload" method="post">
	<input type="hidden" name="MAX_FILE_SIZE" value="20971520">
	  <label><?php p("ID_SETUP_UPLOAD_FILE")?></label>&nbsp;<input type="file" size=40 name="p_file"/>&nbsp;&nbsp;<input type="submit" value="<?php p("ID_UPLOAD")?>"/>&nbsp; [<?php p("ID_SETUP_MAX_SIZE")?> <?php print ini_get("upload_max_filesize")?> ]
  	  <div class="description"><?php p("ID_SETUP_UPLOAD_FILE_DESC")?></div>
	</form>
	</div>
	
	<!-- upload zip file -->
	<div class="form-item">
	<form enctype="multipart/form-data" action="main.php?cmd=setup&var1=admin&var2=uploadzip" method="post">
	<input type="hidden" name="MAX_FILE_SIZE" value="20971520">
	  <label><?php p("ID_SETUP_UPLOAD_ZIP_FILE")?></label>&nbsp;<input type="file" size=40 name="p_file"/>&nbsp;&nbsp;<input type="submit" value="<?php p("ID_UPLOAD_ZIP")?>"/>&nbsp; [<?php p("ID_SETUP_MAX_SIZE")?> <?php print ini_get("upload_max_filesize")?> ]
  	  <div class="description"><?php p("ID_SETUP_UPLOAD_ZIP_FILE_DESC")?></div>
	</form>
	</div>

	<!-- upload zip file -->
	<div class="form-item">
	<form action="main.php?cmd=setup&var1=admin&var2=mkdir" method="post">
  	  <label><?php p("ID_SETUP_CREATE_DIR")?></label>&nbsp;<input size=40 name="p_dir"/><input type="submit" value="<?php p("ID_CREATE")?>"/>
  	  <div class="description"><?php p("ID_SETUP_CREATE_DIR_DESC")?></div>
	</form>
	</div>

</div></fieldset>

<fieldset><legend><?php p("ID_SETUP_ACT_DIR")?>&nbsp;<b><?php print $pa_setup["ftp_server_photos_dir"]?><?php print conv_out($p_actdir)?></b></legend>
<?php if($ftp_error){
	   print_error($ftp_error);
}?>
<?php $files=ftp_get_files($p_actdir); $ln=0;?>
<table width="100%" style="border: 1px solid #aaa" cellpadding="2" cellspacing="0">
<tr bgcolor="#dddddd"><td><b><?php p("ID_FILENAME")?></b></td><td style="border-left: 1px solid #aaa;"><b><?php p("ID_SIZE")?></b></TD><td style="border-left: 1px solid #aaa;"><b><?php p("ID_IMAGE_SIZE")?></b></td><td style="border-left: 1px solid #aaa;"><b><?php p("ID_TIME")?></b></td><td style="border-left: 1px solid #aaa;"><b><?php p("ID_OWNER")?></b></td><td style="border-left: 1px solid #aaa;"><b><?php p("ID_GROUP")?></b></td><td style="border-left: 1px solid #aaa;"><b><?php p("ID_FUNCTIONS")?></b></td></tr>
<?php  if(is_array($files)){ ?>
<?php   	while (list ($key, $file) = each ($files)){ ?>
<?php if($ln==0){ echo "<tr onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">\n"; $ln=1;}else{ echo "<tr bgcolor=\"#eeeeee\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">"; $ln=0;} ?>
	 	<?php 
			if( $file['type']=="dir" ){
				print "<td colspan=\"3\">&nbsp;";
				$link=$p_actdir.$file['name']."/";
				if($file['name']==".."){
				  $link=dirname($p_actdir)."/";
				}
				if($file['name']=="."){
				  $link=$p_actdir;
				}
				if($link=="./"){ $link="";}
				if($link=="/"){ $link="";}
				print "<a class=\"mex\" href=\"main.php?cmd=setup&var1=admin&var2=chdir&p_dir=".urlencode(conv_out($link))."\">[ ".conv_out($file['name'])." ]</a>";
				print "&nbsp;</td>";
			}else{
				print "<td>&nbsp;";
				print conv_out($file['name']);
				print "&nbsp;</td><td  style=\"border-left: 1px solid #aaa;\" align=\"right\">&nbsp;".$file['size']."&nbsp;</td>";
				print "<td style=\"border-left: 1px solid #aaa;\">";
	 			print "&nbsp;".$file['image_size'];
				print "&nbsp;</td>";
			}

		?>	 
	 
	 <td style="border-left: 1px solid #aaa;">&nbsp;
	 	<?php print $file['time']?>
	 &nbsp;</td>
	 <td style="border-left: 1px solid #aaa;">&nbsp;
	 	<?php print $file['owner']?>
	 &nbsp;</td>
	 <td style="border-left: 1px solid #aaa;">&nbsp;
	 	<?php print $file['group']?>
	 &nbsp;</td>
	 
	 <td style="border-left: 1px solid #aaa;">&nbsp;
	 	<?php print $file['func']?>
	 &nbsp;</td></tr>
<?php   	} ?>
<?php  } ?>
<?php  } // !$var2 ?>
</table>
</fieldset>
<!----------      -->
</td></tr>
</table>       

