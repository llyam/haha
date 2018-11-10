/*************************************************************************
	> File Name:14.hash.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年11月06日 星期二 20时41分54秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//APHash ZobristHash
typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct hashtable {
    Node **data;
    int size;
} hashtable;


Node *init_node (char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str); //
    p->next = head;
    return p;
}

hashtable *init_hashtable (int n) {
    hashtable *h = (hashtable *)malloc(sizeof(hashtable));
    h->size = n << 1;
    h->data = (Node **)calloc(sizeof(Node *) , h->size);
    return h;
}
int BKDRHash(char *str) {
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; i++) {
        hash = hash * seed + str[i];
    }
    return hash & 0x7fffffff;
}
int insert(hashtable *h, char *str) { //拉链头叉法
    int hash = BKDRHash(str); 
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    /*Node *node = init_node(str,NULL);                                 
    int times = 0;
    while (h->data[ind]) { 
        times++;
        ind += times * times;
        ind %= h->size;
    }
    h->data[ind] = node;*/
    return 1;
}

int search(hashtable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while (p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}

void clear_node(Node *node) {
    if(node == NULL) return ;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return ;
}

void clear_hashtable(hashtable *h) {
    if (h == NULL) return ;
    for (int i =0; i < h->size; i++) {
        clear_node(h->data[i]);
    }
    free(h->data);
    free(h);
    return ;
}

int main() {
    int op;
    char str[100];
    hashtable *h = init_hashtable(100);
    while (scanf("%d%s", &op, str) != EOF) {
        switch(op) {
            case 0:{
                printf("insert %s to hash_table\n", str);
                insert(h, str);
            } break;
            case 1:{
                printf("inserch str result = %d\n",  search(h, str));
            }
        }
    }
    return 0;
}
