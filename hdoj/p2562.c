/*************************************************************************
	> File Name: p2562.c
	> Author: 
	> Mail: 
	> Created Time: 2019年05月23日 星期四 18时33分28秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    int x;
    scanf("%d", &x);
    for (int z = 0 ;z < x; z++) {
        char str[55];
        scanf("%s", str);
        int n = strlen(str);
        for (int i = 0; i < n - (n % 2); i += 2) {
            printf("%c%c", str[i + 1], str[i]);
        }
        if (n % 2 != 0) {
            printf("%c", str[n - 1]);
        }
        printf("\n");
    }
}
