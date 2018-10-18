/*************************************************************************
	> File Name:1.vector.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年10月11日 星期四 18时56分44秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 //默认申请10
#define DEFAULT_ARG(a, b) ((#a)[0] ? a + 0 : b)
// '+ 0'
#define init(a) __init(DEFAULT_ARG(a, 10))

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

Vector *__init(int n) { //申请空间
    Vector *p = (Vector *)malloc(sizeof(Vector));
    p->data = (int *)malloc(sizeof(int)* n);
    p->size = n;
    p->length = 0;
    return p;
}

int expand(Vector *v) { //扩充空间
    int *p = (int *)realloc(v->data, sizeof(int) * 2 * v->size); //内存泄漏
    if (p == NULL) return 0;
    v->data = p;
    v->size *= 2;
    printf("[%p]expand Vector success, the new size : %d\n",v->data ,v->size);
    return 1;
}

int insert(Vector *v, int value, int ind) { //数据输入
    if (v->length == v->size) {
        if (expand(v) == 0) {
            return 0;
        }
    }
    if (v->length == v->size) return 0;
    if (ind < 0 || ind > v->length) return 0;
    for (int i = v-> length - 1; i >= ind; --i) {
        v->data[i + 1] = v->data[i];
    }
    v->data[ind] = value;
    v->length += 1;
    return 1;
} 

int erase(Vector *v, int ind) {  //删除数据
    if (v->length == 0) return 0;
    if (ind < 0 || ind >= v -> length) return 0;
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
}

int clear(Vector *v) { //清空
    if (v == NULL) {
        return 0;
    }
    free(v -> data);
    free(v);
    return 1;
}

int output(Vector *v) { //输出
    printf("Vector = [");
    for (int i = 0; i < v->length; i++) {
        printf(" %d", v->data[i]);
    }
    printf(" ]\n");
}

int main() {
    Vector *v = init(); //申请空间
    #define max 20
    for (int t = 0; t < max; t++) {
        int op = rand() % 4, ind, value;
        switch (op) {
            case 2: 
            case 3:
            case 0: {
                ind = rand() % (v->length + 3) - 1;    
                value = rand() % 100;    
                printf("insert(%d, %d) to vector %d\n", value, ind, insert(v, value, ind));
                output(v);
            } break;
            case 1: {
                ind = rand() % (v->length + 3) - 1;
                printf("erase(%d) = %d from vector\n", ind, erase(v, ind));
                output(v);
            } break;
        }
    }
    clear(v);
    return 0;
}
