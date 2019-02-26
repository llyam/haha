/*************************************************************************
	> File Name:huffman.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年10月29日 星期一 18时57分56秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct  Node {
    int key, freq;
    struct Node *lchild, *rchild;
} Node;

Node *getnewnode (int key, int freq) {  // 
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int swap_node(Node **p, Node **q) {
    Node *temp = *p;
    *p = *q;
    *q = temp;
    return 1;
}

Node *build_huffman(Node **arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        //int ind1 = arr[0]->freq > arr[1]->freq;
        //int ind2 = arr[0]->freq <= arr[1]->freq;
        for (int j = 0; j < n - i - 2; j++) {
            if (arr[j]->freq < arr[n - 1 - i]->freq) {
                swap_node(arr + j, arr + n - i - 1);
            }
            if (arr[j]->freq < arr[n - 2 - i]->freq) {
                swap_node(arr + j, arr + n - i - 2);
            }
        }
        Node *temp = getnewnode(0, arr[n - i - 1]->freq + arr[n - i - 2]->freq);
        temp->lchild = arr[n - 1 - i];
        temp->rchild = arr[n - 2 - i];
        arr[n - i - 2] = temp;
    }
    return arr[0];
}

void extract_code(Node *root, char (*code)[20], int k, char *buff) {
    buff[k] = 0;
    if (root->key) {
        strcpy(code[root->key], buff);
        return ;
    }
    buff[k] = '0';
    extract_code(root->lchild, code, k + 1, buff);
    buff[k] = '1';
    extract_code(root->rchild, code, k + 1, buff);
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    Node **arr = (Node **)malloc(sizeof(Node *) * n);
    Node *root;
    for (int i = 0; i < n; i++) {
        char key[10];
        int freq;
        scanf("%s%d", key, &freq);  //a : 123
        arr[i] = getnewnode(key[0], freq);
    }
    root = build_huffman(arr, n);
    char code[256][20] = {0}, buff[20];
    extract_code(root, code, 0, buff); 
    for (int i = 0; i < 256; i++) {
        if (code[i][0] == 0) continue;
        printf("%c : %s\n", i, code[i]);
    }
    return 0;
}
