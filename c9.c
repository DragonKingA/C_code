#include <stdio.h>
void main(){

    //��һϵ������ƽ����
    int num,sum=-1,times=0;
    printf("������һϵ����������������-1��Ϊֹͣ����:\n");
    scanf("%d",&num);
    while(num != -1){    
        times++;
        sum += num;
        scanf("%d",&num);
    }
    if(sum != -1){
        sum++;//��ֵ
        printf("ƽ����Ϊ%f",1.0*sum/times);
        //***������1.0ȥ����sumʹ����Ϊ����ֵ
        //ͬ��java��double average = sum/times
        //ֻ���С������Ϊ0��С��,�����ǽӽ�ʵ�ʵĽ��
    }
    
}