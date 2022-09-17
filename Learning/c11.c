#include <stdio.h>

void main(){
    //使整数逆序输出，重点：整数的分解
    int num,numOpp=0;
    int NumOnDigit;
    printf("请输入一个整数:");//3
    scanf("%d",&num);
    
    //方法：从个位开始，取得该位的数，随后使数丢弃该位数，整体右移
    // 
    // while(num > 0){
    //     NumOnDigit = num % 10;
    //     num /= 10;
    //     numOpp += NumOnDigit;
    //     numOpp *= 10;
    // }
    // //最后其实numOpp *= 10算是多执行了一次，故除回去
    // numOpp /= 10;

    //更好的写法：
    while(num > 0){
        NumOnDigit = num % 10;
        num /= 10;
        numOpp = numOpp*10 + NumOnDigit;
    }
    printf("%d",numOpp);
  

   
}