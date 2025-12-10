#! /bin/bash
  
#set -x
  sed -i 's/recipes\/recipes.html/AAAAA\/BBBBB.html/' *.html
  sed -i 's/Meany Lodge Recipes/ZZZZZZZZ/' *.html
  sed -i 's/misc\/guest_info.html/recipes\/recipes.html/'  *.html
  sed -i 's/Guest Information/Meany Lodge Recipes/' *.html
  sed -i 's/AAAAA\/BBBBB.html/misc\/guest_info.html/' *.html
  sed -i 's/ZZZZZZZZ/Guest Information/' *.html

