#include <stdio.h>
int main()
{
	for(int j = 0;j<1;j++){
		
	}
	int price = 0;
	printf("12+34=%d\n",12+34);// %d��˼�ǽ��󷽼���������ֵת�����ַ��������ڴ�
	printf("�������Ԫ����");
	scanf("%d",&price);
	// & �� ȡ��ַ�����
	//����scanf������� & ���� ������&price��
	//��˼��ָ�����price���ڴ��ַ��ʹ���û������ֵ������ڴ�ռ� 
	printf("����price���ڴ��ַΪ%d\n",&price);//�����printf��������ʹ�ã�����������price�ľ����ڴ��ַ 
	
	int change = 10000 - price; 
	printf("�һ���%dԪ\n",change);
	return 0;
 } 
