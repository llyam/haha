/*************************************************************************
	> File Name:p1068.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年11月27日 星期二 16时37分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define swap(a, b) {\
    __typeof(a) _temp = a; a = b; b = _temp;\
}
typedef struct Data {
    int x, y;
}Data;

typedef struct Node {
    Data *data;
    int length, size;
} Node;

Node *init(int x) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = (Data *)malloc(sizeof(Data) * (x + 1));
    p->length = -1;
    p->size = x;
}

void push(Data data, Node *p) {
    p->length++;
    p->data[p->length] = data;
    return ;
}

int main() {
    Node *p;
    int m, n;
    scanf("%d %d", &m, &n);
    Data q;
    p = init(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &q.x, &q.y);
        push(q, p);
    }
    for (int i = m - 1; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            if (p->data[j].y > p->data[j - 1].y) {
                swap(p->data[j], p->data[j - 1]);
            }
            if (p->data[j].y == p->data[j - 1].y) {
                if (p->data[j - 1].x > p->data[j].x) swap(p->data[j].x, p->data[j - 1].x);
            }
        }
    }
    int z = (int)floor(n * 1.5);
    while (p->data[z - 1].y == p->data[z].y) z++;
    printf("%d %d\n", p->data[z - 1].y, z);
    for (int i = 0; i < z; i++) {
        printf("%d %d\n", p->data[i].x, p->data[i].y);
    }
    return 0;
}
