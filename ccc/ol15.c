/*************************************************************************
    > File Name: ol15.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月29日 星期日 11时39分15秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int main() {
	int64_t s = 1, n = 40, w = 1;
	while (n > 20) {
		s *= n;
		if(s % n == 0) s /= w;
		n--;
		if(w >= 20) {
			w = 1;
			continue;
		}
		w++;
	}
	printf("%" PRId64 "\n", s);
	return 0;
}
