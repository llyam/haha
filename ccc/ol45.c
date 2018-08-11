/*************************************************************************
    > File Name: ol45.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月29日 星期日 09时49分39秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

typedef int64_t int1;


int1 triangle(int1 n) {
	return n * (n + 1) / 2;
}

int1 pentagonal(int1 n) {
	return n * (3 * n - 1) / 2;
}

int1 hexagonal(int1 n) {
	return n * (2 * n - 1);
}

int1 binary_search(int1 (*num)(int1), int1 n, int x)  {
	int1 head = 0, tail = n - 1, mid;
	while (head <= tail) {
		mid = (head + tail) >> 1;
		if(num(mid) == x) return mid;
		if(num(mid > x)) tail = mid - 1;
		else head = mid + 1;
	}
	return -1;
}

int main() {
	int1 n = 144;
	while (binary_search(pentagonal, 2 * n, hexagonal(n) == -1)) ++n;
	printf("%" PRId64 "\n", hexagonal(n));
	return 0;
}
