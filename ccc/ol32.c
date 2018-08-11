/*************************************************************************
    > File Name: ol32.c
    > Author: ma6174 
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月27日 星期五 14时25分48秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

#define MAX_N 10000

int figit(int x) {
	return floor(log10(x)) + 1;
}

int get_figit(int a, int *num) {
	while(a) {
		if (a == 0) return 0;
		if (a % 10 == 0) return 0;
		
		
	}
	return 1;
}

int is_valid(int a, int b, int c) {
	int num[10] = {0};
	if(!get_digit(a, num)) return 0;
	if(!get_digit(b, num)) return 0;
	if(!get_digit(c, num)) return 0;
}

int valid[MAX_N] = {0};

int  main() {
	int ans = 0;
	for (int a = 2; digit(a) + digit(a) +digit(a * a) <= 9; a++ ) {
		for (int b = a + 1; digit(a) + digit(b) + digit(a * b) <= 9; b++) {
			if(digit(a) + digit(b) + digit(a * b) < 9) contunue;
			if(is_valid(a, b, a * b)) {
				ans += a * b * (1 - valid[a * b]);
				valid[a * b] = 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
