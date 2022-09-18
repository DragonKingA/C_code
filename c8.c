#include <stdio.h>
#include <stdbool.h>

void main(){
    //近似计算log2(x)
    int x = 128;
    int times = 0;
    int x_temp = x;
    for(; x > 1;){
        x/=2;
        times++;
    }
    printf("log2 of %d is %d\n",x_temp,times);
    
    bool a = 1>9;
    bool b = true;
    bool c = a | b;//1
    bool d = a & b;//0
    printf("a=%d,b=%d,c=%d,d=%d",a,b,c,d);
    //a=0,b=1
    //哪怕是这样，C语言没有像Java一样真正的布尔类型，输出的布尔量仍只能为0或1
    
    //表达限制一个数的取值区间
    // a<10 && a>1 即 a (1,10)

    //判断(限制)一个字符为大写字符
    // char c; c>='A' && c<='Z'

    //优先级的注意：
    // !age<20 ，会先计算!age
    // !(age<20) 这样才能正常计算
    // &或&& 的优先级高于 |或||
    //(C语言与java相同，同样有 短路 的概念，指表达式1判断为false就不会进行表达式2的判断)

    //以下语句与java相同，条件表达式的第二种写法
    int count = 1;
    count = (count > 20) ? count + 10 : count - 10;
    printf(",count=%d\n",count);

    //取3个整数中最大者
    int num1,num2,num3,max;
    scanf("%d %d %d",&num1,&num2,&num3);
    if(num1 > num2){
        if(num1>num3){
            max=num1;
        }else{
            max=num3;
        }
    }else{
        if(num2>num3){
            max=num2;
        }else{
            max=num3;
        }
    }
    printf("max=%d",max);

    //级联if-elseif-else语句与java完全相同    
    // if(..){

    // }else if(){

    // }else if(){    

    // }else{

    // }


    //switch语句也与java完全相同
    //同样的,该语句中变量只能为int类型
    //特别的,C99可以在case后写const int常量
    // const int abc = 2;
    // switch(变量){
    //     case 1:
    //     continue;
    //     case 2：
    //     break;
    //     case abc:
    //     ...
    //     default:
    //     break;
    // }

}