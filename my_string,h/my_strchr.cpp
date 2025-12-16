/*定义自己的函数实现strchr*/
#include<stdio.h>
//函数声明
char *my_strchr(const char *str,int ch); 
int main()
{
	//初始化字符串和要查找的字符
	char str[20] = {0};
	int ch = 0;
	printf("请输入字符串：");
	gets(str);
	printf("请输入要查询的字符：");
	scanf("%c",&ch);
	
	//调用函数
	char *pstr = my_strchr(str,ch);
	
	//输出结果
	printf("查找结果为：");
	if(*pstr==NULL)
		printf("该字符串中无要查找元素！\n");
	else
		printf("%s\n",pstr); 
	return 0;
}

//函数声明
char *my_strchr(const char *str,int ch)
{
	//定义辅助变量
	char *pstr = (char *)str;
	
	//开始查找字符
	while(*pstr!='\0')
	{
		if(*pstr==ch)
			return pstr;
		pstr++;
	}
	return pstr;
}
