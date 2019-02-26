#!/bin/bash
sum=0
long=0
name=0
p=("" "" "")
x=0
a=0

find() {
    max=0
    for i in `ls`; do
        if [[ ! -r "$i" ]]; then 
            continue;
        fi
    #if [[ $i == '.' || $i == '..' ]]; then
    #    continue;
    #fi
    #    echo $i
        if [[ -d "$i" ]]; then
            cd $i
            find
            cd ..
        #    continue
        fi
        if [[ -f $i ]]; then
            for j in `strings $i`; do 
            #if [[ $j == "/*" || $j == "*/" ]]; then 
            #    continue;
            #fi
                sum=${#j}
                if [[ sum -gt max ]]; then
                    for (( k=0; k<$a; k++ ));do
                        if [[ ${p[$k]} == $sum ]]; then
                            break
                        fi
                        #echo $sum
                    done
                    if [[ $sum == ${p[$k]} ]]; then
                        continue
                    fi
                    long=$j
                    name=`pwd`
                    max=$sum
                    p[$a]=$sum
                    x=`cat $i | grep -n "$j" "$i" | tail -n 1 | cut -d':' -f1`
                    #echo ${long[$a]}
                fi
            done
        fi
    done
    (( a++ ))
    #echo $a
}

ne=$1
for (( z=0; z<3; z++ )); do
    cd $ne
    find 
    cd ..
    echo 长度：$max
    echo 路径：$name
    echo 行号: $x
    echo 字符串：$long
done
