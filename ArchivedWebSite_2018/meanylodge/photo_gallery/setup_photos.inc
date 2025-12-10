<table><tr><td><h6><?php p("ID_SETUP_MENU_PICS");?></h6>
</td></tr>
<tr><td>
<div class="description"><?php p("ID_SETUP_DESC_PICS")?></div>

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
<br><a href="main.php?cmd=setup&var1=pics&var2=scan_dirs"><?php p("ID_SETUP_SCAN_DIRS")?></a><br><?php p("ID_SETUP_NEXT_SCAN",date("d M Y H:i:s",$pa_setup["last_dir_scan"]+24*60*60))?>
</div>
<input type="hidden" name="cmd" value="setup"/>
<input type="hidden" name="var1" value="pics"/>
<input type="hidden" name="var2" value="chdir"/>
</form>
<?php 
  $pics=db_select_all("files_".$var3);
  $rec=db_select_all("directory","seq_files==".$var3);
  $dir=$rec[0];
  $dir_path=substr($rec[0]["path"],1);
  
  
  // getting parameters to be displayed (setted up)
  if($dir["show_parameters"]=="default"){
  	$params=db_select_all("photo_param","default_displayed='true'");
  }else{
  	$where ="";
  	if(is_array($dir["show_parameters_custom_id"])){
  		foreach($dir["show_parameters_custom_id"] as $key => $value){
  			if($where != ""){ $where.=" || "; }
  			$where.="id==$key";
  		}
  	}
  	if($where != "") $params=db_select_all("photo_param",$where);
  }
?>
<form name="main_setup" action="main.php" method="post">

<fieldset><legend><?php p("ID_SETUP_MENU_PICS")?></legend><div class="form-item">
<div class="form-item">
<?php  $cnt=1; $col=1;?>
<table cellpadding="5" cellspacing="0" border="0">
<?php  foreach( $pics as $pic){ ?>
<tr <?php if($col==1){ echo "bgcolor=\"#eeeeee\"";}?>><td align="center" valign="top">
<img border="1" src="<?php print get_thmb_standard_link($dir_path,$pic)?>"><br/>
</td>
<td>
<b><?php print p("ID_NAME");?></b>&nbsp;&nbsp;<?php print $pic["file_name"]?>

<input type="checkbox" name="p_visible<?php print $cnt?>" class="form-text" <?php  if($pic["visible"]=="true") echo "checked";?>>
<b><?php p("ID_SETUP_VISIBLE")?></b></intput>

<input type="checkbox" name="p_use_for_logo<?php print $cnt?>" class="form-text" <?php  if($pic["use_for_logo"]=="true") echo "checked";?>>
<b><?php p("ID_USE_FOR_LOGO")?></b></intput>
<br/>
<!-- desc -->
<div class="form-item">
<label><?php p("ID_SETUP_DESC")?></label></br>
<input name="p_desc<?php print $cnt?>" size="40" class="form-text" value="<?php print prepit($pic["desc"])?>">
<div class="description"><?php p("ID_SETUP_PIC_DESC_DESC")?></div>
</div>

<!-- long_desc -->
<div class="form-item">
<label><?php p("ID_SETUP_LONG_DESC")?></label></br>
<input name="p_long_desc<?php print $cnt?>" size="80" class="form-text" value="<?php print prepit($pic["long_desc"])?>">
<div class="description"><?php p("ID_SETUP_PIC_LONG_DESC_DESC")?></div>
</div>
<!-- parameters of photos -->
<?php  if(is_array($params)){?>
<?php foreach($params as $param){
	if($param["type"]=="user"){?>
		<div class="form-item">
		<label><?php print $param["name"]?></label></br>
		<input name="p_param<?php print $cnt?>_<?php print $param["id"]?>" size="40" class="form-text" value="<?php print prepit($pic["params"][$param["id"]])?>">
		<div class="description">
		<?php if($param["allow_html"]=="true"){p("ID_HTML_ALLOWED");}else{p("ID_HTML_NOT_ALLOWED");}?>
		<?php if($param["default"]!=""){ p("ID_DEFAULT_VALUE",$param["default"]); }?>
		</div>
		</div>
	<?php }?>
	<?php if($param["type"]=="userlov"){?>
		<div class="form-item">
		<label><?php print $param["name"]?></label>
		<select name="p_param<?php print $cnt?>_<?php print $param["id"]?>" class="form-text" value="<?php print $pic["params"][$param["id"]]?>">
			<OPTION value="-1" <?php if( !isset($pic["params"][$param["id"]]) || $pic["params"][$param["id"]]==-1){echo "selected";}?>><?php p("ID_DEFAULT")?></OPTION>
			<?php if(is_array($param["lov"])){?>
				<?php  foreach($param["lov"] as $id=>$desc){ ?>
					<OPTION value="<?php print $id?>" <?php if(isset($pic["params"][$param["id"]]) && $pic["params"][$param["id"]]==$id){echo "selected";}?>><?php print $desc?></OPTION>
				<?php }?>
			<?php }?>

		</select>
		<div class="description">
		<?php if($param["default_lov"]!=-1){ p("ID_DEFAULT_VALUE",$param["lov"][$param["default_lov"]]); }else{p("ID_NO_DEFAULT_VALUE");}?>
		</div>
		</div>
	<?php }?>

<?php }?>
<?php }?>
<input type="hidden" name="p_file_name<?php print $cnt?>" value="<?php print $pic["file_name"]?>"/>
</td>
</tr>
<?php $cnt++;$col++;if($col==2) $col=0;?>
<?php  }?>
</table>
</div>
</fieldset>
<input type="hidden" name="cmd" value="setup"/>
<input type="hidden" name="var1" value="pics"/>
<input type="hidden" name="var2" value="save"/>
<input type="hidden" name="var3" value="<?php print $var3?>"/>
<input type="submit" class="form-submit" value="<?php p("ID_SETUP_SAVE_CONFIG")?>"  />
<input type="reset" class="form-submit" value="<?php p("ID_SETUP_RESET_CONFIG")?>"  />
</form>
</td></tr>
</table>       
