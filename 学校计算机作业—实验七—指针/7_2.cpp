#include<stdio.h>
//函数声明
//输入函数
void Input_score(int score[100],int *n); 
//逆序排序函数
void Sort_score(int score[100],int *n);  
//输出函数
void Output_score(int score[100],int *n);
int main()
{
	//用户输入学生数量 
	printf("please enter the quantity of student:");
	int n = 0;
	scanf("%d",&n);
	
	//创建静态数组储存数据
	int score[100] = {0};
	
	//输入学生成绩
	Input_score(score,&n); 
	
	//逆序排序成绩
	Sort_score(score,&n); 
	
	//输出排序后的成绩
	Output_score(score,&n); 
	return 0;
}

//函数定义
//输入函数
void Input_score(int score[100],int *n)
{
	printf("please input scores:");
	for(int i = 0;i<*n;i++)
	{
		scanf("%d",&score[i]);
	}
	printf("逆序排序成功！\n");
} 

//逆序排序函数
void Sort_score(int score[100],int *n)
{
	int left = 0,right = *n-1;
	while(left<right)
	{
		int tem = score[left];
		score[left] = score[right];
		score[right] = tem;
		left++;
		right--;
	}
}

//输出函数
void Output_score(int score[100],int *n)
{
	printf("排序后的成绩为：");
	for(int i =0;i<*n;i++)
	{
		printf("%d ",score[i]);
	}
}
