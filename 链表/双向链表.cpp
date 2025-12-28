/*
本文件内容：
双向链表的结构(动态)（因为静态太局限）
初始化
插入（头插、尾插、指定位置插）
遍历链表
删除（头节点、尾节点、指定位置节点、指定值节点）
获取链表长度
销毁
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//链表的结构定义
struct LinkList {
	struct LinkList* pre;
	int data;//数据域
	struct LinkList* next;//指针域
};

//重命名
typedef LinkList List;

//函数声明
//初始化一个链表
List* Init_List();

//插入
//头插
void Input_Head(List* LinkList, List** phead, List** ptail);
//尾插
void Input_Tail(List* LinkList, List** ptail);
//指定位置插入
void Posinput_List(List* LinkList, int len, List** phead, List** ptail);

//遍历链表
void Print_List(List* LinkList);

//获取链表长度
int Len_List(List* LinkList);

//删除
//删除头节点
void Deletehead_List(List* LinkList, List** phead);
//删除尾节点
void Deletetail_List(List* LinkList, List** ptail);
//删除指定位置节点
void Deletepos_List(List* LinkList, int len);
//删除指定值节点
void Deletenum_List(List* LinkList, List** phead, List** ptail);


//销毁链表
void Destory(List* LinkList, List** phead, List** ptail);

int main()
{
	//初始化链表
	List* LinkList = Init_List();
	//创建尾部指针、头部指针
	static List* ptail = LinkList;
	List* phead = LinkList;

	//头插
	Input_Head(LinkList, &phead,&ptail);
	Input_Head(LinkList, &phead, &ptail);
	//尾插
	Input_Tail(LinkList, &ptail);
	Input_Tail(LinkList, &ptail);
	//获取链表长度
	int len = Len_List(LinkList);
	printf("当前链表有效长度为：%d\n", len);
	//遍历链表
	Print_List(LinkList);

	//指定位置插入
	Posinput_List(LinkList,len,&phead,&ptail);

	//遍历链表
	Print_List(LinkList);

	//销毁链表
	Destory(LinkList, &phead,&ptail);
}

//函数定义
//初始化一个链表
List* Init_List()
{
	List* LinkList = (List*)malloc(sizeof(List));
	LinkList->pre = NULL;
	LinkList->next = NULL;
	return LinkList;
}

//插入
//头插
void Input_Head(List* LinkList, List** phead, List** ptail)
{
	List* newNode = (List*)malloc(sizeof(List));
	printf("请输入要插入的数据大小：");
	scanf("%d", &newNode->data);
	if ((*phead)->next == NULL)
	{
		LinkList->next = newNode;
		newNode->pre = LinkList;
		newNode->next = NULL;
		*ptail = newNode;
	}
	else
	{
		newNode->next = LinkList->next;
		LinkList->pre = newNode;
		LinkList->next = newNode;
		newNode->pre = LinkList;
	}
	printf("插入头节点成功！\n");
}
//尾插
void Input_Tail(List* LinkList, List** ptail)
{
	List* newNode = (List*)malloc(sizeof(List));
	printf("请输入你要插入的数据大小：");
	scanf("%d", &newNode->data);
	if (LinkList->next == NULL)
	{
		LinkList->next = newNode;
		newNode->pre = LinkList;
		newNode->next = NULL;
		*ptail = newNode;
	}
	else
	{
		(*ptail)->next = newNode;
		newNode->pre = *ptail;
		newNode->next = NULL;
		*ptail = newNode;
	}
	printf("插入尾节点成功！\n");
}
//指定位置插入
void Posinput_List(List* LinkList, int len, List** phead, List** ptail)
{
	List* newNode = (List*)malloc(sizeof(List));
	if (len < 1)
	{
		printf("链表长度不足，插入失败！\n");
		return;
	}
	else if (len == 1)
	{
		printf("链表长度为1，默认头插！\n");
		Input_Head(LinkList, phead, ptail);
		return;
	}
	printf("请输入你要插入的位置：");
	int pos = 0; scanf("%d", &pos);
	if (pos < 1 || pos > len)
	{
		printf("插入位置不合法，插入失败！\n");
		return;
	}
	printf("请输入你要插入的数据大小：");
	scanf("%d", &newNode->data);
	List* cur = *phead;
	for (int i = 0; i < pos - 1; i++)
	{
		cur = cur->next;
	}
	newNode->next = cur->next;
	cur->next->pre = newNode;
	cur->next = newNode;
	newNode->pre = cur;
	printf("插入成功！\n");
}

/*//删除
//删除头节点
void Deletehead_List(List* LinkList, List** phead)
//删除尾节点
void Deletetail_List(List* LinkList, List** ptail);
//删除指定位置节点
void Deletepos_List(List* LinkList, int len);
//删除指定值节点
void Deletenum_List(List* LinkList, List** phead, List** ptail);
因为和单向链表操作区别不大，有区别的地方在插入的实现已经体现，故不在操作
*/


//遍历链表
void Print_List(List* LinkList)
{
	List* cur = LinkList;
	printf("当前链表的数据为：\n");
	while (cur->next != NULL)
	{
		printf("%d ", cur->next->data);
		cur = cur->next;
	}
	printf("\n");
}

//获取链表长度
int Len_List(List* LinkList)
{
	int len = 0;
	List* cur = LinkList->next;
	while (cur != NULL)
	{
		len++;
		cur = cur->next;
	}
	return len;
}


//销毁链表
void Destory(List* LinkList, List** phead, List** ptail)
{
	List* tem = LinkList->next;
	while (tem != NULL)
	{
		List* temp = tem;
		tem = tem->next;
		free(temp);
	}
	*ptail = LinkList;
	printf("链表销毁成功！\n");
}
