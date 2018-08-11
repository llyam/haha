/*************************************************************************
    > File Name: ol22.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月30日 星期一 13时00分30秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define MAX_N 5000
char ch[MAX_N][15];
int b[26];

int sort(int *ch, int x) {
	
}

int main() {
	char a[500000];
	char b[40000];
	int i, h = 0, j = -1, x, n, o = 0;
	gets(a);
	x = strlen(a);
	for(int z = 0; z < x; z++) {
		if(a[z] == '"') {
			continue;
		}
		if(a[z] >= 'A' && a[z] <= 'Z') {
			ch[h][j++] = a[z];
		}
		if(a[z] == ',') {
			h++;
			j = -1;
		}
	}
	for(i = 0; i < h - 1; i++) {
		int s = 0, j = 0;
		while(ch[i][j]) {
			s += ch[i][j] - 'A' + 1;
			j++;
		}
		printf("%d  ", s);
	}
	return 0;
}
