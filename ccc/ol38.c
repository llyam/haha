/*************************************************************************
    > File Name: ol38.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月27日 星期五 15时14分19秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int is_valid(int x) {
	int num[10] = {0};
	int n = 0, digit = 0;
	do {
		n += 1;
		int y = x * n;
		while (y) {
			if (y % 10 == 0) return 0;
			if (num[y % 10]) return 0;
			num[y % 10] = 1;
			y /= 10;
			digit += 1;
		}
	}while (digit < 9);
	if(digit > 9) return 0;
	int ret = 0;
	for(int i = 1; i <= n; i++) {
		int y = x * i;
		ret = ret * (int)pow(10, floor(log10(y)) + 1) + y;
	}
	return ret;
}

int main() {
	int ans = 0;
	for(int i = 0; i < 10000; i++) {
		int temp = is_valid(i);
		if(temp > ans) ans = temp;
	}
	printf("%d\n", ans);
	return 0;
}
