#include<stdio.h>
void Input(int score[100], int n);//输入
void Show(int score[100], int n);//输出
void Sort(int score[100], int n);//冒泡排序
void Find(int score[100], int n, int x);//查找
int main()
{
	int score[100], n;
	printf("请输入学生人数：");
	scanf("%d", &n);
	printf("please input students' scores:");
	Input(score, n);
	printf("These students' scores are:");
	Show(score, n);
	printf("对成绩降序处理:");
	Sort(score, n);
	Show(score, n);
	printf("请输入要查找的成绩x：");
	int x = 0;
	scanf("%d", &x);
	Find(score, n, x);
	return 0;
}
void Input(int score[100], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &score[i]);
	}
}
void Show(int score[100], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", score[i]);
	}
	printf("\n");
}
void Sort(int score[100], int n)
{
	int i = 0, j = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (score[j] < score[j + 1])
			{
				int tem = score[j];
				score[j] = score[j + 1];
				score[j + 1] = tem;
			}
		}
	}
	printf("\n");
}
void Find(int score[100], int n, int x)
{
	int i = 0, k = 0;
	for (i = 0; i < n; i++)
	{
		if (x == score[i])
		{
			printf("%d ", i);
			k = 1;
		}
	}
	if (i == n && k == 0)
	{
		printf("-1");
	}
}