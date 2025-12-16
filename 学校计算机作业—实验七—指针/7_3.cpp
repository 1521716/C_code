#include<stdio.h>
//倒放函数声明 
void lnv(int arr[],int *n);
int main()
{
	//初始化数组 
	printf("请输入数组中元素个数：");
	int n = 0;
	scanf("%d",&n); 
	printf("请输入数组原数据：");
	int arr[100] = {0};
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	//调用函数 
	lnv(arr,&n);
	//打印排序后函数
	printf("倒放后数组：");
	for(int j = 0;j<n;j++)
	{
		printf("%d ",arr[j]);	
	} 
	return 0;
}
//倒放函数定义 
void lnv(int arr[],int *n)
{
	int left = 0,right = *n-1;
	while(left<right)
	{
		int tem = *(arr+left);
		*(arr+left) = *(arr+right);
		*(arr+right) = tem;
		left++;
		right--;
	}
}
