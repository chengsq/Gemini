#!/usr/bin/sh
 #!/bin/bash
if [ -z $1 ];then
  echo "usage:./test.sh filename"
  exit 1 
fi

if [ -f $1 ];then
echo "$1 is file"
input="$1" 
cat patch_tail >> $input
else
echo "$1 no such file"
fi


