/*************************************************************************
	> File Name: p2007.c
	> Author: 
	> Mail: 
	> Created Time: 2019年05月23日 星期四 18时02分43秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int x, y, m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
	if (m > n) m ^= n, n ^= m, m ^= n;        
	long long int s1 = 0, s2 = 0;
        for (int i = m; i <= n; i++) {
            if (i % 2 == 0) {
                s1 += i * i;
            } else {
                s2 += i * i * i;
            }
        }
        printf("%lld %lld\n", s1, s2);
    }
    return 0;
}
