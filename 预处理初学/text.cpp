#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#define N 100
//#define STR "hello world!"
//#define MAX(x,y) (x>y?x:y)
//#define DOUBLE(x) ((x)*2)
//#define PRINT(N) printf("the value of "#N" is %d\n", N)
//#define CAT(Class,Num) Class##Num
//int main()
//{
//	//define本质为替换，注意，只是替换，不会额外加东西
//
//
//	/*
//	几个已经被定义的变量：
//	__FILE__:文件路径
//	__LINE__:行数
//	__TIME__:当前时间
//	__DATE__:当前日期*/
//
//	//printf("%s\n%s\n%s\n%d\n", __FILE__, __DATE__, __TIME__, __LINE__);
//	
//	//define起定义常量的作用
//	//printf("%d", N);
//
//	//define起定义字符串作用
//	//printf("%s", STR);
//
//	//define起类似比较两者最大值的作用
//	/*int max = MAX(3, 4);
//	printf("%d", max);*/
//
//	//define起类似双倍变量的作用
//	/*int y = DOUBLE(10);
//	printf("%d", y);*/
//
//	//‘#’与'##'的作用
//	//‘#’的作用：将变量名转化为字符串
//	/*int a = 10;
//	printf("the value of a is %d\n", a);
//	PRINT(a);*/				//两者打印结果相同
//
//	//‘##’的作用：将两侧变量名链接为一个
//	/*int Class106 = 100;
//	printf("%d\n", Class106);
//	printf("%d\n", CAT(Class, 106));*/
//
//	return 0;
//}

//#if 1
//#define MAX(x,y) x>y?x:y
//#endif
//int main()
//{
//	int a = MAX(10, 20);
//	printf("%d", a);
//	return 0;
//}

int main()
{
	/*'&'按位与
	 ‘|’按位或
	 ‘<<’（左移）运算符*/
	//‘&’：对于二进制字节，若均为1，则是1，否则为0
	//int a = 10;//1010
	//int b = 6;//0110
	//int c = a & b;//0010 = 2
	//printf("%d", c);
	//'|':对于二进制字节，若有一个为1，则是1，否则为0
	//int a = 10;//1010
	//int b = 6;//0110
	//int c = a | b;//1110 = 14
	//printf("%d", c);
	//'<<':将二进制为整体左移，不越界前提下，a<<x =a*（2 的 x次方）
	//int a = 10;
	//a = a << 2;//10*2*2 = 40
	//printf("%d", a);

	return 0;
}