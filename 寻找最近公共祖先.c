/*************************************************************************
	> File Name:test1.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年10月23日 星期二 19时39分24秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h> 
#define max 1000
#define k 20
struct Edge{
    int v, n;
} g[max << 1];

int head[max + 5] = {0}, cnt  = 0;

inline void add(int a, int b) {
    g[++cnt].v = b;
    g[cnt].n = head[a];
    head[a] = cnt;
}
//ges[i][j] i点往上走 2^j 步 所能到达祖先结点编号
int gas[max][k] = {0}, dep[max] = {0};
//0结点不用 
void dfs(int u, int father) {
    gas[u][0] = father;
    dep[u] = dep[father] + 1;
    for (int i = 1; i < k ;i++) {
        gas[u][i] = gas[gas[u][i - 1]][i - 1];
    }
    for (int i = head[u] ; i; i = g[i].n) {
        if (g[i].v == father) continue;
        dfs(g[i].v, u);
    }
    return ;
}

int lca(int a, int b) {
    if (dep[b] < dep[a]) {//交换a ，b
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int l = dep[b] - dep[a];
    for (int i = 0; i < k; i++) {
    //对齐的操作
    //l的相关二进制
        if ((l & (1 << i))) b = gas[b][i];//倍增
    } // !
    if (a == b) return a;
    for (int i = k - 1; i >= 0; i--) {//往上走
        if (gas[a][i] != gas[b][i]) a = gas[a][i], b = gas[b][i];
    }
    return gas[a][0];
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { 
        scanf("%d %d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    while (scanf("%d %d", &a, &b) != EOF) {
        printf("lca(a, b) = %d , a-> b = %d\n", lca(a, b), dep[a] +dep[b] - 2 * dep[lca(a, b)]);
    }
    return 0;
}
