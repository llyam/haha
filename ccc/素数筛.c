/*************************************************************************
    > File Name: 素数筛.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月24日 星期二 17时35分10秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 10000

int main() {
	for(int i = 2; i * i <= MAX_N; i++) {
		if(prime[i]) continue;
		for(int j = i; j <= MiAX_N; j += i) {
			if(primr[j]) continue;
			prime[i] =  i;
		}
	}
	for(int i = 2; i <= MAX_N; i++) {
		if(primr[i]) continue;
		prime[i] = i;
	}
	for(int i = 2; i <= MAX_N; i++) {
		printf("%d max primr is %d\n", i, prime[i]);
	}
	return 0;
}
