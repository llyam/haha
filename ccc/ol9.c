/*************************************************************************
    > File Name: ol9.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月30日 星期一 09时58分55秒
 ************************************************************************/

#include<stdio.h>

int main() {
	int a, b, c, s;
	for (int m = 32; m >= 1; m--) {
		for(int n = 1; n < m; n++) {
			a = 2 * n * m;
			b = m * m - n * n;
			c = m * m + n * n;
			if(a + b + c == 1000) {
				s = a * b * c;
				printf("%d\n", s);
				return 0;
			}
		}
	}
}
