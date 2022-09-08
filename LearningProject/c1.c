#include <stdio.h>
int main()
{
	for(int j = 0;j<1;j++){
		
	}
	int price = 0;
	printf("12+34=%d\n",12+34);// %d意思是将后方计算后的整数值转换成字符串并置于此
	printf("请输入金额（元）：");
	scanf("%d",&price);
	// & 是 取地址运算符
	//这里scanf语句中有 & 加上 变量即&price，
	//意思是指向变量price的内存地址，使得用户输入的值存入该内存空间 
	printf("变量price的内存地址为%d\n",&price);//如果在printf语句中如此使用，则会输出变量price的具体内存地址 
	
	int change = 10000 - price; 
	printf("找回您%d元\n",change);
	return 0;
 } 
