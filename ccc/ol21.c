/*************************************************************************
    > File Name: ol21.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年08月06日 星期一 09时19分13秒
 ************************************************************************/

#include<stdio.h>

int main() {
	for(int i = 1; i <= 10000; i++) {
		if(!isprime[i]) prime[++prime[0]] = i;
		for(int j = 1, p = prime[i]; j <= prime[0]; j++, p = prime[i]) {
			
		}
	}
}
