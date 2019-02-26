#!/bin/bash
time=`date +"%Y-%m-%d_%H:%M:%S"`
num=`last | grep "[a-zA-Z]" |  grep -v "reboot" | grep -v "wtmp" | wc -l`
name=(`last | cut -d " " -f 1 | grep "[a-zA-Z0-9]"|grep -v "reboot" | grep -v "wtmp" | sort | uniq -c | awk '{if(NR<=3) print $2}'`)
ip=(`who | awk '{print $1"_"$5"_"$2}'`)
inum=`who -q | tail -n 1 |cut -d "=" -f 2-`
root=`last | cut -d "" -f 1 | grep "[a-zA-Z0-9]" | grep -v "reboot" | grep -v "stmp" | sort | uniq | id | awk '{print $1}' | cut -d '(' -f 2 | cut -d ')' -f 1`
echo -n "$time $num" 
echo -n " ["
for i in {0..2}; do
    if [[ ${name[$i]} ]]; then
        if [[ $i -ne 0 ]]; then
            echo -e ",""\c"
        fi
        echo -e "${name[$i]}""\c"
    fi
done
echo -n "] "
echo -n "[$root] ["
(( inum=$inum - 1 ))
for i in `seq 0 $inum`; do
    if [[ $i != 0 ]]; then
        echo ","
    fi
    echo -n ${ip[$i]} 
done
echo -n "]"
echo ""
