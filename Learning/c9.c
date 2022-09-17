#include <stdio.h>
void main(){

    //求一系列数的平均数
    int num,sum=-1,times=0;
    printf("请输入一系列正整数，若输入-1即为停止输入:\n");
    scanf("%d",&num);
    while(num != -1){    
        times++;
        sum += num;
        scanf("%d",&num);
    }
    if(sum != -1){
        sum++;//补值
        printf("平均数为%f",1.0*sum/times);
        //***这里用1.0去乘以sum使其结果为浮点值
        //同于java，double average = sum/times
        //只输出小数点后均为0的小数,而并非接近实际的结果
    }
    
}