<?php 
if($var2=="delete"){
	if(file_exists($data_dir."error.log")){
		unlink($data_dir."error.log");
	}
}
?>
<table>
<tr><td>
  <h6><?php p("ID_SETUP_MENU_ERRORLOG");?></h6>
</td></tr>
<tr><td>
  <div class="description"><?php p("ID_SETUP_ERRORLOG_DESC")?></div>
  <fieldset><legend><?php p("ID_SETUP_MENU_ERRORLOG")?></legend><div class="form-item">
	<form action="main.php" method="POST">
		<div class="form-item">
		<input type="checkbox" name="p_disable_error_log" <?php  if($pa_setup["error_logging_enabled"]=="false"){echo "checked";}?>></input><label><?php p("ID_DISABLE_ERROR_LOG")?></label></br>
		<input type="hidden" name="cmd" value="setup"/>
		<input type="hidden" name="var1" value="errorlog"/>
		<input type="hidden" name="var2" value="save"/>
		<input type="submit" class="form-submit" value="<?php p("ID_SETUP_SAVE_CONFIG")?>"  />
		<input type="reset" class="form-submit" value="<?php p("ID_SETUP_RESET_CONFIG")?>"  />

	</div>
	</form>
 	<a href="main.php?cmd=setup&var1=errorlog&var2=delete"><?php p("ID_SETUP_DELETE_ERROROLOG")?></a><br/><br/>
 	<table width="100%"  cellpadding="2" cellspacing="0" style="border: 1px solid #aaa;">
 	<tr  bgcolor="#dddddd">
		<td><?php p("ID_TYPE")?><br/><font color="#888888"><?php p("ID_TIME")?></font></td>
 	<!--	<td style="border-left: 1px solid #aaa;"><?php p("ID_ERROR_NUMBER")?><br/><?php p("ID_LINE")?></td>-->
 		<td style="border-left: 1px solid #aaa;"><?php p("ID_ERROR_MESSAGE")?><br/><font color="#888888"><?php p("ID_SCRIPT_NAME")?></font></td>
 	</tr>
	<?php 
		
		if(file_exists($data_dir."error.log")){
			if(isset($phpalbum_Errors)){
					unset($phpalbum_Errors);
			}
			include($data_dir."error.log");
			$row=1;
			if(is_array($phpalbum_Errors)){
				foreach($phpalbum_Errors as $err){
					if($row==1){
						echo "<tr bgcolor=\"#FFFFFF\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
						$row=2;
					}else{
						echo "<tr bgcolor=\"#EEEEEE\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
						$row=1;
					}
					?>
						<td valign="top" nowrap><?php print $err['errortype']?><br/><font color="#888888"><?php print $err['datetime']?></font></td>
 						<!--<td valign="top" style="border-left: 1px solid #aaa;"><?php print $err['errornum']?><br/><?php print $err['scriptlinenum']?></td>-->
 						<td valign="top" style="border-left: 1px solid #aaa;"><?php print $err['errormsg']?><br/><font color="#888888"><?php print $err['scriptname']?>&nbsp;(<?php p("ID_LINE")?>:<?php print $err['scriptlinenum']?>)</font></td>
					</tr>
					<?php 
				}
			}else{
			}
		}
    ?>
    </table>
</td></tr>
</table>
