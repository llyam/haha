/*************************************************************************
	> File Name:p1003.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年10月05日 星期五 20时15分11秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, a[10001][4], p, q;
    scanf("%d", &n);
    if (n == 0) {
        printf("-1\n");
        return 0;
    }
    for (int z = 0; z < n; z++) {
        scanf("%d %d %d %d", &a[z][0], &a[z][1], &a[z][2], &a[z][3]);
    }
    scanf("%d %d", &p, &q);
    for (int i = n - 1; i >= 0; i--) {
        if (p >= a[i][0] && p <= a[i][0] + a[i][2] && q >= a[i][1] && q <= a[i][3]) {
            printf("%d\n", i+1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
