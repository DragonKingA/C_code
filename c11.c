#include <stdio.h>

void main(){
    //ʹ��������������ص㣺�����ķֽ�
    int num,numOpp=0;
    int NumOnDigit;
    printf("������һ������:");//3
    scanf("%d",&num);
    
    //�������Ӹ�λ��ʼ��ȡ�ø�λ���������ʹ��������λ������������
    // 
    // while(num > 0){
    //     NumOnDigit = num % 10;
    //     num /= 10;
    //     numOpp += NumOnDigit;
    //     numOpp *= 10;
    // }
    // //�����ʵnumOpp *= 10���Ƕ�ִ����һ�Σ��ʳ���ȥ
    // numOpp /= 10;

    //���õ�д����
    while(num > 0){
        NumOnDigit = num % 10;
        num /= 10;
        numOpp = numOpp*10 + NumOnDigit;
    }
    printf("%d",numOpp);
  

   
}