#include <stdio.h>
#define SizeofArray 12

//通过排序得到一个正序数组
//1.选择排序（求数组最大数及其索引，将其移至数组最后，并以此循环直到剩下两个数的判定）

//2.冒泡排序(以第一个元素起头，与下一位置元素比较，大者后移，如此循环)
//int ArrayInTurn[SizeofArray];
void LetArrayInTurn(int arr[])
{
    int temp;
    for(int i=0;i<SizeofArray-1;i++){
        for(int j=1;j<SizeofArray-i;j++){
            if(arr[j-1]>arr[j]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}



void main(){
    //定义结构体（类似于Java的对象）
    struct {
        int amount;
        char *name;//字符串指针
        //{amount,name}
    } coins[] = {
        {1,"penny"},
        {5,"nickel"},
        {10,"dime"},
        {25,"quarter"},
        {50,"half-dollar"}
    };

    int money = 10;//对应“dime”
    for(int i=0;i<sizeof(coins)/sizeof(coins[0]);i++){
        if( money == coins[i].amount){//读取数组coins中的amount列
            printf("%s\n",coins[i].name);//输出数组coins中对应的name列
            break;
        }
    }

    //对一升序数组，用二分搜索法搜索一个数
    //二分法效率高，对于数字num，最大搜索次数为log2(num),若num=1000，则最多搜索10次
    int index_min,index_max,index_mid;
    int num = 22;//要搜索的数
    // printf("请输入要搜索的数：");
    // scanf("%d",&num);
    int arr[SizeofArray]={1,22,41,44,54,65,81,99,100,105,230,600};
    index_min=0;
    index_max=SizeofArray;
    for(int i=0;i<SizeofArray;i++){
        index_mid=(index_min+index_max)/2;
        if(arr[index_mid] != num){
            if(arr[index_mid] < num){
                index_min = index_mid;
            }else{
                index_max = index_mid;
            }
        }else{
            printf("%d即数组索引位置为%d的元素",num,index_mid);
            break;
        }
        if(i == SizeofArray - 1){
            printf("%d不在该数组里",num);
            break;
        }
    }

    printf("\n");

    //输出正序数组
    int ArrayMix[SizeofArray] = {3,6,18,2,5,8,99,30,20,50,60,};
    LetArrayInTurn(ArrayMix);
    //遍历
    for(int i=0;i<SizeofArray;i++){
        printf("%d ",ArrayMix[i]);
    }

}