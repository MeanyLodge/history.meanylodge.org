<table><tr><td><h6><?php p("ID_SETUP_MENU_ECARD");?></h6>
</td></tr>
<tr><td>
<form name="main_setup" action="main.php" method="post">
<div class="description"><?php p("ID_SETUP_DESC_ECARD")?></div>
<fieldset><legend><?php p("ID_SETUP_MENU_ECARD")?></legend><div class="form-item">

<div class="form-item">
	<input type="checkbox" name="p_ecard_enabled" <?php if($pa_setup["ecard_enabled"]=="true"){echo "checked";}?>>
	<label><?php p("ID_SETUP_ENABLE_ECARD")?></label>
	<div class="description"><?php p("ID_SETUP_ENABLE_ECARD_DESC")?></div>
</div>

<div class="form-item">
	<input type="checkbox" name="p_antispam_enabled" <?php if($pa_setup["antispam_code_enabled"]=="true"){echo "checked";}?>>
	<label><?php p("ID_SETUP_ENABLE_ANTISPAM")?></label>
	<div class="description"><?php p("ID_SETUP_ENABLE_ANTISPAM_DESC")?></div>
</div>

<div class="form-item">
	<label><?php p("ID_SETUP_ECARD_SUBJECT")?></label><br/>
	<input size="40" name="p_ecard_subject" value="<?php print $pa_setup["ecard_subject"]?>">
	<div class="description"><?php p("ID_SETUP_ECARD_SUBJECT_DESC")?></div>
</div>
<div class="form-item">
	<label><?php p("ID_SETUP_ECARD_TEXT")?></label><br/>
	<textarea cols="80" rows="8" name="p_ecard_text" ><?php print $pa_setup["ecard_text"]?></textarea>
	<div class="description"><?php p("ID_SETUP_ECARD_TEXT_DESC")?></div>
</div>
<div class="form-item">
	<label><?php p("ID_SETUP_ECARD_PICKED_SUBJECT")?></label><br/>
	<input size="40" name="p_ecard_picked_subject" value="<?php print $pa_setup["ecard_picked_subject"]?>">
	<div class="description"><?php p("ID_SETUP_ECARD_PICKED_SUBJECT_DESC")?></div>
</div>
<div class="form-item">
	<label><?php p("ID_SETUP_ECARD_PICKED_TEXT")?></label><br/>
	<textarea cols="80" rows="8" name="p_ecard_picked_text" ><?php print $pa_setup["ecard_picked_text"]?></textarea>
	<div class="description"><?php p("ID_SETUP_ECARD_TEXT_DESC")?></div>
</div>



</div>
</fieldset>
<input type="hidden" name="cmd" value="setup"/>
<input type="hidden" name="var1" value="ecard"/>
<input type="hidden" name="var2" value="save"/>
<input type="submit" class="form-submit" value="<?php p("ID_SETUP_SAVE_CONFIG")?>"  />
<input type="reset" class="form-submit" value="<?php p("ID_SETUP_RESET_CONFIG")?>"  />
</form>
</td></tr>
</table>
  
