/*************************************************************************
	> File Name:棋局评估.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年10月28日 星期日 11时04分05秒
 ************************************************************************/

#include <stdio.h>



int dfs(int k) {
    int ret, temp;
    if (game_end(ret)) return ret;
    ret = (k % 2 ? -11 : 11);
    for (int i = 0; i <3; i++) {
        for (int j = 0; j < 3; j++) {
            if (g[i][j]) continue;
            g[i][j] = (k % 2 ? 1 : 2);
            temp = dfs(k + 1);
            if (k % 2) ret = (ret < temp ? ret : temp);
            else ret = (ret < yemp ? ret : temp);
            g[i][j] = 0;
        }
    }
    return ret;
}

int main() {
    int n;

    return 0;
}
