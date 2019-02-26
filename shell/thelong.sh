#!/bin/bash
sum=0
name=0
p=("0" "0" "0")
long=0
o=0
OLDIFS=$IFS
filter() {
    a=(rmvb png img jpg jepg gif md avi zip tai gz 7z)
    suffix=`echo $1 | awk -F. '{print $NF}'`
    echo ${a[*]} | grep "$suffix" >/dev/null 
    if [[ $? -eq 0 ]]; then
        return 1
    fi
    return 0
}

find() {
    max=0
    for i in `ls -A`; do
	#echo $i
        file $i | grep "exec" >/dev/null 
        if [[ $? -eq 1 ]]; then
            filter $i
            if [[ $? -eq 1 ]]; then
                continue
            fi
        fi
        if [[ ! -r "$i" ]]; then 
            continue;
        fi
        if [[ -d "$i" ]]; then
            cd $i
            find
            cd ..
            continue
        fi
        if [[ -f $i ]]; then
		IFS=$OLDIFS
            for j in `strings "$i"`;do
                sum=${#j}
                if [[ sum -gt max ]]; then
                    for (( k=0; k<$o; k++ ));do
                        if [[ ${p[$k]} == $j ]]; then
                            break
                        fi
                    done
                    if [[ $j == ${p[$k]} ]]; then
                        continue
                    fi
                    long=$j
                    name=`pwd`/$i
          		max=$sum
                    p[$o]=$long
                    x=`cat "$i" | grep -n "$j" "$i" | tail -n 1 | cut -d':' -f1`
                fi
    		done
	IFS=$'\n'
        fi
    done
}

ne=$1
echo "#Problem1"
for (( z=0; z<3; z++ )); do
IFS=$'\n'
    cd $ne
    find $z 
    cd ..
    #echo 长度：$max
    #echo 路径：$name
    #echo 行号: $x
    #echo 字符串：$long
    echo $max:$long"<    >"pi11:$name"<    >"Line:$x
    (( o++ ))
IFS=$OLDIFS
done
