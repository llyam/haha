/*************************************************************************
	> File Name:p1618.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年10月06日 星期六 11时22分23秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void num1(int x, int *a, int y) {
    while(x) {
        a[y] = x % 10;
        x /= 10;
        y++;
    }
}

int num(int x, int y, int z) {
    int a[10];
    num1(x, a, 0);
    num1(y, a, 3);
    num1(z, a, 6);
    sort(a, a + 9);
    for (int i = 0; i < 9; i++) {
        if (a[i] != i+1) return 0;
    }
    return 1;
}

int main() {
    int x, y, z, h, o = 0;
    scanf("%d %d %d", &x, &y, &z);
    for (int i = 100; i <= 999; i++) {
        if (i % x == 0) {
            h = i / x;
        } else {
            continue;
        }
        if (h * y >= 1000) {
           break;
        }
        if (h * z >= 1000) {
            break;
        } 
        if (num(i, h * y, h * z) == 1) {
            printf("%d %d %d\n", i, h * y, h * z);
            o = 1;
        }       
    }
    if  (o == 0) printf("NO!!!\n");
    return 0;
}
