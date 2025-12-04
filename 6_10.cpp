#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define n 4
void Input(int arr[n][n]);//二维数组赋值
void Shift(int arr[n][n]);//调转二维数组
void Print(int arr[n][n]);//打印二维数组
int main()
{
	int arr[n][n];
	printf("请输入要给原数组赋的值：\n");
	Input(arr);
	printf("原数组为：\n");
	Print(arr);
	Shift(arr);
	printf("后数组为：\n");
	Print(arr);
	return 0;
}
void Input(int arr[n][n])
{
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
}
void Print(int arr[n][n])
{
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
}
void Shift(int arr[n][n])
{
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		j = i + 1;
		while (j < n)
		{
			int tem = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = tem;
			j++;
		}
	}
}