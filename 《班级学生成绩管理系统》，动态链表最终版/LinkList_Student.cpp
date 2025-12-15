#define _CRT_SECURE_NO_WARNINGS
#include"LinkList_Student.h"
//初始化链表
struct LinkNode* Init_LinkList()
{
	//分配动态空间
	struct LinkNode* Student = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	//初始化头节点
	Student->ID = 0;
	Student->name[0] = {0};
	Student->score = 0;
	Student->next = NULL;
	return Student;
}

void clear()
{
	system("pause");
	system("cls");
}

//打印菜单
void menu()
{
	printf("*****************************************************************************************\n");
	printf("*********1-录入   2-删除(清空)   3-修改   4-显示   5-查找   6-排序  0-退出***************\n");
	printf("*****************************************************************************************\n");
	printf("请输入你的选择(0-5)>");
}

//1-录入
void Input_Studentdata(struct LinkNode* Student,struct LinkNode* pHead,struct LinkNode** pPear)
{
	//判断传入链表是否存在
	if (NULL == Student)
		return;

	//通过循环，录入所需数据
	printf("请输入新增加的学生个数：");
	int n = 0,sign = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		//创建新节点
		struct LinkNode* newStudent = (struct LinkNode*)malloc(sizeof(struct LinkNode));

		//输入学号，并判断学号是否已经存在
		do {
			sign = 0;
			printf("请输入第%d个学生的学号：", i + 1);
			scanf("%d", &newStudent->ID);
			while (pHead != NULL)
			{
				if (pHead->ID == newStudent->ID)
				{
					printf("该学号已存在，请重新输入！\n");
					sign = 1;
					break;
				}
				pHead = pHead->next;
			}
		} while (sign);

		//输入姓名
		printf("请输入第%d个学生的姓名：",i+1);
		scanf("%s", newStudent->name);
		while (getchar() != '\n');

		//输入成绩，并判断成绩是否合法
		do {
			sign = 0;
			printf("请输入第%d个学生的C语言成绩：", i + 1);
			scanf("%lf", &newStudent->score);
			if (newStudent->score < 0 || newStudent->score >100)
			{
				printf("成绩输入不合法，请重新输入！\n");
				sign = 1;
			}
		} while (sign);
		
		newStudent->next = NULL;

		//将新节点连接到链表
		(*pPear)->next = newStudent;
		*pPear = newStudent;

		//刷新辅助节点
		pHead = Student;
	}
}

//2-删除
void Remove_Studentdata(struct LinkNode* Student)
{
	if (Student == NULL)
		return;

	//辅助指针变量
	struct LinkNode* pPrev = Student;
	struct LinkNode* pCurrent = Student->next;
	struct LinkNode* ptem1 = Student->next;

	int select = 0,select1 = 0;;
	do {
		//菜单
		printf("*******************************************************\n");
		printf("***1-按学号删除    2-按姓名删除      3-清空   0-退出***\n");
		printf("*******************************************************\n");
		printf("请输入你的选择>");
		
		scanf("%d", &select);
		int remove_ID = 0; char remove_name[20] = { 0 };
		switch (select)
		{
		case 1:
			//按照学号删除
			printf("请输入你要删除的学号：");
			scanf("%d", &remove_ID);
			while (pCurrent != NULL)
			{
				if (pCurrent->ID == remove_ID)
				{
					pPrev->next = pCurrent->next;
					free(pCurrent);
					printf("删除成功！\n");
					//更新指针变量
					pPrev = Student;
					pCurrent = Student->next;
					ptem1 = Student->next;
					return;
				}
				pPrev = pCurrent;
				pCurrent = pCurrent->next;
			}
			printf("未找到要删除的学号！\n");
			//更新指针变量
			pPrev = Student;
			pCurrent = Student->next;
			ptem1 = Student->next;
			break;
		case 2:
			//按照姓名删除
			
			printf("请输入你要删除的学生姓名：");
			scanf("%s", remove_name);
			while (getchar() != '\n');
			while (pCurrent != NULL)
			{
				if (strcmp(pCurrent->name, remove_name) == 0)
				{
					pPrev->next = pCurrent->next;
					free(pCurrent);
					printf("删除成功！\n");
					//更新指针变量
					pPrev = Student;
					pCurrent = Student->next;
					ptem1 = Student->next;
					return;
				}
				pPrev = pCurrent;
				pCurrent = pCurrent->next;
			}
			printf("未找到要删除的学生！\n");
			//更新指针变量
			pPrev = Student;
			pCurrent = Student->next;
			ptem1 = Student->next;
			break;
		case 3:
			//询问用户是否清空
			printf("你真的要清空吗？清空后不可恢复！！！\n");
			printf("*****************************************************\n");
			printf("****1-仍要清空   0-放弃清空（输入其他值默认放弃）****\n");
			printf("*****************************************************\n");

			//用户选择
			printf("请输入你的选择：");
			scanf("%d", &select1);
			switch (select1)
			{
			case 1:
				
				//开始清空
				Student->next = NULL;
				while (ptem1 != NULL)
				{
					struct LinkNode* ptem2 = ptem1->next;
					free(ptem1);
					ptem1 = ptem2;
				}
				printf("链表已清空！\n");
				return;
				break;
			case 0:
				printf("已放弃清空。\n");
				return;
				break;
			default:
				printf("已默认放弃清空。\n");
				return;
			}
		case 0:
			printf("删除程序退出！\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
		}
	} while (select);
}

//3-修改
void Change_Studentdata(struct LinkNode* Student, struct LinkNode* pHead)
{
	if (Student == NULL)
		return;
	
	int select = 0;

	do {
		//菜单
		printf("**********************************************\n");
		printf("*****1-按学号修改   2-按姓名修改   0-退出*****\n");
		printf("**********************************************\n");
		printf("请输入你的选择>");

		//选择
		int sign = 0;
		scanf("%d", &select);
		switch (select)
		{
		case 1:

			do {
				sign = 0;
				pHead = Student;
				//输入修改的学生学号
				printf("请输入要修改的学生的学号：");
				int change_ID = 0;
				scanf("%d", &change_ID);

				//通过循环遍历链表，查找节点
				while (pHead != NULL)
				{
					//如果找到，开始修改
					if (pHead->ID == change_ID)
					{
						printf("要修改学生信息已找到！\n");
						printf("请输入新学号：");
						scanf("%d", &pHead->ID);
						printf("请输入新姓名：");
						scanf("%s", pHead->name);
						while (getchar() != '\n');
						printf("请输入新成绩：");
						scanf("%lf", &pHead->score);
						printf("修改成功！\n");
						return;
					}
					//更新指针指向
					pHead = pHead->next;
				}

				//跳出循环，说明未找到
				printf("要修改的学生信息未找到！请重新输入！\n");
				//重置指针
				pHead = Student;
				sign = 1;
			} while (sign);
			break;
		case 2:
			do {
				sign = 0;
				pHead = Student;
				//输入修改的学生姓名
				printf("请输入要修改的学生的姓名：");
				char change_name[20] = { 0 };
				scanf("%s", change_name);
				while (getchar() != '\n');

				//通过循环遍历链表，查找节点
				while (pHead != NULL)
				{
					//如果找到，开始修改
					if (strcmp(pHead->name, change_name) == 0)
					{
						printf("要修改学生信息已找到！\n");
						printf("请输入新学号：");
						scanf("%d", &pHead->ID);
						printf("请输入新姓名：");
						scanf("%s", pHead->name);
						while (getchar() != '\n');
						printf("请输入新成绩：");
						scanf("%lf", &pHead->score);
						printf("修改成功！\n");
						return;
					}
					//更新指针指向
					pHead = pHead->next;
				}

				//跳出循环，说明未找到
				printf("要修改的学生信息未找到！请重新输入！\n");
				//重置指针
				pHead = Student;
				sign = 1;
			} while (sign);
			break;
		case 0:
			printf("修改程序使用结束！\n");
			clear();
			break;
		default:
			printf("选择错误，请重新输入！\n");
		}
	} while (select);
}


//4-显示
void Output_Studentdata(struct LinkNode* Student)
{
	if (NULL == Student)
		return;

	//辅助指针变量
	struct LinkNode* pCurrent = Student->next;

	printf("%-8s%-8s%s\n", "学号", "姓名", "C成绩");

	//通过循环遍历链表
	while (pCurrent != NULL)
	{
		printf("%-8d%-8s%.2lf\n", pCurrent->ID, pCurrent->name, pCurrent->score);
		pCurrent = pCurrent->next;
	}
}

//5-查找
void Search_Studentdata(struct LinkNode* Student, struct LinkNode* pHead)
{
	if (Student == NULL)
		return;

	int select = 0;

	do {
		//菜单
		printf("**********************************************\n");
		printf("*****1-按学号查找   2-按姓名查找   0-退出*****\n");
		printf("**********************************************\n");
		printf("请输入你的选择>");

		//选择
		int sign = 0;
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			do {
				sign = 0;
				//输入查询学号
				printf("请输入你要查询的学号:");
				int search_ID = 0;
				scanf("%d", &search_ID);

				//循环遍历查找
				while (pHead != NULL)
				{
					//找到便输出
					if (pHead->ID == search_ID)
					{
						printf("查询结果为：\n");
						printf("%-8s%-8s%s\n", "学号", "姓名", "C成绩");
						printf("%-8d%-8s%.2lf\n", pHead->ID, pHead->name, pHead->score);
						return;
					}
					//更新指针
					pHead = pHead->next;
				}

				//循环结束，说明链表内无要查询数据
				printf("未找到你要查询的学生信息，请重新输入！\n");
				//重置指针
				pHead = Student;
				sign = 1;
			} while (sign);
			break;
		case 2:
			do {
				sign = 0;
				//输入查询学号
				printf("请输入你要查询的姓名:");
				char search_name[20] = { 0 };
				scanf("%s", search_name);

				//循环遍历查找
				while (pHead != NULL)
				{
					//找到便输出
					if (strcmp(pHead->name, search_name) == 0)
					{
						printf("查询结果为：\n");
						printf("%-8s%-8s%s\n", "学号", "姓名", "C成绩");
						printf("%-8d%-8s%.2lf\n", pHead->ID, pHead->name, pHead->score);
						return;
					}
					//更新指针
					pHead = pHead->next;
				}

				//循环结束，说明链表内无要查询数据
				printf("未找到你要查询的学生信息，请重新输入！\n");
				//重置指针
				pHead = Student;
				sign = 1;
			} while (sign);
			break;
		case 0:
			printf("查找程序使用结束！\n");
			break;
		default:
			printf("输入选择错误，请重新输入！\n");
		}
	} while (select);
}

//6-排序
void Sort_Studentdata(struct LinkNode* Student, struct LinkNode* pHead)
{
	if (Student == NULL)
		return;
	/*思路：因为如果只用链表排序，需要遍历多次，
	考虑遍历一次链表，将各个节点的数据域拷贝到静态（或者动态）数组，
	对数组排序，再用循环将排好序内容放回链表*/

	//因为动态数组还没学习，此处用静态数组
	int n = 0;
	int arr_ID[999] = { 0 }; char arr_name[999][20] = { 0 }; double arr_score[999] = { 0 };
	pHead = Student->next;
	while (pHead != NULL)
	{
		arr_ID[n] = pHead->ID;
		strcpy(arr_name[n], pHead->name);
		arr_score[n] = pHead->score;
		n++;
		pHead = pHead->next;
	}

	//重置指针
	pHead = Student->next;

	int select = 0;
	do {
		//菜单
		printf("*********************************************************\n");
		printf("*********1-按学号升序    2-按成绩降序    0-退出**********\n");
		printf("*********************************************************\n");

		//用户选择
		printf("请选择操作数>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:

			//按学号给数组排序(冒泡)
			for (int i = 0; i < n-1; i++)
			{
				int sign = 1;
				for (int j = 0; j < n-1 - i; j++)
				{
					if (arr_ID[j] > arr_ID[j + 1])
					{
						int tem01 = arr_ID[j];
						arr_ID[j] = arr_ID[j + 1];
						arr_ID[j + 1] = tem01;
						char tem02[20] = { 0 };
						strcpy(tem02, arr_name[j]);
						strcpy(arr_name[j], arr_name[j + 1]);
						strcpy(arr_name[j + 1], tem02);
						double tem03 = arr_score[j];
						arr_score[j] = arr_score[j + 1];
						arr_score[j + 1] = tem03;
						sign = 0;
					}
				}
				if (sign)
					break;
			}

			//将按照ID排序的数组赋值给链表
			for (int i = 0; i < n; i++)
			{
				pHead->ID = arr_ID[i];
				strcpy(pHead->name, arr_name[i]);
				pHead->score = arr_score[i];
				pHead = pHead->next;
			}
			printf("按学号升序排序成功！\n");
			//重置指针
			pHead = Student->next;
			return;
			break;
		case 2:
			//按成绩给数组排序(冒泡)
			for (int i = 0; i < n-1; i++)
			{
				int sign = 1;
				for (int j = 0; j < n-1 - i; j++)
				{
					if (arr_score[j] < arr_score[j + 1])
					{
						int tem01 = arr_ID[j];
						arr_ID[j] = arr_ID[j + 1];
						arr_ID[j + 1] = tem01;
						char tem02[20] = { 0 };
						strcpy(tem02, arr_name[j]);
						strcpy(arr_name[j], arr_name[j + 1]);
						strcpy(arr_name[j + 1], tem02);
						double tem03 = arr_score[j];
						arr_score[j] = arr_score[j + 1];
						arr_score[j + 1] = tem03;
						sign = 0;
					}
				}
				if (sign)
					break;
			}

			//将按照分数排序的数组赋值给链表
			for (int i = 0; i < n; i++)
			{
				pHead->ID = arr_ID[i];
				strcpy(pHead->name, arr_name[i]);
				pHead->score = arr_score[i];
				pHead = pHead->next;
			}
			printf("按成绩降序排序成功！\n");
			//重置指针
			pHead = Student->next;
			return;
			break;
		case 0:
			printf("排序程序结束！\n");
			break;
		default:
			printf("输入选择错误，请重新选择！\n");
		}
	} while (select);
	
}
