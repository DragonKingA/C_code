#include <stdio.h>
void main(){
    int value = (100 - 90)/2;
    //上述语句一整个语句称为一条表达式，其中包含 运算符(operator) 和 算子(operand)
    //算子：指参与运算的值（常数、变量或一个方法的返回值），包括左侧的接收变量
    int a = 2;
    int b = 3;
    printf("2*-3=%d\n",a*-b);//输出-6
    //a*-b指a与b相乘后结果取负值，此处“-”称为单目取反，特殊地，自右向左结合。区别于减号作减法
    //a*+b指结果即为乘值不变，此处“+”称为单目不变，特殊地，自右向左结合。区别于加号作加法
    //一般地，运算符都是自左向右结合，特殊的自右向左结合有单目取反、单目不变、赋值（=）
    
    int c,d;
    c=d=6;
    //在C语言中赋值操作的等号“=”也是一种产生结果的运算，并且自右向左执行
    //如上语句，先执行d=6，将6赋值给d，则d=6产生结果6,再由c=6，将6赋值给c
    //c=d=6 --> c= ( d=6 ) --> c= 6  

    //计算时间差
    int hour1,minute1;
    int hour2,minute2;
    printf("请分别输入两组时间:X(时) X(分):");
    scanf("%d %d",&hour1,&minute1);
    scanf("%d %d",&hour2,&minute2);
    int time1 = hour1 * 60 + minute1;
    int time2 = hour2 * 60 + minute2;
    int difference = 0;
    if(time1 > time2){
        difference = time1 - time2;
    }else{
        difference = time2 - time1;
    } 
    printf("两组时间的时间差为%d分钟,",difference);
    printf("抑或者说时间差为%d时%d分",difference / 60,difference % 60);
}