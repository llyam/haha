/*************************************************************************
	> File Name:p1149.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年10月03日 星期三 15时57分12秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, c[2000] = {0};
    int n, sum = 0, i, j, f;
    c[0] = 6;
    scanf("%d", &n);
    for (i = 1; i <= 1425; i++) {
        int o = i;
        while (o) {
            c[i] += a[o % 10];
            o /= 10;
        }
    }
    for (i = 0; i <= 711; i++) {
        for (j = 0; j <= 711; j++) {
            f = i + j;
            if (c[i] + c[j] + c[f] + 4 == n) {
                sum++;
                printf("%d %d\n", i, j);
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
