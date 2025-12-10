<table>
<tr>
<form method="post">
<td><?php p("ID_NAME")?></td><td><input class="login" size="7" name="p_username"></input></td>
<td><?php p("ID_PASSWORD")?></td><td><input class="login" type="password" size="7" name="p_userpassword"></input></td>
<td><input class="login_btn" type="submit" value="<?php p("ID_LOGIN")?>"/>
<td><input class="login" type="checkbox" name="p_storepassword"><?php p("ID_REMEMBER")?></input></td>
</form>
<?php  if($register_enabled){?>
<form name="register"  action="main.php" method="POST">
<input type="hidden" name="cmd" value="setup"/><input type="hidden" name="var2" value="register"/><input type="hidden" name="var1" value="user"/>
<td>&nbsp;&nbsp;<input class="login_btn" type="submit" value="<?php p("ID_REGISTER")?>"/></td>
</form>
<?php }?>
</tr>
</table>
