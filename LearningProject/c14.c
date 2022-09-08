#include <stdio.h>
#include <math.h>

void main(){
//求最大公约数
    int a,b,min,maxCommon;
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    //先取最小数，作为循环的最大循环次数
    if(a > b){
        min = b;
    }else{
        min = a;
    }
    //枚举
    for(int i=1;i <= min;i++){
        if(a % i == 0  && b % i == 0){
            maxCommon = i;
        }
    }
    printf("%d和%d的最大公约数为%d\n",a,b,maxCommon);


//前n项求和
    int n;
    double sum = 0;
    printf("n=");
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        sum += pow(-1,i+1)*(1.0/i);
        //sum = 1 - 1/2 + 1/3 - 1/4 +···+1/n 
        //注意 num1^num2不能表示数的幂运算

        /*另外一种写法:
        double sign = 1.0;//定义正负并使计算结果为double
        sum += sign/i;
        sign = -sign;//每次循环变换符号即可
        */
    }
    printf("sum=%lf",sum);
}