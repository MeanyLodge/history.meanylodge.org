<table>
<tr><td>
  <h6><?php p("ID_SETUP_MENU_TEXTS");?></h6>
</td></tr>
<tr><td>
  <form name="main_setup" action="main.php" method="post">
  <div class="description"><?php p("ID_SETUP_TEXTS_DESC")?></div>
  <fieldset><legend><?php p("ID_SETUP_MENU_TEXTS")?></legend><div class="form-item">
  <div class="description"><?php p("ID_SETUP_TEXTS_GUIDE")?></div><br/>
    <table width="100%"  cellpadding="5" cellspacing="0" style="border: 1px solid #aaa;">
			<?php  $row=1;
				foreach($pa_texts as $key=>$text){ 
				if($row==1){
					echo "<tr bgcolor=\"#FFFFFF\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
					$row=2;
				}else{
					echo "<tr bgcolor=\"#EEEEEE\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
					$row=1;
				}
			?>			
				
				<td style="border-bottom: 1px solid #888;">
					<font color="#888888">[<?php print $key?>]&nbsp;</font>
					<font color="#008800"><?php print pa_html_encode($text)?></font><br/>
					<?php if(isset($pa_translated_texts[$key])){$bgcol="#fff";}else{$bgcol="ffc";}?>
					<div style="padding: 2px;"><input style="padding: 2px; border:1px dotted #888; background-color: <?php print $bgcol?>;" type="text" size="80" value="<?php print pa_html_encode($pa_translated_texts[$key])?>" name="<?php print $key?>"/></div>
				</tr>
			<?php  } ?>
		</table>
	<input type="hidden" name="cmd" value="setup"/><input type="hidden" name="var1" value="texts"/><input type="hidden" name="var2" value="save"/>
	<table width="100%"><tr><td></td>
		<input type="submit" class="form-submit" value="<?php p("ID_SETUP_SAVE_CONFIG")?>"  />
		<input type="reset" class="form-submit" value="<?php p("ID_SETUP_RESET_CONFIG")?>"  />
	</td></tr></table>	
</form>
  </td></tr>
</table>
  
