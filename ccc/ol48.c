/*************************************************************************
    > File Name: ol48.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年08月05日 星期日 18时25分48秒
 ************************************************************************/

#include<stdio.h>


int main() {
	for(int i = 1; i <= 1000; i++) {
		for (int z = 1; z <= i; z++) {
			for(int k = 1; !num[k]; k++) num[k] *= i;
			for(int j = 1; j <= num[0]; j++) {
				if(num[j] < 10) continue;
				num[j + 1] += num[j] / 10;
				num[j] %= 10;
				num[0] += (j == num[0]);
			}
		}
		for(int j = 1; j < num[0]; j++) {
			number[num[0] - j] += num[j];
		}
	}
	
}
