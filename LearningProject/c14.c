#include <stdio.h>
#include <math.h>

void main(){

//�����Լ��gcd
    int a,b,mode,reminder,gcd,a_temp,b_temp,temp,temp_origin;
GetMaxOfgcd:
//���ڱ����ִ�����int a,b,mode,reminder,gcd;��Ϊ����goto��ת������,���ܻᵼ���޷����壬�������ж��߼���������
    printf("�����������Լ����������������\n");
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);

    //ʹ��a>=b
    if(a == 0 || b == 0){
    printf("�������,����������\n");
    goto GetMaxOfgcd;
    }else if(b>a){
        temp_origin=a;
        a=b;
        b=temp_origin;
    }
    /*
    if��else if(�������)�ǲ������߶�ִ�еģ�ֻ�����ִ�н�������һ�ߣ�
    �������˵�һ��if���㲻���ж�����κ�else if������Ҳ����ִ�����д���
    */
    // if(b>a){
    //     temp_origin=a;
    //     a=b;
    //     b=temp_origin;
    // }else if(a == 0 || b == 0){
    //     printf("�������,����������\n");
    //     goto GetMaxOfgcd;
    // }

    //�洢ԭa,b��ֵ������������
    a_temp=a;
    b_temp=b;

    printf("��ѡ����(1.ö��2.շת���3.�������):");
    scanf("%d",&mode);
    if(mode == 1){
        //1.ö�ٷ�:
        //����С������Ϊѭ�������ѭ������
        //ö��
        for(int i=1;i <= b;i++){
            if(a % i == 0  && b % i == 0){
                gcd = i;
            }
        }
        printf("%d��%d�����Լ��Ϊ%d\n",a_temp,b_temp,gcd);

    }else if(mode == 2){
        //2.շת�����:
        // 144%88=1...56
        // 88%56=1...32
        reminder = a % b;
        while(reminder >= 0){//�ر�ע������Ϊreminder>=0,ʹ�õ�reminder=0ʱ�ܹ�ͨ��һ��ѭ����gcd=b���Խ���
            reminder = a % b;
            if(reminder == 0){
                gcd=b;
                break;
            }
            a=b;
            b=reminder;
        }
        printf("%d��%d�����Լ��Ϊ%d\n",a_temp,b_temp,gcd);

    }else if(mode == 3){
        //3.�������:
        while(a>0){
            if(a<b){
                temp=a;
                a=b;
                b=temp;
            }
            a -= b;
            if(a == 0){
                gcd=b;
            }
        }
        printf("%d��%d�����Լ��Ϊ%d\n",a_temp,b_temp,gcd);

    }else{
        printf("�������,����������\n");
        goto GetMaxOfgcd;

    }

//�ն�����·����λ������gcc����ʶ���ļ�����ʾû�������ļ������������
//����cd D:\ClanguageCorrelations\C_code\LearningProjectת��·��


    //*������:
    goto GetMaxOfgcd;









//=================================================================================================================
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