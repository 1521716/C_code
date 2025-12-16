/*定义自己的函数实现strlen函数*/
#include<stdio.h>
//函数声明 
int my_strlen(const char* str);
//全局变量计数 
int count = 0;

int main()
{
	printf("请输入字符串：");
	char str[100] = { 0 };
	gets(str);
	int len = my_strlen(str);
	printf("该字符串的长度为：%d\n",len);
	return 0;
}

//函数定义 
int my_strlen(const char* str)
{
	if (*str == '\0')
		return count;
	else
	{
		count++;
		return my_strlen(str + 1);
	}
}
