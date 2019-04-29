/*************************************************************************
	> File Name: CODEVS1230.c
	> Author: 
	> Mail: 
	> Created Time: 2019年04月24日 星期三 17时54分05秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int hash[1000015];
void get_hash(int x) {
    int h = x;
    x %= 1000007; 
    while (1) {
        if (hash[x] == -1) {
            hash[x] = h;
            return ;
        }
        if (hash[x] != h) {
            x++;
            if (x == 1000008) x = 0;
        } else {
            return ;
        }
    }
    return ;
}

int find(int x) {
    int num = x;
    x %= 1000007;
    while (1) {
        if (hash[x] == -1) {
            return 0;
        }
        if (hash[x] != num) {
            x++;
            if (x == 1000008) x = 0;
        } else {
            return 1;
        } 
    }
}

int main() { 
    int m, n, x;
    memset(hash, -1, sizeof(hash));
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        get_hash(x);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (find(x) == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
