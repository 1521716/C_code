#include<stdio.h>
//函数声明
char *StringCat(char *str1,char *str2); 
int main()
{
	//初始化两个字符串
	printf("请输入原字符串：");
	char str1[100] = {0};
	gets(str1);
	printf("请输入要连接的字符串：");
	char str2[100] = {0};
	gets(str2);
	
	//调用函数
	char *str = StringCat(str1,str2);
	
	//打印连接后的字符串
	printf("连接完成后的字符串为：");
	printf("%s",str); 
	return 0;
}

//函数定义 
char *StringCat(char *str1,char *str2)
{
	char *left = str1;
	char *right = str2;
	while(1)
	{
		if((*left)=='\0')
		{
			while((*right!='\0'))
			{
				*left = *right;
				left++;
				right++;
			}
			break;
		}
		left++;
	}
	return str1;
} 
