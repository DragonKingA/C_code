#include <stdio.h>
//����Ϊʹ��rand()�ı�Ҫ����
#include <stdlib.h>
#include <time.h>

void main(){

    srand((unsigned int)time(NULL));//time(0)��time(NULL)
    //���ǳ���ʹ��ϵͳʱ������ʼ����ʹ��time��������ȡϵͳʱ�䣬
    //�õ���ֵ��һ��ʱ���������1970��1��1��0�㵽����ʱ�������
        /*ʱ���:��ָ��������ʱ����1970��1��1�գ�00:00:00 GMT������ǰʱ�����������
         ��Ҳ����ΪUnixʱ�����Unix Timestamp����
         ͨ�׵Ľ���ʱ�����һ���ܹ���ʾһ��������һ���ض�ʱ����Ѿ����ڵ������Ŀ���֤�����ݡ�
         */

    //srand(����)���������������������Ϊ����
    //��������һ�ֳ�ʼ�����ӵķ�ʽ���£��ý��̵�pid��Ϊ����ֵseed����ͬһ�������У����������ӵ�ֵ����ͬ��
    //srand((unsigned int)getpid())

 

  

    //��ͬ��C���ԣ�javaȡ�����ΪMath.random(),�᷵������[0,1)��ֵ
    //��CΪrand(),
    int a = rand();
    printf("%d\n",a);
    printf("%d\n",a%100);
    //ͨ��a%100��ȡ��0��99������
    //�� a%100 + 1 �� [1,100]

    printf("����1~100��һ����number����²⣺");
    int number = rand()%100 + 1;
    int Ifnum,times=1;
    scanf("%d",&Ifnum);
    while(Ifnum != number){
        if(Ifnum > number){
            printf("�´��ˣ����������룺");
        }else{
            printf("��С�ˣ����������룺");
        }
        scanf("%d",&Ifnum);
        times++;
    }
    if(Ifnum == number){
        printf("number=%d,����%d��,������ţ��",number,times);
    }
    //���ַ���������7�μ��ɵó��𰸣���Ϊ1~100������100�ֿ�����
    //��2^7=128 > 100 �� 7�ζ��ַ�����������100�ֿ�����



}