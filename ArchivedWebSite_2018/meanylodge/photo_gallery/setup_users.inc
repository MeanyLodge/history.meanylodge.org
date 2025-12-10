<table><tr><td><h6><?php p("ID_SETUP_MENU_USERS");?></h6>
</td></tr>
<tr><td>
<div class="description"><?php p("ID_SETUP_DESC_USERS")?></div>
<fieldset><legend><?php p("ID_SETUP_MENU_USERS")?></legend><div class="form-item">
<table width="100%" cellpadding="2" cellspacing="0" style="border: 1px solid #aaa;">
<tr bgcolor="#dddddd">
	<td><?php p("ID_ID")?></td>
	<td style="border-left: 1px solid #aaa;"><?php p("ID_USERNAME")?></td>
	<td style="border-left: 1px solid #aaa;"><?php p("ID_EMAIL")?></td>
	<td style="border-left: 1px solid #aaa;" align="center"><?php p("ID_EDIT")?></td>
	<td style="border-left: 1px solid #aaa;" align="center"><?php p("ID_DELETE")?></td>
</tr>
<?php 
	$rec=db_select_all("user");
	$row=1;
	foreach($rec as $user){
		if($row==1){
			echo "<tr bgcolor=\"#FFFFFF\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
			$row=2;
		}else{
			echo "<tr bgcolor=\"#EEEEEE\" onmouseout=\"this.style.backgroundColor=''\" onmouseover=\"this.style.backgroundColor='#ccddFF'\">";
			$row=1;
		}
?>
	
	
	<td><?php print $user["id"]?></td>
	<td style="border-left: 1px solid #aaa;"><?php print $user["name"]?></td>
	<td style="border-left: 1px solid #aaa;"><?php print $user["email"]?>&nbsp;</td>
	<td style="border-left: 1px solid #aaa;" align="center"><a href="main.php?cmd=setup&var1=user&var3=<?php print $user["id"]?>"><?php p("ID_EDIT")?></a></td>
	<?php if(isset($user["groups"]["superuser"])){?>
	    <td style="border-left: 1px solid #aaa;" align="center"><?php p("ID_NOT_POSSIBLE")?></td>
	<?php }else{?>
	    <td style="border-left: 1px solid #aaa;" align="center"><a class="red" href="main.php?cmd=setup&var1=users&var2=delete&var3=<?php print $user["id"]?>"><?php p("ID_DELETE")?></a></td>
	<?php }?>
	</tr>
<?php 		
	}
?>
</table>
</div>
</fieldset>
</td></tr>
</table>       
