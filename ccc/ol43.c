/*************************************************************************
    > File Name: ol43.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月28日 星期六 11时36分23秒
 ************************************************************************/

#include<iostream>
#include<algorithm>

using namespace std;

int a[7] = {2, 3, 5, 7, 11, 13, 17};

long long int haha(int *num) {
	long long int sum = 0;
	int h = 0;
	for(int i = 0; i < 10; i++) {
		long long int s = 0;
		sum *= 10;
		sum += num[i];
		if(i >= 1 && i < 8) {
			for(int j = 0; j < 3; j++) {
				s *= 10;
				s += num[j + i];
			}
			if(s % a[h] == 0) {
				h++;
			} else {
				return 0;
			}
		}
	}
	return sum;
}
int main() {
	int num[10];
	for(int i = 0; i < 10; i++) {
		num[i] = i;
	}
	long long int s = 0;
	do{
		s += haha(num);
	} while(next_permutation(num, num + 10));
	cout << s << endl;
}
