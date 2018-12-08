/*************************************************************************
	> File Name:p1030.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年11月06日 星期二 17时33分03秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
}Node;



int main() {
    char ch1[9], ch2[9];
    scanf("%s", ch1);
    scanf("%s", ch2);
    int n2 = strlen(ch2);
    int n1 = strlen(ch1);
    char x = ch2[n2 - 1];
    for (int i = 0; i < n1; i++) {
        if (x == ch1[i]) {
            int n = i;
            break;    
        }
    }
    Node *l = init(n + 1);
    Node *r = init(n1 - n);
    for (int i = 0; i < n; i++) {
        push(ch1[i], l);
    }
    for (int i = n + 1;i < n1; i++) {
        push(ch[i], r);
    }
    return 0;
}
