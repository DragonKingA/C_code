#include <stdio.h>

void main(){
    int number[10];//数组类型 数组名[数组元素个数];
    //c99及其之后可以用变量来定义数组元素个数,c99之前只能输入常量如上句
    //不同于java的数组定义方式和空间开辟方式,java中:int number = new int[10]等效于上述语句
    //其余相关概念与java相同，包括 如何返回数组中的元素与java相同 int receive = number[0];返回第一个元素
    //***但必须注意的是编译器不会检查数组的下标越界，越界的数组访问可能造成问题，程序崩溃
    //   因此必须保证数组的下标不越界！！！
    int a[0];
    //长度为0的数组存在，但没有任何用处，并且int x = a[0]也算是越界操作
    int set['a'];
    //字符可以作为下标（即表示元素个数），因为字符Char的本质是整数

    //输出大于一系列数平均数的所有数
    int num,sum=0,times=0,count;
Back:
    printf("请输入整数数量:\n");
    scanf("%d",&count);//用户决定数组大小
    if(count>0){
        int numset[count];
        printf("请输入一系列整数:\n");        
        while(times < count){
            scanf("%d",&num);
            numset[times]=num;    
            times++;
            sum += num;
            //printf("sum=%d\n",sum);
        }
        if(sum != -1){
            double average = 1.0*sum/count;           
            printf("以下为大于平均数%f的数:\n",average);
            for(int i = 0;i<count;i++){
                if(numset[i]>average){
                    printf("%d ",numset[i]);
                }
            }
        }
    }else{
        printf("输入错误,请重新输入\n");
        goto Back;
    }
}
/*
输入：
第一行输入参数T，表示有T个测试实例
第二行输入参数n，表示这一组青蛙的数量，第三行输入n个青蛙的体重
以此类推

输出：
输出每一组青蛙中，超出平均体重的青蛙数量。
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
   
