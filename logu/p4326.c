/*************************************************************************
	> File Name:p4326.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年08月20日 星期一 15时54分01秒
 ************************************************************************/

#include <stdio.h>

#define pi 3.1415926535

int main() {
    float r;
    scanf("%f", &r);
    double s1, s2;
    s1 = pi * r * r;
    s2 = r * r * 2; 
    printf("%.6f\n%.6f", s1, s2);
return 0;
}
