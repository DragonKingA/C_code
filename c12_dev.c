#include <stdio.h>

int main(){
    //输出前n个素数
    int num=2,n,count=0;
    printf("选择输出素数的个数:");
    scanf("%d",&n);
    for(;count<n;num++){
        int ifPrime,i;//该数为素数
        //**注意：此处必须定义全局变量
        //如果在for语句内初始化变量（即局部变量）,当num=2时，
		//待到判断条件后，作为For语句的局部变量i和ifPrime均会被销毁
		//当然DevC++的C语言版本不允许在for语句内定义变量，也就是不存在局部变量，就不存在这类问题 
        for(i = 2,ifPrime = 1;i<num;i++){
            if(num % i == 0){
                ifPrime=0;
                break;
            }
        }
        if(ifPrime == 1 ){
            count++;
            printf("%d ",num);
        }
    }
 
    return 0;
}
