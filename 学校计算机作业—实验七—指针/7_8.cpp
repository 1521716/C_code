#include<stdio.h>
#include<string.h>
//函数声明
char *Shift_month(char month[12][10],int m); 
int main()
{
	//初始化月份字符数组
	char month[12][10] = {"January","February","March","April","May","June",
						  "July","August","September","October","November","December"};
	
	//用户输入
	printf("请输入月份：");
	int m = 0;
	scanf("%d",&m);
	
	//调用函数
	char *Month = Shift_month(month,m); 
	
	//输出转换结果
	printf("转化结果为：");
	printf("%s",Month); 
	return 0;
} 

//函数定义 
char *Shift_month(char month[12][10],int m)
{
	return *(month+m-1);
}
