#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h>
int main()
{
	int sign = 1;
    while(sign)
	{
	printf("––––––––––学生成绩管理系统––––––––––\n");
    printf("      1-录入    2-显示    0-退出       \n");
    printf("––––––––––––––––––––––––––––––––––––\n");
		printf("请选择操作（0-2）");
		int select,sign1 = 1,sign2 = 1,sign3 = 1,old,score,num;char name[10];char sex;
		scanf("%d", &select);
		switch (select)
		{
		case 1: {
		    printf("请输入学生信息:\n");
		    printf("学号:");
		    scanf("%d", &num);
		    printf("姓名:");
		    scanf("%s", &name);
		    while (getchar() != '\n');
			printf("性别（F||M）:");      
	        sex = getchar();
	        while (getchar() != '\n');
		    while (sign1)
		    {    
	            if (sex != 'F' && sex != 'M')
	            {
	                printf("输入性别不合法，请重新输入！\n");
	                printf("性别（F||M）:"); 
	                sex = getchar();
	                while (getchar() != '\n');
	            }
	            else
	                sign1 = 0;
		    }
			printf("年龄:");
	        scanf("%d", &old);
		     while (sign2)
		    {     
	            if (old <= 0||old>=100)
	            {
	                printf("输入年龄不合法，请重新输入！\n");
	                printf("年龄:");
	                scanf("%d", &old);
	            }
	            else
	                sign2 = 0;
		    }
			printf("成绩（0-100）:"); 
		    scanf("%d", &score);
		    while (sign3)
		    {    
	            if (score < 0 || score > 100)
	            {
	                printf("输入成绩不合法，请重新输入！\n");
	                printf("成绩（0-100）:");
	                scanf("%d", &score);
	            }
	            else
	                sign3 = 0;
		    }
		    system("pause");
		    system("cls");
		}break;
		case 2:  {
			printf("学号    姓名    性别    年龄    分数    \n");
		    printf("%4d%8s%8c%8d%8d\n", num, name, sex, old, score);
		    system("pause");
		    system("cls");
		}break;
		default: return 0;
		}
	}
    return 0;
}
