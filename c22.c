#include <stdio.h>

void main(){
    //��нN�򣬷������200��ÿ��ٷ�֮K����,    (200*100+K)/100 ÿ�������󷿼�
    //��20���֮ǰ�������£������M���������Impossible
    int N;
    int K;
    int M=1;//�������
    int i=1;
    scanf("%d %d",&N,&K);
    double sum = 200;
    while(i<22){
        //printf("sum=%lf",sum);
        if(N*i >= sum){
            M = i;
            break;
        }
        sum += sum*K/100;
        i++;
    }
    if(M <= 20){
        printf("%d",M);
    }else{
        printf("Impossible");
    }
    



}