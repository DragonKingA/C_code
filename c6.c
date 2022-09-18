#include <stdio.h>
int main(){
	//用于条件判定的6个关系运算符:==、!=、>、>=、<、<=
	//此处C语言与JAVA基本相同 
	int a = -1;
	int r = a > 0;
	//***而不同的是，C语言的逻辑表达式返回的值为0或1
	//   故上述a>0返回0，故r=0 
	printf("%d\n",r);
	
	//读入一个正3位数，输出按位逆序的数字，注：输出数字不用带有前导0，如700输出7即可
	int num,numRV;//246
	printf("请输入一个3位整数:");
	scanf("%d",&num); 
	if(num > 999 || num < -999){
		printf("输入有误，请重新运行输入正确的3位数字!");
		return 0;
	}else{
		numRV = num/100 + (num%100-num%10) +num%10*100;
		printf("%d",numRV);
		return 0;
	}

}
