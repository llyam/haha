/*************************************************************************
	> File Name:5.binary_tree.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年10月23日 星期二 19时17分18秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
        
}  Node;


int init() {
        NOde *p = (Node *) malloc(sizeof (Node));
    p->data = data;
    p->lchild = p->rchild = NULL;
    
    
    return 0;
}

void clear (Node *root) {
    if (node == NULL) return ;
    clear(node -> lchild);
    clear(node -> rchild);
    free(node);
    return ;
}


Node *build() {
    Node *root = init(1);
    root = lchild = init(2);
    root -> rchild = init (3);
    root -> lchild->lchild  = init(6);
    root -> rchild -> rchild = init(7);
    root -> lchild -> lchild -> lchild = init(12);
    root -> rchild -> lchild = init(5);
    root -> rchild -> rchild = init(9);
    root -> rchild -> lchild -> lchild = init(10);
    root -> rchild -> lchild -> rchild = init(11);
    return root;
}

int height_tree (Node *root) {
    if ( root == NULL) return 0;
    int lh = height_tree (root -> lchild), rh = height_tree(root->rchild);
    return (lh > rh ? lh : rh) + 1;
}

void preorder(Node *root) {
    if (root == NULL) return ;
    printf("%d", root -> data);
    preorder(root->lchild);
    preorder(root->rchild);
    return ;
}

void inorder (Node *root) {
    if(root == NULL) return ;
    inorder (root -> lchild);
    printf("%d", root ->data);
    inorder (root -> rchild);
    return ;
}



int main() {
    Node *root = build ();
    printf("height tree = %d\n", height_tree(root));
    preorder(root);
    inorder(roott);
    postorder(root);
    clear(root);
}
