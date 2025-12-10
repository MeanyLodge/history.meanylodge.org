<?php

function read_settings_old(){
  global $data_dir;
 /***********************/
 /*read main_setup      */
 /***********************/
 if(!file_exists($data_dir."quality.dat")){
   put_default_quality_settings();
 }
 $file=file($data_dir."quality.dat");
 foreach($file as $line_num=>$line){
 	$quality_settings[$line_num]=explode("|",$line);
 }
//  var_dump($quality_settings);echo '<br>';
 
 if(!file_exists($data_dir."main_setup.dat")){
 	 $cmd="setup";
	 $var1="main";
	return;
 }
 
 $file=file($data_dir."main_setup.dat");
 $setup_password=substr($file[0],0,strlen($file[0])-1);
 $album_dir=substr($file[1],0,strlen($file[1])-1);
 $cache_dir=substr($file[2],0,strlen($file[2])-1);
 $site_name=substr($file[3],0,strlen($file[3])-1);	
 $logo_enabled=substr($file[4],0,strlen($file[4])-1);
 $logo_path=substr($file[5],0,strlen($file[5])-1);
 $site_theme=substr($file[6],0,strlen($file[6])-1);
 $return_home_url=substr($file[7],0,strlen($file[7])-1);
 $new_dir_indic=substr($file[8],0,strlen($file[8])-1); 
 if(isset($file[9])){
 //version 0.2.4 already stored.
   $album_name=substr($file[9],0,strlen($file[9])-1);
   $album_dir_name=substr($file[10],0,strlen($file[10])-1);
   $cookie_password_hours=substr($file[11],0,strlen($file[11])-1);
   $setup_text=substr($file[12],0,strlen($file[12])-1);
   $next_text=substr($file[13],0,strlen($file[13])-1);
   $previous_text=substr($file[14],0,strlen($file[14])-1);
   $disable_bottom_nextprev=substr($file[15],0,strlen($file[15])-1);
   $character_set=substr($file[16],0,strlen($file[16])-1);
 }
 if(isset($file[17])){
 //version 0.3.0 already stored
 $directory_style=substr($file[17],0,strlen($file[17])-1);
 $maximum_photos_per_page=substr($file[18],0,strlen($file[18])-1);
 $raster_dir_x=substr($file[19],0,strlen($file[19])-1);
 $raster_dir_y=substr($file[20],0,strlen($file[20])-1);
 $next_page_text=substr($file[21],0,strlen($file[21])-1);
 $previous_page_text=substr($file[22],0,strlen($file[22])-1);
 //ftp-settings
 $ftp_server=substr($file[23],0,strlen($file[23])-1);
 $ftp_server_photos_dir=substr($file[24],0,strlen($file[24])-1);
 }
 if(isset($file[25])){
 	$show_filenames=(substr($file[25],0,strlen($file[25])-1)=="true")? true:false;
 }
 if(isset($file[26])){
	 $default_sorting=substr($file[26],0,strlen($file[26])-1);
 }
 /***********************/
 /*read quality settings*/
 /***********************/


/***********************/
 /*read comments settings */
 /***********************/
 if(file_exists($data_dir."comments_setup.dat")){
	 $file=file($data_dir."comments_setup.dat");
	 $comments_settings=explode("|",$file[0]);
	 $comments_enabled=($comments_settings[0]=="true")? true:false;
	 
 }
 
 /***********************/
 /*read logs    settings*/
 /***********************/
 if(file_exists($data_dir."logs_setup.dat")){
	 $file=file($data_dir."logs_setup.dat");
	 $logs_settings=explode("|",$file[0]);
	 $logs_enabled=$logs_settings[0];
	 $logs_filename=$logs_settings[1];
	 $logs_exclude=$logs_settings[2];
 }
 /***********************/
 /*  read theme settings*/
 /***********************/
 global $theme_params;
 if(file_exists($data_dir.$site_theme.".dat")){
	 $file=file($data_dir.$site_theme.".dat");
	 $theme_settings=explode("|",$file[0]);
	 $num=0;
	 while (isset($theme_settings[$num])){
	 	$theme_params[$num]= $theme_settings[$num];
	 	$num=$num+1;
	 }
 }
 
 if(file_exists($data_dir."cache_setup.dat")){
	 $file=file($data_dir."cache_setup.dat");
	 $logs_settings=explode("|",$file[0]);
	 $cache_thumbnails=$logs_settings[0];
	 $cache_resized_photos=$logs_settings[1];
 }

}


function get_directory_settings_old($dir,$full = 1){
global $data_dir,$album_dir;

if ($dir=="\\") $dir="";
if(substr($dir,0,1)!="/"){
 $dir="/".$dir;
}
if(substr($dir,-1,1)!="/"){
 $dir=$dir."/";
}
$file_name=stripslashes($data_dir.str_replace(" ","_",str_replace("/","_",$dir)).".dat");
$settings[0]=$dir;
if(file_exists($file_name)){
	$file=file($file_name);
	if(strlen($file)>0){
		$params=explode("|",substr($file[0],0,strlen($file[0])-1));
		$settings[1]=$params[0];
		$settings[2]=$params[1];
		$settings[3]=$params[2];
		if(strlen($params[5])>0){
			/*new settings for 0.3.1.4*/
			$settings[4]=$params[3]; /*alias*/
			$settings[5]=$params[4]; /*sorting*/
			$settings[6]=$params[5]; /*visibility*/
		}else{
			$settings[4]=""; /*alias*/
			$settings[5]="default"; /*sorting*/
			$settings[6]="true"; /*visibility*/
		}
	}else{
		$settings[1]="";
		$settings[2]="";
		$settings[3]="";
		$settings[4]=""; /*alias*/
		$settings[5]="default"; /*sorting*/
		$settings[6]="true"; /*visibility*/
	}
}else{
	$settings[1]="";
	$settings[2]="";
	if(!isset($settings[3])){
	   $settings[3]="";
	}
	$settings[4]=""; /*alias*/
	$settings[5]="default"; /*sorting*/
	$settings[6]="true"; /*visibility*/
}
$sett[0]=$settings;
/*read settings for all photos in this direcotry ..*/
/*first read the settings in the file*/
if($full==1){
	$num=1;
	while(isset($file[$num])){
		$files[]=explode("|",substr($file[$num],0,strlen($file[$num])-1));
		$num=$num+1;
	}
	
	/*now read the directory for files and try to find something about 
	 these in settings*/
	 if(file_exists($album_dir.$dir)){
	    if ($dh = opendir($album_dir.$dir)) {
	       while (($file = readdir($dh)) !== false) {
	           if( (filetype($album_dir.$dir ."/". $file)=="file" || filetype($album_dir.$dir ."/". $file)=="link" ) && is_image($file) ){
		   		$files2[]=$file;
			}
				
	       }
	       closedir($dh);
	
	    }
	   }
	  /*consolidate files with settings*/
      if(sizeof($files2)>0){
          asort($files2);
	 foreach($files2 as $num => $file_name){
	    /*find file in settings*/
	    $found=0;
	    $i=0;
    
	    while(isset($files[$i])){
	    	if($file_name==$files[$i][0]){
		  $found=1;
		  $sett[]=$files[$i];
		  break;
		}
	    	$i=$i+1;
	    }
	    if($found==0){
	     $sett[]=Array($file_name,"","");
	    }	
	 }
       }/*if */
   }
return $sett;
}