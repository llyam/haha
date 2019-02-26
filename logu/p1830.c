/*************************************************************************
	> File Name:p1830.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年09月09日 星期日 14时44分49秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, m, x, y, x1, x2, y1, y2, h, q;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    int a[n][m] = {0}, b[n][m] = {0};
    for (int i = 1; i <= x; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int j = x1 - 1; j < x2; j++) {
            for(int k = y1 - 1; k < y2; k++) {
                a[j][k]++;
                b[j][k]=i;
            }
        }
    }
    for ( int j = 0; j < y; j++) {
        scanf("%d %d", &h, &q);
        if (a[h-1][q-1] != 0) {
            printf("Y %d %d\n", a[h-1][q-1], b[h-1][q-1]);
        } else {
            printf("N\n");
        }
    }
return 0;
}
