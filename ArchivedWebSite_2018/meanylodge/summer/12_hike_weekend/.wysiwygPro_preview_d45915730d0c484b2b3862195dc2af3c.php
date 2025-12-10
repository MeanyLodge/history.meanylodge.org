<?php
if ($_GET['randomId'] != "lfHyhqoOBlTeo6iSNnhGUhSWC7y4ytuH2icjMAKKoDfnPVL01JkDLovGqIfyvzJp") {
    echo "Access Denied";
    exit();
}

// display the HTML code:
echo stripslashes($_POST['wproPreviewHTML']);

?>  
