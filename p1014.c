/*************************************************************************
	> File Name:p1014.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年11月17日 星期六 14时26分52秒
 ************************************************************************/

#include <stdio.h>

int main() {
    long long n, i, sum = 0;
    scanf("%lld", &n);
    for (i = 1; sum < n; i++) {
        sum += (i + 1);
    }
    long long h = n - sum + i - 1;
    printf("h=%d\n", h);
    printf("%lld/%lld\n", h+1, i-h);
}
