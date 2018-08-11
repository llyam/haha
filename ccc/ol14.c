/*************************************************************************
    > File Name: ol14.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年07月24日 星期二 15时12分05秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX_N 1000000
// (x & 1)判断奇偶            
// (x >>= 1)x 除 2
#define KEEP_RANGE 1000000
int keep_ans[KEEP_RANGE + 5] = {
	0
};
int get_length(int64_t x) {
	if (x == 1) return 1;
	if (x <= KEEP_RANGE && keep_ans[x]) return keep_ans[x];
	int temp_ans;
	if (x & 1) return get_length(x * 3 + 1) + 1;
	else temp_ans = get_length(x >> 1) + 1;
	if (x <= KEEP_RANGE) keep_ans[x] = temp_ans;

	return temp_ans;
}
int main() {
	int ans = 0, ans_length = 0;
	for(int i = 1; i < MAX_N; i++) {
		int temp_length = get_length(i);
		if(temp_length > ans_length) {
			ans = i;
			ans_length = temp_length;
		}
	}
	printf("%d(%d)\n", ans, ans_length);
	return 0;
}
