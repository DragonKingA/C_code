#include <stdio.h>

int main(){
    //���ǰn������
    int num=2,n,count=0;
    printf("ѡ����������ĸ���:");
    scanf("%d",&n);
    for(;count<n;num++){
        int i,ifPrime;//��ifPrime=1������Ϊ����
        //**ע�⣺�˴����붨��ȫ�ֱ���
        //�����for����ڳ�ʼ�����������ֲ�������,��num=2ʱ�������ж���������ΪFor���ľֲ�����i��ifPrime���ᱻ����
        for(i = 2,ifPrime = 1;i<num;i++){
            if(num % i == 0){
                ifPrime=0;
                break;
            }
        }
        // printf("i=%d ",i);
        if(ifPrime == 1 ){
            count++;
            printf("%d ",num);
        }
    }
 
    return 0;
}