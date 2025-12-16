#include<stdio.h>
//函数声明
void ReplaceString(char *str,char ch1,char ch2); 
int main()
{
	//初始化字符串 
	char str[100] = {0};
	printf("please input string:");
	gets(str); 
	
	//用户输入要修改的字符和要改成的字符
	char ch1 = '0',ch2 = '0';
	printf("请输入要修改的字符：");
	scanf("%c",&ch1);
	while(getchar()!='\n');
	printf("请输入要改成的字符：");
	scanf("%c",&ch2);
	while(getchar()!='\n');
	
	//调用函数
	ReplaceString(str,ch1,ch2);
	
	//打印更改后的字符串 
	printf("更改后的字符串：");
	printf("%s",str); 
	return 0;
}

//函数定义
void ReplaceString(char *str,char ch1,char ch2)
{
	//两种情况，可能字符串中无要修改的元素 
	int sign = 1;
	char *tem = str;
	while(*tem!='\0')
	{
		if(*tem==ch1)
		{
			*tem = ch2;
			sign = 0;	
		}	
		tem++;
	}
	if(sign)
		printf("字符串中无“%c”，故不修改！\n",ch1);
	else
		printf("修改成功！\n");
} 
