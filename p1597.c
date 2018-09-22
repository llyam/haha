/*************************************************************************
	> File Name:p1597.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年09月21日 星期五 16时11分30秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char ch[15];
    char ss['a'] = ss['b'] = ss['c'] = '0';
    scanf("%s", &ch);
    int n = strlen(ch);
    for (int i = 0, j = 3; i < n; i += 5, j += 5) {
        if (ch[i] == 'a') {
            ss['a'] = ch[j];
        }
        if (ch[i] == 'b') {
            ss['b'] = ch[j];
        }
        if (ch[i] == 'c') {
            ss['c'] = ch[j];
        }
    }
    printf("%c %c %c", ss['a'], ss['b'], ss['c']);
    return 0;
}
