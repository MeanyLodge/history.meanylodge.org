#! /bin/bash

#set -x
files=`find ~/public_html/ -name "*.html"`
#files="test1.html"

for i in $files
do
  mv $i_bak $i
  exit_code=$?
  if [ $exit_code -ne 0 ]; then 
    echo file $i did not get remove
  fi
done
