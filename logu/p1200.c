/*************************************************************************
	> File Name:p1200.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年09月25日 星期二 11时22分49秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    int n, suma = 1, sumb = 1;
    char ufo[6], team[6];
    scanf ("%s %s", &ufo, &team);
    int n1 = strlen(ufo);
    int n2 = strlen(team);
    for (int i = 0; i < n1; i++) {
        suma *= (ufo[i] - 64);
        suma %= 47;
    }
    for (int j = 0; j < n2; j++) {
        sumb *= (team[j] - 64);
        sumb %= 47; 
    }
    if (suma == sumb) {
        printf("GO\n");
    } else {
        printf("STAY\n");
    }
    return 0;
}
