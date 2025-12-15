#include<stdio.h>
void Input(char name[5][20],int score[5][3]);
void Avg_Cor(int name[5][3]);
void Max_ij(char name[5][20], int score[5][3]);
int main()
{
	char name[5][20] = { 0 };
	int score[5][3];
	printf("请输入学生姓名及成绩：\n");
	printf("姓名\t语文\t数学\t英语\n");
	Input(name, score);
	printf("各科成绩平均值为（语文、数学、英语）：");
	Avg_Cor(score);
	Max_ij(name, score);
	return 0;
}
void Input(char name[5][20],int score[5][3])
{
	int i = 0, j = 0;
	for (i = 0; i < 5; i++)
	{
		scanf_s("%s", &name[i],20);
		for (j = 0; j < 3; j++)
		{
			scanf_s("%d", &score[i][j]);
		}
	}
}
void Avg_Cor(int score[5][3])
{
	int i = 0, j = 0, avg = 0;
	for (j = 0; j < 3; j++)
	{
		int sum = 0;
		for (i = 0; i < 5; i++)
		{
			sum += score[i][j];
		}
		double ave = sum / 5.0;
		printf("%.2f\t", ave);
	}
	printf("\n");
}
void Max_ij(char name[5][20], int score[5][3])
{
	int i = 0, j = 0;
	int max = score[0][0];
	for (i = 0; i < 5;i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (max < score[i][j])
			{
				max = score[i][j];
			}
		}
	}
	printf("最高分为：%d\n", max);
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (max == score[i][j])
			{
				printf("取得最高分的学生为：");
				printf("%s\n",name[i]);
				printf("取得最高分的课程下标为：%d\n", j);
			}
		}
	}
}