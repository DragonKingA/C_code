#include <stdio.h>

void main(){
    int number[10];//�������� ������[����Ԫ�ظ���];
    //c99����֮������ñ�������������Ԫ�ظ���,c99֮ǰֻ�����볣�����Ͼ�
    //��ͬ��java�����鶨�巽ʽ�Ϳռ俪�ٷ�ʽ,java��:int number = new int[10]��Ч���������
    //������ظ�����java��ͬ������ ��η��������е�Ԫ����java��ͬ int receive = number[0];���ص�һ��Ԫ��
    //***������ע����Ǳ�����������������±�Խ�磬Խ���������ʿ���������⣬�������
    //   ��˱��뱣֤������±겻Խ�磡����
    int a[0];
    //����Ϊ0��������ڣ���û���κ��ô�������int x = a[0]Ҳ����Խ�����
    int set['a'];
    //�ַ�������Ϊ�±꣨����ʾԪ�ظ���������Ϊ�ַ�Char�ı���������

    //�������һϵ����ƽ������������
    int num,sum=0,times=0,count;
Back:
    printf("��������������:\n");
    scanf("%d",&count);//�û����������С
    if(count>0){
        int numset[count];
        printf("������һϵ������:\n");        
        while(times < count){
            scanf("%d",&num);
            numset[times]=num;    
            times++;
            sum += num;
            //printf("sum=%d\n",sum);
        }
        if(sum != -1){
            double average = 1.0*sum/count;           
            printf("����Ϊ����ƽ����%f����:\n",average);
            for(int i = 0;i<count;i++){
                if(numset[i]>average){
                    printf("%d ",numset[i]);
                }
            }
        }
    }else{
        printf("�������,����������\n");
        goto Back;
    }
}
/*
���룺
��һ���������T����ʾ��T������ʵ��
�ڶ����������n����ʾ��һ�����ܵ�����������������n�����ܵ�����
�Դ�����

�����
���ÿһ�������У�����ƽ�����ص�����������
*/
    //   int T;
    //   scanf("%d",&T);
    //   while(T--){
	//       int num,sum=0,times=0,count,countOW=0;
	//       scanf("%d",&count);
	//       if(count>0){
	//           int numset[count];
	//           while(times < count){
	//               scanf("%d",&num);
	//               numset[times]=num;    
	//               sum += num;
	//               times++;
	//           }
	         
	        
	          
	//         double average = 1.0*sum/count;           
	// 		//printf("average=%f,sum=%d",average,sum);
	//         for(int i = 0;i<count;i++){
	//           if(numset[i]>average){
	//             countOW++;
	//           }
	//         }
	//         printf("%d\n",countOW);
	//         countOW=0;
	//     }
    // }
   
