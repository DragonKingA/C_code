#include <stdio.h>
#include <math.h>

void main(){

//求最大公约数gcd
    int a,b,mode,reminder,gcd,a_temp,b_temp,temp,temp_origin;
GetMaxOfgcd:
//若在标号下执行语句int a,b,mode,reminder,gcd;因为存在goto跳转可能性,可能会导致无法定义，编译器判定逻辑不够严密
    printf("现求两数最大公约数，请输入两数：\n");
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);

    //使得a>=b
    if(a == 0 || b == 0){
    printf("输入错误,请重新输入\n");
    goto GetMaxOfgcd;
    }else if(b>a){
        temp_origin=a;
        a=b;
        b=temp_origin;
    }
    /*
    if和else if(否则如果)是不会两者都执行的，只会最多执行进入其中一者，
    若进入了第一者if，便不会判断其后任何else if条件，也不会执行其中代码
    */
    // if(b>a){
    //     temp_origin=a;
    //     a=b;
    //     b=temp_origin;
    // }else if(a == 0 || b == 0){
    //     printf("输入错误,请重新输入\n");
    //     goto GetMaxOfgcd;
    // }

    //存储原a,b的值，便于输出结果
    a_temp=a;
    b_temp=b;

    printf("请选择求法(1.枚举2.辗转相除3.更相减损):");
    scanf("%d",&mode);
    if(mode == 1){
        //1.枚举法:
        //以最小数，作为循环的最大循环次数
        //枚举
        for(int i=1;i <= b;i++){
            if(a % i == 0  && b % i == 0){
                gcd = i;
            }
        }
        printf("%d和%d的最大公约数为%d\n",a_temp,b_temp,gcd);

    }else if(mode == 2){
        //2.辗转相除法:
        // 144%88=1...56
        // 88%56=1...32
        reminder = a % b;
        while(reminder >= 0){//特别注意条件为reminder>=0,使得当reminder=0时能够通过一次循环让gcd=b得以进行
            reminder = a % b;
            if(reminder == 0){
                gcd=b;
                break;
            }
            a=b;
            b=reminder;
        }
        printf("%d和%d的最大公约数为%d\n",a_temp,b_temp,gcd);

    }else if(mode == 3){
        //3.更相减损法:
        while(a>0){
            if(a<b){
                temp=a;
                a=b;
                b=temp;
            }
            a -= b;
            if(a == 0){
                gcd=b;
            }
        }
        printf("%d和%d的最大公约数为%d\n",a_temp,b_temp,gcd);

    }else{
        printf("输入错误,请重新输入\n");
        goto GetMaxOfgcd;

    }

//终端由于路径定位而导致gcc不能识别到文件而显示没有输入文件，解决方法：
//输入cd D:\ClanguageCorrelations\C_code\LearningProject转到路径


    //*测试用:
    goto GetMaxOfgcd;









//=================================================================================================================
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