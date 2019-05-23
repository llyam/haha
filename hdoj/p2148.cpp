/*************************************************************************
	> File Name: p2148.c
	> Author: 
	> Mail: 
	> Created Time: 2019年05月23日 星期四 18时57分58秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef struct Node{
    int cheng, nu;
}Node;

bool cmp(Node x, Node y) {
    if (x.cheng == y.cheng && x.nu < y.nu) return true;
    if (x.cheng > y.cheng) return true;
    return false;
    //return x.cheng < y.cheng;
}
void show (Node *x, int z) {
    for (int i = 1; i <= z; i++) {
        printf ("[%d %d] ", x[i].cheng, x[i].nu);
    }
    printf("\n");
}

int main() {
    int m, n;
    scanf("%d", &n);
    while (n--) {
        int x, y, k;
        Node num[1005] = {0};
        scanf("%d %d", &x, &y);
        if (y > x) {
            printf("0\n");
            continue;
        }
        for (int i = 1; i <= x; i++) {
            scanf("%d", &num[i].cheng);
            num[i].nu = i;
            if (i == y) k = num[i].cheng;
        }
        sort(num + 1, num + x + 1, cmp);
        int sum = 0;
        show(num, x);
        for (int i = 1; i <= x; i++) {
            if (num[i].cheng == k) {
                printf("%d\n", i - 1);
                break;
            }
        }
    }
    return 0;
}
