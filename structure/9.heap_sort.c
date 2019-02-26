/*************************************************************************
	> File Name:9.heap_sort.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年10月30日 星期二 20时27分38秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a; a = b; b = __temp;\
}

void heap_sort(int *arr, int n) {
    int *p = arr - 1;
    for (int i = n >> 1; i >= 1; i--) {
        int ind = i;
        while((ind << 1) <= n) {
            int temp = ind; //如果还有子孩子
            if (p[ind] < p[ind << 1]) temp = ind << 1;
            if ((ind << 1 | 1) <= n && p[temp] < p[ind << 1 | 1])
            temp = ind << 1 | 1;
            if (temp == ind) break;
            swap(p[temp], p[ind]);
            ind = temp;
        }
    }
    for (int i = n; i > 1; i--) {
        swap(p[i], p[1]);
        int ind = 1;
        while ((ind << 1) <= i - 1) {
            int temp = ind; //如果还有子孩子
            if (p[ind] < p[ind << 1]) temp = ind << 1;
            if ((ind << 1 | 1) <= i - 1 && p[temp] < p[ind << 1 | 1])
            temp = ind << 1 | 1;
            if (temp == ind) break;
            swap(p[temp], p[ind]);
            ind = temp;
        }
    }
    return ;
}

void output(int *num, int n) {
    printf("arr = [");
    for (int i = 0; i < n; i++) {
        printf(" %d", num[i]);
        i == n - 1 || printf(",");
    }
    printf(" ]\n");
}

int main() {
    #define max 20
    srand(time(0));
    int arr[max];
    for (int i = 0; i < max ;i++) arr[i] = rand() % 100;
    output(arr, max);
    heap_sort(arr,max);
    output(arr, max);
    return 0;
}
