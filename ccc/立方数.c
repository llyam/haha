/*************************************************************************
    > File Name: 立方数.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月28日 星期六 11时46分32秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 100

int main() {
	int left = 1, right = MAX_N, mid = (left + right) / 2, n;
	scanf("%d", &n);
	int l = mid * mid * mid;
	while (left <= right) {
		if(l > n) {
			right = mid - 1;
		} 
		if(l < n) {
			left = mid + 1;
		} 
		if(l == n) {
	 		printf("YES\n" );
			return 0;
		}
		mid = (left + right) / 2;
		l = mid * mid * mid;
	}
	printf("NO\n");
	return 0;
}
