#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
struct Book
{
	char name[20];//C���Գ������
	short price;//55
};//; ����ȱ�٣���ʾ�ṹ��Ľ���

int main()
{
	//���ýṹ������--����һ�������͵Ľṹ�����
	struct Book b1 = {"C���Գ������",55};
	//�޸���������Ϊ������һ�����飬������b1.name = "C++"ֱ�Ӹ�д
	strcpy(b1.name, "C++");
	//strcpy--string copy(�ַ�������)���⺯����ʹ��ʱ������ͷ�ļ�string.h
	printf("%s\n", b1.name);

	//struct Book* p = &b1;
	////����p��ӡ�������ͼ۸�
	////����1���ṹ�����.��Ա
	////printf("%s\n",(*p).name);
	////printf("%d\n",(*p).price);
	////����2���ṹ�����->��Ա
	//printf("%s\n", p->name);
	//printf("%d\n", p->price);

	//printf("������%s\n", b1.name);
	//printf("�۸�%d\n", b1.price);
	//b1.price = 15;
	//printf("�޸ĺ�ļ۸�%d\n", b1.price);
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
//	int a = 10;//ռ4���ֽ�
//	//ָ����� p ������Ϊ int*
//	int* p = &a;//ȡa�ĵ�ַ�����*p��
//	//ָ�����p--���ڴ�ŵ�ַ
//	printf("%p\n", &a);
//	printf("%p\n", p);
//	*p = 20;//*--�����ò�����
//	//�˴��൱��ͨ��*p�еĵ�ַ�ҵ�����a������Ϊa=20
//	printf ("a = %d\n", a);
//	return 0;
//}

////������ʵ��
//int Max(int x, int y)
//{
//	if (x > y)
//		return x; 
//	else 
//		return y;
//}
////define���壨����������
//#define MAX(X,Y) (X>Y?X:Y)
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//������ʽ
//	int max = Max(a, b);
//	printf("max = %d\n", max);
//	//��ķ�ʽ
//	max = MAX(a, b);
//	//max = (a>b?a:b)
//	printf("max = %d\n", max);
//	return 0;
//}

//void test()
//{
//	//static ���ξֲ�����
//	//�ֲ��������������ڱ䳤
//	static int a = 1;//a��һ����̬�ֲ�����
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
//	//�����޷��ŵı���
//	//��unsinged int num = 20;ͬ��Ч��
//	u_int num = 20;
//}

//int main()
//{
//	int a = 12;
//	int b = 36;
//	int max = 0;
//	//��ʽ���滻����if else���ʽ
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
//	//int b = a++;//����++����ʹ�ã���++
//	//printf("a = %d  b = %d\n", a, b);//10 11
//	int b = ++a;//ǰ��++����++����ʹ��
//	printf("a = %d  b = %d\n", a, b);//11 11
//	return 0;
//}

//int main()
//{
//	int a = 0;//4���ֽڣ�32��bitλ
//	int b = ~a;//b���з��ŵ�����
//	//~--����2���ƣ�λȡ�� ������λҲҪȡ����
//	//0000000000 0000000000 0000000000 00������
//	//1111111111 1111111111 1111111111 11������
//	//ԭ�롢���롢����
//	//�������ڴ��д洢ʱ���洢���Ƕ����ƵĲ���
//	//�������������λ��ʾ����λ��0Ϊ����1Ϊ��
//	//���룺1111111111 1111111111 1111111111 11
//	//���룺=����-1����1111111111 1111111111 1111111111 10
//	//ԭ�룺=����ȡ��������λ���䣩����1000000000 0000000000 0000000000 01
//	printf("%d\n",b);//ʹ�õĵ�/��ӡ�����������ԭ��
//	return 0;
//}

//int main()
//{
//	//C�����б�ʾ���
//	//0--��
//	//���з�0--��
//	int a = 10;
//	printf("%d\n", a);
//	printf("%d\n", !a);
//}

//int main()
//{
//	int a = 3;//�����ƣ�011
//	int b = 5;//�����ƣ�101
//	int c = a&b;//��2����λ����
//	//0&1,1&0,1&1 -->c�Ķ�����Ϊ001����ʮ����1
//	printf("%d\n", c);
//	return 0;
//}

//int main()
//{
//	//�ƣ�2���ƣ�λ������
//	int a =  1;
//	//����1ռ4���ֽ�--32bitλ
//	//000000000000000000000000000000001
//	int b = a<<2;
//	//a<<2��00 00000000 0000000000 0000000000  100
//	//�����ȥ2��0���Ҷ˲���2��0��-->100�����õ�����b=4
//	printf("%d\n", b);
//	return 0;
//}

//int main()
//{
//	//����һ�����10���������ֵ�����
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int i = 0;
//	while(i<10)
//	{
//		printf("%d ", arr[i]);
//		i++;
//	}
//	return 0;
//}

////��������Ϊint��AddΪ����������������x��yΪint�͵ı���
//int Add(int x, int y)
//{
//	//������
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
//	printf("��˾ʵϰ\n");
//	while(line<6)
//	{
//		line++;
//		printf("��һ�д��룺%d\n", line);
//	}
//	//������if(line>=6)
//	printf("��offer\n");
//	return 0;
//}

//int main()
//{
//	printf("%d\n", strlen("C:\test\32\test.c"));
//	//\32�е�32��2��8��������
//	//3 2��Ϊ8�����������ʮ�������֣���Ӧһ��ASCII��ֵ����Ӧ��һ���ַ�
//	//3 2ת��Ϊ10���� -> 26����ΪASCII��ֵ������ַ�
//	return 0;
//}

//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = {'a', 'b', 'c'};
//	//ʹ��strlen��Ҫ��ͷ�ļ� string.h
//	//strlen--��string length--�����ַ������ȵ�
//	printf("%d\n", strlen(arr1));
//	printf("%d\n", strlen(arr2));
//	return 0;
//}

//int main()
//{
//	//const-- ������
//	const int num = 4;
//	printf("%d\n", num);
//	num = 8;//��ʱnum�����ٷ����ı�
//	printf("%d\n", num);
//}

//int main()
//{
//	//����2�����ĺ�
//	int num1 = 0;//����һ����ʼֵ����������
//	int num2 = 0;
//	int sum = 0;
//	//��������--ʹ�����뺯��scanf
//	scanf("%d%d", &num1, &num2);//ȡ��ַ����& ����������ֽ�������һ����ַ��
//	//C�����﷨�涨������Ҫ�����ڵ�ǰ����飨{}������ǰ��
//	//int sum = 0; ���ܶ����ڴ˴�
//	sum = num1 + num2;
//	printf("sum = %d\n", sum);
//	return 0;
//}

//int main()
//{
//	////char-�ַ�����
//	//char ch = 'A';//�ڴ�
//	//printf("%c\n",ch);//%c--��ӡ�ַ���ʽ������
//
//	int age = 20;
//	printf("%d\n",age);//%d--��ӡ����ʮ��������
//	return 0;
//}

////int�����ε���˼
////mainǰ���int��ʾ��main�������÷���һ������ֵ
//int main()  //������-��������-main�������ҽ���һ��
//{
//	printf("hehe\n");
//	return 0; //����0����int main()���ʹ��
//}