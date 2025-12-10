<table><tr><td><h6><?php p("ID_SETUP_MENU_DIRS");?></h6>
</td></tr>
<tr><td>
<div class="description"><?php p("ID_SETUP_DESC_DIRS")?></div>

<form name="main_setup" action="main.php" method="post">
<div class="form-item">
<label><?php p("ID_SETUP_GALLERY")?></label></br>
   <SELECT name="var3" onchange="submit();">
   	<?php 
	$dirs=db_select_all("directory",null,"path");
   	foreach($dirs as $key => $dir){
		if($dir["seq_files"]==$var3){
		  echo "<OPTION selected ";
		}else{
		  echo "<OPTION ";
		}
		echo "value=\"".$dir["seq_files"]."\">".conv_out($dir["path"])."&nbsp;&nbsp;(".$dir["photo_count"].")</OPTION>";
	}
	?>
   </SELECT>
<div class="description"><?php p("ID_SETUP_GALLERY_DESC")?></div>
<br><a href="main.php?cmd=setup&var1=dirs&var2=scan_dirs"><?php p("ID_SETUP_SCAN_DIRS")?></a><br><?php p("ID_SETUP_NEXT_SCAN",date("d M Y H:i:s",$pa_setup["last_dir_scan"]+24*60*60))?>
</div>
<input type="hidden" name="cmd" value="setup"/>
<input type="hidden" name="var1" value="dirs"/>
<input type="hidden" name="var2" value="chdir"/>
</form>
<?php $rec=db_select_all("directory","seq_files=='".$var3."'"); $dir=$rec[0];?>
<form name="main_setup" action="main.php" method="post">
<fieldset><legend><?php p("ID_SETUP_MENU_DIRS")?></legend><div class="form-item">
<div class="form-item">
<!-- visible -->
<div class="form-item">
<input type="checkbox" name="p_visibility" <?php  if($dir["visibility"]=="true"){echo "checked";}?>><label><?php p("ID_SETUP_VISIBLE")?></label></input></br>
<div class="description"><?php p("ID_SETUP_VISIBLE_DESC")?></div>
<div>

<!-- alias -->
<div class="form-item">
<label><?php p("ID_SETUP_ALIAS")?></label></br>
<input name="p_alias" size="30" class="form-text" value="<?php print prepit($dir["alias"])?>">
<div class="description"><?php p("ID_SETUP_ALIAS_DESC")?></div>
</div>

<!-- desc -->
<div class="form-item">
<label><?php p("ID_SETUP_DESC")?></label></br>
<input name="p_desc" size="80" class="form-text" value="<?php print prepit($dir["desc"])?>">
<div class="description"><?php p("ID_SETUP_DESC_DESC")?></div>
</div>

<!-- long_desc -->
<div class="form-item">
<label><?php p("ID_SETUP_LONG_DESC")?></label></br>
<textarea cols="80" rows="5" name="p_long_desc" ><?php print $dir["long_desc"]?></textarea>
<div class="description"><?php p("ID_SETUP_LONG_DESC_DESC")?></div>
</div>

<div class="form-item">
<label><?php p("ID_SETUP_SORTING")?></label></br>
<SELECT name="p_sorting">
	<?php  $srt=get_all_sortings();
	   foreach($srt as $key => $sort){
	      if($key==$dir["sorting"]){
			  echo "<OPTION selected value=\"$key\">$sort</OPTION>";
		  }else{
			  echo "<OPTION value=\"$key\">$sort</OPTION>";
		  }
	   }
	  ?>
</SELECT>
<div class="description"><?php p("ID_SETUP_SORTING_DESC")?></div>
</div>

<!--show newest pictures count-->
<div class="form-item">
	<label><?php p("ID_SETUP_THEME_NEWEST_COUNT")?></label></br>
	<input name="p_show_newest_pictures_count" size="10" class="form-text" value="<?php print $dir["show_newest_pictures_count"]?>">
	<div class="description"><?php p("ID_SETUP_THEME_NEWEST_COUNT_DESC")?></div>
</div>

<div class="form-item">
<fieldset><legend><?php p("ID_SETUP_ACCESS_RIGHTS")?></legend>
<div class="form-item">
<label><?php p("ID_SETUP_MENU_GROUPS")?></label><br/>
<?php  $rec=db_select_all("group");
   $cnt=0;
   foreach($rec as $group){
   $cnt++;	
?>
	  <input type="checkbox" name="p_group<?php print $cnt?>" value="<?php print $group["name"]?>" <?php if(isset($dir["inh_groups"][$group["name"]])){echo "checked disabled";/*disabled*/}else{if(isset($dir["groups"][$group["name"]])){echo "checked";}}?>>
	  		<?php print $group["name"]?>
	  </input><br/>
<?php    }?>
</div>
<div class="description"><?php p("ID_SETUP_GALLERY_GROUP_DESC")?></div>
</fieldset>
</div>

<div class="form-item">
<fieldset><legend><?php p("ID_SETUP_MENU_PARAMS")?></legend>
<div class="form-item">
<label><?php p("ID_SETUP_SHOW_PARAMS")?></label><br/>
<select name="p_show_parameters" onchange="submit();">
	<option <?php if($dir["show_parameters"]=="custom"){ echo "selected";}?> value="custom"><?php p("ID_SETUP_SHOW_CUSTOM_PARAMS")?></option>
	<option  <?php if($dir["show_parameters"]=="default"){ echo "selected";}?> value="default"><?php p("ID_SETUP_SHOW_DEFAULT_PARAMS")?></option>
</select>
<div class="description"><?php p("ID_SETUP_PARAMS_DEFAULT_CUSTOM_DESC")?></div>
</div>
<?php if($dir["show_parameters"]=="custom"){?>
		<div class="form-item">
		<label><?php p("ID_SETUP_MENU_PARAMS")?></label><br/>
		<?php  $rec=db_select_all("photo_param");
		   $cnt=0;
		   if(count($rec)==0){
		   		p("ID_NO_DEFINED_PARAMS");
		   }
		   foreach($rec as $param){
		   $cnt++;	
		?>
			  <input type="checkbox" name="p_param<?php print $cnt?>" value="<?php print $param["id"]?>" <?php if(isset($dir["show_parameters_custom_id"][$param["id"]])){echo "checked";}?> >
			  		<?php print $param["name"]?>
			  </input><br/>
		<?php    }?>
		</div>
		<div class="description"><?php p("ID_SETUP_GALLERY_PARAMS_DESC")?></div>
		</fieldset>
		</div>
<?php }else{
	$rec=db_select_all("photo_param");
	$cnt=0;
	foreach($rec as $param)	{
		$cnt++;?>
			  <input disabled type="checkbox" name="p_param<?php print $cnt?>" value="<?php print $param["id"]?>" <?php if($param["default_displayed"]=="true"){echo "checked";}?> >
			  		<?php print $param["name"]?>
			  </input><br/>
	<?php }?>
	<input type="hidden" name="p_default" value="x"/>
<?php }?>


</div>
</fieldset>
<input type="hidden" name="cmd" value="setup"/>
<input type="hidden" name="var1" value="dirs"/>
<input type="hidden" name="var2" value="save"/>
<input type="hidden" name="var3" value="<?php print $var3?>"/>
<input type="submit" class="form-submit" value="<?php p("ID_SETUP_SAVE_CONFIG")?>"  />
<input type="reset" class="form-submit" value="<?php p("ID_SETUP_RESET_CONFIG")?>"  />
</form>
</td></tr>
</table>       
