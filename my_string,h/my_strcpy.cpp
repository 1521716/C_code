/*定义自己函数实现strcpy函数*/
#include<stdio.h>
//函数定义
char *my_strcpy(char *str1,const char *str2); 
int main()
{
	//初始化两个字符串
	char str1[100] = {0},str2[100] = {0};
	printf("请输入原字符串：");
	gets(str1);
	printf("请输入要拷贝的字符串：");
	gets(str2);
	
	//调用函数
	char *pstr = my_strcpy(str1,str2);
	
	//输出结果
	printf("拷贝后字符串：");
	printf("%s",pstr); 
	return 0;	
} 

//函数定义 
char *my_strcpy(char *str1,const char *str2)
{
	//设置两个辅助指针，便于拷贝
	char *left = str1;
	const char *right = str2;
	
	//利用循环开始拷贝
	while(*right!='\0')
	{
		*left = *right;
		left++;
		right++;
	}
	printf("拷贝成功！\n");
	
	//返回str1指针
	return str1; 
} 
