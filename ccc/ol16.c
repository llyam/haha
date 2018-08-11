/*************************************************************************
    > File Name: ol16.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月26日 星期四 18时15分38秒
 ************************************************************************/

/*#include<stdio.h>

int main() {
	int a[1000] = {0};
	a[0] = 1;
	for(int i = 0; i < 1000; i++) {
		for(int j = 0; j < 1000; j++) {
			a[j] *= 2;
		}
		for(int j = 0; j < 1000; j++) {
			if(a[j] > 9) {
				a[j+1]++;
				a[j] = a[j] % 10;
			}
		}
	}
	int s = 0;
	for(int i = 999; i >= 0; i--) {
		printf("%d", a[i]);
		s += a[i];
	}
	printf("%d", s);
}*/
#include<stdio.h>

int main() {
	int num[4000] = {1, 1};
	for (int i = 0; i < 50; i++) {
		for (int j = 1; j <= num[0]; j++) {
			num[j] *= 1024 * 1024;
		}
		for (int j = 1; j <= num[0]; j++) {
			if (num[j] < 10) continue;
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
