/*定义自己函数实现strcat函数*/
#include<stdio.h>
//函数声明
char *my_strcat(char *str1,const char *str2); 
int main()
{
	//初始化两个字符串
	char str1[100] = {0},str2[100] = {0};
	printf("请输入起始字符串：");
	gets(str1);
	printf("请输入要连接的字符串：");
	gets(str2);
	
	//调用函数
	char *pstr = my_strcat(str1,str2);
	
	//输出结果
	printf("连接后的字符串为：");
	printf("%s",pstr); 
	return 0;
}

//函数定义 
char *my_strcat(char *str1,const char *str2)
{
	//设置辅助变量
	char *left = str1;
	const char *right = str2; 
	
	//运用循环实现函数
	while(1)
	{
		if(*left=='\0')
		{
			while(*right!='\0')
			{
				*left = *right;
				left++;
				right++;
			}
			return str1;
		}
		left++;
	} 
}
