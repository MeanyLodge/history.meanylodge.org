<table><tr><td><h6><?php p("ID_SETUP_MENU_COMMENTS");?></h6>
</td></tr>
<tr><td>
<form name="main_setup" action="main.php" method="post">
<div class="description"><?php p("ID_SETUP_DESC_COMMENTS")?></div>
<fieldset><legend><?php p("ID_SETUP_MENU_COMMENTS")?></legend><div class="form-item">

<div class="form-item">
	<input type="checkbox" name="p_comments_enabled" <?php if($pa_setup["comments_enabled"]=="true"){echo "checked";}?>>
	<label><?php p("ID_SETUP_ENABLE_COMMENTS")?></label>
	<div class="description"><?php p("ID_SETUP_ENABLE_COMMENTS_DESC")?></div>
</div>

<div class="form-item">
	<input type="checkbox" name="p_antispam_enabled" <?php if($pa_setup["antispam_code_enabled"]=="true"){echo "checked";}?>>
	<label><?php p("ID_SETUP_ENABLE_ANTISPAM")?></label>
	<div class="description"><?php p("ID_SETUP_ENABLE_ANTISPAM_DESC")?></div>
</div>

<div class="form-item">
	<input type="checkbox" name="p_publish_only_approved" <?php if($pa_setup["publish_only_approved_comments"]=="true"){echo "checked";}?>>
	<label><?php p("ID_SETUP_PUBLISH_ONLY_APPROVED")?></label>
	<div class="description"><?php p("ID_SETUP_PUBLISH_ONLY_APPROVED_DESC")?></div>
</div>

<div class="form-item">
	<label><?php p("ID_SETUP_COMMENT_QUEUE")?></label><br/>
	<input size="15" name="p_comments_approve_queue_size" value="<?php print $pa_setup["comments_approve_queue_size"]?>">
	<div class="description"><?php p("ID_SETUP_COMMENT_QUEUE_DESC")?></div>
</div>




</div>
</fieldset>
<input type="hidden" name="cmd" value="setup"/>
<input type="hidden" name="var1" value="comments"/>
<input type="hidden" name="var2" value="save"/>
<input type="submit" class="form-submit" value="<?php p("ID_SETUP_SAVE_CONFIG")?>"  />
<input type="reset" class="form-submit" value="<?php p("ID_SETUP_RESET_CONFIG")?>"  />
</form>
</td></tr>

<tr><td>
<fieldset><legend><?php p("ID_SETUP_NEW_COMMENTS")?></legend>
<div class="description"><?php p("ID_SETUP_COMMENT_APPROVING_DESC")?></div>
</br>
 <?php 
 	$comments=get_all_comments();
 	$row=2;
	?>
 	<table width="100%" cellpadding="2" cellspacing="0" style="border: 1px solid #aaa;">
 	<tr bgcolor="#dddddd"><td><b><?php p("ID_PICTURE")?></b></td><td style="border-left: 1px solid #aaa;"><b><?php p("ID_TIME")?></b></td><td style="border-left: 1px solid #aaa;"><b><?php p("ID_NAME")?></b></td><td style="border-left: 1px solid #aaa;"><b><?php p("ID_TEXT")?></b></td><td style="border-left: 1px solid #aaa;" align="center"><b><?php p("ID_DELETE")?></b></td><td style="border-left: 1px solid #aaa;" align="center"><b><?php p("ID_APPROVE")?></b></td></tr>
 	<?php 	
 	 foreach($comments as $com){
 		  if($row==1){
					echo "<tr bgcolor=\"#eeeeee\"  onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
					$row=2;
 	            }else{
 	           		echo "<tr bgcolor=\"#ffffff\"  onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
 	            	$row=1;
 	            }
 		echo "<td valign=\"top\"><a class=\"me\" href=\"main.php?cmd=imageview&var1=".urlencode($com['pic_link'])."\">".$com['file_name']."</a></td>";
 		echo "<td valign=\"top\" style=\"border-left: 1px solid #aaa;\">".date($pa_setup["date_format"],$com['time'])."</td>";
 		echo "<td valign=\"top\" style=\"border-left: 1px solid #aaa;\">".$com['name'];
 		if($com['email']){echo " / ".$com['email'];}
 		echo"</td>";
 		echo "<td style=\"border-left: 1px solid #aaa;\">".$com['text']."</td>";
 		echo "<td align=center style=\"border-left: 1px solid #aaa;\"><a href=\"main.php?cmd=setup&var1=comments&var2=delete&var3=".urlencode($com['pic_link'])."&var4=".$com['id']."\" class=\"red\">".t("ID_DELETE")."</a></td>";
 		echo "<td align=center style=\"border-left: 1px solid #aaa;\"><a href=\"main.php?cmd=setup&var1=comments&var2=approve&var3=".urlencode($com['pic_link'])."&var4=".$com['id']."\" class=\"green\">".t("ID_APPROVE")."</a></td>";
 		echo "</tr>\n";
 	 }
 	echo "</table>";
 ?>
</fieldset> 
</td></tr>
</table>
  
