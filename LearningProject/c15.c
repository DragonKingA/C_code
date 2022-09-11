#include <stdio.h>
#include <math.h>

void main(){
    //将一个非负整数正序相隔输出
    int num;
Test:
    printf("num=");
    scanf("%d",&num);
    int num_temp = num;
    int digit = 0;
    int number_single,index;
    //计算整数的位数
    while(num_temp > 0){
        num_temp /= 10;
        digit++;
    }
    //printf("digit=%d\n",digit);
    //num=0时的特殊处理
    if(digit == 0){
        printf("%d",num);
    }
    //逐个输出num的数字
    for(int i=1;i<=digit;i++){
        index = pow(10,digit-i);
        number_single = num / index;
        printf("%d",number_single);
        if(i != digit){
            printf(" ");
        }
        num %= index;
    }
    printf("\n");
    
    //测试用
    goto Test;
}