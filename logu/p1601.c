/*************************************************************************
	> File Name: p1601.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月29日 星期二 13时38分04秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
void add(int *num1, int *num2) {
    for (int i = 1; i <= num1[0]; i++) {
        num1[i] += num2[i];
    }
    for (int i = 1; i <= num1[0]; i++) {
        if (num1[i] < 10) continue;
        num1[i + 1] += num1[i] / 10;
        num1[i] %= 10;
        num1[0] += (num1[0] == i);
    }
    for (int i = num1[0]; i > 0; i--) {
        printf("%d", num1[i]);
    }
    printf("\n");
}

int main() {
    char str1[500], str2[500];
    scanf("%s %s", str1, str2);
    int n1 = strlen(str1), n2 = strlen(str2);
    int num1[600] = {0}, num2[600] = {0};
    num1[0] = n1, num2[0] = n2;
    for (int i = 1; i <= n1; i++) {
        num1[i] = str1[n1 - i] - '0';
    }
    for (int i = 1; i <= n2; i++) {
        num2[i] = str2[n2 - i] - '0';
    }
    if (n1 > n2) {
        add(num1, num2);
    } else {
        add(num2, num1);
    }
}
