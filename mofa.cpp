/*************************************************************************
	> File Name: mofa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月16日 星期六 14时17分43秒
 ************************************************************************/

#include<iostream>
#include<inttypes.h>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int vis[32] = {0};

int check(uint32_t x) {
    int num[32] = {0};
    for (int i = 0; i < 32; i++) {
        num[(x << i) >> 27] += 1;
        if (num[(x << i) >> 27] == 2) return 0;
    }
    /*for (int i = 0; i < 32; i++) {
        printf("%d -> %d\n", i, (x >> i) << 27);
    }*/
    for (int i = 0; i < 32; i++) {
        num[(x << i) >> 27] = i;
    }
    printf("int arr[32]={\n");
    for (int i = 0; i < 32; i++) {
        printf("%d\n", num[i]);
        if (i + 1 % 16 == 0) printf("\n");
    }
    printf("}\n");
    return 1;
}

uint32_t find(uint32_t x, int k) {
    if (k == 0) {
        if (check(x)) return x;
        //printf("0x%08X\n", x);
        return -1;
    }
    uint32_t ans = 0;
    int val = x & 0xf;
    if (vis[(val << 1) | 1] == 0)  {
        vis[val << 1 | 1] = 1;
        ans = find(x << 1 | 1, k - 1);
        //if (ans) return ans;
        vis[val << 1 | 1] = 0;
    } 
    if (vis[val << 1] == 0) {
        vis[val << 1] = 1;
        ans = find(x << 1, k -1);
        //if (ans) return ans;
        vis[val << 1] = 0;
    }
    return 0;
}

int main() {
    uint32_t x;
    for (int i = 0; i < 31; i++) {
        vis[i] = 1;
        //if (x = find(i, 27)) printf("%X\n", x);
        find(i,  27);
        vis[i] = 0;
    }
}
