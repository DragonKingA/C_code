#include <stdio.h>
void main(){
    int value = (100 - 90)/2;
    //�������һ��������Ϊһ�����ʽ�����а��� �����(operator) �� ����(operand)
    //���ӣ�ָ���������ֵ��������������һ�������ķ���ֵ�����������Ľ��ձ���
    int a = 2;
    int b = 3;
    printf("2*-3=%d\n",a*-b);//���-6
    //a*-bָa��b��˺���ȡ��ֵ���˴���-����Ϊ��Ŀȡ��������أ����������ϡ������ڼ���������
    //a*+bָ�����Ϊ��ֵ���䣬�˴���+����Ϊ��Ŀ���䣬����أ����������ϡ������ڼӺ����ӷ�
    //һ��أ�����������������ҽ�ϣ�����������������е�Ŀȡ������Ŀ���䡢��ֵ��=��
    
    int c,d;
    c=d=6;
    //��C�����и�ֵ�����ĵȺš�=��Ҳ��һ�ֲ�����������㣬������������ִ��
    //������䣬��ִ��d=6����6��ֵ��d����d=6�������6,����c=6����6��ֵ��c
    //c=d=6 --> c= ( d=6 ) --> c= 6  

    //����ʱ���
    int hour1,minute1;
    int hour2,minute2;
    printf("��ֱ���������ʱ��:X(ʱ) X(��):");
    scanf("%d %d",&hour1,&minute1);
    scanf("%d %d",&hour2,&minute2);
    int time1 = hour1 * 60 + minute1;
    int time2 = hour2 * 60 + minute2;
    int difference = 0;
    if(time1 > time2){
        difference = time1 - time2;
    }else{
        difference = time2 - time1;
    } 
    printf("����ʱ���ʱ���Ϊ%d����,",difference);
    printf("�ֻ���˵ʱ���Ϊ%dʱ%d��",difference / 60,difference % 60);
}