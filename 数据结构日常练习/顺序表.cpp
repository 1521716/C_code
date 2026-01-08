#define _CRT_SECURE_NO_WARNINGS

//********************************顺序表***************************

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
//结构
typedef struct {
	int* data;
	int len;
}SeqList;

//函数声明
//初始化
SeqList* SeqListInit();
//销毁
void SeqListDestroy(SeqList** list);
//指定位置插入
void SeqListInsert(SeqList* list, int pos, int data);
//尾部追加数据
void SeqListPushBack(SeqList* list, int data);
//头部插入数据
void SeqListPushFront(SeqList* list, int data);
//删除指定位置的元素
void SeqListErase(SeqList* list, int pos);
//删除尾部元素
void SeqListPopBack(SeqList* list);
//删除头部元素
void SeqListPopFront(SeqList* list);
//删除第一个值为x的元素
void SeqListRemove(SeqList* list, int x);
//查找元素，找到下标，否则-1
int SeqListFind(const SeqList* list, int search);
//输出有效长度
int SeqListGetize(const SeqList* list);
//判断是否为空,空0，非1
int SeqListEmpty(const SeqList* list);
//打印数据
void SeqListPrint(const SeqList* list);
//清空
void SeqListClear(SeqList* list);
int main()
{
	//初始化
	SeqList* list = SeqListInit();
	//头部插入数据
	SeqListPushFront(list,10);
	//头部插入数据
	SeqListPushFront(list, 30);
	//头部插入数据
	SeqListPushFront(list, 40);
	//头部插入数据
	SeqListPushFront(list, 99);
	//头部插入数据
	SeqListPushFront(list, 99);
	//尾部追加数据
	SeqListPushBack(list,9);
	//打印数据
	SeqListPrint(list);
	//头部插入数据
	SeqListPushFront(list, 20);
	//打印数据
	SeqListPrint(list);
	//删除尾部元素
	SeqListPopBack(list);
	//删除头部元素
	SeqListPopFront(list);
	//打印数据
	SeqListPrint(list);
	//删除第一个值为x的元素
	SeqListRemove(list,99);
	//打印数据
	SeqListPrint(list);
	//删除指定位置的元素
	SeqListErase(list,2);
	//打印数据
	SeqListPrint(list);
	//指定位置插入
	SeqListInsert(list,2,12);
	//打印数据
	SeqListPrint(list);
	//查找数据
	printf("查找结果为：%d\n", SeqListFind(list, 40));
	//清空
	SeqListClear(list);
	//打印数据
	SeqListPrint(list);
	//销毁
	SeqListDestroy(&list);
	return 0;
}

//函数定义
//初始化
SeqList* SeqListInit()
{
	SeqList* list = (SeqList*)malloc(sizeof(SeqList));
	list->data = (int*)malloc(sizeof(int) * MAXSIZE);
	list->len = -1;
	printf("初始化顺序表成功！\n");
	return list;
}
//销毁
void SeqListDestroy(SeqList** list)
{
	if (list == NULL)
	{
		return;
	}
	(*list)->len = -1;
	free(*list);
	*list = NULL;
	printf("销毁成功！\n");
}
//指定位置插入
void SeqListInsert(SeqList* list, int pos, int data)
{
	if (list == NULL)
	{
		return;
	}
	if (list->len >= MAXSIZE - 1)
	{
		printf("表已满，插入失败！\n");
		return;
	}
	if (pos > list->len)
	{
		printf("表中数据不足，插入失败！\n");
		return;
	}
	if (pos == list->len)
	{
		SeqListPushBack(list,data);
		return;
	}
	else if(pos==0)
	{
		SeqListPushFront(list,data);
		return;
	}
	else
	{
		int tem = list->len;
		while (tem >= pos)
		{
			list->data[tem + 1] = list->data[tem];
			tem--;
		}
		list->data[pos] = data;
		list->len++;
		printf("插入数据成功！\n");
		return;
	}
}
//尾部追加数据
void SeqListPushBack(SeqList* list, int data)
{
	if (list == NULL)
	{
		return;
	}
	if (list->len >= MAXSIZE - 1)
	{
		printf("顺序表已满，追加失败！\n");
		return;
	}
	list->len++;
	list->data[list->len] = data;
	printf("尾部追加成功！\n");
}
//头部插入数据
void SeqListPushFront(SeqList* list, int data)
{
	if (list->len >= MAXSIZE - 1)
	{
		printf("顺序表已满，插入失败！\n");
		return;
	}
	if (list->len >= 0)
	{
		int tem = list->len;
		while (tem >= 0)
		{
			list->data[tem + 1] = list->data[tem];
			tem--;
		}
		list->data[0] = data;
		list->len++;
	}
	else
	{
		list->len = 0;
		list->data[0] = data;
	}
	
	printf("头部插入成功！\n");
}
//删除指定位置的元素
void SeqListErase(SeqList* list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	int tem = pos;
	if (pos > list->len)
	{
		printf("表中无足够元素，删除失败！\n");
		return;
	}
	else if(pos < list->len)
	{
		while (pos <list->len)
		{
			list->data[pos] = list->data[pos + 1];
			pos++;
		}
		list->len--;
	}
	else
	{
		list->len--;
	}
	printf("删除下标为%d的元素成功！\n",tem);
}
//删除尾部元素
void SeqListPopBack(SeqList* list)
{
	if (list == NULL)
	{
		return;
	}
	if (list->len == -1)
	{
		printf("顺序表中无数据，删除失败！\n");
		return;
	}
	list->len--;
	printf("尾部数据删除成功！\n");
}
//删除头部元素
void SeqListPopFront(SeqList* list)
{
	if (list == NULL)
	{
		return;
	}
	if (list->len == -1)
	{
		printf("顺序表数据为空，删除失败！\n");
		return;
	}
	if (list->len == 0)
	{
		list->len = -1;
	}
	else
	{
		for (int i = 0; i < list->len; i++)
		{
			list->data[i] = list->data[i + 1];
		}
		list->len--;
	}
	printf("头部数据删除成功！\n");
}
//删除第一个值为x的元素
void SeqListRemove(SeqList* list, int x)
{
	if (list == NULL)
	{
		return;
	}
	if (list->len == -1)
	{
		printf("顺序表为空，删除失败！\n");
		return;
	}
	for (int i = 0; i <= list->len; i++)
	{
		if (list->data[i] == x)
		{
			if (i == list->len)
			{
				list->len--;
				printf("已删除第一个为%d的数据!\n", x);
				return;
			}
			else
			{
				for (int j = i; j < list->len; j++)
				{
					list->data[j] = list->data[j + 1];
				}
				list->len--;
			}
			printf("已删除第一个为%d的数据!\n", x);
			return;
		}
	}
	printf("表中无值为%d的元素,删除失败！\n", x);
}
//查找元素，找到下标，否则-1
int SeqListFind(const SeqList* list, int search)
{
	if (list == NULL)
	{
		return -1;
	}
	if (list->len == -1)
	{
		printf("表为空，查找失败！\n");
		return -1;
	}
	for (int i = 0; i <= list->len; i++)
	{
		if (list->data[i] == search)
		{
			return i;
		}
	}
	return -1;
}
//输出有效长度
int SeqListGetize(const SeqList* list)
{
	if (list == NULL)
	{
		return -1;
	}
	int sum = 0;
	sum = list->len;
	return sum;
}
//判断是否为空,空0，非1
int SeqListEmpty(const SeqList* list)
{
	if (list->len == -1)
	{
		return 0;
	}
	return 1;
}
//打印数据
void SeqListPrint(const SeqList* list)
{
	if (list->len == -1)
	{
		printf("顺序表为空！\n");
		return;
	}
	printf("当前顺序表中数据为：\n");
	int cur = 0;
	while (cur != list->len)
	{
		printf("%d ", list->data[cur]);
		cur++;
	}
	printf("%d ", list->data[cur]);
	printf("\n");
}
//清空
void SeqListClear(SeqList* list)
{
	if (list == NULL)
	{
		return;
	}
	list->len = -1;
	printf("顺序表清空成功！\n");
}