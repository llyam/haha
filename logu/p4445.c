/*************************************************************************
	> File Name:p4445.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年08月20日 星期一 14时11分57秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, a[10001], i;
    int s = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(i = 1; i < n; i++) {
        if(a[i] > a[i - 1]) {
            s += a[i];
        } else {
            s += a[i - 1];
        }
    }
    printf("%d", s);
return 0;
}
