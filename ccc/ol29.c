/*************************************************************************
    > File Name: ol29.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月31日 星期二 10时39分59秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX_N 10000

int result[MAX_N] = {0};
int is_result[MAX_N] = {0};
int main() {
	int m = 0, n = 1; 
	for(int i = 2; i <= 100; i++) {
		for(int j = 2; j <= 100; j++) {
			is_result[m] = pow(i , j);
			m++;
		}
	}
	for(int i = 0; i < m; i++) {
		for(int j = i + 1; j < m; j++) {
			if(is_result[i] == is_result[j]) {
				n++; 
				break;
			}

		}
	}
	printf("%d", n);
}
