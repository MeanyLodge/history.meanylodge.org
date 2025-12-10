<table><tr><td><h6><?php p("ID_SETUP_MENU_LOGS");?></h6>
</td></tr>
<tr><td>
<form name="main_setup" action="main.php" method="post">
<div class="description"><?php p("ID_SETUP_DESC_LOGS")?></div>
<fieldset><legend><?php p("ID_SETUP_MENU_LOGS")?></legend><div class="form-item">

<div class="form-item">
	<label><?php p("ID_SETUP_ENABLE_LOGGING")?></label><br/>
	<input type="checkbox" name="p_enabled" <?php if($pa_setup["logs_enabled"]=="true"){echo "checked";}?>">
	<div class="description"><?php p("ID_SETUP_ENABLE_LOGGING_DESC")?></div>
</div>

<div class="form-item">
	<label><?php p("ID_SETUP_LOGS_FILENAME")?></label><br/>
	<input name="p_filename" value="<?php print $pa_setup["logs_filename"]?>">
	<div class="description"><?php p("ID_SETUP_LOGS_FILENAME_DESC")?></div>
</div>

<div class="form-item">
	<label><?php p("ID_SETUP_LOGS_EXCLUDE")?></label><br/>
	<input name="p_exclude" value="<?php print $pa_setup["logs_exclude"]?>">
	<div class="description"><?php p("ID_SETUP_LOGS_EXCLUDE_DESC")?></div>
</div>



</div>
</fieldset>
<input type="hidden" name="cmd" value="setup"/>
<input type="hidden" name="var1" value="logs"/>
<input type="hidden" name="var2" value="save"/>
<input type="submit" class="form-submit" value="<?php p("ID_SETUP_SAVE_CONFIG")?>"  />
<input type="reset" class="form-submit" value="<?php p("ID_SETUP_RESET_CONFIG")?>"  />
</form>
</td></tr>
<tr><td><a class="me" href="main.php?cmd=setup&var1=logs&var2=view">Show Logs</a>&nbsp;&nbsp;
 <a class="me" href="main.php?cmd=setup&var1=logs&var2=del">Delete Logs</a></td></tr>
<tr><td>
<?php 	  if($var2=="view"){
		$row=2;
		if(file_exists($pa_setup["cache_dir"].$pa_setup["logs_filename"])){
			$file=file($pa_setup["cache_dir"].$pa_setup["logs_filename"]);
			echo "<table width=\"100%\" cellpadding=\"2\" cellspacing=\"0\" style=\"border: 1px solid #aaa;\">";
				?>
				<tr bgcolor="#dddddd"><td><b><?php p("ID_TIME")?></b></td><td style="border-left: 1px solid #aaa;"><b><?php p("ID_COMMAND")?></b></TD><td style="border-left: 1px solid #aaa;"><b><?php p("ID_FILE_DIR")?></b></td><td style="border-left: 1px solid #aaa;"><b><?php p("ID_USERNAME")?></b></td><td style="border-left: 1px solid #aaa;"><b><?php p("ID_HOST")?></b></td></tr>
				<?php 
	        	foreach($file as $line_num=>$line){
 	                	$strings=explode("|",$line);
 	            if($row==1){
					echo "<tr bgcolor=\"#eeeeee\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
					$row=2;
 	            }else{
 	           		echo "<tr bgcolor=\"#ffffff\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
 	            	$row=1;
 	            }
 	            $first_pix=0;
				foreach($strings as $num=>$string){
					if(!$string)$string="&nbsp;";
					if($string=="\n") break;
					if($num==2){
						echo "<td style=\"border-left: {$first_pix}px solid #aaa;\"><a class=\"me\" href=\"main.php?cmd=".$strings[1]."&var1=".$strings[2]."\">".$string."</a></td>";
					}else{
						echo "<td style=\"border-left: {$first_pix}px solid #aaa;\">".$string."</td>";
					}
					$first_pix=1;
				}	
				echo "</tr>";
                	}
			echo "</table>";
		}else{ 	print_error(t("ID_MSG_FILE_NOT_EXISTS"),$pa_setup["logs_filename"]);
		}
		return;
	  }
  	  if($var2=="del"){
		  if(file_exists($pa_setup["cache_dir"].$pa_setup["logs_filename"])){
		  	unlink($pa_setup["cache_dir"].$pa_setup["logs_filename"]);
			printf("<b>".t("ID_FILE_WAS_DELETED")."</b>",$pa_setup["logs_filename"]);
		  }else{
		  	print_error(t("ID_MSG_FILE_NOT_EXISTS"),$pa_setup["logs_filename"]);
		  }
	  }

?>
</td></tr>
</table>