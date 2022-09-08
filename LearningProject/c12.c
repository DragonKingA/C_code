#include <stdio.h>

int main(){
    //输出前n个素数
    int num=2,n,count=0;
    printf("选择输出素数的个数:");
    scanf("%d",&n);
    for(;count<n;num++){
        int i,ifPrime;//若ifPrime=1即该数为素数
        //**注意：此处必须定义全局变量
        //如果在for语句内初始化变量（即局部变量）,当num=2时，待到判断条件后，作为For语句的局部变量i和ifPrime均会被销毁
        for(i = 2,ifPrime = 1;i<num;i++){
            if(num % i == 0){
                ifPrime=0;
                break;
            }
        }
        // printf("i=%d ",i);
        if(ifPrime == 1 ){
            count++;
            printf("%d ",num);
        }
    }
 
    return 0;
}