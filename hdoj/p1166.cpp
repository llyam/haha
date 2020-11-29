/*************************************************************************
	> File Name: p1166.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年11月29日 星期日 19时22分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

int lowbit(int n) {
    return n & (-n);
}

void bit_get(int x, int y, int n, int *num) {
    for (int i = x; i <= n; i += lowbit(i)) {
        num[i] += y;
    }
}

int find(int x, int *num) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) {
        ans += num[i];
    }
    return ans;
}

int main() {
    int T, n, z;
    cin >> T;
    z = T;
    while (T--) {
        cin >> n;
        int c[50005] = {0}, r;
        for (int i = 1; i <= n; i++) {
            cin >> r;
            bit_get(i, r, n, c);
        }
        char str[10];
        cout << "Case " << z - T << ":" << endl;
        while (scanf("%s", str)) {
            int i, j;
            if (str[0] == 'E') break;
            cin >> i >> j;
            if (str[0] == 'Q') {
                cout << find(j, c) - find(i - 1, c) << endl;
            }
            else if (str[0] == 'A') {
                bit_get(i, j, n, c);
            }
            else if (str[0] == 'S') {
                bit_get(i, -j, n, c);
            }   
        }
    }
    return 0;
}
