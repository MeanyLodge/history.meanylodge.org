<table><tr><td><h6><?php p("ID_SETUP_MENU_THUMBNAILS");?></h6>
</td></tr>
<tr><td>
<form name="main_setup" action="main.php" method="post">
<div class="description"><?php p("ID_SETUP_DESC_THUMBNAILS")?></div>
</br>
<a href="main.php?cmd=setup&var1=thumbnails&var2=add"><img border="0" src="res/new.png" /><?php p("ID_SETUP_ADD_QUALITY")?></a>
</br>
<?php  
	$q=db_select_all("quality");
	foreach($q as $rec){ ?>
		
		<fieldset><legend><?php p("ID_SETUP_THUMBNAILS")?>&nbsp;-&nbsp;<b><?php print $rec["name"]?></b></legend><div class="form-item">
			<!-- checking the form -->
			<div class="form-item">
					<label><?php p("ID_SETUP_QUALITY_NAME")?></label><br />
					<input class="form-text" name="p_q_desc<?php print $rec["id"]?>" value="<?php print prepit($rec["name"])?>"/> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<?php  if (count($q)>1){ ?><a href="main.php?cmd=setup&var1=thumbnails&var2=del&var3=<?php print $rec["id"]?>" class="red"><img border="0" src="res/red_x.png" /><?php p("ID_SETUP_DELETE_QUALITY")?></a> <?php }?>
					<div class="description"><?php p("ID_SETUP_QUALITY_NAME_DESC")?></div>
			</div>
			
	  	<div class="form-item">
	  	<label><?php p("ID_SETUP_QUALITY_THMB")?></label><br/>
	  	<input class="form-text" size="6" name="p_q_thmbs<?php print $rec["id"]?>" value="<?php print $rec["thmb_size"]?>"></input>&nbsp;/&nbsp;
		<input class="form-text" size="6" name="p_q_thmbq<?php print $rec["id"]?>" value="<?php print $rec["thmb_qual"]?>"></input>&nbsp;&nbsp;<input type="checkbox" name="p_q_square_thumbnails<?php print $rec["id"]?>" <?php  if($rec["square_thumbnails"]=="true"){echo "checked";}?>><?php p("ID_SETUP_SQUARE_THMB")?></input></br>
		<div class="description"><?php p("ID_SETUP_QUALITY_THMB_DESC")?></div>
		</div>
			
	  	<div class="form-item">
	  	<label><?php p("ID_SETUP_SHARPEN_THMB")?></label><br/>
	  	<input type="checkbox" name="p_thmb_sharp_use<?php print $rec["id"]?>" <?php  if($rec["thmb_sharp_use"]=="true"){echo "checked";}?>><?php p("ID_SETUP_SHARPEN_WITH_PARAM")?></input>&nbsp;&nbsp;&nbsp;
	  	<?php p("ID_SETUP_AMOUNT");?>:<input class="form-text" size="6" name="p_thmb_sharp_amount<?php print $rec["id"]?>" value="<?php print $rec["thmb_sharp_amount"]?>"></input>&nbsp;&nbsp;
	  	<?php p("ID_SETUP_RADIUS");?>:<input class="form-text" size="6" name="p_thmb_sharp_radius<?php print $rec["id"]?>" value="<?php print $rec["thmb_sharp_radius"]?>"></input>&nbsp;&nbsp;
		<div class="description"><?php p("ID_SETUP_SHARPEN_DESC")?></div>
		</div>

	  	<div class="form-item">
	  	<label><?php p("ID_SETUP_INFO_THMB")?></label><br/>
	  	<input type="checkbox" name="p_thmb_show_views<?php print $rec["id"]?>" <?php  if($rec["thmb_show_views"]=="true"){echo "checked";}?>><?php p("ID_SETUP_INFO_THMB_VIEWS")?></input>&nbsp;&nbsp;&nbsp;
		<input type="checkbox" name="p_thmb_show_comments<?php print $rec["id"]?>" <?php  if($rec["thmb_show_comments"]=="true"){echo "checked";}?>><?php p("ID_SETUP_INFO_THMB_COMMENTS")?></input>&nbsp;&nbsp;&nbsp;
		<input type="checkbox" name="p_thmb_show_votes<?php print $rec["id"]?>" <?php  if($rec["thmb_show_votes"]=="true"){echo "checked";}?>><?php p("ID_SETUP_INFO_THMB_VOTES")?></input>&nbsp;&nbsp;&nbsp;
		<div class="description"><?php p("ID_SETUP_INFO_THMB_DESC")?></div>
		</div>

		<div class="form-item">
			  	<label><?php p("ID_SETUP_QUALITY_PHOTO")?></label><br/>
				<input class="form-text" size="6" name="p_q_pics<?php print $rec["id"]?>" value="<?php print $rec["photo_size"]?>"/>&nbsp;/&nbsp;
				<input class="form-text" size="6" name="p_q_picq<?php print $rec["id"]?>" value="<?php print $rec["photo_qual"]?>"/>&nbsp;&nbsp;<input type="checkbox" name="p_q_resizeifbigger<?php print $rec["id"]?>" <?php  if($rec["resize_if_bigger"]=="true"){echo "checked";}?>><?php p("ID_SETUP_RESIZE_IF_BIGGER")?></input></br>
				<div class="description"><?php p("ID_SETUP_QUALITY_PHOTO_DESC")?></div>
			</div>
			<div class="form-item">
				<label><?php p("ID_SETUP_RESIZE_TO_FIT")?></label><br />
				<select name="p_resize_photo_to_fit<?php print $rec["id"]?>">
					<option value="both" <?php if($rec["resize_photo_to_fit"]=="both") echo "selected";?>><?php p("ID_BOTH_WIDTH_AND_HEIGHT")?></option>
					<option value="width" <?php if($rec["resize_photo_to_fit"]=="width") echo "selected";?>><?php p("ID_WIDTH")?></option>
					<option value="height" <?php if($rec["resize_photo_to_fit"]=="height") echo "selected";?>><?php p("ID_HEIGHT")?></option>
				</select>
				<div class="description"><?php p("ID_SETUP_RESIZE_TO_FIT_DESC")?></div>
			</div>
			<div class="form-item">
				<input type="checkbox" name="p_q_enabled<?php print $rec["id"]?>" <?php  if($rec["enabled"]=="true"){echo "checked";}?>>Enabled</input></br>
				<input type="radio" value="<?php print $rec["id"]?>" name="p_q_default" <?php if($rec["default"]=="true"){echo "checked";}?>/>Default</br>
			</div>
			<div class="form-item">
				<label><?php p("ID_SETUP_WATERMARK_FILE")?></label><br />
				<select name="p_watermark_file<?php print $rec["id"]?>">
					<option value="" <?php if($rec["watermark_file"]=="") echo "selected";?>><?php p("ID_NO_WATERMARK")?></option>			
					<?php 
				      $dh=opendir("./");
				      while (($file = readdir($dh)) !== false) {
           					if( filetype($dir . $file)=="file" ) {
           						if(strtoupper(substr($file,-3,3))=="PNG"){?>
           							<option value="<?php print $file?>" <?php if($rec["watermark_file"]==$file) echo "selected";?>><?php print $file?></option>			
	       			<?php 			}
           					}
				      }
					?>					
				</select>
			<div class="description"><?php p("ID_SETUP_WATERMARK_FILE_DESC")?></div>
			</div>

			<div class="form-item">
				<label><?php p("ID_SETUP_WATERMARK_POSITION")?></label><br />
				<table cellpadding="5" bgcolor="#eeeeee" style="border-style: solid; border-width=2; border-color: #888888;">
					<tr>
						<td> 
							<input type="radio" name="p_watermark_position<?php print $rec["id"]?>" value="LU" <?php if($rec["watermark_position"]=="LU") echo "checked";?>/>
						</td>
						<td> 
							<input type="radio" name="p_watermark_position<?php print $rec["id"]?>" value="U" <?php if($rec["watermark_position"]=="U") echo "checked";?>/>
						</td>
						<td> 
							<input type="radio" name="p_watermark_position<?php print $rec["id"]?>" value="RU" <?php if($rec["watermark_position"]=="RU") echo "checked";?>/>
						</td>
					</tr>
					<tr>
						<td> 
							<input type="radio" name="p_watermark_position<?php print $rec["id"]?>" value="L" <?php if($rec["watermark_position"]=="L") echo "checked";?>/>
						</td>
						<td> 
							<input type="radio" name="p_watermark_position<?php print $rec["id"]?>" value="C" <?php if($rec["watermark_position"]=="C") echo "checked";?>/>
						</td>
						<td> 
							<input type="radio" name="p_watermark_position<?php print $rec["id"]?>" value="R" <?php if($rec["watermark_position"]=="R") echo "checked";?>/>
						</td>
					</tr>
					<tr>
						<td> 
							<input type="radio" name="p_watermark_position<?php print $rec["id"]?>" value="LD" <?php if($rec["watermark_position"]=="LD") echo "checked";?>/>
						</td>
						<td> 
							<input type="radio" name="p_watermark_position<?php print $rec["id"]?>" value="D" <?php if($rec["watermark_position"]=="D") echo "checked";?>/>
						</td>
						<td> 
							<input type="radio" name="p_watermark_position<?php print $rec["id"]?>" value="RD" <?php if($rec["watermark_position"]=="RD") echo "checked";?>/>
						</td>
					</tr>
				</table>
				
				<div class="description"><?php p("ID_SETUP_WATERMARK_POSITION_DESC")?></div>
			</div>

			
		 </div>
	 </fieldset>
<?php }?>

<input type="hidden" name="cmd" value="setup"/>
<input type="hidden" name="var1" value="thumbnails"/>
<input type="hidden" name="var2" value="save"/>
<input type="submit" class="form-submit" value="<?php p("ID_SETUP_SAVE_CONFIG")?>"  />
<input type="reset" class="form-submit" value="<?php p("ID_SETUP_RESET_CONFIG")?>"  />
</form>
</td></tr>
</table>       
