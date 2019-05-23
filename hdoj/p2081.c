/*************************************************************************
	> File Name: p2081.c
	> Author: 
	> Mail: 
	> Created Time: 2019年05月23日 星期四 20时17分51秒
 ************************************************************************/

#include<stdio.h>

#define ll long long 

int main() {
    int n;
    scanf("%d", &n);
    ll x;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        printf("6%lld\n", x % 100000);
    }
    return 0;
}
