/*************************************************************************
	> File Name:p1067.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年10月06日 星期六 10时24分10秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, z;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &z);
        if (z > 0) {
            if (i == 1) {
                printf("%dx^%d", z, n);
                continue;
            }  
            printf ("+x^%d", n - i);
        } else if (z == 0) {
            continue;
        } else {
            if (n == -1) {
                printf("-x^%d", n - i);
                continue;
            }
            printf("%dx^%d", z, n - i);
        }
    }
    printf("\n");
    return 0;
}
