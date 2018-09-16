/*************************************************************************
	> File Name:1.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年09月13日 星期四 18时30分47秒
 ************************************************************************/

#include <stdio.h>

int main() {
    char str[100];
    FILE *fout = fopen("/dev/null", "w");
    printf("\n%d\n", printf("%d", 1234));
    printf("\n%d\n", fprintf(fout, "%d", 1234));
    printf("\n%d\n", sprintf(str, "%d", 1234)); 
    for (int i = 0, j = 0; i <= 20; i++) {
        j += sprintf(str + j, "%d", i);
    }
    printf("%s\n", str);
    return 0;
}
