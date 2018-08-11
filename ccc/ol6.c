/*************************************************************************
    > File Name: ol6.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月22日 星期日 15时25分23秒
 ************************************************************************/

#include<stdio.h>
int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a % b);
}  // 求最小公约数
int main() {
	int ans = 1;
	for	(int i = 1; i < 20; i++) {
			if (ans % i == 0) continue;
			ans = ans * i / gcd(ans, i);
	}
	printf("%d\n", ans);
	return 0;
