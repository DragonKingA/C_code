#include <stdio.h>

// void arr1(int a[]){
//     printf("函数中sizeof(arr2)=%lu\n",a);//输出一个非常大的随机数
//     printf("函数中 arr2=%p\n",a);
//     printf("arr2[0]=%d\n",a[0]);//1
//     a[0]=10000;
// }
//说明函数原型中参数int a[] 等价于 int *a
void arr1(int *a){
    printf("函数中sizeof(arr2)=%lu\n",a);//输出一个非常大的随机数
    printf("函数中 arr2=%p\n",a);
    printf("arr2[0]=%d\n",a[0]);//1
    a[0]=10000;
}

void GetAddress(int *p){
    printf("&p=%p\n",p);
    printf("*p=%d\n",*p);//访问指针对应的变量值 1
    *p = 100;//函数中改变外部变量值！
    int m=0;
    m = *p;//m=100
    //星号* 也可以作为一个单目运算符，用来访问指针的值所表示的地址上的变量
}


void main(){
    //取地址运算符&
    //获取变量的地址，其操作数必须为变量，不能是计算表达式或常量
    int i=1;
    //将i的地址强转为int类型时
    //int p=(int)&i;printf("%x\n",p);
    //定义时就报错
    printf("%x\n",&i);//%x输出16进制整数(一般输出时不带0x)
    printf("%X\n",&i);//%x输出16进制整数(一般输出时不带0x且字母大写)
    printf("%#x\n",&i);//%#x输出带0x的16进制
    printf("%p\n",&i);//%p输出指针地址
    //在64位编译器下，使用%p打印指针变量，则会显示64位的地址（16进制的），左边空缺的会补0
    // %x：无符号十六进制整数(字母小写，不像上面指针地址那样补零)
    // %X：无符号十六进制整数(字母大写，不像上面指针那样补零)
    // %x、%X和%p的相同点都是16进制，不同点是%p按编译器位数长短（32位/64位）输出地址，不够的补零；而其他默认输出32位地址

    printf("%lu\n",sizeof(int));//4
    printf("%lu\n",sizeof(&i));//8（64位编译器里地址占8个字节，32位地址占4个字节）
    //%u表示无符号10进制整型，
    //%lu表示输出无符号长整型整数 (long unsigned)

    int a;
    int b;
    printf("&a=%p,&b=%p\n",&a,&b);
    //两者地址值相差4,先定义的变量a的地址值更大

    int arr[10];
    printf("%p\n",&arr);
    printf("%p\n",arr);
    printf("%p\n",&arr[0]);
    //以上三者输出地址均相同
    printf("%p\n",&arr[1]);//这里比上述三者地址值多4

    //相邻变量空间地址恒相差4（相当于int类型占据字节数
    
    //指针：用于保存地址的变量
    int* pointer = &i;
    printf("%x\n",pointer);
    GetAddress(&i);
    printf("变化后i=%d\n",i);//100
    /*
    //*星号靠近谁都一样，都指的是某变量是一个指针，而没有int*这种类型
    int* p,q;
    int *p,q;
    //上两句都指p为一个整型指针，q为一个int类型
    int *p,*q;
    //该句指p,q都是整型指针
    */

    int arr2[]={1,2,3,4,5,6,7,8,9};
    arr1(arr2);
    printf("main中sizeof(arr2)=%lu\n",arr2);//与函数arr1()中输出相等
    printf("main中 arr2=%p\n",arr2);        //与函数arr1()中输出相等
    printf("arr2[0]=%d\n",arr2[0]);//10000，与在函数中修改后的值相同
    //说明main函数中数组arr2与传入函数arr1()中数组完全相同
    printf("*arr2=%d\n",*arr2);//10000,
    //因为arr2地址与首元素arr2[0]地址相同，故直接对数组arr2取地址变量，即面向arr2[0]作用

    int *pp = arr2;
    printf("*pp=%d\n",*pp);//*pp=10000,故数组arr2地址对应变量即首元素
    //亦可以说 *pp == arr2[0] !!!

    /*强化理解：以下四种函数原型是等价的
    int sum(int *arr,int n);
    int sum(int *,int);
    int sum(int arr[],int n);
    int sum(int [],int);

    传入数组相当于传入一个指针
    并且函数内修改数组，相当于利用*arr修改main中的数组
    1.数组变量是一个特殊的指针，数组变量本身表达地址,如
    int arr[10];
    int *p = arr;

    2.但是数组的单元变量表达变量，若需要其地址，则需要&取地址
    arr == &arr[0]
    //同时有个事实是数组arr的地址即数组首元素地址arr[0]

    3.[]运算符可以对数组作用，也可以对指针作用
    p[0] == arr[0]
    如int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &a[5];
    则p[-2] 等于 54

    4.数组变量实际上是const修饰的指针,即常量指针，所以数组变量间不能直接赋值
    int a[],b[];// 相当于int * const a;int * const b;
    b = a; //由于b是被const修饰的，故不能被赋值改变
    而指针可以接收数组变量
    int *p = a;

    具体说明：数组与指针有区别。
    int a[10];
    int *p;
    p=a; 
    p是一个可以变化的指针变量，而a是一个常数，
    因为数组一但被说明，数组的地址也就确定下来了。因此a是不能变化的，而p可以。
*/
}