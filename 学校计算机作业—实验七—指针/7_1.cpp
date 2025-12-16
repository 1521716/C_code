#include<stdio.h>
//交换函数的声明 
void Swap(int *a,int *b);
int main()
{
	//数组储存年龄数据 
	int old[3] = {0};
	
	//用户输入 
	printf("please enter three ages:");
	for(int i = 0;i<3;i++)
	{
		scanf("%d",&old[i]);	
	}
	
	//冒泡排序 
	for(int j = 0;j<3-1;j++)
	{
		int sign = 1;
		for(int k = 0;k<3-1-j;k++)
		{
			if(old[k]>old[k+1])
			{
				Swap(&old[k],&old[k+1]);
				sign = 0;
			}
		}
		if(sign)
		break;
	}
	
	//输出排序后数据 
	printf("三个学生的年龄由小到大为：\n");
	for(int i = 0;i<3;i++)
	{
		printf("%d ",old[i]);
	}
	return 0;
}

//函数定义，交换两个整数的值 
void Swap(int *a,int *b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}
