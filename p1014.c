/*************************************************************************
	> File Name:n.p1014.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年12月28日 星期五 19时54分28秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, num = 0, sum = 0, p;
    scanf("%d", &n);
    for (p = 1; ; p++) {
        num++;
        sum += p;
        if (sum >= n) break;
    }
    printf("p=%d\n", p);
    int nu = n - sum + p;
    if (num % 2 == 0) {
        printf("%d/%d\n", nu, p-nu+1);
    } else {
        printf("%d/%d\n", p-nu+1, nu);
    } 

    return 0;
}
