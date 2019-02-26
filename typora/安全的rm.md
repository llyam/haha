## 2.安全的rm

#### （1）题目说明

垃圾桶建立一个文件夹将要删除的文件移动到此文件夹中

设置一个时间自动删除文件内容

有-f和-r的出现则按照rm -f或-r的规则运行

#### （2）代码说明

```sh
#!/bin/bash
if [[ ! -d ~/.垃圾桶 ]]; then
    mkdir ~/.垃圾桶
fi   #没有垃圾桶就再建一个
if [[ $1 == "-f" ]]; then  #-f
    for j in $@; do 
        if [[ -f $j || -d $j ]]; then
            mv -b $j ~/.垃圾桶
        fi
    done
elif [[ $1 == "-r" && $2 == "-f" ]]; then #-r -f
    for i in ls; do
        if [[ -f $i || -d $i ]]; then
            mv -b $i ~/.垃圾桶
        fi
    done
else
    echo $@
    echo "你确定要删除文件么？y/n"
    read x
    if [[ $x == y ]]; then
        for l in $@; do  
            if [[ -f $l || -d $l ]]; then
                mv -b $l ~/.垃圾桶
            else
                echo "无此文件或目录"
            fi
        done
    else
        echo "已结束操作"
    fi
fi
```



```sh
#!/bin/sh
find ~/.ljt -mtime +30 -exec rm -rf {} \;#30天自动删除
```



#### （3）执行结果

![1534248464074](/tmp/1534248464074.png)

#### （4）难点记录

刚开始的思路问题，对$ 的理解不到位，以及-r和-f运行方式

#### （5）其他思考

对shell的用法等了解的不太熟悉缺少练习