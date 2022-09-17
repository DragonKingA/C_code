#include <stdio.h>
int main(){
    const int AMOUNT = 100;
    int change = AMOUNT - 10;//书写规范：只读变量的变量名全大写
    printf("%d\n",change);
    //const是一个修饰符，表示变量不变的属性（只读变量），即变成常量（只读变量），而常量（只读变量）一旦初始化就不能再修改
    //若试图对常量修改，即常量被重新赋值时，运行就会报错

    int a,b;
    printf("请输入两个整数：");
    scanf("%d %d",&a,&b);
    printf("%d+%d=%d\n",a,b,a+b);

    int c,d=9;//c只被定义不被赋值(不被初始化)，输出c时会出现乱数,故初始值不定
    printf("c=%d,d=%d",c,d);
    return 0;
}