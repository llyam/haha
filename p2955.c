/*************************************************************************
	> File Name:p2955.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年09月09日 星期日 14时04分24秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int main() {
    int n, s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char a[100];
        scanf("%s", a);
        s=strlen(a);
        if ( (a[s-1]-'0')%2==0) {
            printf("even\n");
        } else {
            printf("odd\n");
        }
    }
return 0;

#include <stdio.h>

int main() {
    int a, b, c, d, e, sum = 0;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
return 0;
}}
