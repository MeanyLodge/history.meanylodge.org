<?php ob_start() ?>
<?php
if ($_GET['randomId'] != "9oyaKdZMWkLNL_fck3IBtf3sLGbwt8hPneXjZWfI3mk5GV_MLNgmkA_RWjx7fLr7KURuhpnwdgwFPQxFWIlhl_444WrfDV335AWkyBI2OrRA6uESxCQMBXk_qbNBZrh5jilnkd3Si9ZwUd9lxAGs34LBbWn7aFWismaqJI8StUazlozv8VngNjivBcUmHnfcQ3FJt27NRSVTr6btgpwLaSBgYzQ4VtCQZwTM0ppj05bjt2xVN_sT6cqhYOSFacqO") {
    echo "Access Denied";
    exit();
}
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<title>Editing hikeweekend.html</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<style type="text/css">body {background-color:threedface; border: 0px 0px; padding: 0px 0px; margin: 0px 0px}</style>
</head>
<body>
<div align="center">

<div id="saveform" style="display:none;">
<form METHOD="POST" name=mform action="http://proxy-netadmin-129841.backstage.site5.com:2082/frontend/na4/fileman/savehtmlfile.html">
    <input type="hidden" name="charset" value="iso-8859-1">
    <input type="hidden" name="baseurl" value="http://www.meanylodge.org/public_html/summer/hikeweekend_09/">
    <input type="hidden" name="basedir" value="/home/meanylod/public_html/">
    <input type="hidden" name="udir" value="/home/meanylod/public_html/summer/hikeweekend_09">
    <input type="hidden" name="ufile" value="hikeweekend.html">
    <input type="hidden" name="dir" value="%2fhome%2fmeanylod%2fpublic_html%2fsummer%2fhikeweekend_09">
    <input type="hidden" name="file" value="hikeweekend.html">
    <input type="hidden" name="doubledecode" value="1">
<textarea name=page rows=1 cols=1></textarea></form>
</div>
<div id="abortform" style="display:none;">
<form METHOD="POST" name="abortform" action="http://proxy-netadmin-129841.backstage.site5.com:2082/frontend/na4/fileman/aborthtmlfile.html">
    <input type="hidden" name="charset" value="iso-8859-1">
    <input type="hidden" name="baseurl" value="http://www.meanylodge.org/public_html/summer/hikeweekend_09/">
    <input type="hidden" name="basedir" value="/home/meanylod/public_html/">
    <input type="hidden" name="dir" value="%2fhome%2fmeanylod%2fpublic_html%2fsummer%2fhikeweekend_09">
        <input type="hidden" name="file" value="hikeweekend.html">
    <input type="hidden" name="udir" value="/home/meanylod/public_html/summer/hikeweekend_09">
    <input type="hidden" name="ufile" value="hikeweekend.html">

        </form>
</div>
<script language="javascript">
<!--//

function setHtmlFilters(editor) {
// Design view filter
editor.addHTMLFilter('design', function (editor, html) {
        return html.replace(/\<meta\s+http\-equiv\="Content\-Type"[^\>]+\>/gi, '<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />');
});

// Source view filter
editor.addHTMLFilter('source', function (editor, html) {
        return html.replace(/\<meta\s+http\-equiv\="Content\-Type"[^\>]+\>/gi, '<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />');
});
}

// this function updates the code in the textarea and then closes this window
function do_save() {
    document.mform.page.value = WPro.editors[0].getValue();
	document.mform.submit();
}
function do_abort() {
	document.abortform.submit();
}
//-->
</script>
<?php
// make sure these includes point correctly:
include_once ('/usr/local/cpanel/base/3rdparty/wysiwygPro/wysiwygPro.class.php');

// create a new instance of the wysiwygPro class:
$editor = new wysiwygPro();

$editor->registerButton('save', 'Save',
        'do_save();', '##buttonURL##save.gif', 22, 22,
        'savehandler'); 
$editor->addRegisteredButton('save', 'before:print' );
$editor->addJSButtonStateHandler ('savehandler', 'function (EDITOR,srcElement,cid,inTable,inA,range){ 
        return "wproReady"; 
        }'); 


$editor->registerButton('cancel', 'Cancel',
        'do_abort();', '##buttonURL##close.gif', 22, 22,
        'cancelhandler'); 
$editor->addRegisteredButton('cancel', 'before:print' );
$editor->addJSButtonStateHandler ('cancelhandler', 'function (EDITOR,srcElement,cid,inTable,inA,range){ 
        return "wproReady"; 
        }'); 
$editor->theme = 'blue'; 
$editor->addJSEditorEvent('load', 'function(editor){editor.fullWindow();setHtmlFilters(editor);}');

$editor->baseURL = "http://www.meanylodge.org/public_html/summer/hikeweekend_09/";

$editor->loadValueFromFile('/home/meanylod/public_html/summer/hikeweekend_09/hikeweekend.html');

$editor->registerSeparator('savecan');

// add a spacer:
$editor->addRegisteredButton('savecan', 'after:cancel');

//$editor->set_charset('iso-8859-1');
$editor->mediaDir = '/home/meanylod/public_html/';
$editor->mediaURL = 'http://www.meanylodge.org/';
$editor->imageDir = '/home/meanylod/public_html/';
$editor->imageURL = 'http://www.meanylodge.org/';
$editor->documentDir = '/home/meanylod/public_html/';
$editor->documentURL = 'http://www.meanylodge.org/';
$editor->emoticonDir = '/home/meanylod/public_html/.smileys/';
$editor->emoticonURL = 'http://www.meanylodge.org/.smileys/';
$editor->loadPlugin('serverPreview'); 
$editor->plugins['serverPreview']->URL = 'http://www.meanylodge.org/public_html/summer/hikeweekend_09/.wysiwygPro_preview_79a8915dc8d5a080ebcc30daa1140189.php?randomId=9oyaKdZMWkLNL_fck3IBtf3sLGbwt8hPneXjZWfI3mk5GV_MLNgmkA_RWjx7fLr7KURuhpnwdgwFPQxFWIlhl_444WrfDV335AWkyBI2OrRA6uESxCQMBXk_qbNBZrh5jilnkd3Si9ZwUd9lxAGs34LBbWn7aFWismaqJI8StUazlozv8VngNjivBcUmHnfcQ3FJt27NRSVTr6btgpwLaSBgYzQ4VtCQZwTM0ppj05bjt2xVN_sT6cqhYOSFacqO';
// print the editor to the browser:
$editor->htmlCharset = 'iso-8859-1';
$editor->urlFormat = 'relative';
$editor->display('100%','450');

?>
</div>
<script>

</script>

</body>
</html>
<?php ob_end_flush() ?>
