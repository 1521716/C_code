/*定义自己的函数实现strstr*/
#include<stdio.h>
//函数声明
char *my_strstr(const char *str1,const char *str2); 
int main()
{
	//初始化字符串和要查找的字符串 
	char str1[100] = {0},str2[100] = {0};
	printf("请输入字符串：");
	gets(str1);
	printf("请输入要查询的字符串：");
	gets(str2);
	
	//调用函数
	char *pstr = my_strstr(str1,str2);
	
	//输出结果
	printf("查找结果为：");
	if(pstr==NULL)
		printf("该字符串中无要查找元素！\n");
	else
		printf("%s\n",pstr); 
	return 0;
}

//函数声明
char *my_strstr(const char *str1,const char *str2)
{
	//定义辅助变量
	char *left = (char *)str1;
	char *right = (char *)str2;
	int len = 0;
	
	//计算要查询的字符串长度
	while(*right!='\0')
	{
		len++;
		right++;
	}
	
	//开始查找字符
	while(*(left+len-1)!='\0')
	{
		if(*left==*str2)
		{
			for(int i = 1;i<len;i++)
			{
				if(*(left+i)!=*(str2+i))
					break;
				else if(i==len-1&&*(left+i)==*(str2+i))
					return left;
			}
		}
		left++;
	}
	return NULL;
}
