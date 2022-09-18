#include <stdio.h>
//以下为使用rand()的必要条件
#include <stdlib.h>
#include <time.h>

void main(){

    srand((unsigned int)time(NULL));//time(0)或time(NULL)
    //我们常常使用系统时间来初始化，使用time函数来获取系统时间，
    //得到的值是一个时间戳，即从1970年1月1日0点到现在时间的秒数
        /*时间戳:是指格林威治时间自1970年1月1日（00:00:00 GMT）至当前时间的总秒数。
         它也被称为Unix时间戳（Unix Timestamp）。
         通俗的讲，时间戳是一份能够表示一份数据在一个特定时间点已经存在的完整的可验证的数据。
         */

    //srand(参数)是随机数发生器，参数作为种子
    //还有另外一种初始化种子的方式如下，用进程的pid作为种子值seed，在同一个程序中，这样的种子的值是相同的
    //srand((unsigned int)getpid())

 

  

    //不同于C语言，java取随机数为Math.random(),会返回属于[0,1)的值
    //而C为rand(),
    int a = rand();
    printf("%d\n",a);
    printf("%d\n",a%100);
    //通过a%100来取得0到99的整数
    //则 a%100 + 1 即 [1,100]

    printf("现有1~100其一整数number，请猜测：");
    int number = rand()%100 + 1;
    int Ifnum,times=1;
    scanf("%d",&Ifnum);
    while(Ifnum != number){
        if(Ifnum > number){
            printf("猜大了，请重新输入：");
        }else{
            printf("猜小了，请重新输入：");
        }
        scanf("%d",&Ifnum);
        times++;
    }
    if(Ifnum == number){
        printf("number=%d,猜了%d次,看把你牛的",number,times);
    }
    //二分法猜数最多猜7次即可得出答案，因为1~100的数有100种可能性
    //而2^7=128 > 100 即 7次二分法足以囊括这100种可能性



}