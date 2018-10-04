/*************************************************************************
	> File Name:p1036.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年09月27日 星期四 17时04分46秒
 ************************************************************************/

#include <stdio.h>

#define max 
int prime[] = {0};

int main() {
    int n, x, z, a[21];
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &z);
        a[i] = z;
    }
    for (int i = 2; i < max; i++) {
        if (prime[i] != 0) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j < prime[0]; j++) {
            if (prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j]) break;
        }
    }


    return 0;
}
