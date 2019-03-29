/*************************************************************************
	> File Name: p1002.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月29日 星期五 19时52分56秒
 ************************************************************************/

#include<stdio.h>

long long int map[21][21] = {0};

int main() {
    int m, n, x, y;
    scanf("%d %d %d %d", &m, &n, &x, &y);
    map[0][0] = 1;
    map[x][y] = -1;
    if (x - 2 >= 0) {
        if (y - 1 >= 0) { 
      //      printf("(%d %d) = 1  ", x - 2, y - 1);
            map[x - 2][y - 1] = -1;
        }
        if (y + 1 <= n) { 
        //    printf("(%d %d) = 1\n", x - 2, y + 1);
            map[x - 2][y + 1] = -1;
        }
    } 
    if (x - 1 >= 0) {
        if (y - 2 >= 0) {
          //  printf("(%d %d) = 1  ", x - 1, y - 2);
            map[x - 1][y - 2] = -1;
        }
        if (y + 2 <= n) {
            //printf("(%d %d) = 1\n", x - 1, y + 2);
            map[x - 1][y + 2] = -1;
        }
    }
    if (x + 2 <= m) {
        if (y - 1 >= 0) {
            //printf("(%d %d) = 1  ", x + 2, y - 1);
            map[x + 2][y - 1] = -1;
        }
        if (y + 1 <= n) {
            map[x + 2][y + 1] = -1;
            //printf("(%d %d) = 1\n", x + 2, y + 1);
        }
    }
    if (x + 1 <= m) {
        if (y - 2 >= 0) {
            //printf("(%d %d) = 1  ", x + 1, y - 2);
            map[x + 1][y - 2] = -1;
        }
        if (y + 2 <= n) {
            map[x + 1][y + 2] = -1;
            //printf("(%d %d) = 1\n", x + 1, y + 2);
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (map[i][j] == -1) continue;
            if (i - 1 >= 0) {
                if (map[i - 1][j] >= 0)
                map[i][j] += map[i - 1][j]; 
            }
            if (j - 1 >= 0) {
                if (map[i][j - 1] >= 0)
                map[i][j] += map[i][j - 1];
            }
        }
    }
    printf("%lld\n", map[m][n]);
}
