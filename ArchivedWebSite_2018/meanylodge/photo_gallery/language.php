<?php
/*checking for security reasons*/
	if(!defined("PHPALBUM_APP")){
		die("Direct access not permitted!");
}

require("lang/".$pa_lang["include_file"]);

if(file_exists($data_dir.$pa_lang["translate_file"])){
	include($data_dir.$pa_lang["translate_file"]);
}

function p($id,$par=null){
	global $actual_language;
	/* function prints text for ide $id and actual language, if not found then EN*/
	if($par === null){
		print pa_get_text($id);
	}else{
		printf ( pa_get_text($id),$par);
	}
	
}
function t($id,$par=null,$par2=null){
	if($par===null){
		return pa_get_text($id);
	}else if($par2==null){
		return sprintf(pa_get_text($id),$par);
	}else{
		return sprintf(pa_get_text($id),$par,$par2);
	}
}
function pa_get_text($id){
	global $pa_texts,$pa_translated_texts;
	if(isset($pa_translated_texts[$id])){
		 return $pa_translated_texts[$id];
	}else{
		if(isset($pa_texts[$id])){
		   return $pa_texts[$id];
	  }else{
	  	return "##N/A:$id##";
	  }
	}
}