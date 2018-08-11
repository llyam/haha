/*************************************************************************
    > File Name: ol30.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月22日 星期日 10时49分01秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

#define MAX_N 354294

int is_equal(int x) {
		int temp = x, sum = 0;
		while (x) {
			sum += (int)pow(x % 10, 5);
			x /= 10;
		}
		return sum == temp;
}
int main() {
	int ans = 0;
	for (int i = 2; i < MAX_N; i++) {
		if (!is_equal(i)) continue;
		ans += i;
	}
	printf("%d\n", ans);
	return 0;
}
