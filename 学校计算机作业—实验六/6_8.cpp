#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Input(char name[5][20], int score[5][3]);
void Avg_Cor(int name[5][3]);
void Max_ij(char name[5][20], int score[5][3]);
void Sort_avg_std(int score[5][3], double avg[5]);
int main()
{
	char name[5][20] = { 0 };
	int score[5][3];double avg[5];
	printf("请输入学生姓名及成绩：\n");
	printf("姓名\t语文\t数学\t英语\n");
	Input(name, score);
	printf("各科成绩平均值为（语文、数学、英语）：");
	Avg_Cor(score);
	Max_ij(name, score);
	Sort_avg_std(score, avg);
	return 0;
}
void Input(char name[5][20], int score[5][3])
{
	int i = 0, j = 0;
	for (i = 0; i < 5; i++)
	{
		scanf_s("%s", &name[i], 20);
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
		double avg = sum / 5.0;
		printf("%.2f\t", avg);
	}
	printf("\n");
}
void Max_ij(char name[5][20], int score[5][3])
{
	int i = 0, j = 0;
	int max = score[0][0];
	for (i = 0; i < 5; i++)
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
				printf("最高分对应的课程下标为：");
				printf("%d\n", j);
			}
		}
	}
}
void Sort_avg_std(int score[5][3], double avg[5])
{
	int i = 0,j = 0, sum = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++) 
		{
			sum += score[i][j];
		}
		avg[i] = sum / 3.0;
		sum = 0;
	}
	i = 0, j = 0;
	for (i = 0; i < 5 - 1; i++)
	{
		for (j = 0; j < 5 - 1 - i; j++)
		{
			if (avg[j] < avg[j + 1])
			{
				int tem = avg[j];
				avg[j] = avg[j + 1];
				avg[j + 1] = tem;
			}
		}
	}
	i = 0;
	printf("学生平均成绩（降序）：");
	for (i = 0; i < 5; i++)
	{
		printf("%.2f\t", avg[i]);
	}
}