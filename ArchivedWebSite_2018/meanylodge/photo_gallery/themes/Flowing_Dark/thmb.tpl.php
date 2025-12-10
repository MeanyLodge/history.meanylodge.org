<li style="float:left;"><table cellspacing="0" cellpadding="0">
  <tr nowrap valign="center" height="<?php  print $height+2*$border; ?>">
    <td width="<?php  print $width+$border*2;?>" align="center" nowrap>
      <table cellpadding="0" cellspacing="0">
         <tr>
      		<td><a class="me3" href="<?php  print $image_view_link; ?>"><img alt="<?php  print $dir_name; ?>" class="thmb" src="<?php  print $thmb_link; ?>"/></a></td>
    <?php  if($display_shadows=="true"){ ?>
            <td valign="top" background="main.php?cmd=themeimage&var1=shdw_r.png&var2=<?php print $pa_color_map["bg_color"]?>&var3=75"><img border="0" src="main.php?cmd=themeimage&var1=shdw_ru.png&var2=<?php print $pa_color_map["bg_color"]?>&var3=75"></td>
        </tr>
        <tr>
   	        <td align="left" background="main.php?cmd=themeimage&var1=shdw_d.png&var2=<?php print $pa_color_map["bg_color"]?>&var3=75"><img border="0" src="main.php?cmd=themeimage&var1=shdw_ld.png&var2=<?php print $pa_color_map["bg_color"]?>&var3=75"></td>
   	       <td><img border="0" src="main.php?cmd=themeimage&var1=shdw_rd.png&var2=<?php print $pa_color_map["bg_color"]?>&var3=75"></td>
   <?php }?>
       </tr>
    </table>
    <a class="me3" href="<?php  print $image_view_link; ?>">
    <?php  if($image_short_desc){ ?>
    	<?php print $image_short_desc; ?>
    	<br>
    <?php }?>
    </a>
    <table cellpadding="0" cellspacing="0">
    <?php if(isset($view_count)){ ?>
    	<tr><td><font class="desc"><?php p("ID_MSG_VIEW_COUNT",$view_count);?></font></td></tr>
    <?php }?>
    <?php if(isset($comment_count)){ ?>
    	<tr><td><font class="desc"><?php p("ID_MSG_COMMENT_COUNT",$comment_count);?></font></td></tr>
    <?php }?>
    </table>

   </td>
  </tr>
</table>
</li>
