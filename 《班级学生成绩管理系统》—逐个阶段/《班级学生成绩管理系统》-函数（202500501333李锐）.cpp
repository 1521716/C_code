#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
void menu(); //主菜单打印 
void Input_sum(int i,int num[100],int sign1);//学号录入（含重复学号检查） 
void Input_name(int i,char name[100][20]);//姓名录入 
void Input_score(int i,float score[100],int sign2);//分数录入（含分数合法性检查） 
void Inputdata(int *n,int num[100],char name[100][20],float score[100],int sign1,int sign2);//（1-录入） 
void Outputdata(int *n,int num[100],char name[100][20],float score[100]);//（2-显示） 
void Search_num(int n,int num[100],char name[100][20],float score[100]);//按学号查找数据 
void Search_name(int n,char name[100][20],int num[100],float score[100]);//按姓名查找数据 
void Searchdata(int *n,int num[100],char name[100][20],float score[100],int sign3);//（3-查找） 
void Sort_num(int n,int num[100],char name[100][20],float score[100]);//按学号升序，并打印 
void Sort_score(int n,int num[100],char name[100][20],float score[100]);//按成绩降序，并打印 
void Sortdata(int *n,int num[100],char name[100][20],float score[100],int sign4);//（4-排序） 
void Statsdata(int *n,int num[100],char name[100][20],float score[100]);//（5-统计） 
int main()
{
	int sign = 1,sign1 = 1,sign2 = 1,sign3 = 1,sign4 = 1; 
	int num[100] = {0},n = 0; char name[100][20] = {0};  float score[100] = {0};
	while(sign)
	{
		menu();
	    int select;
	    scanf("%d", &select);
	    switch (select)
	    {
	    case 1: {
	        Inputdata(&n,num,name,score,sign1,sign2);
			break;
	    }
	    case 2:{
	    	Outputdata(&n,num,name,score);
			break;
		}
		case 3:{
			Searchdata(&n,num,name,score,sign3);
			break;
		}
		case 4:{
			Sortdata(&n,num,name,score,sign);
			break;
		} 
		case 5:{
			Statsdata(&n,num,name,score);
			break;
		} 
	    case 0: return 0;
	    }
	} 
    
    return 0;
}
void menu()
{
	printf("––––––––––学生成绩管理系统––––––––––——————————————————————\n");
	printf("      1-录入    2-显示   3-查找   4-排序   5-统计     0-退出   \n");
	printf("–––––––––––––––––––––––––––––––——————————————————————–––––\n");
    printf("请选择操作（0-5）");
}
void Input_sum(int i,int num[100],int sign1)
{
	sign1 = 1;
	while(sign1)
	{    
		printf("请输入第%d个学生的学号:",i);
		scanf("%d", &num[i]);
		for(int j = i-1;j>=0;j--)
        {
        	if(i==1)
        	{
        		sign1 = 0;
				break; 
        	}
        	else if(num[i]==num[j])
        	{
        		printf("该学号已存在，请重新输入！\n");
        		break;
        	}
        	else if(j==1&&num[i]!=num[j])
        		sign1 = 0;
        }
	}
}
void Input_name(int i,char name[100][20])
{
	printf("请输入第%d个学生的姓名:",i);
	scanf("%s", name[i]);
	while (getchar() != '\n');
}
void Input_score(int i,float score[100],int sign2)
{
	printf("请输入第%d个学生的C语言成绩（0-100）:",i);
    scanf("%f", &score[i]);
    while (sign2)
    {
        if (score[i] < 0 || score[i] > 100)
        {
            printf("输入成绩不合法，请重新输入！\n");
            scanf("%f", &score[i]);
        }
        else
            sign2 = 0;
    }
    sign2 = 1; 
}
void Inputdata(int *n,int num[100],char name[100][20],float score[100],int sign1,int sign2) 
{
	printf("请输入新增学生个数:");
	        scanf("%d",n);
	        for(int i = 1;i<=*n;i++)
	        {
	        	Input_sum(i,num,sign1);
	        	Input_name(i,name);
	        	Input_score(i,score,sign2);
			}
	        printf("数据录入已成功！\n");
	        system("pause");
	        system("cls");
}
void Outputdata(int *n,int num[100],char name[100][20],float score[100])
{
	printf("学号	姓名	C语言\n");
	for(int i = 1;i<=*n;i++)
   	{
		printf("%d	%s	%.2f\n",num[i],name[i],score[i]);
	}
	system("pause");
    system("cls");
}
void Search_num(int n,int num[100],char name[100][20],float score[100])
{
	printf("请输入查找学号：");
	int search_num = 0;
	scanf("%d",&search_num);
	printf("查找结果：\n");
	int k = 0,i = 1;
	for(i = 1;i<=n;i++)
	{
		if(search_num==num[i])
		{
			k = i;	
		}
	}
	if(k)
	{
		printf("学号	姓名	C语言\n");
		printf("%d	%s	%.2f\n",num[k],name[k],score[k]);
	}
	else
		printf("该学生信息未找到！\n");
	system("pause");
    system("cls");
}
void Search_name(int n,char name[100][20],int num[100],float score[100])
{
	printf("请输入查找姓名：");
	char search_name[20] = {0};
	scanf("%s",search_name);
	while (getchar() != '\n');
	printf("查找结果：\n");
	int k = 0,i = 1;
	for(i = 1;i<=n;i++)
	{
		if(strcmp(search_name,name[i])==0)
		{
			k = i;
		}
	}
	if(k)
	{
		printf("学号	姓名	C语言\n");
		printf("%d	%s	%.2f\n",num[k],name[k],score[k]);
	}
	else
		printf("该学生信息未找到！\n");
	system("pause");
	system("cls");
}
void Searchdata(int *n,int num[100],char name[100][20],float score[100],int sign3) 
{
	while(sign3) 
	{
		printf("1-按学号查找	2-按姓名查找	0-返回：");
		int select3 = 0;
		scanf("%d",&select3);
		switch(select3)
		{
			case 1:{
				Search_num(*n,num,name,score);
				break;
			}
			case 2:{
				Search_name(*n,name,num,score);
				break;
			}
			default: {
				system("cls"); 
				sign3 = 0;
				break;
			}
		}
	
	}
}
void Sort_num(int n,int num[100],char name[100][20],float score[100])
{
	printf("排序后的结果为：\n");
	printf("学号	姓名	C语言\n");
	int i = 1,j = 1;
	for(i = 1;i<n;i++)
	{
		for(j = 1;j<n-i+1;j++)
		{
			if(num[j]>num[j+1])
			{
				int tem1 = num[j];
				num[j] = num[j+1];
				num[j+1] = tem1;
				char tem2[20] = {0};
				strcpy(tem2,name[j]);
				strcpy(name[j],name[j+1]);
				strcpy(name[j+1],tem2);
				float tem3 = score[j];
				score[j] = score[j+1];
				score[j+1] = tem3; 
			}
		}
	}
	for(int i = 1;i<=n;i++)
	{
		printf("%d	%s	%.2f\n",num[i],name[i],score[i]);
	}
	system("pause");
	system("cls");
}
void Sort_score(int n,int num[100],char name[100][20],float score[100])
{
	printf("排序后的结果为：\n");
	printf("学号	姓名	C语言\n");
	int i = 1,j = 1;
	for(i = 1;i<n;i++)
	{
		for(j = 1;j<n-i+1;j++)
		{
			if(score[j]<score[j+1])
			{
				int tem1 = num[j];
				num[j] = num[j+1];
				num[j+1] = tem1;
				char tem2[20] = {0};
				strcpy(tem2,name[j]);
				strcpy(name[j],name[j+1]);
				strcpy(name[j+1],tem2);
				float tem3 = score[j];
				score[j] = score[j+1];
				score[j+1] = tem3; 
			}
		}
	}
	for(int i = 1;i<=n;i++)
	{
		printf("%d	%s	%.2f\n",num[i],name[i],score[i]);
	}
	system("pause");
	system("cls");
}
void Sortdata(int *n,int num[100],char name[100][20],float score[100],int sign4) 
{
	while(sign4)
	{
		printf("1-按学号（升序）  2-按成绩（降序）  0-返回：");
		int select4 = 0;
		scanf("%d",&select4);
		switch(select4)
		{
			case 1:{
				Sort_num(*n,num,name,score);
				break;
			}
			case 2:{
				Sort_score(*n,num,name,score);
				break;
			}
			default:{
				system("cls"); 
				sign4 = 0;
				break;
			}
		}
	}
}
void Statsdata(int *n,int num[100],char name[100][20],float score[100])
{
	printf("*********************************************************\n");
	printf("成绩统计结果：\n");
	printf("学生总数：	%d\n",*n);
	float max = score[1],min = score[1],sum = 0;
	for(int i = 1;i<=*n;i++)
	{
		if(max<score[i])
			max = score[i];
		if(min>score[i])
			min = score[i];
		sum+=score[i];
	}
	printf("  最高分：	%.2f\n",max);
	printf("  最低分：	%.2f\n",min);
	printf("平均成绩：	%.2f\n",sum/(*n));
	printf("\n成绩分布情况：\n");
	printf("  分数段  人数  百分比\n");
	int A = 0,B = 0,C = 0,D = 0,E = 0;
	for(int i = 1;i<=*n;i++)
	{
		if(score[i]>89)
			A++;
		else if(score[i]>79)
			B++;
		else if(score[i]>69)
			C++;
		else if(score[i]>59)
			D++;
		else
			E++;
	}
	printf(" 100-90%7d%8.2f%%\n",A,A*100.0/(*n));
	printf("  89-80%7d%8.2f%%\n",B,B*100.0/(*n));
	printf("  79-70%7d%8.2f%%\n",C,C*100.0/(*n));
	printf("  69-60%7d%8.2f%%\n",D,D*100.0/(*n));
	printf("   59-0%7d%8.2f%%\n",E,E*100.0/(*n));
	printf("*********************************************************\n");
	system("pause");
	system("cls");
}



