/*************************************************************************
    > File Name: ol12.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月29日 星期日 10时10分19秒
 ************************************************************************/
#include<stdio.h>
	
#define MAX_N 10000

int dnum[MAX_N + 5] = {0};
int prime[MAX_N + 5] = {0};
int mnum[MAX_N + 5] = {0};//最小素因子数

int init() {
	for(int i = 2; i < MAX_N; i++) {
		if (!prime(i)) {
			prime[++prime[0]] = i;
			dnum[i] = 2;
			mnum[i] = 1;
		}
		for(int j = 1; j <= prime[0]; j++) {
			if (i * prime[j] > MAX_N) break;
			prime[i % prime[j]] = 1;
			if (i % prime[j] == 0) {
				mnum[i * prime[j]] = mnum[i] + 1;
				dnum[i * prime[j]] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
				break;
			} else {
				mnum[i * prime[j]] = 1;
				dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
			}
		}
	}
	return ;
}

int facor_nums(int n) {
		
}

int main() {
			
}
