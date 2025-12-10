
		<tr><td class="boxhead" nowrap>Styles:</td>
		   <td width="100%" align="left" class="boxbody">
		   <!-- <?php =$site_theme?> -->
		   <SELECT name="p_theme_0" onchange="submit();">
		   	<?php 
			$styles=theme_get_styles();
			asort($styles);
		   	foreach($styles as $num => $style){
				if($style==$theme_params[0]){
				  echo "<OPTION selected value=\"$style\">$style</OPTION>";
				}else{
				  echo "<OPTION value=\"$style\">$style</OPTION>";
				}
			}
			?>
		   </SELECT>&nbsp;&nbsp;Choose color model. With "custom" you can change colors.
		</td></tr>

		<tr><td class="boxhead" nowrap>Logo-Style:</td>
		   <td width="100%" align="left" class="boxbody">
		<SELECT name="p_theme_7">
			<?php 
			$styles=theme_get_logo_styles();
			asort($styles);
		   	foreach($styles as $num => $style){
				if($style==$theme_params[7]){
				  echo "<OPTION selected value=\"$style\">$style</OPTION>";
				}else{
				  echo "<OPTION value=\"$style\">$style</OPTION>";
				}
			}
			?>
		</SELECT>&nbsp;&nbsp;Choose logo style.
		</td></tr>
		
		<?php  
		echo "<td class=\"boxhead\" nowrap>Logo-text:</td><td width=\"100%\" align=\"left\" class=\"boxbody\">";
		echo "<input value=\"$theme_params[6]\" name=\"p_theme_6\">&nbsp;&nbsp;Type text which schould be used for Logo.</input>";
		echo "</td></tr>";
		echo "<td class=\"boxhead\" nowrap>Logo-color:</td><td width=\"100%\" align=\"left\" class=\"boxbody\">";
		echo "<input value=\"$theme_params[5]\" name=\"p_theme_5\">&nbsp;&nbsp;Use HTML HEX color descriptoin without #, for example 33AAFF</input>";
		echo "</td></tr>";
		

		  if($theme_params[0]=="custom"){
		  	
			echo "<td class=\"boxhead\" nowrap>Background:</td><td width=\"100%\" align=\"left\" class=\"boxbody\">";
			echo "<input value=\"$theme_params[1]\" name=\"p_theme_1\">&nbsp;&nbsp;Use HTML HEX color descriptoin without #, for example 33AAFF</input>";
			echo "</td></tr>";
			echo "<td class=\"boxhead\" nowrap>Linkcolor:</td><td width=\"100%\" align=\"left\" class=\"boxbody\">";
			echo "<input value=\"$theme_params[2]\" name=\"p_theme_2\">&nbsp;&nbsp;Use HTML HEX color descriptoin without #, for example 33AAFF</input>";
			echo "</td></tr>";
			echo "<td class=\"boxhead\" nowrap>Dirdesc-color:</td><td width=\"100%\" align=\"left\" class=\"boxbody\">";
			echo "<input value=\"$theme_params[3]\" name=\"p_theme_3\">&nbsp;&nbsp;Use HTML HEX color descriptoin without #, for example 33AAFF</input>";
			echo "</td></tr>";
			echo "<td class=\"boxhead\" nowrap>Bordercolor:</td><td width=\"100%\" align=\"left\" class=\"boxbody\">";
			echo "<input value=\"$theme_params[4]\" name=\"p_theme_4\">&nbsp;&nbsp;Use HTML HEX color descriptoin without #, for example 33AAFF</input>";
			echo "</td></tr>";
			echo "<td class=\"boxhead\" nowrap>Photodesc-color:</td><td width=\"100%\" align=\"left\" class=\"boxbody\">";
			echo "<input value=\"$theme_params[8]\" name=\"p_theme_8\">&nbsp;&nbsp;Use HTML HEX color descriptoin without #, for example 33AAFF</input>";
			echo "</td></tr>";
		 }
       		?>



