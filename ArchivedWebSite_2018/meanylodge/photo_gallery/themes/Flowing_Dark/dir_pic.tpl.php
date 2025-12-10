<li style="float:left;"><table style="float: left;" cellspacing="0" cellpadding="0">
  <tr nowrap valign="center" height="<?php  print $height+2*$border; ?>">
    <td width="<?php  print $width+$border*2;?>" align="center" nowrap>
      <table cellpadding="0" cellspacing="0">
         <tr>
      		<td><a class="me3" href="<?php  print $dir_link; ?>"><img alt="<?php  print $dir_name; ?>" class="thmb" src="<?php  print $dir_logo_path; ?>"/></a></td>
    <?php  if($display_shadows=="true"){ ?>
            <td valign="top" background="main.php?cmd=themeimage&var1=shdw_r.png&var2=<?php print $pa_color_map["bg_color"]?>&var3=75"><img border="0" src="main.php?cmd=themeimage&var1=shdw_ru.png&var2=<?php print $pa_color_map["bg_color"]?>&var3=75"></td>
        </tr>
        <tr>
   	        <td align="left" background="main.php?cmd=themeimage&var1=shdw_d.png&var2=<?php print $pa_color_map["bg_color"]?>&var3=75"><img border="0" src="main.php?cmd=themeimage&var1=shdw_ld.png&var2=<?php print $pa_color_map["bg_color"]?>&var3=75"></td>
   	       <td><img border="0" src="main.php?cmd=themeimage&var1=shdw_rd.png&var2=<?php print $pa_color_map["bg_color"]?>&var3=75"></td>
   <?php }?>
       </tr>
    </table>
     
    <a class="me" href="<?php  print $dir_link; ?>">
    	 ::&nbsp;<?php print $dir_name."&nbsp;::<br/>";?>
    </a>
    <font class="desc"><?php print $dir_short_desc;?></font>
    	 
    
   </td>
  </tr>
</table>
</li>
