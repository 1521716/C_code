#include<stdio.h>
#include<string.h>
//函数声明
int Ishuiwen(char *str); 
int main()
{
	//初始化字符串 
	printf("请输入要判断的字符串：");
	char str[100] = {0};
	gets(str);
	
	//调用函数
	int result = Ishuiwen(str); 
	
	//输出结果
	if(result)
		printf("该字符串是回文！\n");
	else
		printf("该字符串不是回文！\n"); 
	return 0;
}
//函数定义 
int Ishuiwen(char *str)
{
	int left = 0,right = strlen(str)-1;
	while(left<=right)
	{
		if(*(str+left)!=*(str+right))
			return 0;
		left++;
		right--;
	}
	return 1;
}
