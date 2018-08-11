/*************************************************************************
    > File Name: ol20.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月29日 星期日 18时34分18秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 200

int main() {
	int num[MAX_N] = {1, 1};
    for (int i = 1; i <= 100; i++) {
		for(int j = 1; j <= num[0]; j++) {
			num[j] *= i;
		}
		for(int j = 1; j <= num[0]; j++) {
			if(num[j] < 10) continue;
			num[j + 1] += num[j] / 10;
			num[j] %= 10;
			num[0] += (j == num[0]);
		}
	} 
	int ans = 0;
	for (int i = 1; i <= num[0]; i++) {
		ans += num[i];
	}
	printf("%d\n", ans);
	return 0;
}
