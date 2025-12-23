#define _CRT_SECURE_NO_WARNINGS
#include"LinkList_Student.h"
int main()
{
	int input = 0;
	//初始化链表
	struct LinkNode* Student = Init_LinkList();

	//创建尾部节点
	static struct LinkNode* pPear = Student;
	//创建头部节点（用于遍历数组）
	struct LinkNode* pHead = Student;

	//加载文件数据到链表
	Olddata(Student,&pPear);

	do {
		//打印菜单
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Input_Studentdata(Student,pHead,&pPear);
			clear();
			break;
		case 2:
			Remove_Studentdata(Student);
			clear();
			break;
		case 3:
			Change_Studentdata(Student,pHead);
			clear();
			break;
		case 4:
			Output_Studentdata(Student);
			clear();
			break;
		case 5:
			Search_Studentdata(Student, pHead);
			clear();
			break;
		case 6:
			Sort_Studentdata(Student,pHead);
			clear();
			break;
		case 0:
			printf("程序使用结束，再见！\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
		}
	} while (input);
	return 0;
}