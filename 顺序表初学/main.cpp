#include"text.h"

int main()
{
	//创建一个空顺序表
	SqList* List = InitList();

	//尾部添加
	Addtail(List, 10);
	Addtail(List, 20);
	Addtail(List, 30);
	Addtail(List, 10);
	Addtail(List, 10);
	Addtail(List, 10);
	Addtail(List, 10);
	PrintfList(List);

	//插入
	InsertList(List, 2, 11);

	//遍历
	PrintfList(List);

	//删除
	DeleteList(List, 3);
	PrintfList(List);

	//按值查找
	int* pos = (int*)malloc(sizeof(int)*MAXSIZE);
	int j = FindList(List, 10,pos);
	for (int i = 0; i < j; i++)
	{
		printf("%d ", *(pos + i));
	}
	return 0;
}