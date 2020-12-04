/*************************************************************************
	> File Name: 01.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月04日 星期五 11时13分52秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    int re0[3], re1[3], num = 1, nu1 = 0, nu0 = 0, n = str.size() - 1;
    for (int i = 1; i < str.size(); i++) {
        if (str[i] != str[i - 1]) {
            if (str[i] == '1') {
                if (num >= nu0) re0[0] = num, re0[1] = i - num, re0[2] = i - 1, nu0 = num;
            } else { 
            if (num >= nu1) re1[0] = num, re1[1] = i - num, re1[2] = i - 1, nu1 = num;
            }
            num = 1;
        } else {
            num++;
        }
    }
    if (str[n] == '0') {
        if (num >= nu0) re0[0] = num, re0[1] = n - num + 1, re0[2] = n;
    } else {
        if (num >= nu1) re1[0] = num, re1[1] = n - num + 1, re1[2] = n;
    }
    cout << re0[0] << " " << re0[1] + 1 << " " << re0[2] + 1 << endl;
    cout << re1[0] << " " << re1[1] + 1<< " " << re1[2] + 1 << endl;
    return 0;
}
