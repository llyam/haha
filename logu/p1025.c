/*************************************************************************
	> File Name: p1025.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月23日 星期六 17时34分30秒
 ************************************************************************/

#include<stdio.h>

int m, n, num = 0;

void find(int z, int x, int y) {
    if (x >= n) {
        if (m - y >= z) num++;
        return ;
    }
    for (int i = z; m > i * (n - x) + y; i++) {
        find(i, x+1, y + i);
    }
}

int main() {
    //int n, m;
    scanf("%d %d", &m, &n);
    find(1, 1, 0);
    printf("%d\n", num);
}
