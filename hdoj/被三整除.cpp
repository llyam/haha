/*************************************************************************
	> File Name: 3整除.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月04日 星期五 10时27分43秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int n, k;
vector<string> v;
set<string> se;
void find(string str, int ch[], int size, int sum) {
    if (str.size() == k) {
        if (sum % 3 == 0) {
            v.push_back(str);
        }
        return ;
    }
    if (n == size) return ;
    for (int i = size; i < n; i++) {
        str += (ch[i] + '0');
        find(str, ch, size + 1, sum + ch[i]);
        str.pop_back();
    }
}

int main() {
    int ch[16];
    string str = "";

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> ch[i];
    }
    find(str, ch, 0, 0);
    for (int i = 0; i < v.size(); i++) {
        int n = v[i].size();
        char *s = const_cast<char *>(v[i].c_str());
        //const char *s = v[i].c_str();
        //sort(s, s+n);
        do {
            se.insert(s);
        } while (next_permutation(s, s + n));
    }
    for (auto iter = se.begin(); iter != se.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}
