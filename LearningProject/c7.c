#include <stdio.h>
void main(){
	for(int j = 1;j++<=9;){
		printf("%d",j);//�������1���������2��3��4��5��6��7��8��9��10
		//��һ��ѭ�����ж�j=1 <= 9,����j++����ִ��ѭ���������
	}




	//����û���������λ�� 
	int num,temp=0,i=0;
	scanf("%d",&num);//933,4
	temp = num;
	if(num > 0){
		while(num > 0){
			i++;
			if((num /= 10) == 0){
				printf("%d��λ��Ϊ%d",temp,i);
			}
		}
	}else{
		printf("error");//����ʮλ���ͻ���������� 
	}

	//��������������ͬ�� ,java��C��do-while��while�����ͬ 
	//	do{
	//		i++;
	//		num/=10;
	//	} while(num>0);



	//����������n,�����n!��ֵ
	int n,n0=1;
	scanf("%d",&n);
	//***���ְ汾��C���Բ�����For����ڳ�ʼ��������ֻ�ܸ�ֵ
	//	 ��Ҫ��for֮����г�ʼ��
	for(int j=1;j<=n;j++){		
		n0 *= j;
	}
	printf("%d",n0);

	



	
}
