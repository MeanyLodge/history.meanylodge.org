<?php
	/* GenCodePic Usage
	*  $code = new GenCodePic();
	*  $code->generate();
	*  header("Content-type: image/png");
	*  imagegif($code->get_image());
	*/
class CodePicture{

		var $code_text;
		var $code_image;
		var $filename;


		function get_image(){
			return $this->code_image;
		}
		function put_gif(){
			if(isset($this->filename)){
				imagegif($this->code_image,$this->filename);
			}else{
				header("content-type: image/gif");
				imagegif($this->code_image);
			}
		}
		function put_jpg(){
			if(isset($this->filename)){
				imagejpeg($this->code_image,$this->filename);
			}else{
				header("content-type: image/jpeg");
				imagejpeg($this->code_image);
			}
		}
		function get_code(){
			return $this->code_text;
		}
		function set_filename($f){
			$this->filename=$f;
		}
		function generate(){
			$this->code_image=imagecreate(70,25);
			$background_color = ImageColorAllocate ($this->code_image, 220, 220 , rand(50,250));
			for ($i = 0; $i<4 ; $i++){
				$text_color = ImageColorAllocate ($this->code_image, rand(0,200), rand(0,150), rand(0,50));
				$num=rand(0,9);
				$this->code_text .= $num;
				ImageString ($this->code_image, 5, rand(8,12)+14*$i, 4+rand(-3,3), $num, $text_color);
			}
		}

}
?>
