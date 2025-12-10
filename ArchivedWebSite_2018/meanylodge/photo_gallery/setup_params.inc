<table><tr><td><h6><?php p("ID_SETUP_MENU_PARAMS");?></h6>
</td></tr>
<tr><td>
<div class="description"><?php p("ID_SETUP_DESC_PARAMS")?></div>
<?php 
   if(is_array($errors)){
   	echo "<br/>";
   	foreach($errors as $err){
   		print_error($err);	
	}
   }
?>
	<div class="form-item">
	<form action="main.php?cmd=setup&var1=params&var2=add" method="post">
		<table cellpadding="5">
	  	  <tr><td><label><?php p("ID_NAME")?></label></td><td><input size=30 value=""  class="form-text<?php print $err_name?>" name="p_name"/></td></tr>
	  	  <tr><td><label><?php p("ID_TYPE")?></label></td><td>
	  	  	<SELECT name="p_type"/>
	  	  	<?php 
				$rec=db_select_all("photo_param_type");
				foreach($rec as $type){
					$pdesc[$type["name"]]=$type["desc"]; // for the list of params below
			?>

	  	  		<OPTION value="<?php print $type["name"]?>"><?php print $type["desc"]?></OPTION>
	  	  	<?php  } ?>
	  	  	</SELECT></td></tr>
	  	  <tr><td colspan="2"><input type="submit" value="<?php p("ID_SETUP_ADD_NEW_PARAM")?>"/></td></tr>
	  	  </table>
	  	  <div class="description"><?php p("ID_SETUP_ADD_PARAM_DESC")?></div>
	</form>
	</div>

<form action="main.php?cmd=setup&var1=params&var2=save" method="post">
<?php 
	$rec=db_select_all("photo_param");
	$cnt=0;
	foreach($rec as $param){
	$cnt++;
	$syslov=Array("dim"=>"Picture dimensions",
				  "siz"=>"File size in KB",
				  "cdt"=>"Creation date of picture",
				  "fnm"=>"Filename",
				  "fnl"=>"Filename with fullsize download link",
				  "dwl"=>"Fullsize download link",
				  "exif_iso"=>"EXIF - ISO Setting",
				  "exif_exp_time"=>"EXIF - Exposure time",
				  "exif_f"=>"EXIF - Aperture setting",
				  "exif_fl"=>"EXIF - Focal Length",
				  "exif_model"=>"EXIF - Camera model",
				  "exif_datetime"=>"EXIF - Date/Time",
				  "iptc_caption"=>"IPTC Caption",
				  "iptc_caption_writer"=>"IPTC Caption Writer",
				  "iptc_headline"=>"IPTC Headline",
				  "iptc_spec_ins"=>"IPTC Special Instructions",
				  "iptc_byline"=>"IPTC Byline",
				  "iptc_byline_title"=>"IPTC Byline Title",
				  "iptc_credits"=>"IPTC Credits",
				  "iptc_source"=>"IPTC Source",
				  "iptc_object_name"=>"IPTC Object Name",
				  "iptc_date"=>"IPTC Date",
				  "iptc_city"=>"IPTC City",
				  "iptc_subloc"=>"IPTC Sublocation",
				  "iptc_state"=>"IPTC Province/State",
				  "iptc_country"=>"IPTC Country",
				  "iptc_otr"=>"IPTC Original Transmission Reference",
				  "iptc_category"=>"IPTC Category",
				  "iptc_subcategory"=>"IPTC Subcategory",
				  "iptc_priority"=>"IPTC Priority/Urgency (1-9)",
				  "iptc_keyword"=>"IPTC Keywords",
				  "iptc_copyright"=>"IPTC Copyright",
				  
			);
?>
<fieldset><legend><b><?php print ($param["name"]."</b> - ".$pdesc[$param["type"]])?></legend><div class="form-item">
	<!-- name -->
	<div class="form-item">
					<label><?php p("ID_SETUP_PARAM_NAME")?></label><br />
					<input class="form-text" name="p_name<?php print $cnt?>" value="<?php print $param["name"]?>"/> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="main.php?cmd=setup&var1=params&var2=del&var3=<?php print $param["id"]?>" class="red"><img border="0" src="res/red_x.png" /><?php p("ID_SETUP_DELETE_PARAM")?></a>
					<div class="description"><?php p("ID_SETUP_PARAM_NAME_DESC")?></div>
	</div>
	<!-- default -->
	<?php if($param["type"]=="user"){?>
		<div class="form-item">
				<label><?php p("ID_SETUP_PARAM_DEFAULT")?></label><br />
				<input class="form-text" name="p_default<?php print $cnt?>" value="<?php print prepit($param["default"])?>"/>
				<input type="checkbox" name="p_allow_html<?php print $cnt?>" <?php if($param["allow_html"]=="true"){echo "checked";}?>><?php print p("ID_ALLOW_HTML")?></input>
				<div class="description"><?php p("ID_SETUP_PARAM_DEFAULT_DESC")?></div>
		</div>
	<?php }?>
	<?php if($param["type"]=="system"){?>
		<div class="form-item">
				<label><?php p("ID_SETUP_PARAM_SYS_DEFAULT")?></label><br/>
				<SELECT name="p_default_lov<?php print $cnt?>">
					<?php  foreach($syslov as $id=>$desc){ ?>
						<OPTION value="<?php print $id?>" <?php if($id==$param["default_lov"]){echo "selected";}?>><?php print $desc?></OPTION>
					<?php }?>
				</SELECT>
				<div class="description"><?php p("ID_SETUP_PARAM_SYS_DEFAULT_DESC")?></div>
		</div>
	<?php }?>
	<?php if($param["type"]=="userlov"){?>
		<div class="form-item">
				<label><?php p("ID_SETUP_PARAM_DEFAULT")?></label><br/>
					<SELECT name="p_default_lov<?php print $cnt?>">
						<OPTION value="-1" <?php if( $param["default_lov"]==-1){echo "selected";}?>><?php p("ID_NOT_DEFINED")?></OPTION>
						<?php if(is_array($param["lov"])){?>
							<?php  foreach($param["lov"] as $id=>$desc){ ?>
								<OPTION value="<?php print $id?>" <?php if($id==$param["default_lov"]){echo "selected";}?>><?php print $desc?></OPTION>
							<?php }?>
						<?php }?>
					</SELECT>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="main.php?cmd=setup&var1=params&var2=edit&var3=<?php print $param["id"]?>"><?php p("ID_SETUP_EDIT_LOV")?></a>
				<div class="description"><?php p("ID_SETUP_PARAM_SYS_DEFAULT_DESC")?></div>
		</div>
		<?php if( ( $var2=="edit" && $var3==$param["id"]) || $_POST["p_lov_edit"]==$param["id"] || ($var2=="dellov" && $var3==$param["id"])){?>	
			<input type="hidden" name="p_lov_edit" value="<?php print $param["id"]?>"/>
			<?php if(is_array($param["lov"])){
				foreach($param["lov"] as $key=>$value){?>
					<input size="40" class="form-text" name="p_lov_value_<?php print $key?>" value="<?php print prepit($value)?>"/> &nbsp;&nbsp;<a href="main.php?cmd=setup&var1=params&var2=dellov&var3=<?php print $param["id"]?>&var4=<?php print $key?>" class="red"><?php p("ID_SETUP_DELETE_LOV")?></a>					
					<br/>
			<?php   } 
			  }?>
			<input class="form-text" size="40" name="p_lov_new" value=""/>&nbsp;&nbsp;<input type="submit" value="<?php p("ID_ADD_NEW_VALUE")?>"  />					
		<?php }?>
	<?php }?>
	<div class="form-item">
		<input type="checkbox" name="p_default_displayed<?php print $cnt?>" <?php if($param["default_displayed"]=="true"){echo "checked";}?>><b><?php print p("ID_DEFAULT_DISPLAYED")?></b></input>
		<div class="description"><?php p("ID_SETUP_PARAM_DEFAULT_DISPLAYED_DESC")?></div>
	</div>
	<input type="hidden" name="p_id<?php print $cnt?>" value="<?php print $param["id"]?>"/>
</div>
</fieldset>
<?php }?>
<input type="submit" class="form-submit" value="<?php p("ID_SETUP_SAVE_CONFIG")?>"  />
<input type="reset" class="form-submit" value="<?php p("ID_SETUP_RESET_CONFIG")?>"  />

</form>
</td></tr>
</table>       
