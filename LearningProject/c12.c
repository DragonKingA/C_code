#include <stdio.h>

//***不同于Java中主类外方法与方法之间的并列关系
//   C语言整个程序严格自上而下运行，故函数必须在被调用前就被执行
//   如这里的函数GetPrime(),GetPositiveSum()都在main函数中被调用，
//   故这两个函数必须要放在main函数之前，否则程序出错

//***值得注意的是，判断是否错误是要看函数的 原型声明 是否在调用前执行
//   而声明后的 函数定义 却又可以放在 调用处 后
//   如函数2,将其函数头加上分号即原型声明 int GetPositiveSum(int min,int max);

int i,j,sum(int o,int p);
//C语言认同边声明函数边声明变量的语句

//创建函数1
//正序输出指定数量的素数
void GetPrime(int amount)
//整个第5行称为 函数头（其包括返回类型，函数名及参数表）        
{
    //以下即为函数体
    int num=2,count=0;//最小的素数为2
    for(;count<amount;num++){
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
    return;
    //若函数为无返回值函数，可以用不带值的return作为函数的终止点;若是有返回值函数，必须要有带值的return语句
    //因此无论怎样，return都能终止函数进程
    //以上即为函数体
}


//创建函数2,进行函数2的 原型声明
int GetPositiveSum(int min,int max);//该整行即为 函数原型
//原型声明也可以在被调用所处的函数内（此处为main函数）声明
//更简洁的声明如下：
//int GetPositiveSum(int,int);
//但一般不这么用，第一种方法方便人的理解
//若声明写成这样：
//int GetPositiveSum();
//表示声明时未知参数的类型和数量，此时调用函数时编译器会先猜测可能的参数类型和数量，往往编译器不报错但执行时产生巨大错误

//int y(void);
//参数列表有void的声明，明确无参数，编译器则会正常报错

//创建函数3
//输出一个整数
void PrintInt(int m){
    printf("整数为%d\n",m);
}



int main(){
    //输出前n个素数(又名质数，指大于1的整数中，只能被1和这个数本身整除的数)
    int n,min,max,sum;
    //不同函数间的变量名相同不影响程序正常运行
    //彼变量不会改变此变量，彼此不会占用相同的内存空间,故对其中一个赋值不会影响另一个
    //并且每个函数都有自己独一的变量空间，参数也位于这个独立空间中，其中的变量被称为局部变量（或称本地变量）
    //本地变量的作用域仅在 块 内（即大括号范围内），执行出了大括号即消亡
    /*
    块：本地变量可以被定义在函数的块内，也可以被定义在语句的块内
    如if(a < b){
        int i = 0;
    }
    当if语句执行完毕后，本地变量i即消亡
    */
    //彻底不同于java，C甚至可以直接写一个大括号来作为一个块，以供定义本地变量
    int a = 6;
    {
        printf("a=%d\n",a);//6
        //外层块的本地变量可以在内层块起作用
        //而当内层块定义同名变量时，则会屏蔽外层块的变量
        int a = 5;
        printf("a=%d\n",a);//5
    }
    printf("a=%d\n",a);//6

    printf("选择输出素数的个数:");
    scanf("%d",&n);
    //函数的调用
    GetPrime(n);
    printf("\n");
    
GetSum:
    printf("输入求和的最小非负整数min=");
    scanf("%d",&min);
    printf("输入求和的最大非负整数max=");
    scanf("%d",&max);
    sum=GetPositiveSum(min,max);
    //函数在调用时只发生了 传值
    if(sum == -1){
        printf("输入有误，请重新输入\n");
        goto GetSum;
    }
    printf("%d到%d求和为%d\n",min,max,sum);


    int something = GetPositiveSum(GetPositiveSum(1,2),GetPositiveSum(3,4));
    //函数的使用可以嵌套调用
    //但函数的定义不能嵌套

    PrintInt(2.4);//输出“整数为2”
    //***C语言的缺陷,明明函数接收int型数据，当输入double型数据(变量)时并不报错
    //   即 调用函数的值 与 原设定参数的类型 不匹配被默许
    //   并且最终结果为编译器悄悄转换后的整数
    //在C++/java等后续语言得到改善
    


    return 0;
    //返回0，公认的程序正确执行的标志，若返回非0值，则是公认的程序发生错误的标志
    //故一般返回0
    //return (0);完全等效于上句，这里的括号只是表达式括号，完全不用写，易被误解成return是个函数并正在进行传值
}


//函数定义的进行如下
//求和指定整数范围内所有整数
int GetPositiveSum(int min,int max){
    int sum=0;
    for(int i = min;i<=max;i++){
        sum+=i;
    }
    if(min >= max || min < 0 || max < 0){
        return -1;
    }else{
        return sum;
    }
    
}