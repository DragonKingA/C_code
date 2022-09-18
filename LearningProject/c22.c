#include <stdio.h>

void main(){
    //年薪N万，房子起价200万，每年百分之K增长,    (200*100+K)/100 每年增长后房价
    //若20年或之前就能买下，就输出M，否则输出Impossible
    int N;
    int K;
    int M=1;//买房子年份
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