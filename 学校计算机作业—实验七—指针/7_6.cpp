#include<stdio.h>
#include<string.h>
void SwapStr(char *str1,char *str2);
int main()
{
	//初始化字符串
	char str[3][20] = {0};
	printf("请输入三个学生的英文名：\n");
	for(int i = 0;i<3;i++)
	{
		gets(str[i]);
	} 
	
	//开始排序
	for(int i = 0;i<3-1;i++)
	{
		for(int j = 0;j<3-1-i;j++)
		{
			if(strcmp(str[j],str[j+1])>0)
			{
				SwapStr(str[j],str[j+1]);
			}
		}
	} 
	printf("排序完成！\n");
	
	//输出排序结果
	printf("排序结果为：\n");
	for(int i = 0;i<3;i++)
	{
		printf("%s\n",str[i]);
	} 
	return 0;
}

//函数定义
void SwapStr(char *str1,char *str2)
{
	char tem[20] = {0};
	strcpy(tem,str1);
	strcpy(str1,str2);
	strcpy(str2,tem);
} 
