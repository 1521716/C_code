#include<stdio.h>

//定义结构体
struct Employee{
	int ID;
	char name[20];
	int salary;
}; 

//函数声明
//输入函数
void Input(struct Employee*emps);
//输出函数
void Output(struct Employee*emps);
//排序函数
void Sort(struct Employee*emps); 
//查找函数
int Search(struct Employee*emps,int search); 
int main()
{
	//创建变量
	Employee emps[5];
	//输入员工信息函数 
	Input(emps);
	//打印员工信息函数
	Output(emps);
	//对员工工资排序
	Sort(emps); 
	Output(emps);
	//查找
	int search = 0;
	printf("请输入要查找的员工编号：");
	scanf("%d",&search);
	int result = Search(emps,search);
	if(result!=-1)
	{
		printf("要查询的员工下标为：%d\n",result);
	}
	else
		printf("查找的员工编号不存在！\n");
	return 0;
} 

//函数定义 
//输入函数
void Input(struct Employee*emps)
{
	
	for(int i = 0;i<5;i++)
	{
		printf("请输入第%d个员工的信息（编号，姓名，工资）：\n",i+1);
		scanf("%d%s%d",&((emps+i)->ID),(emps+i)->name,&((emps+i)->salary));
	}
}
//输出函数
void Output(struct Employee*emps)
{
	printf("编号	姓名	工资\n");
	for(int i = 0;i<5;i++)
	{
		printf("%d	%s	%d\n",(emps+i)->ID,(emps+i)->name,(emps+i)->salary);
	}
}
//排序函数
void Sort(struct Employee*emps)
{
	//冒泡排序 
	for(int i = 0;i<4;i++)
	{
		for(int j = 0;j<4-i;j++)
		{
			if((emps+j)->salary<(emps+j+1)->salary)
			{
					Employee tem = *(emps+j);
					*(emps+j) = *(emps+j+1);
					*(emps+j+1) = tem;
			}
		}
	}
	printf("排序完成！\n按工资降序结果为：\n");
}
//查找函数
int Search(struct Employee*emps,int search)
{
	for(int i = 0;i<5;i++)
	{
		if(search==(emps+i)->ID)
		return i;
	}
	return -1;
}
