<?php
if ($_GET['randomId'] != "m2vJHEI6KijB8y5TNWNTah2gJ2VZ3mS9K7qy_xeT4hVghOX6gNhOnd32fb8NUTAB") {
    echo "Access Denied";
    exit();
}

// display the HTML code:
echo stripslashes($_POST['wproPreviewHTML']);

?>  
