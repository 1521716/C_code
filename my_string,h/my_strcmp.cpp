/*定义自己的函数实现strcmp*/ 
#include<stdio.h>
//函数声明
int my_strcmp(const char *str1,const char *str2); 
int main()
{
	//初始化两个字符串
	char str1[20] = {0},str2[20] = {0};
	printf("请输入第一个字符串：");
	gets(str1);
	printf("请输入第二个字符串：");
	gets(str2);
	
	//调用函数
	int result = my_strcmp(str1,str2);
	
	//输出结果
	if(result>0)
		printf(">\n");
	else if(result==0)
		printf("=\n");
	else
		printf("<\n"); 
	return 0;
} 

//函数定义 
int my_strcmp(const char *str1,const char *str2)
{
	//定义辅助变量
	const char *left = str1;
	const char *right = str2;
	
	//利用循环比较字符串大小
	while(*left!='\0'&&*right!='\0')
	{
		if((int)*left>(int)*right)
			return 1;
		else if((int)*left<(int)*right)
			return -1;
		else
		{
			left++;
			right++;
		}
	}
	if(*left=='\0'&&*right=='\0')
		return 0;
	else if(*left=='\0')
		return -1;
	else
		return 1;
}
