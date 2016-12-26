#!/bin/bash

folderbase=chapter
 

for folder in {11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28}
do
FolderName=${folderbase}${folder} #拼接最后文件夹的名称
if [ -d $FolderName ]; then　#如果文件夹存在
 echo ${FolderName} exist
else
 mkdir ${FolderName}  #创建文件夹
fi
done


