/*************************************************************************
	> File Name:p1464.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年10月08日 星期一 18时22分26秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
int wa[22][22][22] = {0};
#define ll long long int
ll w(ll a, ll b, ll c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    } else if(wa[a][b][c] != 0) {
        return wa[a][b][c];
    } else if (a > 20 || b > 20 || c > 20) {
        return wa[a][b][c] = w(20, 20, 20);
    } else if (a < b && b < c) {
        return wa[a][b][c] = w(a, b, c - 1) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    } else {
        return wa[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
}


int main() {
    ll a, b, c, x, y, z;
    while(scanf("%lld %lld %lld", &x, &y, &z) != EOF) {
        a = x;
        b = y;
        c = z;
        if(a == -1 && b == -1 && c == -1) {
            return 0;
        }
        if (a > 20) a = 21;
        if (b > 20) b = 21;
        if (c > 20) c = 21;
        ll ans = w(a, b, c);
        printf("w(%lld, %lld, %lld) = %lld\n", x, y, z, ans);
    }
    return 0;
}
