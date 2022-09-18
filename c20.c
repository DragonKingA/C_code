#include <stdio.h>
#include <math.h>
#define number 100
//���������С����

//�ж�һ�����Ƿ�Ϊ����
int ifPrime(int x){//����0Ϊ������,1Ϊ����
    if( x == 1 || (x%2 == 0 && x!=2)){//�Ų�Ϊ1��2������������Ƴ�Ϊż�������
        return 0;
    }
    for(int i = 3;i<sqrt(x);i++){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
    //�����������Ͻ��Ļ�������һ������ret��Ϊ����ֵ��ֻ�ں��������з��ز�����ʹ����ֻ�е�һ���ڣ��߼��Ͻ����׶�
}

//�ж�һ�����Ƿ�С�ڸ���������������������
int ifPrime_Ex(int x,int KnownPrimes[],int NumberOfKnownPrimes){
    int ret = 1;//0Ϊ������,1Ϊ����
    for(int i=0;i<NumberOfKnownPrimes;i++){
        if(x % KnownPrimes[i] == 0){
            ret = 0;
            break;
        }
    }
    return ret;
}




//һά����ı���
void PrintArray(int array[],int amount){
    for(int i=0;i<amount;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

//Ѱ�������������е����λ��
int search(int key,int arr[],int length){
    //*������Ϊ��������ʱ����������Ҫ������Ĳ������������鳤��
    //��[]�в���ֱ���ñ��ʽ��������鳤�ȣ�ֻ���������ֻ����
    //�ں����У���Ϊ���������鲻��ʹ��sizeof����ֽڳ���
    int ret = -1;
    for(int i=0;i<length;i++){
        if(arr[i]==key){
            ret = i;
            break;
        }
    }
    return ret;
}

void main(){
    //����������ʼ�����������ڵ�������ȷ��Ԫ��ϡ��ʱ.��ʱδȷ��Ԫ�ر�Ĭ��Ϊ0
    int arr1[]={[1]=2,4,[5]=6};// 0 2 4 0 0 6 
    int arr2[10]={[2]=2,[4]=4,5,6};// 0 0 2 0 4 5 6 0 0 0
    // [x]= �������൱�ڽ��������ƶ�������λ��Ϊx,���ж��ȷ��Ԫ�أ���ݴ������
    PrintArray(arr1,6);
    PrintArray(arr2,10);
    
    //sizeof()���������������һ��Ԫ����ռ�����ݵĴ�С����λ���ֽ�
    //%u��ʾ�޷���10�������ͣ�
    //%lu��ʾ����޷��ų��������� (long unsigned)
    printf("����arr1�����ֽڴ�С=%lu\n",sizeof(arr1));//24
    printf("����arr1����Ԫ��(��Ԫ��)�ֽڴ�С=%lu\n",sizeof(arr1[0]));//4
    //int��������ÿ��Ԫ��ռ��4���ֽڵĿռ�
    //�ʿ�����������������Ԫ�ظ���(���鳤��)
    int arr1len = sizeof(arr1)/sizeof(arr1[0]);//6
    printf("����arr1����=%d\n",arr1len);

    //�ҳ������������е����λ��
    int x=6;
    // printf("x=");
    // scanf("%d",&x);
    int location = search(x,arr1,arr1len);
    if(location != -1){
        printf("%d������λ��%d��",x,location);
    }else{
        printf("%d������",x);
    }


    // printf("x=");
    // scanf("%d",&x);
    // printf("���(0Ϊ������,1Ϊ����)��%d",ifPrime(x));
    // ���¸�ֵ�����������ڣ�����C�����������ͣ���const���Σ�
    //����ȫ��ͬ��java��������ڿ�����ַ�ĸ�ֵ,��arr1=arr2ʹ��arr1ָ��arr2��ָ���ڴ�ռ�(��ַ)
    // arr1 = arr2;   X
    // arr1[]=arr2;   X
    // arr1[]=arr2[]; X

    printf("\n");

    //ȡ���������Ż���
    /*
    ԭ���κκ������ܱ���������
    �κκ��������Ա�ʾ��a��b
    ��a,b����������,����a=m��n
    ��m,n����������,������ֽ�,������ֽܷ������
    *���ܴ�������x��x<m����������m
    */
    //const int number = 100;//�������������С  
    int prime[number]={2};//��ʼ���������飬�׸�����Ϊ2
    /*
    const int number = 100;
    int prime[number]={2};
    ���ϴ�����c���Ա�������C++ͨ��
    c������#define���徲̬������C++������const���徲̬��������Ϊconst��������ڴ�ռ䣬��define��
    */
    int count = 1;//����������������λ��(Ҳ����������֪�����ĸ���)
    for(int i = 3;count<number;i++){//*�ص㣺�˴�ѭ������Ϊcount<number������¼�����������ﵽ100����ͣ��,��ʱi����ֵ�ܿ��ܳ���100�ҽϴ�
        if(ifPrime_Ex(i,prime,count)){//Ϊ1��Ϊ������ִ��¼��
            prime[count++] = i;//��Ч��prime[count]=i;count++;
        }
    }
    //��������
    for(int i = 0;i<number;i++){
        printf("%d ",prime[i]);
        if( !(((i+1) % 5)>0)){printf("\n");}
    }


    printf("\n");
    //ֱ�ӹ���������
    //ԭ��
    //��֪��С����x=2������2x,3x,4x����ֱ��A*x<n����ʱ2x,3x����A*x�ؾ�Ϊ������,����Щ�������Ϊ��������
    //�����������а���Щ������Щ����������λ��ֵ�����Ϊ0
    //�˺��ٱ����������Ԫ��ֵΪ1������λ�ã���ʱ������λ��ֵ��������������
    int isPrime[number];//100���ڵ�������
    //��ʼ��Ϊ1
    for(int i=0;i<number;i++){
        isPrime[i]=1;
    }
    //�������¼��
    for(int numP=2;numP<number;numP++){
        if(isPrime[numP]){
            for(int i=2;i*numP<number;i++){
                isPrime[i*numP] = 0;
            }
        }
    }
    for(int i=2;i<number;i++){
        if(isPrime[i]){
            printf("%d ",i);
        }
        
    }


}