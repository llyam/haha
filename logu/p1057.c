/*************************************************************************
	> File Name: p1057.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月23日 星期六 18时33分23秒
 ************************************************************************/

#include<stdio.h>

int m, n, num = 0;

void find(int x, int y) {
    if (y == n) {
        if (x == 2 || x == m) {
	        num++;
	  //      printf("(%d, %d) Yes\n", x, y);	
	    }	
        return ;
    }
    //printf("(%d, %d)->", x, y);
    if (x == m) find(1, y + 1); 
    else find (x + 1, y + 1);
    if (x == 1) find(m, y + 1);
    else find (x - 1, y + 1);
    return ;
}

int main() {
    scanf("%d %d", &m, &n);
    find(1, 1);
    printf("%d\n", num);
}
