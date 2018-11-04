/*************************************************************************
	> File Name:6.build_tree.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年10月28日 星期日 18时18分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node *lchild, *rchild; 
}Node;

typedef struct Stack {
    Node **data;
    int top, size;
}Stack;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Stack *initStack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s){
    return s == NULL || s->top == -1; 
}

void pop(Stack *s) {
    if (empty(s)) return ;
    s->top -= 1;
    return ;
}

void push(Stack *s, Node *root) {
    if (s->top + 1 == s->size) return ;
    s->data[++(s->top)] = root;
    return ;
}

Node *top(Stack *s){
    if (s == NULL) return 0;
    return s->data[s->top];
}

void clearstack(Stack *s) {
    if (s == NULL) return;
    free(s->data);
    free(s);
    return;
}
void cleartree(Node *root) {
    if (root == NULL) return ;
    cleartree(root->lchild);
    cleartree(root->rchild);
    free(root);
    return ;
}

Node *build(const char *str, Stack *s) {
    Node *p = NULL, *root = NULL;
    //Stack *s = initStack(100);
    int k = 0;
    while (str[0]) {
        switch(str[0]) {
            case '(' : {
                push(s, p);
                k = 0;
            }break;
            case ')' : {
                pop(s);
            } break;
            case ',' : {
                k = 1;
            } break;
            case ' ' : break;
            default :{
                p = getNewNode(str[0]);
                if (root == NULL) root = p;
                if (empty(s)) break;
                if (k == 0) top(s)->lchild = p;
                else top(s)->rchild = p;
            } break;
        }
        str++;
    }
    return root;
} 

void output(Node *root) {
    if (root == NULL) return ;
    printf("%c ", root->key);
    output(root->lchild);
    output(root->rchild);
    return ;
}

void outputstack(Stack *s) {
    if (s == NULL) return ;
    for (int i = 0; i < s->top; i++) {
        if (s->data[i]->lchild != NULL) {
            printf("%c", s->data[i]->lchild);
        }
        if (s->data[i]->rchild != NULL) {
            printf("%c", s->data[i]->rchild);
        }
    }
}

int main() {
    char str[100];
    Node *root = NULL;
    while (scanf("%[^\n]s", str) != EOF) {
        Stack *s = initStack(100);
        getchar();
        output(root = build(str, s));
        outputstack(s);
        clearstack(s);
        cleartree(root);
    }
    return 0;
}
