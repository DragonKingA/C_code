#include <stdio.h>
#include <stdbool.h>

void main(){
    //���Ƽ���log2(x)
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
    //������������C����û����Javaһ�������Ĳ������ͣ�����Ĳ�������ֻ��Ϊ0��1
    
    //�������һ������ȡֵ����
    // a<10 && a>1 �� a (1,10)

    //�ж�(����)һ���ַ�Ϊ��д�ַ�
    // char c; c>='A' && c<='Z'

    //���ȼ���ע�⣺
    // !age<20 �����ȼ���!age
    // !(age<20) ����������������
    // &��&& �����ȼ����� |��||
    //(C������java��ͬ��ͬ���� ��· �ĸ��ָ���ʽ1�ж�Ϊfalse�Ͳ�����б��ʽ2���ж�)

    //���������java��ͬ���������ʽ�ĵڶ���д��
    int count = 1;
    count = (count > 20) ? count + 10 : count - 10;
    printf(",count=%d\n",count);

    //ȡ3�������������
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

    //����if-elseif-else�����java��ȫ��ͬ    
    // if(..){

    // }else if(){

    // }else if(){    

    // }else{

    // }


    //switch���Ҳ��java��ȫ��ͬ
    //ͬ����,������б���ֻ��Ϊint����
    //�ر��,C99������case��дconst int����
    // const int abc = 2;
    // switch(����){
    //     case 1:
    //     continue;
    //     case 2��
    //     break;
    //     case abc:
    //     ...
    //     default:
    //     break;
    // }

}