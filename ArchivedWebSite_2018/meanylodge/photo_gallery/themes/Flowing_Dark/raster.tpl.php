  <table border="1">
	<?php  foreach($thumbnails as $thmb_row) { ?>
	  <tr>
	    <?php  foreach($thmb_row as $th) { ?>
	       <td align="center" valign="center"><?php  print $th; ?></td>
	    <?php  } ?>
	  </tr>
       <?php  } ?>
  </table>
