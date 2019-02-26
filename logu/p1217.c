/*************************************************************************
	> File Name:p1217.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年10月03日 星期三 16时42分33秒
 ************************************************************************/

#include <stdio.h>

#define max 10000000
int prime[max];

void prime_x() {
    for (int i = 2; i <= max; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i >= max) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int hui(int x) {
    int a = 0, b = x;
    while(b) {
        a *= 10;
        a += b % 10;
        b /= 10; 
    }
    if (a == x) {
        return 1;
    }
    return 0;
}

int main() {
    prime_x();
    int x, y;
    scanf("%d %d", &x, &y);
    for (int i = 1; i <= max; i++) {
        if(prime[i] >= x && prime[i] <= y) {
            if(hui(prime[i]) != 0) {
                printf("%d\n", prime[i]);
            }
        }    
    }
    return 0;
}
