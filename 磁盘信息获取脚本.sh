#!/bin/bash 
num=`df -T  -m -x tmpfs -x devtmpfs | tail -n +2`
inum=$num | wc -l
echo $num
echo $inum
