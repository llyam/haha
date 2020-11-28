/*************************************************************************
	> File Name: hh.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年11月28日 星期六 12时12分17秒
 ************************************************************************/

#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

set<string> s;
map<char, int> m;
    
void find(vector<vector<string>> &v, int z, string str) {
    if (z == v.size()) {
        s.insert(str);
        return ;
    }
    for (int i = 0; i < v[z].size(); i++) {
        find(v, z + 1, str + v[z][i]); 
    }
}

int main() {
    string str;
    cin >> str;
    for (char i : str) {
        m[i]++;
    }
    vector<vector<string>> v;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        vector<string> s;
        string ch = "";
        for (int i = 0; i < iter->second; i++) {
            ch += iter->first;
            s.push_back(ch);
        }
        v.push_back(s);
    }
    find(v, 0, "");
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}
