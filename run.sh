#!/bin/bash

git add .
echo "请输入commit -m 后的XXX"
read a
git commit -m $a
git push -u origin master
