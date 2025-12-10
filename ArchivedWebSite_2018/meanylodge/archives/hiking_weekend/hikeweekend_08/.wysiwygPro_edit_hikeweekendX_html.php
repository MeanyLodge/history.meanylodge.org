<?php header("Content-type","text/html; charset=iso-8859-1"); ?>
<?php ob_start() ?>
<?php
if ($_GET['randomId'] != "3uBuborel1mu9UNo5XykFgR0ItGfkkcSFqVkwYRkBuQSKao9i8bCVKu4AXV1cc8qyYKE6toz5GfPU22Mf4OTn6fuVxVBTy0rBdwGtzPAzAwPA6Y3mxLqSE3VcKNuV7UoXw4SBVyy7h4fujosx1s_keDjzApO9YbNzbVCQC2oqb0LEP3VM4xC6LnUo1TDFIOOXadzKcUXWlyxcfvA5eRCbWM42bcX3SHgm0Jz5epFtPg71EbpyP3Nr36Ycru5PT2o") {
    echo "Access Denied";
    exit();
}
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<title>Editing hikeweekendX.html</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<style type="text/css">body {background-color:threedface; border: 0px 0px; padding: 0px 0px; margin: 0px 0px}</style>
</head>
<body>
<div align="center">
<script language="javascript">
<!--//
// this function updates the code in the textarea and then closes this window
function do_save() {
	var code =  htmlCode.getCode();
	document.open();
	document.write('<html><form METHOD="POST" name=mform action="http://proxy-netadmin-129841.backstage.site5.com:2082/frontend/na4/fileman/savehtmlfile.html"><input type="hidden" name="udir" value="/home/meanylod/public_html/summer/hikeweekend_08"><input type="hidden" name="ufile" value="hikeweekendX.html"><input type="hidden" name="dir" value="%2fhome%2fmeanylod%2fpublic_html%2fsummer%2fhikeweekend_08"><input type="hidden" name="file" value="hikeweekendX.html"><input type="hidden" name="doubledecode" value="1">Saving&nbsp;....<br /><br ><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><textarea name=page rows=1 cols=1></textarea></form></html>');
	document.close();
	document.mform.page.value = code;
	document.mform.submit();
}
function do_abort() {
	var code =  htmlCode.getCode();
	document.open();
	document.write('<html><form METHOD="POST" name="mform" action="http://proxy-netadmin-129841.backstage.site5.com:2082/frontend/na4/fileman/aborthtmlfile.html"><input type="hidden" name="dir" value="/home/meanylod/public_html/summer/hikeweekend_08"><input type="hidden" name="file" value="hikeweekendX.html">Aborting Edit&nbsp;....</form></html>');
	document.close();
	document.mform.submit();
}
//-->
</script>
<?php
// make sure these includes point correctly:
include_once ('/usr/local/cpanel/base/3rdparty/WysiwygPro/editor_files/config.php');
include_once ('/usr/local/cpanel/base/3rdparty/WysiwygPro/editor_files/editor_class.php');

// create a new instance of the wysiwygPro class:
$editor = new wysiwygPro();

// add a custom save button:
$editor->addbutton('Save', 'before:print', 'do_save();', WP_WEB_DIRECTORY.'images/save.gif', 22, 22, 'undo');

// add a custom cancel button:
$editor->addbutton('Cancel', 'before:print', 'do_abort();', WP_WEB_DIRECTORY.'images/cancel.gif', 22, 22, 'undo');

$body = '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html lang="en">
  <head>
     <title>Meany Lodge 08 family Hiking Weekend</title>

     <meta http-equiv="content-type" content="text/html; charset=utf-8">
     <meta name="keywords" content="family activity, Mountaineers, Meany Lodge, hiking, downhill skiing, 
      Cross-Country skiing, Snoqualmie Pass, Washington , Stampede pass, ski area, ski lessons, ski school, 
      professional ski  school, snowboard lessons, snow board lessons, cross county ski lessons, back country
      skiing, x-country skiing, down hill, alpine, alpine touring, downhill ski lessons, 
      down hill ski lessons, professional ski  school, winter sports, snowshoe, snow shoe, snowshoeing, 
      snow shoeing, telemark lessons, telemark skiing, telemark, skiing in Washington, skiing in the Cascades,
      ski areas at Snoqualmie Pass, ski club, private ski area, snowcat, kids, children, private lessons, 
      adults, groomed trails, Iron Horse Trail, Central Washington, Central Washington ski area, rope tow, 
      ski lodge, ski hut, Central Cascades, Central Cascade Mountains, Cascade Mountains, tow grippers, 
      nutcrackers, family activities, massage, on-site, on-site massage">
     <meta name="orgType" content="Meany">
     <meta name="description" content="Meany Lodge Internet">
     <meta name="author" content="emilio.marasco@gmail.com, bdthom@comcast.net">
     <meta name="URL" content="http://">

      <!-- Cascading style sheet links -->
      <link type="text/css" rel="stylesheet" href="../Style.css">
      <!-- Cascading style sheet ends -->
  </head>


  <body>
    <div id="container">
      <div id="header">
	<div id="search">
        <!-- Google CSE Search Box Begins  -->
        <form action="http://www.meanylodge.org/misc/google_search.html" id="searchbox_013775294804690014487:sphuf_lgf38">
          <input type="hidden" name="cx" value="013775294804690014487:sphuf_lgf38" />
          <input type="hidden" name="cof" value="FORID:11" />
          <input type="text" name="q" size="25" />
          <input type="submit" name="sa" value="Search" />
        </form>
        <script type="text/javascript" src="http://www.google.com/coop/cse/brand?form=searchbox_013775294804690014487%3Asphuf_lgf38&lang=en"></script>
        <!-- Google CSE Search Box Ends -->
	</div>
      </div>
      <br>
      <div id="leftCol">
        <div id="menu">
          <img src="../banner/orange_dodad.png"><a href="../../../index.html">
            Home Page
          </a><br>
          <img src="../banner/orange_dodad.png"><a href="../../../recipes/recipes.html">
            Meany Lodge Recipes
          </a><br>
          <img src="../banner/orange_dodad.png"><a href="../../../rec_links/rec_links.html">
            Recrational Links
          </a><br>
          <img src="../banner/orange_dodad.png"><a href="../../../classes/classes.html">
            Classes at Meany
          </a><br>
          <img src="../banner/orange_dodad.png"><a href="../../../misc/guest_info.html">
            Guest Information
          </a><br>
          <img src="../banner/orange_dodad.png"><a href="../../../misc/contact.html">
            Contacts
          </a><br>
          <img src="../banner/orange_dodad.png"><a href="../../../summer/hikeweekend/hikeweekend.html">
            Family Hiking Weekend
          </a><br>
          <img src="../banner/orange_dodad.png"><a href="../../../fall/mushroomwknd/mushroom.html">
            Mushroom Weekend
          </a><br>
          <img src="../banner/orange_dodad.png"><a href="../../../winter/winter.html">
            Winter Sports Activities
          </a><br>
          <img src="../banner/orange_dodad.png"><a href="../../../calendar.html">
            Meany Calendar
          </a><br>
          <img src="../banner/orange_dodad.png"><a href="../../../misc/blog.html">
            Meany Blogs
          </a><br>
          <img src="../banner/orange_dodad.png"><a href="../../../misc/archive.html">
            Meany Archives
          </a><br>
        </div>
      </div>
      <div id="content">
	<h2>Welcome to the Meany\'s Family Weekend hiking page</h2>
	<p class="top">
          This is the page where we describe what fantastic activities Brian and Sojien have in store for
          all the lucky individual that plan to come<br>
          Please come back and check on the progress
        </p>
        <p>
          In the meantime check out what we did last year, please click on 
          <img src="../banner/orange_dodad.png"><a href="../hikeweekend_07/hikeweekend.html">
            2007 Hiking Weekend
          </a><br>

        <p>
          if you have any suggestion on this page please email <a href="mailto:bdthom@comcast.net">Brian</a> or
          <a href="mailto:emilio.marasco@gmail.com">Emilio</a>
	</p>

        <br><br><br><br><br><br><br><br>
      </div>
    </div>
    <div id="footer">
         <hr />
           Meany Lodge&copy;, Design by Brian Thompson and Emilio Marasco, 
       </div>
     </div>
     <script src="http://www.google-analytics.com/urchin.js" type="text/javascript"></script>
     <script type="text/javascript">
       _uacct = "UA-3764828-1";
       urchinTracker();
     </script>
</body>
</html>';

$editor->set_code($body);

// add a spacer:
$editor->addspacer('', 'after:cancel');

$editor->set_charset('iso-8859-1');

// print the editor to the browser:
$editor->print_editor('100%','450');

?>
</div>
</body>
</html>
<?php ob_end_flush() ?>
