#include <stdio.h>

int main(){
    int one,two,five;
    int money;
    int ifAllin;
    printf("请输入需转换的整数金额:");
    scanf("%d",&money);
    printf("请选择转换模式（1则全部方案，0则一个方案）:");
    scanf("%d",&ifAllin);
    for(int i = 1;i<=money*10/5;i++){
        five = i;
        for(int j = 1;j<=money*10/2;j++){
            two = j;
            for(int z = 1;z<=money*10;z++){
                one = z;
                if(one+two*2+five*5 == money*10){
                    printf("%d个5角硬币+%d个2角硬币+%d个1角硬币可以凑出%d元\n",five,two,one,money);
                    if(ifAllin == 0){
                        goto exit;
                        //goto :程序直接跳转到具体标号，执行标号后语句
                        //但goto将会破坏程序的绝对逻辑，在必要情况(如跳出多重循环)才能可斟酌使用，可读性差
                    }
                }
            }
        }
    }
    //跳转标号，凡使用，其后必须有具体代码内容
exit:
    return 0;


}