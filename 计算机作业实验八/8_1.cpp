#include<stdio.h>

//定义结构体 
struct Time{
	int hour;
	int minute;
	int second;
}; 

int main()
{
	//定义结构体变量
	Time time = {0};
	//输入信息
	printf("请输入时间信息（时:分:秒）：");
	scanf("%d:%d:%d",&(time.hour),&(time.minute),&(time.second));
	//判断上下午 
	if(time.hour>12)
	{
		//输出时间
		printf("PM %d:%d:%d\n",time.hour-12,time.minute,time.second);
	} 
	else
		//输出时间
		printf("AM %d:%d:%d\n",time.hour,time.minute,time.second);
	
	return 0;
} 

