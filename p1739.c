/*************************************************************************
	> File Name:n.p1739.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年12月05日 星期三 16时27分36秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Queue {
    char *data;
    int length, head, tail;
}Queue;

Queue *init() {
    //printf("init\n");
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (char *)malloc(sizeof(char) * 256);
    q->length = 0;
    q->head = 0;
    q->tail = -1;
    return q;
}

void push(Queue *q, char x) {
    q->tail++;
    q->data[q->tail] = x;
    return ;
}

char top(Queue *q) {
    return q->data[q->head];
}

void pop(Queue *q) {
    q->head++;
    return ;
}

void output(Queue *q) {
    int i = 0;
    while (q->head != q->tail) {
        if (top(q) == '(') i++;
        else if (top(q) == ')') i--;
        if (i < 0) {printf("NO\n"); return ;}
        pop(q);
    } 
    if (i != 0) printf("NO\n");
    else printf("YES\n");
    return ;
}

void clear(Queue *q) {
    free(q->data);
    free(q);
    return ;
}

int main() {
    Queue *q = init();
    char str[256];
    scanf("%s", str);
    for (int i = 0; str[i] != '@' || i < strlen(str); i++) {
        push(q, str[i]);
    }
    output(q);
    clear(q);
    return 0;
}
