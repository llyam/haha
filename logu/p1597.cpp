/*************************************************************************
	> File Name:p1597.cpp
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年08月20日 星期一 14时37分22秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>

int main() {
        char a[100], z;
        int n;
        char ch[3] = {0};
        gets(a);
        n = strlen(a);
    for(int i = 0; i < n; i++) {
        if(a[i] == 'a') {
            ch[0] = a[i + 3];
                        
        } else if(a[i] == 'b') {
            ch[1] = a[i + 3];
                        
        } else if(a[i] == 'c'){
            ch[2] = a[i + 3];
                        
        }
            
    }
    for(int i = 0; i <= 2; i++) {
        printf("%c", ch[i]);
        if(i != 2) {
            printf(" ");
                    
        }
            
    }

}

