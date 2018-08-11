/*************************************************************************
    > File Name: ol40.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年08月05日 星期日 09时29分57秒
 ************************************************************************/

#include<stdio.h>
#include<string.h> 

int main() {
	int  a[1010000];
	int l = 0, n, e;
	for(int i = 1; i <= 1000000;) {
		l += 1;
		n = 0;
		int j = l;
		int g = l;
		while(g) {
			g /= 10;
			n++;
		}
		for(e = i + n - 1; e >= i; e--) {
				a[e] = j % 10;
				j /= 10;
		}
		i += n;
	}
	int s = 1, h = 1;
	while(h <= 1000000) {
		s *= a[h];
		h *= 10;
	}
	printf("%d\n", s);
	return 0;
}
