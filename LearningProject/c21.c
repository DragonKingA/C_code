#include <stdio.h>
#define SizeofArray 12

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
    int index_min,index_max,index_mid;
    int num;//Ҫ��������
    printf("������Ҫ����������");
    scanf("%d",&num);
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




}