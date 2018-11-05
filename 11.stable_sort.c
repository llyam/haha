/************************************************************************
	> File Name:11.stable_sort.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年11月04日 星期日 19时45分50秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define swap(a, b) {\
    a ^= b;\
    b ^= a;\
    a ^= b;\
}

#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    printf("%s =", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && num[j] < num[j - 1]; j--) {
            swap(num[j], num[j - 1]);
        }
    }
}

void bubble_sort(int *num, int n) {
    int times;
    for (int i = 1; i < n && times; i++) {
        times = 0;
        for (int j = 0; j < n - i; j++) {
            if (num[j] > num[j + 1]) {
                swap(num[j], num[j + 1]);
                times++;
            }
        }   
    }
}

void merge_sort(int *num, int l, int r) {
    if (r - l < 2) {
        if (r - l == 1 && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
}

void randint(int *num, int n) {
    while(n--) {
       num[n] = rand() % 100; 
    }
    return ;
}

void output(int *num, int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define max 20
    int arr[max];
    randint(arr, max);
    TEST(arr, max, insert_sort, num, max);
    TEST(arr, max, merge_sort, num, 0, max - 1);
    TEST(arr, max, bubble_sort, num, max);
    return 0;
}
