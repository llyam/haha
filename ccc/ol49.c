/*************************************************************************
    > File Name: ol49.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年08月05日 星期日 10时21分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

#define MAX_N 100000
int prime[MAX_N + 5] = {
	0
};
int is_prime[MAX_N + 5] = {
	0
};

int check(int x, int n) {
	int num1[5] = {0}, num2[5] = {0}, num3[5] = {0};
	int a = prime[x], b = prime[x] + n, c = prime[x] + 2 * n, m = 0;
	while(m++ < 4) {
		num1[m] = a % 10;
		num2[m] = b % 10;
		num3[m] = c % 10;
		a /= 10, b /= 10, c /= 10;
	}
	sort(num1, num1 + 5);
	sort(num2, num2 + 5);
	sort(num3, num3 + 5);
	while(--m >= 1) {
		if (num1[m] != num3[m] || num2[m] != num3[m] || num1[m] != num2[m]) return 0;
	}
	return 1;
}

int main() {
	int k = 0;
	for(int i = 2; i <= MAX_N; i++) {
		if(!is_prime[i]) prime[++prime[0]] = i;
		if(prime[prime[0]] > 1000 && !k) k = prime[0];
		for(int j = 1; j <= prime[0]; j++) {
			if(prime[j] * i >= MAX_N) break;
			is_prime[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	for(int i = k; prime[i] < 10000; i++) {
		for(int n = 1; prime[i] + 2 * n < 10000; n++) {
			if(is_prime[prime[i] + 2 * n] || is_prime[prime[i] + n]) continue;
			if(check(i, n)) printf("%d %d %d\n", prime[i], prime[i] + n, prime[i] + 2 * n);
		}
	}
	
}
