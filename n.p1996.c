/*************************************************************************
	> File Name:n.p1996.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年11月30日 星期五 19时42分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int x;
    struct List *next;
}List;

typedef struct Link {
    int length;
    List head;
}Link;

Link *init() {
    Link *p = (Link *)malloc(sizeof(Link));
    p->length = 0;
    p->head.next = NULL;
    return p;
}
List *getnewnode(int x) {
    List *p = (List *)malloc(sizeof(List));
    p->x = x;
    //printf("%d", p->x);
    p->next = NULL;
    return p;
}

void push(Link *p , int x) {
    List *q = &(p->head);
    int n = p->length;
    while (n--) {
        q = q->next;
    }
    List *_new = getnewnode(x);
    q->next = _new;
    p->length++;
    return ;
}

void top(List *p) {
    printf("%d ", p->x);
    return ;
}

int pop(List *p) {
    if (p->next->x == p->x) return 0;
    List *q = p;
    q = q->next;
    p->next = p->next->next;
    free(q);
    return 1;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    Link *p = init();
    List *q, *h, *o, *t;
    for (int i = 0; i < x; i++) {
        push(p, i + 1);
    }
    h = &(p->head);
    q = &(p->head);
    q = q->next;
    o = &(p->head);
    while (h->next != NULL) {
        h = h->next;
    }
    h->next = o->next;
    /*for (int i = 0; i < 30; i++) {
        printf("%d\n", q->x);
        q = q->next;
    }*/
    for (int i = 0; i < y - 2; i++) {
        q = q->next;
    }
    while (1) {
        t = q;
        top(t->next);
        if (pop(t) == 0) {
            //top(t);
            free(t->next);
            printf("\n");
            return 0;
        }
        for (int i = 0; i < y - 1; i++) {
            q = q->next;
        }
    }
    return 0;
}
