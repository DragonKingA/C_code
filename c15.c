#include <stdio.h>
#include <math.h>

void main(){
    //��һ���Ǹ���������������
    int num;
Test:
    printf("num=");
    scanf("%d",&num);
    int num_temp = num;
    int digit = 0;
    int number_single,index;
    //����������λ��
    while(num_temp > 0){
        num_temp /= 10;
        digit++;
    }
    //printf("digit=%d\n",digit);
    //num=0ʱ�����⴦��
    if(digit == 0){
        printf("%d",num);
    }
    //������num������
    for(int i=1;i<=digit;i++){
        index = pow(10,digit-i);
        number_single = num / index;
        printf("%d",number_single);
        if(i != digit){
            printf(" ");
        }
        num %= index;
    }
    printf("\n");
    
    //������
    goto Test;
}