/*************************************************************************
    > File Name: ol37.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月28日 星期六 10时49分52秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 1000000

int prime[MAX_N] = {0};

int truncatable(int x) {
	int a[100] = {0};
	int h = x, n = 0;
	while(h) {
		a[n] = h % 10;
		h /= 10;
		n++;
		if(prime[h]) return 0;
	}
	for(int i = n - 2; i >= 0; i--) {
		int s = 0;
		for(int j = i; j >= 0; j--) {
			s *= 10;
			s += a[j];
		}
		if(prime[s]) return 0;
	}
	return 1;
}
int main() {
	int s = 0, n = 0;
	prime[1] = 1;
	for(int i = 2; i * i <= MAX_N; i++) {
		if(prime[i]) continue;
		for(int j = i * i; j <= MAX_N; j += i) {
			prime[j] = 1;
		}
	}
	for(int i = 10; i <= MAX_N; i++) {
		if(prime[i]) continue;
		if(truncatable(i)) {
		 	n++;
			s += i;
			printf("%d\n", i);
		}
		if(n == 11) break; 
	}
	printf("%d\n", s);
}
