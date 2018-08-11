/*************************************************************************
    > File Name: ol19.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年08月05日 星期日 11时29分08秒
 ************************************************************************/

#include<stdio.h>

int days[13] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int leap_year(int y) {
	return (y % 4 == 0 && y % 100) || (y % 400 == 0); //闰年
}

int get_next_date (int y, int m, int d) {
	d += 1;
	if (d > days[m] + (m == 2 && leap_year(y))) {
		d = 1;
	}
	return d;
}

int main() {
	int ans = 0, y = 1900, m = 1, d = 1, w = 1;
	do {
		d = get_next_date(y, m, d);
		m += (d == 1);
		y += (m == 13 && (m = 1));
		w++;
		if(w == 8) w = 1;
		if(y > 1900) {
			if(w == 7 && d == 1) {
				ans++;
			}
		}
	} while(y <= 2000);
	printf("%d\n", ans);
	return 0;
}
