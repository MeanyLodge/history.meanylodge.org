<?php
/*checking for security reasons*/
if(!defined("PHPALBUM_APP")){
	die("Direct access not permitted!");
}


function check_version($actual,$to_be){
	$a=explode(".",$actual);
	$b=explode(".",$to_be);
	
	if(intval($a[0])<intval($b[0])){
		return true;
	}
	if(intval($a[0])>intval($b[0])){
		return false;
	}

	if(intval($a[1])<intval($b[1])){
		return true;
	}
	if(intval($a[1])>intval($b[1])){
		return false;
	}
	
	if(intval($a[2])<intval($b[2])){
		return true;
	}
	if(intval($a[2])>intval($b[2])){
		return false;
	}
	
	if(intval($a[3])<intval($b[3])){
		return true;
	}
	return false;
}
echo "upgrading from:" . $pa_db_version[0]["version"]."to $phpalbum_version<br>";
if(!isset($pa_db_version[0])){
	 // changes for 0.4.1.beta9
	echo "applying changes for 0.4.1.9 version<br>";
    db_create_table("anti_spam_codes",Array(
    	"pic_seq"=>"",
    	"code"=>"",
    	"time"=>"",
    ));
    db_create_sequence("antispam_pic_seq",1,1);
    db_create_table("phpalbum_version",Array("version"=>""));
    db_insert("phpalbum_version",Array("version"=>"0.4.1.9"));
    db_alter_table_add_column("setup","error_logging_enabled","false");
    // correcting bug from 0.4.1.beta8
    $rec=db_select_all("photo_param","default_lov=='exif_fl' && type=='system' && id=='8'");
    if(isset($rec[0])){
    	$new_id=db_get_seq_nextval("photo_param_id");
    	db_update("photo_param","id='$new_id';","default_lov=='exif_fl' && type=='system' && id=='8'");
    	db_commit();
    }
    $pa_db_version[0]["version"]="0.4.1.9";
}
if(check_version($pa_db_version[0]["version"],"0.4.1.10")){
	echo "applying changes for 0.4.1.10 version<br>";
	db_alter_table_add_column("setup","antispam_code_enabled","true");
   	$new_id=db_get_seq_nextval("photo_param_id");
	db_insert("photo_param",Array("id"=>$new_id,"name"=>"Date/Time (Exif)","type"=>"system","default_lov"=>"exif_datetime"));
	db_update("phpalbum_version","version='0.4.1.10';");
    $pa_db_version[0]["version"]="0.4.1.10";
}
if(check_version($pa_db_version[0]["version"],"0.4.1.11")){
	echo "applying changes for 0.4.1.11 version<br>";
	db_alter_multiple_table_add_column("comments_","visible","true");
	db_alter_table_add_column("setup","publish_only_approved_comments","false");
	db_update("phpalbum_version","version='0.4.1.11';");
    $pa_db_version[0]["version"]="0.4.1.11";
}
if(check_version($pa_db_version[0]["version"],"0.4.1.12")){
	echo "applying changes for 0.4.1.12 version<br>";
	db_update("phpalbum_version","version='0.4.1.12';");
    $pa_db_version[0]["version"]="0.4.1.12";
}
if(check_version($pa_db_version[0]["version"],"0.4.1.13")){
	echo "applying changes for 0.4.1.13 version<br>";
	db_drop_table("stat_newest_photos");
	db_drop_table("stat_newest_dirs");
	db_drop_table("stat_photo_comments");
	db_drop_table("stat_photo_views");
	db_drop_table("stat_photo_votes");
	db_alter_table_add_column("directory","newest_file_time_with_subdirs","");
	db_alter_table_add_column("directory","newest_file_time","");
	db_alter_table_add_column("directory","keywords",Array());
	db_alter_multiple_table_add_column("files_","file_time","");
	db_alter_table_add_column("directory","show_newest_pictures_count","0");
	db_alter_multiple_table_add_column("files_","screenshot","");
	db_alter_multiple_table_add_column("files_","type","I");//I=Image,V=Video,M=Music,O=Others
	db_alter_table_add_column("setup","use_iptc_desc","true");
	db_alter_multiple_table_add_column("files_","keywords",Array());
	db_update("group","grants['imageview']='1';grants['imageorig']='1';");
	db_alter_table_modify_column("group","grants",Array("imageorig"=>"1","imageview"=>"1"));
	db_insert("group",Array("name"=>"guest"));
	db_create_table("object_cache",Array("type"=>"","file"=>""));
	db_delete("directory","path=='/./'");
	db_update("phpalbum_version","version='0.4.1.13';");
  $pa_db_version[0]["version"]="0.4.1.13";
}
if(check_version($pa_db_version[0]["version"],"0.4.1.14")){
	echo "applying changes for 0.4.1.14 version<br>";
	db_create_table("ecards",Array("uid"=>"","image"=>"","from_name"=>"","from_email"=>"","to_name"=>"","to_email"=>"","message_text"=>"","created"=>"","picked_up"=>"false"));
	db_alter_table_add_column("setup","ecard_enabled","true");
	db_alter_table_add_column("setup","ecard_subject","You have got an e-card !");
	db_alter_table_add_column("setup","ecard_text","Hello #TO_NAME,\n\n#FROM_NAME sent you an electronic card from phpAlbum.net.\nYou can pick up it on this adress: http://www.phpalbum.net/phpAlbum/#ECARD_ADRESS\nOr you can just look at the picture here: http://www.phpalbum.net/phpAlbum/#IMAGE_ADRESS\n\nYour e-card was sent on #DATE at #TIME.");
	db_alter_table_add_column("setup","ecard_picked_subject","You e-card was picked up !");
	db_alter_table_add_column("setup","ecard_picked_text","Hello #FROM_NAME,\n\n#TO_NAME picked up your e-card on #DATE at #TIME\n\ne-card adress: http://www.phpalbum.net/phpAlbum/#ECARD_ADRESS"); 	db_alter_table_add_column("setup","smtp_adress","localhost");
	db_alter_table_add_column("theme","show_search_box","true");
	db_alter_table_add_column("setup","tracking_code","");
	db_update("phpalbum_version","version='0.4.1.14';");
    $pa_db_version[0]["version"]="0.4.1.14";
}
if(check_version($pa_db_version[0]["version"],"0.4.1.15")){
     db_update("phpalbum_version","version='0.4.1.15';");
    $pa_db_version[0]["version"]="0.4.1.15";
}if(check_version($pa_db_version[0]["version"],"0.4.1.16")){
     db_update("phpalbum_version","version='0.4.1.16';");
    $pa_db_version[0]["version"]="0.4.1.16";
}