/*************************************************************************
	> File Name:p2705.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年09月09日 星期日 11时33分25秒
 ************************************************************************/
#include<cstdio>
using namespace std;
int main(){
        int r,b,c,d,e,sum,k;
        scanf("%d%d%d%d%d",&r,&b,&c,&d,&e);
        if(r>b) k=1;
        else k=0;//先判断一下蓝球和红球的数量
        if(c+d>e+e) sum=r*c+b*d;//如果同色盒中的大
    else{
                if(k==1)//如果红球多
                    sum=b*2*e+(r-b)*c;
                else sum=r*2*e+(b-r)*d;//如果蓝球多
            
    }
        printf("%d",sum);
        return 0;

}
