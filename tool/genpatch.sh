#!/bin/bash
#this shell refer to generate the patch of elf according the ruled format 
#though this shell has workout some mission ,you need to change the patch  header information by youself
#chengsq123@gmail.com
# author  chengsq
code_file=$1
#echo $code_file
readelf -t $code_file | awk '{if(NR%3){ORS=" "}else{ORS="\n"};print }' | awk '{gsub(/\[ /,"[")};{print}'|awk  '{printf " %-15s %-35s %-15s %-15s %-15s %-15s %-15s  %s \n",$1,$2,$3,$4,$5,$6,$7,$8}' >elf.temp

func_name=$2
#echo $func_name
#cat  elf.temp |grep "$func_name"|awk '{print $2,$5}'

# getnerate pathc fiel 

#cat elf.temp |grep "$func_name"| awk '{printf "0x%s 0x%s", $5,$6}' 
cat elf.temp | grep "$func_name" |awk '{printf "0x%s 0x%s", $5,$6}' |xargs ./cup.sh
mv patch.out  $func_name.patch

mypath=`pwd`"/path"
#echo $mypath

if [  ! -d "patch" ] ; then
echo "**** make dir patch  *******"
mkdir patch 
else
echo "dictory patch  have existed"
fi
mv  $func_name.patch  patch/$func_name.patch

#delete the tmporary file
rm elf.temp -fr 
rm target.patch -fr
echo "generate $func_name patch file -- $func_name.patch sucess"
echo "now you need to modify the patch file header acording to reqirement"


