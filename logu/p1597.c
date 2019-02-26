/*************************************************************************
	> File Name:p1597.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年11月16日 星期五 20时23分50秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int main() {
    char str['c' + 1];
    str['c'] = '0', str['b'] = '0', str['a'] = '0';
    char name[100], p;
    scanf("%s", name);
    int n = strlen(name);
    for (int i = 0; i < n; i++) {
        if (name[i] == 'a' || name[i] == 'b' || name[i] == 'c') {
            p = name[i];
        }
        if (name[i] == '=' && i + 1 < n) {
            str[p] = name[i + 1];
        }
    }
    for (int i = 'a'; i <= 'c'; i++) {
        if (str[i] == '0') {
            printf("0");
        } else {
        printf("%c", str[i]);
        }
        if(i != 'c' || str[i] == '0')  printf(" ");
    }
    printf("\n");
    return 0;
}
