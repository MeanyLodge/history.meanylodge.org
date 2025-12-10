<table>
	<?php  foreach($thumbnails as $thmb_row) { ?>
	  <tr>
	    <?php  foreach($thmb_row as $th) { ?>
	       <td><?php  print $th; ?></td>
	    <?php  } ?>
	  </tr>
       <?php  } ?>
</table>
