#!/bin/bash
time=`date "+%Y-%m-%d__%H:%M:%S"`
cpu=`cat /proc/loadavg | awk '{print $1" "$2" "$3}'`
wendu=`cat /sys/class/thermal/thermal_zone0/temp | awk '{printf("%.2f", $1/1000)}'`
cause=(`top -bn 1 -i -c | awk 'NR==3 {print $8}'`)
use=`echo "scale=1; 100-$cause" | bc`
if [[ $wendu>=0 && $wendu<=50 ]]; then
    warn="normal"
fi
if [[ $wendu>50 && $wendu<=70 ]]; then
    warn="note"
fi
if [[ $wendu>70 ]]; then
    warn="warning"
fi
echo "$time $cpu $use% $wendu℃  $warn"
