#include <stdio.h>
#include <math.h>
#define number 100
//定义数组大小常数

//判定一个数是否为素数
int ifPrime(int x){//返回0为非素数,1为素数
    if( x == 1 || (x%2 == 0 && x!=2)){//排查为1和2的特殊情况，移除为偶数的情况
        return 0;
    }
    for(int i = 3;i<sqrt(x);i++){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
    //更清晰，更严谨的话，定义一个变量ret作为返回值，只在函数最后进行返回操作，使函数只有单一出口，逻辑严谨且易读
}

//判断一个数是否被小于该数的素数整除，否即素数
int ifPrime_Ex(int x,int KnownPrimes[],int NumberOfKnownPrimes){
    int ret = 1;//0为非素数,1为素数
    for(int i=0;i<NumberOfKnownPrimes;i++){
        if(x % KnownPrimes[i] == 0){
            ret = 0;
            break;
        }
    }
    return ret;
}




//一维数组的遍历
void PrintArray(int array[],int amount){
    for(int i=0;i<amount;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

//寻找数字在数组中的最初位置
int search(int key,int arr[],int length){
    //*数组作为函数参数时，往往必须要用另外的参数来传入数组长度
    //在[]中不能直接用表达式计算出数组长度，只能置入数字或变量
    //在函数中，作为参数的数组不能使用sizeof获得字节长度
    int ret = -1;
    for(int i=0;i<length;i++){
        if(arr[i]==key){
            ret = i;
            break;
        }
    }
    return ret;
}

void main(){
    //数组的另类初始化，可以用于当数组中确定元素稀疏时.此时未确定元素被默认为0
    int arr1[]={[1]=2,4,[5]=6};// 0 2 4 0 0 6 
    int arr2[10]={[2]=2,[4]=4,5,6};// 0 0 2 0 4 5 6 0 0 0
    // [x]= 的作用相当于将操作区移动到索引位置为x,若有多个确定元素，则据此向后推
    PrintArray(arr1,6);
    PrintArray(arr2,10);
    
    //sizeof()返回数组或数组中一个元素所占据内容的大小，单位：字节
    //%u表示无符号10进制整型，
    //%lu表示输出无符号长整型整数 (long unsigned)
    printf("整个arr1数组字节大小=%lu\n",sizeof(arr1));//24
    printf("数组arr1单个元素(首元素)字节大小=%lu\n",sizeof(arr1[0]));//4
    //int类型数组每个元素占据4个字节的空间
    //故可以利用来计算数组元素个数(数组长度)
    int arr1len = sizeof(arr1)/sizeof(arr1[0]);//6
    printf("数组arr1长度=%d\n",arr1len);

    //找出数字在数组中的最初位置
    int x=6;
    // printf("x=");
    // scanf("%d",&x);
    int location = search(x,arr1,arr1len);
    if(location != -1){
        printf("%d在索引位置%d上",x,location);
    }else{
        printf("%d不存在",x);
    }


    // printf("x=");
    // scanf("%d",&x);
    // printf("结果(0为非素数,1为素数)：%d",ifPrime(x));
    // 以下赋值操作均不存在，对于C语言数组类型，有const修饰，
    //故完全不同于java中数组存在拷贝地址的赋值,如arr1=arr2使得arr1指向arr2所指向内存空间(地址)
    // arr1 = arr2;   X
    // arr1[]=arr2;   X
    // arr1[]=arr2[]; X

    printf("\n");

    //取素数方法优化：
    /*
    原理：任何合数都能被素数整除
    任何合数都可以表示成a×b
    若a,b都不是质数,则设a=m×n
    若m,n都不是质数,则继续分解,最后总能分解出质数
    *即总存在素数x（x<m）整除合数m
    */
    //const int number = 100;//定义素数数组大小  
    int prime[number]={2};//初始化素数数组，首个素数为2
    /*
    const int number = 100;
    int prime[number]={2};
    以上代码在c语言报错，而在C++通过
    c语言用#define定义静态变量，C++尽量用const定义静态变量，因为const不会分配内存空间，而define会
    */
    int count = 1;//欲输入素数的索引位置(也是数组中已知素数的个数)
    for(int i = 3;count<number;i++){//*重点：此处循环条件为count<number，即总录入素数个数达到100个才停下,此时i的数值很可能超过100且较大
        if(ifPrime_Ex(i,prime,count)){//为1即为素数则执行录入
            prime[count++] = i;//等效于prime[count]=i;count++;
        }
    }
    //遍历数组
    for(int i = 0;i<number;i++){
        printf("%d ",prime[i]);
        if( !(((i+1) % 5)>0)){printf("\n");}
    }


    printf("\n");
    //直接构造素数表
    //原理：
    //已知最小素数x=2，当有2x,3x,4x……直至A*x<n（此时2x,3x……A*x必均为合数）,把这些合数标记为非素数，
    //即在素数表中把这些数（这些数就是索引位置值）标记为0
    //此后再遍历这个数组元素值为1的索引位置（此时该索引位置值就是素数）即可
    int isPrime[number];//100以内的素数表
    //初始化为1
    for(int i=0;i<number;i++){
        isPrime[i]=1;
    }
    //素数表的录入
    for(int numP=2;numP<number;numP++){
        if(isPrime[numP]){
            for(int i=2;i*numP<number;i++){
                isPrime[i*numP] = 0;
            }
        }
    }
    for(int i=2;i<number;i++){
        if(isPrime[i]){
            printf("%d ",i);
        }
        
    }


}