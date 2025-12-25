#include<stdio.h>
#define N 3
struct Student{
	int num;
	char name[20];
	float score[3];
	float aver;
};

//函数声明
void input(struct Student stu[]);
struct Student min(struct Student stu[]);
void print(struct Student stu);
int main()
{
	struct Student stu[N],*p = stu;
	input(p);
	print(min(p));
	return 0;
}

//函数定义
void input(struct Student stu[])
{
	int i;
	printf("请输入各学生的信息（学号、姓名、三门课成绩）：\n");
	for(i = 0;i<N;i++)
	{
		scanf("%d%s%f%f%f",&stu[i].num,stu[i].name,&stu[i].score[0],\
							&stu[i].score[1],&stu[i].score[2]);
		stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
	}
}
struct Student min(struct Student stu[])
{
	int i = 0,m = 0;
	for(i = 0;i<N;i++)
	{
		if(stu[i].aver<stu[m].aver)
			m = i;
	}
	return stu[m];
}
void print(struct Student stu)
{
	printf("成绩最低的学生是：\n");
	printf("学号：%d\n姓名：%s\n三门课成绩：%5.1f,%5.1f,%5.1f平均成绩：%6.2f\n",stu.num,stu.name,stu.score[0],\
																		stu.score[1],stu.score[2],stu.aver);
}
