/*************************************************************************
	> File Name:牛顿.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年09月14日 星期五 16时09分41秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>



double f1(double x, double n) {
        return x * x - n;
}

double f1_prime(double x) {
        return 2 * x;
}

double haha(double n, double(*f1)(double, double), double(*f1_prime)(double)) {
    double x = 1.0;
    #define EPS 1e-7
    while (fabs(f1(x, n)) > EPS) {
        x -= f1(x, n) / f1_prime(x);
    }
    #undef EPS
    return x;
}

int main() {
    double n;
    while(scanf("%lf", &n) != EOF) {
        printf("%lf\n", haha(n, f1, f1_prime));
    }
    return 0;
}
