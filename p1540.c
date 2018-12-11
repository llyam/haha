/*************************************************************************
	> File Name:p1540.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年12月07日 星期五 18时51分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
int main() {
    int m, n, x, head = 0, tail = 0, sum = 0, z = 0;
    scanf("%d %d", &m, &n);
    int cun[m + n + 1], wen[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        for (int j = head; j < tail; j++) {
            if (x == cun[j]) {/*printf(" %d %d\n",sum, cun[j]);*/z = 1; break;}
        }
        if (z == 1) {
            z = 0;
            continue;
        }
        if (tail >= m) head++;
        cun[tail++] = x;
        sum++;
        //printf("%d %d\n", sum, i);
    }
    printf("%d\n", sum);
    return 0;
}
