/*************************************************************************
    > File Name: hz3.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月20日 星期五 15时34分55秒
 ************************************************************************/

#include<stdio.h>

int main() {
	int f[3] = {1, 0, 0}, sum = 0, n = 1;
	while (f[(n + 2) % 3] + f[(n + 1) % 3] <= 4000000) {
		f[n % 3] = f[(n + 1) % 3] + f[(n + 2) % 3];
		if((f[(n % 3)] & 1) == 0) sum += f[n % 3];
		n += 1;
	}
	printf("%d\n", sum);
	return 0;
}
