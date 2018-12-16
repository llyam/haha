/*************************************************************************
	> File Name:p1098.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年12月16日 星期日 19时36分02秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void prit(char start, char end, int a, int b, int c) {
    char num;
    //printf("[a = %d]", a);
    if (c == 3) num = '*';
    if (b == 2) {
        for (int i = end - 1; i > start; i--) {
            //printf("%c\n", i);
            for (int j = 0; j < a; j++) {
                if (num == '*') {
                    printf("%c", num);
                } else {
                    if (c == 2 && start >= 97 && end <= 122) {
                        printf("%c", i - 32);
                        continue;
                    } else if (c == 1 && start >= 65 && end <= 90) {
                        printf("%c", i + 32);
                        continue;
                    } else {
                        printf("%c", i);
                    }
                } 
            }
        }
    } else {
        for (int i = start + 1; i < end; i++) {
            //printf("%c\n", i);
            for (int j = 0; j < a; j++) {
                //printf("%c", i);
                //printf("[j=%d]", j);
                if(num == '*') {
                    printf("%c", num);
                } else {
                    if (c == 2 && (start >= 97 && end <= 122)) {
                        printf("%c", i - 32);
                        continue;
                    } else if (c == 1 && (start >= 65 && end <= 90)) {
                        printf("%c", i + 32);
                        continue;
                    } else {  
                        printf("%c", i);
                    }
                }     
            } 
        }
    }
}

int main() {
    int a, b, c;
    char *str;
    str = (char *)malloc(sizeof(char) * 10000);
    scanf("%d %d %d", &a, &b, &c);
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {
        if(str[i] == '-') {
            if (str[i - 1] + 1 >  str[i + 1]) {
                printf("%c", str[i]);
                continue;
            }
            if (((str[i - 1] >= '0' && str[i - 1] <= '9') && (str[i + 1] <= '9' && str[i + 1] >= '0')) || ((str[i - 1] >= 'A' && str[i - 1] <= 'z') && (str[i + 1] >= 'A' && str[i + 1] <= 'z'))) {
                    prit(str[i - 1], str[i + 1], b, c, a);
            } else {
                printf("%c", str[i]);
            }
        } else {
            printf("%c", str[i]);
        }
    }
    free(str);
    printf("\n");
    return 0;
}
