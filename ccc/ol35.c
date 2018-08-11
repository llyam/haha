/*************************************************************************
    > File Name: ol35.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月28日 星期六 09时42分04秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000
int prime[MAX_N] = {0};
int a[6] = {0};

int is_circular(int x) {
	int n = 0;
	while(x) {
		a[n] = x % 10;
		x /= 10;
		n++;
	}
	int z = n - 1;
	for(n = n - 1; n >= 0; n--) {
		int j = z;
		int s = 0;
		for(int i = n; i >= 0; i--) {
			s *= 10; 
			s += a[i];
		}
		for(j; j > n; j--) {
			s *= 10;
			s += a[j];
		}
		if(prime[s] == 1) {
			return 0;
		}
	}
	return 1;
}


int main() {
	int n = 0;
	for(int i = 2; i * i < MAX_N; i++) {
		if(prime[i]) continue;
		for(int j = i * i ; j <= MAX_N; j += i) {
			prime[j] = 1;
		}
	}
	for(int i = 2; i <= MAX_N; i++) {
		if(prime[i]) continue;
		if(is_circular(i)) {
			n++;
		}
	}
	printf("%d\n", n);
	return 0;
}
