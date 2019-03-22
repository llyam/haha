/*************************************************************************
	> File Name: p2142.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月22日 星期五 17时03分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void haha(char *ch1, char *ch2, int x) {
    int jj = 0;
    int nu1[10000] = {0}, nu2[10000] = {0}, nu[10000];
    int n1 = strlen(ch1), n2 =  strlen(ch2);
    //printf("%d %d \n", n1, n2);
    for (int i = 0; i < n1; i++) {
        nu1[i] = ch1[n1 - i - 1] - '0';
    }
    for (int j = 0; j < n2; j++) {
        nu2[j] = ch2[n2 - j - 1] - '0';
   
    }
    if (x == 1) printf("-");
    for (int i = 0; i < n1; i++) {
        if (nu2[i] > nu1[i]) {
            nu1[i + 1]--;
            nu1[i] += 10;
        }
        nu[i] = nu1[i] - nu2[i];
    }
    int max = n1 - 1;
    while (nu[max] == 0) max--;
    for (int i = max; i >= 0; i--) {
        printf("%d", nu[i]);
    }
    printf("\n");
    return ;
}

int main() {
    char *ch1, *ch2;
    ch1 = (char *)malloc(sizeof(char) * 10000);
    ch2 = (char *)malloc(sizeof(char) * 10000);
     scanf("%s %s", ch1, ch2);
    int n1 = strlen(ch1), n2 = strlen(ch2);
    //printf("%d %d\n", n1, n2);
    if (n1 >= n2) {
        if (n1 == n2 && strcmp(ch1, ch2) > 0) {
            haha(ch1, ch2, 0);
            return 0;
        } else if (n1 == n2 && strcmp(ch2, ch1) > 0){
            haha(ch2, ch1, 1);
            return 0;
        } else if (n1 == n2 &&  strcmp(ch1, ch2) == 0) {
            printf("0\n");
            return 0;
        }
        haha(ch1, ch2, 0);
    } else {
        haha(ch2, ch1, 1);
    }
    free(ch1);
    free(ch2);
}
