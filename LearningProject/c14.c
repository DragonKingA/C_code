#include <stdio.h>
#include <math.h>

void main(){
//�����Լ��
    int a,b,min,maxCommon;
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    //��ȡ��С������Ϊѭ�������ѭ������
    if(a > b){
        min = b;
    }else{
        min = a;
    }
    //ö��
    for(int i=1;i <= min;i++){
        if(a % i == 0  && b % i == 0){
            maxCommon = i;
        }
    }
    printf("%d��%d�����Լ��Ϊ%d\n",a,b,maxCommon);


//ǰn�����
    int n;
    double sum = 0;
    printf("n=");
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        sum += pow(-1,i+1)*(1.0/i);
        //sum = 1 - 1/2 + 1/3 - 1/4 +������+1/n 
        //ע�� num1^num2���ܱ�ʾ����������

        /*����һ��д��:
        double sign = 1.0;//����������ʹ������Ϊdouble
        sum += sign/i;
        sign = -sign;//ÿ��ѭ���任���ż���
        */
    }
    printf("sum=%lf",sum);
}