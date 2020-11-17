/*************************************************************************
	> File Name:2.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年09月13日 星期四 19时12分32秒
 ************************************************************************/

#include <stdio.h>

int main() {
    char str[100];
    scanf("%[^\n]s", str);
    int n = printf("%s", str);
    printf("\n%d\n", n);
    return 0;
}
