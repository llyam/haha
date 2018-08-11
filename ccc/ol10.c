/*************************************************************************
    > File Name: ol10.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月26日 星期四 14时14分01秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX_N 2000000

int prime[MAX_N + 5] = {0};

int main() {
	for (int M = 2; M <= MAX_N; M++) {
		if (!prime[M]) {
			prime[++prime[0]] = M;
		}
		for (int i = 1; i <= prime[0]; i++) {
			if(prime[i] * M > MAX_N) break;
			prime[M * prime[i]] = 1;
			if (M % prime[i] == 0) break;
		}
	}
	int64_t s = 0;
	for (int i = 1; i <= prime[0]; i++) {
		 s += prime[i];
	}
	printf("%" PRId64 "\n", s);
	return 0;
}
