#!/bin/bash

echo "要提交的文件"
read b
git add $b
echo "请输入commit -m 后的XXX"
read a
git commit -m $a
git push -u origin master
