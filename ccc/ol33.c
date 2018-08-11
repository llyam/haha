/*************************************************************************
    > File Name: ol33.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月22日 星期日 11时45分25秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

#define MAX_N 2540160
int haha(int x) {
	int t = x, s = 0, l, o;
	while (x) {
		l = x % 10;
		o = 1;
		for (int i = 1; i <= l; i++) {
			o *= i;
		}
		s += o;
		x /= 10;
	}
	return s == t; 
}
int main() {
	int ans = 0;
	for(int i = 3; i < MAX_N; i++) {
		if(!haha(i)) continue;
		ans += i;
	}
	printf("%d\n", ans);
	return 0;
}
