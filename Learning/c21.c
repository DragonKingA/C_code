#include <stdio.h>
#define SizeofArray 12

//ͨ������õ�һ����������
//1.ѡ�����������������������������������������󣬲��Դ�ѭ��ֱ��ʣ�����������ж���

//2.ð������(�Ե�һ��Ԫ����ͷ������һλ��Ԫ�رȽϣ����ߺ��ƣ����ѭ��)
//int ArrayInTurn[SizeofArray];
void LetArrayInTurn(int arr[])
{
    int temp;
    for(int i=0;i<SizeofArray-1;i++){
        for(int j=1;j<SizeofArray-i;j++){
            if(arr[j-1]>arr[j]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}



void main(){
    //����ṹ�壨������Java�Ķ���
    struct {
        int amount;
        char *name;//�ַ���ָ��
        //{amount,name}
    } coins[] = {
        {1,"penny"},
        {5,"nickel"},
        {10,"dime"},
        {25,"quarter"},
        {50,"half-dollar"}
    };

    int money = 10;//��Ӧ��dime��
    for(int i=0;i<sizeof(coins)/sizeof(coins[0]);i++){
        if( money == coins[i].amount){//��ȡ����coins�е�amount��
            printf("%s\n",coins[i].name);//�������coins�ж�Ӧ��name��
            break;
        }
    }

    //��һ�������飬�ö�������������һ����
    //���ַ�Ч�ʸߣ���������num�������������Ϊlog2(num),��num=1000�����������10��
    int index_min,index_max,index_mid;
    int num = 22;//Ҫ��������
    // printf("������Ҫ����������");
    // scanf("%d",&num);
    int arr[SizeofArray]={1,22,41,44,54,65,81,99,100,105,230,600};
    index_min=0;
    index_max=SizeofArray;
    for(int i=0;i<SizeofArray;i++){
        index_mid=(index_min+index_max)/2;
        if(arr[index_mid] != num){
            if(arr[index_mid] < num){
                index_min = index_mid;
            }else{
                index_max = index_mid;
            }
        }else{
            printf("%d����������λ��Ϊ%d��Ԫ��",num,index_mid);
            break;
        }
        if(i == SizeofArray - 1){
            printf("%d���ڸ�������",num);
            break;
        }
    }

    printf("\n");

    //�����������
    int ArrayMix[SizeofArray] = {3,6,18,2,5,8,99,30,20,50,60,};
    LetArrayInTurn(ArrayMix);
    //����
    for(int i=0;i<SizeofArray;i++){
        printf("%d ",ArrayMix[i]);
    }

}