/*************************************************************************
    > File Name: ol36.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月22日 星期日 14时11分18秒
 ************************************************************************/

#include<stdio.h>

int is_palindromic(int x, int n) {
	int temp = x, num = 0;
	while (x) {
		num = num * n + x % n;
		x /= n;
	}
	return temp == num;
}
int main() {
	int ans = 0;
	for (int i = 1; i <= 1000000; i++) {
		if (!is_palindromic(i, 2)) continue;
		if (!is_palindromic(i, 10)) continue;
		ans += i;
	}
	printf("%d\n", ans);
	return 0;
}
