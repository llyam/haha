/*************************************************************************
	> File Name:my_printf.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年09月20日 星期四 20时26分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

int my_printf(const char *frm, ...) {
    int cut = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0, cut = 0; frm[i]; i++, cut++) {
        switch (frm[i]) {
            case '%': {
                i++;
                switch(frm[i]) {
                    case 'd' : {
                        int64_t temp = va_arg(arg, int), x = 0, h = 0, a[1000000];
                        if (temp < 0) {
                            temp *= -1;
                            putchar('-');
                        }
                        while (temp) {
                            x = temp % 10;
                            a[h++] = x;
                            temp /= 10;
                        }
                        for (int l = h - 1; l >= 0; l--) {
                            putchar(a[l] + '0');
                        }
                        /*while (x) {
                            putchar(x % 10 + '0');
                            x /= 10;
                        }*/
                    } break;
                    default : fprintf(stderr, "error : unknow %%%c", frm[i]);
                    exit(1);
                }
            } break;
            default : putchar(frm[i]);
        }
    }    
    return cut;
}

int main() {
    int n = 123;
    my_printf("hello world\n");
    my_printf("n = %d\n", n);
    my_printf("n = %d\n", 12000);
    my_printf("n = %d\n", -567);
    my_printf("n = %d\n", INT32_MIN);
    my_printf("n = %d\n", INT32_MAX);
    return 0;
}
