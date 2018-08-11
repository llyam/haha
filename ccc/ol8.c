/*************************************************************************
    > File Name: ol8.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月24日 星期二 10时56分53秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include"ol8.h"

int main() {
	int64_t p = 1, zero = 0;
	for (int i = 0; num[i]; i++) {
		if (num[i] == '0') {
			zero += 1;
		} else {
			p *= (num[i] - '0');
		}
		if (i >= 13) {
			if (num[i - 13] == '0') {
				zero -= 1;
			} else {
				p /= (num[i - 13] - '0');
			}
		}
		if (zero == 0 && p > ans) ans = p;
	}
	printf("%"PRId64 "\n", ans);
	return 0;
}
