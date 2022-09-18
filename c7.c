#include <stdio.h>
void main(){
	for(int j = 1;j++<=9;){
		printf("%d",j);//不会输出1，而是输出2，3，4，5，6，7，8，9，10
		//第一次循环先判断j=1 <= 9,随后就j++，再执行循环体内语句
	}




	//输出用户输入数的位数 
	int num,temp=0,i=0;
	scanf("%d",&num);//933,4
	temp = num;
	if(num > 0){
		while(num > 0){
			i++;
			if((num /= 10) == 0){
				printf("%d的位数为%d",temp,i);
			}
		}
	}else{
		printf("error");//超过十位数就会溢出并报错 
	}

	//如下与上述代码同理 ,java与C的do-while，while语句相同 
	//	do{
	//		i++;
	//		num/=10;
	//	} while(num>0);



	//键入正整数n,则计算n!的值
	int n,n0=1;
	scanf("%d",&n);
	//***部分版本的C语言不能在For语句内初始化变量，只能赋值
	//	 需要在for之外进行初始化
	for(int j=1;j<=n;j++){		
		n0 *= j;
	}
	printf("%d",n0);

	



	
}
