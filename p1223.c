/*************************************************************************
	> File Name:n.p1223.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年12月06日 星期四 19时03分37秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {\
    __typeof(a) _temp = a; a = b; b = _temp;\
}

typedef struct Node {
    int x, y;
} Node;

int main() {
    int n;
    scanf("%d", &n);
    Node x[n+1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i].x);
        x[i].y = i;
    }
    double sum = 0;
    for (int i = n; i > 0; i--) {
        for (int j = 1; j < i; j++) {
            if (x[j].x < x[j - 1].x) {
                swap(x[j], x[j-1]);
            }
            sum += x[j - 1].x;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", x[i].y + 1);
        i == n - 1 | printf(" ");
        //sum += x[i].x /** (n - i)*/;
    }
    printf("\n%.2f\n", sum / n);
    return 0;
}
