/*************************************************************************
	> File Name:url映射.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年10月28日 星期日 09时42分10秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Vector {
    char **data;
    int length, cnt;
    char *name;
} Vector;

Vector *init(int n) {
    Vector *v = (Vector *)malloc (sizeof(Vector));
    v->data = (char **)malloc (sizeof(char *) * n);
    v->length = n;
    v->cnt = -1;
    return v;
}

void clear(Vector *v) {
    if (v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

void push(Vector *v, const char *str) {
    if (v == NULL) return ;
    v->cnt += 1;
    v->data[v->cnt] = strdup(str);
    return ;
}

void output(Vector *v) {
    for (int i= 0; i < v->cnt; i++) {
        i && printf(" | ");
        printf("%s", v->data[i]);
    }
    printf("\n");
}

Vector *getVector(char *str) {
    int n = 0;
    for (int i = 0; str[i]; i++) {
        n += str[i] == '/';
    }
    Vector *vec = init(2 * n + 1);
    push(vec, "/");
    str++;
    char *now = str;
    while (now[0]) {
        while (str[0] && str[0] != '/') str++;
        if (str[0] == '/') {
            str[0] = 0;
            push(vec, now);
            push(vec, "/");
            str++;
        } else {
            push(vec, now);
        }
        now = str;
    }
    return vec;
}

int getType(const char *str) {
    if (strcmp(str, "<int>") == 0) return 1;
    if (strcmp(str, "<str>") == 0) return 2;
    if (strcmp(str, "<path>") == 0) return 3;
    return 0;
}

int match_node (const char *p, const char *t) {
        int type = getType(p);
        switch (type) {
            case 1: {
                for (int i = 0; t[i]; i++) {
                    if (t[i] < '0'|| t[i] > '9') return -1;
                }
		        return type;
            } break;
            case 2: 
            case 3: return type;
            case 0: return strcmp(p, t) == 0 ? type : -1;
        }
        return -1;
}

int match(Vector *v1, Vector *v2) {
    if (v1 -> cnt > v2 -> cnt) return 0;
    for (int i = 0; i < v1->cnt; i++) {
        int type;
        if ((type = match_node(v1->data[i], v2->data[i])) == -1) return 0;
        if (type == 3) return 1;
    }
    return v1 -> cnt == v2 -> cnt;
}

Vector *rules[105];

int main() {
    char str[1000];
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {    
        scanf("%s", str);
        rules[i] = getVector(str);
        scanf("%s", str);
        rules[i]->name = strdup(str);
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", str);
        int j = 0;
        Vector *now = getVector(str);
        while (j < n && match(rules[j], now) == 0) ++j;
        if (j == n) {
            printf("404\n");
        } else {
            printf("%s", rules[j] -> name);
        }
    }
    return 0;
}
