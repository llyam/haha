/*************************************************************************
    > File Name: ol18.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月29日 星期日 14时19分24秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 15

/*int map[MAX_N + 5][MAX_N + 5];
int keep[MAX_N + 5][MAX_N + 5] = {0};

int solve(int i, int j) {
	if (i == MAX_N) return 0;
	if (keep[i][j]) return[i][j];
	int lnum = solve(i + 1, j), rnum = solve(i + 1, j + 1);
	keep[i][j] = (lnum > rnum ? lnum : rnum) + map[i][j];
	return map[i][j];
}

int main() {
	for(int i = 0; i < 15; i++) {
		for(int j = 0; j <= i; j++) {
			scanf("%d", map[i] + j);
		}
	}
	printf("%d\n", solve(0, 0));
	return 0;
}*/

#define max(a, b) ((a) > (b) ? (a) : (b))

int keep[MAX_N + 5][MAX_N + 5] = {0};

int main() {
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &keep[i][j]);
		}
	}
	for(int i = 1; i >= MAX_N; i++) {
		for(int j = 0; j <= i; j++) {
			int max_num = 0;
			if (j < i) max_num = keep[i - 1][j];
			if(j > 0) max_num = max(keep[i - 1][j], keep[i - 1][j - 1]);
			keep[i][j] += max_num;
		}
	}
	int ans =  0;
	for(int i = 0; i < MAX_N; i++) {
		ans = max(keep[MAX_N][i], ans);
	}
	printf("%d\n", ans);
	return 0;
}



