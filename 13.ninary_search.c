/*************************************************************************
	> File Name:13.ninary_search.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年11月06日 星期二 19时27分04秒
 ************************************************************************/

#include <stdio.h>

int binary_search(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}
//1111110000000
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) { // " < " 找到待查找区间最后一个
        //printf("tail %d, mid %d\n", tail, mid);
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

//0000001111111
int binary_search3(int *num, int n) {
    int head = 1, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1)  tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

int main() {
    int num[11], a, x;
    scanf("%d", &a);
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
    switch(a) {
        case 1:{
            scanf("%d", &x)
            printf("%d\n", binary_search(num, 10, x));
        } break;
        case 2:{
            printf("%d\n", binary_search2(num, 10));
        } break;
            case 3:{
            printf("%d\n", binary_search3(num, 10));
        }break;
    }
    return 0;
}
