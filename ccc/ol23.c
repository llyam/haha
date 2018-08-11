/*************************************************************************
    > File Name: ol23.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年08月05日 星期日 17时07分26秒
 ************************************************************************/

#include<stdio.h>

int main() {
	int sum = 0;
	int a[28150] = {0};
	int b[28150] = {0};
	for (int i = 2; i <= 28150; i++) {
		for(int j = i * 2; j <= 28150; j += i) {
			a[j] += i;
		}
	}
	for(int i = 1; i <= 28150; i++) {
		if(a[i] <= i) a[i] = 0;
	}
	for(int i = 1; i <= 28150; i++) {
		for(int j = 1; j <= 28150; j++) {
			if((i + j) >= 28150) continue;
			if(a[i] && a[j]) {
				b[i + j] = 1;
			}
		}
	}
	for(int i = 1; i <= 28123; i++) {
		if(!b[i]) {
			sum += i;
		}
	}
	printf("%d\n", sum);
	return 0;
}
