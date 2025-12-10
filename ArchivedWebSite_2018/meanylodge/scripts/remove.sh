#! /bin/bash

set -x
files=`find ~/public_html/ -name "*.html_*"`

for i in $files
do
  rm $i
  exit_code=$?
  if [ $exit_code -ne 0 ]; then 
    echo file $i did not get remove
  fi
done
