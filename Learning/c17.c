#include <stdio.h>

void main(){
    //输入若干个属于[0,9]的整数，统计每一个整数出现的次数，输入-1表示结束录入
    int num;
    int countset[10];//分别记录0~9的个数
    //初始化数组，使次数从零开始计数
    for(int i = 0 ;i<10;i++){
        countset[i]=0;
    }
    //录入数值并进行统计
    printf("请输入若干个0~9的数值:\n");
    while( num != -1){
back:
        scanf("%d",&num);
        if(num >= 0 && num <= 9){
            countset[num]++;
        }else if(num != -1){
            printf("此数值无效，请重新输入该数值:\n");
            goto back;
        }   
    }
    //输出统计结果
    for(int i = 0;i<10;i++){
        printf("数值%d出现了%d次\n",i,countset[i]);
    }

    //C语言拥有Java所没有的逗号运算符
    //如(表达式1,表达式2)只会返回表达式2的结果，但是表达式1会被执行并且可能影响表达式2的结果

}