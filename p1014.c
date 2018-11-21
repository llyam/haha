/*************************************************************************
	> File Name:p1014.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年11月17日 星期六 14时26分52秒
 ************************************************************************/

#include <stdio.h>

int main() {
    long long n, i;
    scanf("%d", &n);
    for (i = 1; ; i++) {
        if ((1 + i) * i / 2 >= n) break;
    }
    int x = n - (i - 1) * i / 2;
    printf("%d/%d\n", x, i - x + 1);
    return 0;
}
