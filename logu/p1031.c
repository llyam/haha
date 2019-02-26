/*************************************************************************
	> File Name:n.p1031.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年12月22日 星期六 15时13分37秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, pai[100], sum = 0, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pai[i]);
        sum += pai[i];
    }
    int avg = sum / n;
    for (int i = 0; i < n; i++) {
        if (pai[i] > avg) {
            pai[i + 1] += (pai[i] - avg);
            ans++;
        }
        if (pai[i] < avg) {
            pai[i + 1] -= (avg - pai[i]);
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0; 
}
