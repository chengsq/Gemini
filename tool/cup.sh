#!/bin/bash
declare -i tmp
declare -i start
declare -i len
PREFIX="csq"
tmpfile=$PREFIX"ab"
targetfile=$PREFIX"aa"
start=$1
len=$2
#echo $tmp
echo "patch length: "$len" bytes" 

split -b $start  code.elf $PREFIX
split -b $len   $tmpfile $PREFIX 
mv $targetfile target.patch
rm $PREFIX*
cat  patch_header  target.patch patch_tail >  patch.out
