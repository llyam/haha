/*************************************************************************
	> File Name:2.舞伴.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年12月19日 星期三 18时44分45秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    char **data;
    int head, tail, length, cnt;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->length = n;
    q->cnt = 0;
    q->head = 0;
    q->tail = -1;
    q->data = (char **)malloc(sizeof(char *) * n);
    return q;
}

void push(Queue *q, char *x) {
    if (q->cnt == q->length) return ;
    q->tail += 1;
    q->data[q->tail] = x;
    return ;
}

char *top(Queue *q) {
    if (q->head > q->tail) return 0;
    return q->data[q->head];
}

void next(Queue *q) {
    if (q->head > q->tail) return ;
    q->head += 1;
    if (q->head >= q->length) q->head -= q->length;
    q->cnt -= 1;
    return ;
}

int main() {
    int n1, n2, x;
    char *man, *woman;
    printf("请输入男生人数：\n");
    scanf("%d", &n1);
    Queue *q1 = init(n1);
    printf("请输入女生人数：\n");
    scanf("%d", &n2);
    Queue *q2 = init(n2);
    printf("请输入%d个男生的名字：\n", n1);
    for (int i = 0; i < n1; i++) {
        man = (char *)malloc(sizeof(char) * 100);
        scanf("%s", man);
        push(q1, man);
    }
    printf("请输入%d个女生的名字：\n", n2);
    for (int i = 0; i < n2; i++) {
        woman = (char *)malloc(sizeof(char *) * 100);
        scanf("%s", woman);
        push(q2, woman);
    }
    int max;
    printf("输入“1”进行配对，“2”退出\n");
    while(scanf("%d", &x) != EOF) {
        switch(x) {
            case 1:{
                do {
                    printf("[man:%s]---[woman:%s]\n", top(q1), top(q2));
                    next(q1);
                    next(q2);
                } while ((q1->head != 0) && (q2->head != 0));
                if (q1->head == 0 && q2->head == 0) {printf("重复上面的配对规则！\n");}
                else if (q1->head == 0) {printf("男生为空！\n");}
                else if (q2->head == 0) {printf("女生为空！\n");}
                printf("输入“1”继续进行配对，“2”退出\n");
            } break;
            case 2:{
                free(q1->data);
                free(q1);
                free(q2->data);
                free(q2);
                free(woman);
                free(man);
                return 0;
            } break;
            default:{
                printf("重新输入！\n");
                break;
            }
        }
    }
    return 0;
}
