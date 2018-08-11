/*************************************************************************
    > File Name: ol32-2.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月28日 星期六 12时19分50秒
 ************************************************************************/

#include<stdio.h>
int yue(int x, int y) {
	return (y == 0 ? x : yue(y, x % y));
}
int main() {
	int x, y, a, b, c = 1, d = 1;
	for(int i = 1; i < 9; i++) {
		for(int j = i + 1; j < 10; j++) {
			if(j == i) continue;
			for(int z = 1; z < 10; z++) {
				a = i * 10 + z;
				b = z * 10 + j;
				if(b > a) {
					if(b * i == j * a) {
						c *= i / yue(j, i);
						d *= j / yue(j, i);
					}
				}
			}
		}
	}
	printf("%d", d / yue(d, c));
}
