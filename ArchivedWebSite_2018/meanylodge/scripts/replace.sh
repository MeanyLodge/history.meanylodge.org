#! /bin/bash

set -x
files=`find ~/public_html/ -name "*.html"`
#files="test.html"

rm output.txt
touch output.txt
for i in $files
do
 cp $i $i"_01Aug13"

  #sed -i '/>Winter Sports<\/a>/ i\
  #sed -i '/ski_program.html\"\>Winter Sports\<\/ai\>/ i\
  #sed -i '/dropmenu_1\" / a\
  # \       <a href=\"http://www.meanylodge.org/calendar.html\"\>Event Calendar\</a\>' $i
  #sed -i '/dropmenu_3\" class=\"dropmenudiv_d/ a\
  #          \<a href=\"mailto:biking_coordinator@meanylodge.org\"\>Biking Coordinator\</a\>\
  #          \<a href=\"mailto:hiking_coordinator@meanylodge.org\"\>Hiking Coordinator\</a\>' $i

  #sed -i 's/misc\/archive.html/archives\/archive.html/' *.html
  #sed -i 's/"mailto:chair@meanylodge.org">Winter Sports Director/"mailto:sports_director@meanylodge.org">Winter Sports Director/' $i
  #sed -i '/Work Parties<\/a>/ a\
#\          \<a href=\"http://www.foothillsmountaineers.org/hiking/pct-series.html\" target=\"blank\"\> Pacific Coast Trail Hikes\</a\>' $i
#  sed -i '/Google CSE Search Box Ends/ i\
#        \<\/div\>\
#        \<!-- Links  Starts --\>\
#        \<div id=\"links\"\>\
#          \<a href=\"http://www.mountaineers.org" target=\"blank\"\>\
#            \<img src=\"./images/misc/bluemlogo.jpg\" height=\"45\" width=\"30\"\>\
#          \<\/a\>\
#          \<a href=\"http://www.facebook.com/pages/Meany-Lodge/120987447986961\" target=\"blank\"\>\
#            \<img src=\"./images/misc/facebook_name.jpg\" height=\"25\" width=\"78\"\>\
#          \<\/a\>\
#        \<!-- Links Ends --\>' $i
#  sed -i ' /Google CSE Search Box Ends/ d
#          /Facebook Tag Starts/ i\
#         \<!-- Google SE Search Box Ends --\>' $i
#
#
# sed -i 's/ Pacific/Pacific/' $i
#  sed -i '/id="dropmenu_2"/ a\
#\          \<a href=\"http://www.meanylodge.org/winter/how_much.html\" target=\"blank\"\>Cost of coming to Meany\</a\>' $i
#sed -i 's/span><\/li>/span><\/a><\/li>/' $i

sed -i 's/\"http:\/\/www.meanylodge.org\/fall\/workparties.html/\"http:\/\/www.meanylodge.org\/misc\/workparties\/workparties.html/' $i
  exit_code=$?
  if [ $exit_code -ne 0 ]; then
    echo file $i did not get changed
  fi

sed -i 's/Fall Work Parties/Work Parties/' $i
  exit_code=$?
  if [ $exit_code -ne 0 ]; then 
    echo file $i did not get changed
  fi
done
