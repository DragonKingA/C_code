#include <stdio.h>

int main(){
    int one,two,five;
    int money;
    int ifAllin;
    printf("��������ת�����������:");
    scanf("%d",&money);
    printf("��ѡ��ת��ģʽ��1��ȫ��������0��һ��������:");
    scanf("%d",&ifAllin);
    for(int i = 1;i<=money*10/5;i++){
        five = i;
        for(int j = 1;j<=money*10/2;j++){
            two = j;
            for(int z = 1;z<=money*10;z++){
                one = z;
                if(one+two*2+five*5 == money*10){
                    printf("%d��5��Ӳ��+%d��2��Ӳ��+%d��1��Ӳ�ҿ��Դճ�%dԪ\n",five,two,one,money);
                    if(ifAllin == 0){
                        goto exit;
                        //goto :����ֱ����ת�������ţ�ִ�б�ź����
                        //��goto�����ƻ�����ľ����߼����ڱ�Ҫ���(����������ѭ��)���ܿ�����ʹ�ã��ɶ��Բ�
                    }
                }
            }
        }
    }
    //��ת��ţ���ʹ�ã��������о����������
exit:
    return 0;


}