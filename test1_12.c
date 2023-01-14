#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
struct Book
{
	char name[20];//C语言程序设计
	short price;//55
};//; 不可缺少，表示结构体的结束

int main()
{
	//利用结构体类型--创建一个该类型的结构体变量
	struct Book b1 = {"C语言程序设计",55};
	//修改书名：因为书名是一个数组，不能用b1.name = "C++"直接改写
	strcpy(b1.name, "C++");
	//strcpy--string copy(字符串拷贝)，库函数，使用时需引入头文件string.h
	printf("%s\n", b1.name);

	//struct Book* p = &b1;
	////利用p打印出书名和价格
	////方法1：结构体变量.成员
	////printf("%s\n",(*p).name);
	////printf("%d\n",(*p).price);
	////方法2：结构体变量->成员
	//printf("%s\n", p->name);
	//printf("%d\n", p->price);

	//printf("书名：%s\n", b1.name);
	//printf("价格：%d\n", b1.price);
	//b1.price = 15;
	//printf("修改后的价格：%d\n", b1.price);
	return 0;
}

//int main()
//{
//	char ch = 'w';
//	char* p = &ch;
//	*p = 'a';
//	printf("%c\n", ch);
//	printf("%d\n", sizeof(p));
//	return 0;
//}

//int main()
//{
//	int a = 10;//占4个字节
//	//指针变量 p 的类型为 int*
//	int* p = &a;//取a的地址存放于*p中
//	//指针变量p--用于存放地址
//	printf("%p\n", &a);
//	printf("%p\n", p);
//	*p = 20;//*--解引用操作符
//	//此处相当于通过*p中的地址找到对象a，并改为a=20
//	printf ("a = %d\n", a);
//	return 0;
//}

////函数的实现
//int Max(int x, int y)
//{
//	if (x > y)
//		return x; 
//	else 
//		return y;
//}
////define定义（带参数）宏
//#define MAX(X,Y) (X>Y?X:Y)
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//函数方式
//	int max = Max(a, b);
//	printf("max = %d\n", max);
//	//宏的方式
//	max = MAX(a, b);
//	//max = (a>b?a:b)
//	printf("max = %d\n", max);
//	return 0;
//}

//void test()
//{
//	//static 修饰局部变量
//	//局部变量的生命周期变长
//	static int a = 1;//a是一个静态局部变量
//	a++;
//	printf("a = %d\n", a);
//}
//int main()
//{
//	int i = 0;
//	while (i < 5)
//	{
//		test();
//		i++;
//	}
//	return 0;
//}

//int main()
//{
//	typedef unsigned int u_int;
//	//定义无符号的变量
//	//与unsinged int num = 20;同样效果
//	u_int num = 20;
//}

//int main()
//{
//	int a = 12;
//	int b = 36;
//	int max = 0;
//	//该式可替换下面if else表达式
//	max = (a > b ? a :b);
//	/*if (a > b)
//		max = a;
//	else
//		max = b;*/
//	printf("%d\n", max);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	//int b = a++;//后置++，先使用，再++
//	//printf("a = %d  b = %d\n", a, b);//10 11
//	int b = ++a;//前置++，先++，再使用
//	printf("a = %d  b = %d\n", a, b);//11 11
//	return 0;
//}

//int main()
//{
//	int a = 0;//4个字节，32个bit位
//	int b = ~a;//b是有符号的整形
//	//~--按（2进制）位取反 （符号位也要取反）
//	//0000000000 0000000000 0000000000 00（正）
//	//1111111111 1111111111 1111111111 11（负）
//	//原码、反码、补码
//	//负数在内存中存储时，存储的是二进制的补码
//	//二进制数的最高位表示符号位：0为正，1为负
//	//补码：1111111111 1111111111 1111111111 11
//	//反码：=补码-1，即1111111111 1111111111 1111111111 10
//	//原码：=反码取反（符号位不变），即1000000000 0000000000 0000000000 01
//	printf("%d\n",b);//使用的的/打印的是这个数的原码
//	return 0;
//}

//int main()
//{
//	//C语言中表示真假
//	//0--假
//	//所有非0--真
//	int a = 10;
//	printf("%d\n", a);
//	printf("%d\n", !a);
//}

//int main()
//{
//	int a = 3;//二进制：011
//	int b = 5;//二进制：101
//	int c = a&b;//按2进制位相与
//	//0&1,1&0,1&1 -->c的二进制为001，即十进制1
//	printf("%d\n", c);
//	return 0;
//}

//int main()
//{
//	//移（2进制）位操作符
//	int a =  1;
//	//整形1占4个字节--32bit位
//	//000000000000000000000000000000001
//	int b = a<<2;
//	//a<<2：00 00000000 0000000000 0000000000  100
//	//左端移去2个0，右端补上2个0，-->100，最后得到整形b=4
//	printf("%d\n", b);
//	return 0;
//}

//int main()
//{
//	//定义一个存放10个整形数字的数组
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int i = 0;
//	while(i<10)
//	{
//		printf("%d ", arr[i]);
//		i++;
//	}
//	return 0;
//}

////返回类型为int，Add为函数名，函数参数x、y为int型的变量
//int Add(int x, int y)
//{
//	//函数题
//	int z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 12;
//	int b = 16;
//	int num1 = 6;
//	int num2 = 9;
//	int sum1 = 0;
//	int sum2 = 0;
//	sum1 = Add(a, b);
//	sum2 = Add(num1, num2);
//	printf("sum1 = %d\n", sum1);
//	printf("sum2 = %d\n", sum2);
//}

//int main()
//{
//	int line = 0;
//	printf("公司实习\n");
//	while(line<6)
//	{
//		line++;
//		printf("敲一行代码：%d\n", line);
//	}
//	//条件：if(line>=6)
//	printf("好offer\n");
//	return 0;
//}

//int main()
//{
//	printf("%d\n", strlen("C:\test\32\test.c"));
//	//\32中的32是2个8进制数字
//	//3 2作为8进制所代表的十进制数字，对应一个ASCII码值，对应了一个字符
//	//3 2转化为10进制 -> 26，作为ASCII码值代表的字符
//	return 0;
//}

//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = {'a', 'b', 'c'};
//	//使用strlen需要加头文件 string.h
//	//strlen--即string length--计算字符串长度的
//	printf("%d\n", strlen(arr1));
//	printf("%d\n", strlen(arr2));
//	return 0;
//}

//int main()
//{
//	//const-- 常属性
//	const int num = 4;
//	printf("%d\n", num);
//	num = 8;//此时num不可再发生改变
//	printf("%d\n", num);
//}

//int main()
//{
//	//计算2个数的和
//	int num1 = 0;//定义一个初始值，可以任意
//	int num2 = 0;
//	int sum = 0;
//	//输入数据--使用输入函数scanf
//	scanf("%d%d", &num1, &num2);//取地址符号& （存入的数字将被放入一个地址）
//	//C语言语法规定，变量要定义在当前代码块（{}）的最前面
//	//int sum = 0; 不能定义在此处
//	sum = num1 + num2;
//	printf("sum = %d\n", sum);
//	return 0;
//}

//int main()
//{
//	////char-字符类型
//	//char ch = 'A';//内存
//	//printf("%c\n",ch);//%c--打印字符格式的数据
//
//	int age = 20;
//	printf("%d\n",age);//%d--打印整形十进制数据
//	return 0;
//}

////int是整形的意思
////main前面的int表示：main函数调用返回一个整形值
//int main()  //主函数-程序的入口-main函数有且仅有一个
//{
//	printf("hehe\n");
//	return 0; //返回0，与int main()配合使用
//}