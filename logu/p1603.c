/*************************************************************************
	> File Name:n.p1603.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年11月28日 星期三 16时27分33秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>


int main() {
    int a[6], j = 0;
    char str[1000];
    char ch[21][10] = {"a", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen" , "seventeen" , "eighteen", "nineteen", "twenty"};
    scanf("%[^\n]s", str);
    char *temp = strtok(str, " ");
    while(temp) {
        for (int i = 0; i < 20; i++) {
            if (strcmp(ch[i], temp) == 0) {
                if (i == 0) i = 1;
                a[j++] = i * i % 100;
                break;
            }
        }
        temp = strtok(NULL, " ");
    }
    /*printf("j=%d\n", j);
    for (int i = 0; i < j; i++) {
        printf("%d", a[i]);
    }
    printf("\n");*/
    if (j == 0) {printf("0\n"); return 0;}
    for (int i = j - 2; i > 1; i--) {
        for (int z = 0; z <= i; z++) {
            if (a[z] > a[z + 1]) {
                int tep = a[z];
                a[z] = a[z + 1];
                a[z + 1] = tep;
            }
        }
    }
    //printf("j==%d", j);
    for (int i = 0; i < j; i++) {
        if (i > 0 && a[i] < 10) {
            printf("0");
        }
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
