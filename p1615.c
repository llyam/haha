/*************************************************************************
	> File Name:p1615.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年08月20日 星期一 15时03分27秒
 ************************************************************************/

#include <stdio.h>

int main() {
    long long int s1, s2, s;
    int x, y, z, a, b, c, l;
    scanf("%d:%d:%d", &x, &y, &z);
    scanf("%d:%d:%d", &a, &b, &c);
    scanf("%d", &l);
    s1 = x * 3600 + y * 60 + z;
    s2 = a * 3600 + b * 60 + c;
    s = (s2 - s1) * l;
    printf("%lld", s);
return 0;
}
