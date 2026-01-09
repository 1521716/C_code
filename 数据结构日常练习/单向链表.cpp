#define _CRT_SECURE_NO_WARNINGS

//********************************单向链表******************************

#include<stdio.h>
#include<stdlib.h>

//链表结点结构
typedef struct ListNode {
	int data;
	ListNode* next;
}ListNode;

//链表结构
struct LinkList {
	ListNode* List;
	ListNode* pHead;
	ListNode* pPear;
};

//函数声明
//创建新结点
ListNode* ListNodeCreate();
//初始化空链表
LinkList* LinkListinit();
//头插数据
void ListInsertHead(LinkList* list,int data);
//尾插数据
void ListInsertPear(LinkList* list, int data);
//指定结点插入数据
void ListInsertPos(LinkList* list, int pos, int data);
//删除头节点
void ListDeleteHead(LinkList* list);
//删除尾结点
void ListDeletePear(LinkList* list);
//删除指定位置结点
void ListDeletePos(LinkList* list, int pos);
//查找值x的结点，返回地址
ListNode* ListFindByx(LinkList* list, int x);
//查找位置为pos的结点，返回地址
ListNode* ListFindByPos(LinkList* list, int pos);
//获取链表有效长度
int ListGetLength(LinkList* list);
//遍历链表
void ListPrint(LinkList* list);
//清空链表
void ListClear(LinkList* list);
//销毁链表
void LinkListDestroy(LinkList* list);


int main()
{
	//初始化空链表
	LinkList* list = LinkListinit();
	//头插数据
	ListInsertHead(list, 10);
	ListInsertHead(list, 20);
	ListInsertHead(list, 30);
	//尾插数据
	ListInsertPear(list,50);
	//遍历链表
	ListPrint(list);
	//删除头节点
	ListDeleteHead(list);
	//遍历链表
	ListPrint(list);
	//删除尾结点
	ListDeletePear(list);
	//遍历链表
	ListPrint(list);
	//指定结点插入数据
	ListInsertPos(list, 1, 15);
	//遍历链表
	ListPrint(list);
	//获取链表有效长度
	printf("%d\n", ListGetLength(list));
	//查找值x的结点，返回地址
	printf("%p\n",ListFindByx(list, 15));
	//清空链表
	ListClear(list);
	//遍历链表
	ListPrint(list);
	//销毁链表
	LinkListDestroy(list);
	return 0;
}


//函数定义
//创建新结点
ListNode* ListNodeCreate()
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->next = NULL;
	return newnode;
}
//初始化空链表
LinkList* LinkListinit()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->List = ListNodeCreate();
	list->pHead = NULL;
	list->pPear = NULL;
	printf("链表初始化成功！\n");
	return list;
}
//头插数据
void ListInsertHead(LinkList* list, int data)
{
	if (list == NULL)
	{
		return;
	}
	if (list->pHead == NULL)
	{
		ListNode *newnode = ListNodeCreate();
		newnode->data = data;
		list->List->next = newnode;
		list->pHead = newnode;
		list->pPear = newnode;
	}
	else
	{
		ListNode* newnode = ListNodeCreate();
		newnode->data = data;
		newnode->next = list->pHead;
		list->List->next = newnode;
		list->pHead = newnode;
	}
	printf("头节点插入成功！\n");
}
//尾插数据
void ListInsertPear(LinkList* list, int data)
{
	if (list == NULL)
	{
		return;
	}
	if (list->pPear == NULL)
	{
		ListNode* newnode = ListNodeCreate();
		newnode->data = data;
		list->List->next = newnode;
		list->pHead = newnode;
		list->pPear = newnode;
	}
	else
	{
		ListNode* newnode = ListNodeCreate();
		newnode->data = data;
		list->pPear->next = newnode;
		list->pPear = newnode;
	}
	printf("尾节点插入成功！\n");
}
//指定结点插入数据
void ListInsertPos(LinkList* list, int pos, int data)
{
	if (list == NULL)
	{
		return;
	}
	if (list->pHead == NULL)
	{
		printf("链表为空，插入失败！\n");
		return;
	}
	ListNode* cur = list->pHead;
	ListNode* tem = list->List;
	int num = 0;
	while (cur != list->pPear)
	{
		if (num == pos)
		{
			ListNode* newnode = ListNodeCreate();
			newnode->data = data;
			newnode->next = cur;
			tem->next = newnode;
			if (pos == 0)
			{
				list->pHead = newnode;
			}
			printf("数据插入成功！\n");
			return;
		}
		num++;
		tem = cur;
		cur = cur->next;
	}
	if (num == pos)
	{
		if (list->pPear == NULL)
		{
			ListNode* newnode = ListNodeCreate();
			newnode->data = data;
			list->List->next = newnode;
			list->pHead = newnode;
			list->pPear = newnode;
		}
		else
		{
			ListNode* newnode = ListNodeCreate();
			newnode->data = data;
			list->pPear->next = newnode;
			list->pPear = newnode;
		}
		printf("数据插入成功！\n");
		return;
	}
	printf("插入位置异常！\n");
}
//删除头节点
void ListDeleteHead(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	if (list->pHead == NULL)
	{
		printf("链表为空，删除失败！\n");
		return;
	}
	ListNode* tem = list->pHead;
	list->List->next = list->pHead->next;
	list->pHead = list->pHead->next;
	free(tem);
	tem = NULL;
	//如果删除前只有一个结点，那删除后一定要改变尾针，否则尾针变为野指针
	if (list->pHead == NULL)
	{
		list->pPear == NULL;
	}
	printf("删除头节点成功！\n");
}
//删除尾结点
void ListDeletePear(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	if (list->pPear == NULL)
	{
		printf("链表为空，删除失败！\n");
		return;
	}
	if (list->pHead == list->pPear)//说明为空链表（上面已排除），或者只有一个有效结点
	{
		ListNode* tem = list->pPear;
		list->pHead = NULL;
		list->pPear = NULL;
		free(tem);
		tem = NULL;
		printf("尾节点删除成功！\n");
		return;
	}
	ListNode* temp = list->pPear;
	ListNode* curr = list->pHead;
	while (curr->next != temp)
	{
		curr = curr->next;
	}
	curr->next = NULL;
	list->pPear = curr;
	free(temp);
	temp = NULL;
	printf("尾节点删除成功！\n");
}
//删除指定位置结点
void ListDeletePos(LinkList* list, int pos);
//查找值x的结点，返回地址
ListNode* ListFindByx(LinkList* list, int x)
{
	if (list == NULL)
	{
		return NULL;
	}
	if (list->pHead == NULL)
	{
		printf("链表为空，查找失败！\n");
		return NULL;
	}
	ListNode* cur = list->List;
	while (cur != list->pPear)
	{
		if (cur->data == x)
		{
			printf("已找到！\n");
			return cur;
		}
		cur = cur->next;
	}
	if (cur->data == x)
	{
		printf("已找到！\n");
		return list->pPear;
	}
	else
		return NULL;
}
//查找位置为pos的结点，返回地址
ListNode* ListFindByPos(LinkList* list, int pos);
//获取链表有效长度
int ListGetLength(LinkList* list)
{
	if (list == NULL)
	{
		return 0;
	}
	if (list->pHead == NULL)
	{
		return 0;
	}
	ListNode* curr = list->pHead;
	int len = 1;
	while (curr != list->pPear)
	{
		len++;
		curr = curr->next;
	}
	return len;
}
//遍历链表
void ListPrint(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	if (list->pHead == NULL)
	{
		printf("当前链表为空！\n");
		return;
	}
	printf("当前链表内容为：\n");
	ListNode* curr = list->pHead;
	while (curr != list->pPear)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("%d\n", curr->data);
}
//清空链表
void ListClear(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	if (list->pHead == NULL)
	{
		printf("链表为空，无需清空！\n");
		return;
	}
	ListNode* curr = list->pHead;
	while (curr != list->pPear)
	{
		ListNode* tem = curr;
		curr = curr->next;
		free(tem);
		tem = NULL;
	}
	free(curr);
	curr = NULL;
	list->List->next = NULL;
	list->pHead = NULL;
	list->pHead = NULL;
	printf("链表清空成功！\n");
}
//销毁链表
void LinkListDestroy(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	if (list->pHead == NULL)
	{
		free(list);
		list = NULL;
		printf("链表销毁成功！\n");
		return;
	}
	ListNode* curr = list->pHead;
	while (curr != list->pPear)
	{
		ListNode* tem = curr;
		curr = curr->next;
		free(tem);
		tem = NULL;
	}
	free(curr);
	curr = NULL;
	free(list);
	list = NULL;
	printf("链表销毁成功！\n");
}