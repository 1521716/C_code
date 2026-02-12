#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//结构体定义
typedef struct Student {
	int ID;
	char name[20];
	double score;
}Student;
//设置一个全局变量记录人数
int count = 0;
//清屏
void clear();
//打印菜单
void menu();
//输入学生数据
void Inputdata(Student* data);
//显示学生数据
void Putdata(Student* data);
//用学号查找学生数据
void Search_ID(Student* data);
//用姓名查找学生数据
void Search_name(Student* data);
//查找学生数据
void Searchdata(Student* data);
//按照学号排序
void Sort_ID(Student* data);
//按照成绩排序
void Sort_score(Student* data);
//排序
void Sortdata(Student* data);
//统计
void Statistics(Student* data);
int main()
{
	int input = 0;
	Student data[100] = { 0 };
	do {
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Inputdata(data);
			break;
		case 2:
			Putdata(data);
			break;
		case 3:
			Searchdata(data);
			break;
		case 4:
			Sortdata(data);
			break;
		case 5:
			Statistics(data);
			break;
		case 0:
			printf("程序结束！\n");
			break;
		default:
			printf("输入选项不合法！请重新输入...\n");
			break;
		}
	} while (input);
	return 0;
}
void clear()
{
	system("pause");
	system("cls");
}
void menu()
{
	printf("*******************************************************************\n");
	printf("********1.录入   2.显示   3.查找   4.排序   5.统计   0.退出********\n");
	printf("*******************************************************************\n");
	printf("请输入选择项：");
}
void Inputdata(Student* data)
{
	int n = 0, sign1 = 0;
	printf("请输入新增加的学生个数：");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		Student tem;
		count++;
		do {
			sign1 = 0;
			printf("请输入第%d个学生的学号：", count);
			scanf("%d", &tem.ID);
			for (int j = 0; j < count; j++)
			{
				if (tem.ID == (data + j - 1)->ID)
				{
					printf("该学号已存在，请重新输入！\n");
					sign1 = 1;
					break;
				}
			}
		} while (sign1);
		printf("请输入第%d个学生的姓名：", count);
		scanf("%s", tem.name);
		do {
			sign1 = 0;
			printf("请输入第%d个学生的C语言成绩：", count);
			scanf("%lf", &tem.score);
			if (tem.score < 0 || tem.score>100)
			{
				printf("成绩输入不合法，请重新输入！\n");
				sign1 = 1;
			}
		} while (sign1);
		data[count-1] = tem;
	}
	printf("数据录入已成功！\n");
	clear();
}

void Putdata(Student* data)
{
	printf("%-8s%-8s%s\n", "学号", "姓名", "C成绩");
	for (int i = 0; i < count; i++)
	{
		printf("%-8d%-8s%.2lf\n", (data + i)->ID, (data + i)->name, (data + i)->score);
	}
	clear();
}
void Search_ID(Student* data)
{
	int search = 0, result = 0;
	printf("请输入要查找的学生的学号：");
	scanf("%d", &search);
	for (int i = 0; i < count; i++)
	{
		if (search == (data + i)->ID)
		{
			if (i == 0)
			{
				printf("%-8s%-8s%s\n", "学号", "姓名", "C成绩");
				printf("%-8d%-8s%.2lf\n", data->ID, data->name, data->score);
				clear();
				return;
			}
			else
				result = i;
			break;
		}
	}
	printf("查找结果：\n");
	if (result)
	{
		printf("%-8s%-8s%s\n", "学号", "姓名", "C成绩");
		printf("%-8d%-8s%.2lf\n", (data + result)->ID, (data + result)->name, (data + result)->score);
	}
	else
		printf("该学生信息未找到！\n");
	clear();
}
void Search_name(Student* data)
{
	char search_name[20] = { 0 };
	int result = 0;
	printf("请输入要查找的学生的姓名：");
	scanf("%s", &search_name);
	for (int i = 0; i < count; i++)
	{
		if (strcmp(search_name, (data + i)->name) == 0)
		{
			if (i == 0)
			{
				printf("%-8s%-8s%s\n", "学号", "姓名", "C成绩");
				printf("%-8d%-8s%.2lf\n", data->ID, data->name, data->score);
				clear();
				return;
			}
			else
				result = i;
			break;
		}
	}
	printf("查找结果：\n");
	if (result)
	{
		printf("%-8s%-8s%s\n", "学号", "姓名", "C成绩");
		printf("%-8d%-8s%.2lf\n", (data + result)->ID, (data + result)->name, (data + result)->score);
	}
	else
		printf("该学生信息未找到！\n");
	clear();
}
void Searchdata(Student* data)
{
	int select = 0;
	do {
		printf("1-按学号查找    2-按姓名查找    0-返回:");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Search_ID(data);
			break;
		case 2:
			Search_name(data);
			break;
		case 0:
			printf("查找程序结束！\n");
			clear();
			break;
		default:
			printf("选项输入错误，请重新输入！\n");
			break;
		}
	} while (select);
}
void Sort_ID(Student* data)
{
	printf("排序后的结果为：\n");
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if ((data + j)->ID > (data + j + 1)->ID)
			{
				int tem_ID = (data + j)->ID;
				(data + j)->ID = (data + j + 1)->ID;
				(data + j + 1)->ID = tem_ID;
				char tem_name[20] = { 0 };
				strcpy(tem_name, (data + j)->name);
				strcpy((data + j)->name, (data + j + 1)->name);
				strcpy((data + j + 1)->name, tem_name);
				double tem_score = (data + j)->score;
				(data + j)->score = (data + j + 1)->score;
				(data + j + 1)->score = tem_score;
			}
		}
	}
	Putdata(data);
}
void Sort_score(Student* data)
{
	printf("排序后的结果为：\n");
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if ((data + j)->score < (data + j + 1)->score)
			{
				int tem_ID = (data + j)->ID;
				(data + j)->ID = (data + j + 1)->ID;
				(data + j + 1)->ID = tem_ID;
				char tem_name[20] = { 0 };
				strcpy(tem_name, (data + j)->name);
				strcpy((data + j)->name, (data + j + 1)->name);
				strcpy((data + j + 1)->name, tem_name);
				double tem_score = (data + j)->score;
				(data + j)->score = (data + j + 1)->score;
				(data + j + 1)->score = tem_score;
			}
		}
	}
	Putdata(data);
}
void Sortdata(Student* data)
{
	int select = 0;
	do {
		printf("1-按学号（升序）   2-按成绩（降序）   0-返回:");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Sort_ID(data);
			break;
		case 2:
			Sort_score(data);
			break;
		case 0:
			printf("排序程序结束！\n");
			clear();
			break;
		default:
			printf("选项输入错误，请重新输入！\n");
			break;
		}
	} while (select);
}
void Statistics(Student* data)
{
	double max = data->score, min = data->score, sum = 0;
	for (int i = 0; i < count; i++)
	{
		if (max < (data + i)->score)
			max = (data + i)->score;
		if (min > (data + i)->score)
			min = (data + i)->score;
		sum += (data + i)->score;
	}
	printf("**********************************************************\n");
	printf("成绩统计结果：\n");
	printf("%-18s%d\n", "学生总数：", count);
	printf("%-18s%.2lf\n", "最高分：", max);
	printf("%-18s%.2lf\n", "最低分：", min);
	printf("%-18s%.2lf\n", "平均成绩：", sum / count);
	int A = 0, B = 0, C = 0, D = 0, E = 0;
	for (int j = 0; j < count; j++)
	{
		if ((data + j)->score >= 90 && (data + j)->score <= 100)
			A++;
		else if ((data + j)->score >= 80)
			B++;
		else if ((data + j)->score >= 70)
			C++;
		else if ((data + j)->score >= 60)
			D++;
		else
			E++;
	}
	printf("%s", "成绩分布情况：\n");
	printf("%8s%8s%8s\n", "分数段", "人数", "百分比");
	printf("%8s%8d%8.2lf%%\n", "100-90", A, 100.0 * A / count);
	printf("%8s%8d%8.2lf%%\n", "89-80", B, 100.0 * B / count);
	printf("%8s%8d%8.2lf%%\n", "79-70", C, 100.0 * C / count);
	printf("%8s%8d%8.2lf%%\n", "69-60", D, 100.0 * D / count);
	printf("%8s%8d%8.2lf%%\n", "59-0", E, 100.0 * E / count);
	printf("**********************************************************\n");
	clear();
}
