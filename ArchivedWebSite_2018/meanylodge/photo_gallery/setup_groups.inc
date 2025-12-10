<table><tr><td><h6><?php p("ID_SETUP_MENU_GROUPS");?></h6>
</td></tr>
<tr><td>
<div class="description"><?php p("ID_SETUP_DESC_GROUPS")?></div>
<fieldset><legend><?php p("ID_SETUP_MENU_GROUPS")?></legend><div class="form-item">
<?php 
   if(is_array($errors)){
   	foreach($errors as $err){
   		print_error($err);	
	}
   }
?>
<form name="main_setup" action="main.php" method="post">
<input type="hidden" name="cmd" value="setup"/>
<input type="hidden" name="var1" value="groups"/>
<input type="hidden" name="var2" value="add"/>
<label><?php p("ID_SETUP_NEW_GROUP_NAME")?></label><br/>
<table><tr>
<td valign="top"><input class="from-text<?php print $err_group?>" name="p_new_group_name" value="<?php print $new_group?>" /></td>
<td valign="top"><input type="submit"  value="<?php p("ID_SETUP_ADD_GROUP")?>"  /></td>
</tr></table>
<div class="description"><?php p("ID_SETUP_ADD_GROUP_DESC")?></div>
</form>
<br/>
<form method="POST">
<input type="hidden" name="cmd" value="setup"/>
<input type="hidden" name="var1" value="groups"/>
<input type="hidden" name="var2" value="save"/>
<table width="100%" cellpadding="2" cellspacing="0" style="border: 1px solid #aaa;">
<tr bgcolor="#dddddd">
	<td><?php p("ID_GROUP")?></td>
	<td style="border-left: 1px solid #aaa;" align="left"><?php p("ID_SETUP_PRIVILEGES")?></td>
	<td style="border-left: 1px solid #aaa;" align="left"><?php p("ID_DEFAULT")?></td>
	<td style="border-left: 1px solid #aaa;" align="center"><?php p("ID_SETUP_SHOW_DIRS")?></td>
	<td style="border-left: 1px solid #aaa;" align="center"><?php p("ID_SETUP_SHOW_USERS")?></td>
	<td style="border-left: 1px solid #aaa;" align="center"><?php p("ID_DELETE")?></td>
</tr>

<?php 
	$rec=db_select_all("group");
	$row=1;
	$cnt=1;
	foreach($rec as $group){
		if($row==1){
			echo "<tr bgcolor=\"#FFFFFF\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
			$row=2;
		}else{
			echo "<tr bgcolor=\"#EEEEEE\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
			$row=1;
		}
?>
	
	
	<td><?php print $group["name"]?></td>
	<td style="border-left: 1px solid #aaa;" align="left">
		<?php if($group["name"]=="superuser"){$disabled="disabled";}else{$disabled="";}?>
		<?php $menus=Array("main"=>t("ID_SETUP_MENU_MAIN"),
		   "themes"=>t("ID_SETUP_MENU_THEMES"),
		   "thumbnails"=>t("ID_SETUP_MENU_THUMBNAILS"),
			 "dirs"=>t("ID_SETUP_MENU_DIRS"),
			 "pics"=>t("ID_SETUP_MENU_PICS"),
			 "params"=>t("ID_SETUP_MENU_PARAMS"),
			 "users"=>t("ID_SETUP_MENU_USERS"),
			 "groups"=>t("ID_SETUP_MENU_GROUPS"),
			 "admin"=>t("ID_SETUP_MENU_ADMIN"),
			 "comments"=>t("ID_SETUP_MENU_COMMENTS"),
			 "ecard"=>t("ID_SETUP_MENU_ECARD"),
			 "texts"=>t("ID_SETUP_MENU_TEXTS"),
			 "cache"=>t("ID_SETUP_MENU_CACHE"),
			 "logs"=>t("ID_SETUP_MENU_LOGS"),
			 "errorlog"=>t("ID_SETUP_MENU_ERRORLOG"),
			 "syscheck"=>t("ID_SETUP_MENU_SYSCHECK"),
			 "imageorig"=>t("ID_IMAGEORIG"),
			 "imageview"=>t("ID_IMAGEVIEW")
			 )?>
		 <?php  foreach($menus as $key => $value){?>
		 	<?php  if (isset($group["grants"][$key])){?>
		 		<table width="150" style="float: left"><tr><td nowrap><a class="green" href="main.php?cmd=setup&var1=groups&var2=revoke&var3=<?php print $group["name"]?>&var4=<?php print $key?>"><?php print $value?>&nbsp;&nbsp;</td></tr></table>
		 	<?php }else{?>
		 		<table width="150" style="float: left"><tr><td nowrap><a class="red" href="main.php?cmd=setup&var1=groups&var2=grant&var3=<?php print $group["name"]?>&var4=<?php print $key?>"><?php print $value?>&nbsp;&nbsp;</td></tr></table>
		 	<?php }?>
		 <?php }?>
			 
	</td>
	<td style="border-left: 1px solid #aaa;" align="center"><input name="p_default<?php print $cnt?>" value="<?php print $group["name"]?>" type="checkbox" <?php if($group["default"]=="true"){echo "checked";}?>/>&nbsp;</td>
	<td style="border-left: 1px solid #aaa;" align="center"><a href="main.php?cmd=setup&var1=groups&var2=show_dirs&var3=<?php print $group["name"]?>"><?php p("ID_SETUP_SHOW_DIRS")?></a></td>
	<td style="border-left: 1px solid #aaa;" align="center"><a href="main.php?cmd=setup&var1=groups&var2=show_users&var3=<?php print $group["name"]?>"><?php p("ID_SETUP_SHOW_USERS")?></a></td>
	<?php if($group["name"]=="superuser" || $group["name"]=="guest"){?>
	 	<td style="border-left: 1px solid #aaa;" align="center"><?php p("ID_NOT_POSSIBLE")?></td>
	<?php }else{?>
		<td style="border-left: 1px solid #aaa;" align="center"><a class="red" href="main.php?cmd=setup&var1=groups&var2=delete&var3=<?php print urlencode($group["name"])?>"><?php p("ID_DELETE")?></a></td>
	<?php }?>
	</tr>
<?php 		
	$cnt++;
	}
?>
</table>
<div class="description"><?php p("ID_SETUP_PRIVILEGES_DESC")?></div>
<input type="submit" class="form-submit" value="<?php p("ID_SETUP_SAVE_CONFIG")?>"  />
<input type="reset" class="form-submit" value="<?php p("ID_SETUP_RESET_CONFIG")?>"  />
</form>
</br>
<?php  if ($var2=='show_users'){?>
<table width="100%" cellpadding="2" cellspacing="0" style="border: 1px solid #aaa;">
<tr bgcolor="#dddddd">
	<td style="border-left: 1px solid #aaa;" align="center"><?php p("ID_NAME")?></td>
	<td style="border-left: 1px solid #aaa;" align="center"><?php p("ID_EMAIL")?></td>
	<td style="border-left: 1px solid #aaa;" align="center"><?php p("ID_SETUP_HOMEPAGE")?></td>
	<td style="border-left: 1px solid #aaa;" align="center"><?php p("ID_EDIT")?></td>
</tr>
<?php 
	$rec=db_select_all("user","isset(groups['".prepdb($var3)."'])");
	$row=1;
	foreach($rec as $record){
		if($row==1){
			echo "<tr bgcolor=\"#FFFFFF\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
			$row=2;
		}else{
			echo "<tr bgcolor=\"#EEEEEE\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
			$row=1;
		}
?>
	
	
	<td><?php print $record["name"]?></td>
	<td style="border-left: 1px solid #aaa;" align="center"><?php print $record["email"]?>&nbsp;</td>
	<td style="border-left: 1px solid #aaa;" align="center"><?php print $record["homepage"]?>&nbsp;</td>
	<td style="border-left: 1px solid #aaa;" align="center"><a class="green" href="main.php?cmd=setup&var1=user&var2=edit&var3=<?php print urlencode($record["name"])?>"><?php p("ID_EDIT")?></a></td>
	</tr>
<?php 		
	}
?>
</table>
<?php } //end show usesrs?>

<?php  if ($var2=='show_dirs'){?>
<table width="100%" cellpadding="2" cellspacing="0" style="border: 1px solid #aaa;">
<tr bgcolor="#dddddd">
	<td style="border-left: 1px solid #aaa;" align="center"><?php p("ID_PATH")?></td>
	<td style="border-left: 1px solid #aaa;" align="center"><?php p("ID_ALIAS")?></td>
	<td style="border-left: 1px solid #aaa;" align="center"><?php p("ID_EDIT")?></td>
</tr>
<?php 
	$rec=db_select_all("directory","isset(groups['".prepdb($var3)."'])");
	$row=1;
	foreach($rec as $record){
		if($row==1){
			echo "<tr bgcolor=\"#FFFFFF\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
			$row=2;
		}else{
			echo "<tr bgcolor=\"#EEEEEE\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
			$row=1;
		}
?>
	
	
	<td>&nbsp;&nbsp;<?php print $record["path"]?>&nbsp;&nbsp;</td>
	<td style="border-left: 1px solid #aaa;" align="center"><?php print $record["alias"]?>&nbsp;</td>
	<td style="border-left: 1px solid #aaa;" align="center">
		&nbsp;&nbsp;<a class="green" href="main.php?cmd=setup&var1=dirs&var2=chdir&var3=<?php print urlencode($record["seq_files"])?>"><?php p("ID_SETUP_MENU_DIRS")?></a>&nbsp;&nbsp;
		<a class="green" href="main.php?cmd=setup&var1=pics&var2=chdir&var3=<?php print urlencode($record["seq_files"])?>"><?php p("ID_SETUP_MENU_PICS")?></a>&nbsp;&nbsp;
	</td>
	</tr>
<?php 		
	}
?>
</table>
<?php } //end show galleries?>
</div>
</fieldset>
</td></tr>
</table>       
