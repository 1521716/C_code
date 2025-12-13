#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"

//初始化链表
struct LinkNode* Init_LinkList()
{
	//创建头节点
	struct LinkNode* header = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	header->data = -1;
	header->next = NULL;

	//尾部指针
	struct LinkNode* pRear = header;

	//循环录入数据
	int val = 0;
	while (true)
	{
		printf("输入插入的数据：");
		scanf("%d", &val);
		//如果输入-1，则停止
		if (-1 == val)
			break;
		//创建新节点
		struct LinkNode* newnode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
		newnode->data = val;
		newnode->next = NULL;

		//将新节点插入
		pRear->next = newnode;

		//更新尾部节点
		pRear = newnode;
	}
	return header;
}

//遍历链表
void Foreach_LinkList(struct LinkNode* header)
{
	if (NULL == header)
		return;
	//辅助遍历链表的指针变量
	printf("现在的链表数据为：\n");
	struct LinkNode* pCurrent = header->next;
	while (NULL != pCurrent)
	{
		printf("%d ", pCurrent->data);
		pCurrent = pCurrent->next;
	}
	printf("\n");
}

//插入新节点
void InsertByValue_LinkList(struct LinkNode* header, int oldval, int newval)
{
	if (NULL == header)
		return;

	//定义两个辅助指针变量，用于找到插入位置
	struct LinkNode* pPrev = header;
	struct LinkNode* pCurrent = header->next;

	//通过遍历链表，查找插入位置
	while (pCurrent != NULL)
	{
		if (pCurrent->data == oldval)
			break;
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

	//如果pCurrent为空指针，则链表中不存在值为oldval的节点
	if (NULL == pCurrent)
	{
		printf("链表中无%d这个元素，默认插入最后！\n",oldval);

		//创建新节点
		struct LinkNode* newnode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
		newnode->data = newval;
		newnode->next = NULL;
		//插入
		pPrev->next = newnode;
		return;
	}

	//反之，链表中有oldval,开始插入
	//首先创建新节点
	struct LinkNode* newnode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	newnode->data = newval;
	newnode->next = NULL;
	//将新节点插入链表
	pPrev->next = newnode;
	newnode->next = pCurrent;
}

//清空链表
void Clear_LinkList(struct LinkNode* header)
{
	if (NULL == header)
	{
		return;
	}
	//辅助指针变量
	struct LinkNode* pCurrent = header->next;

	//通过循环，从第二个节点向后不断释放节点空间
	while (pCurrent != NULL)
	{
		//设置辅助指针变量，以保存下一个节点位置
		struct LinkNode* pTem = pCurrent->next;

		//开始释放内存，并更新辅助指针位置
		free(pCurrent);
		pCurrent = pTem;
	}
	//使头节点指向空
	header->next = NULL;
	printf("链表已清空！\n");
}

//删除节点
void RemoveByValue_LinkList(struct LinkNode* header, int delval)
{
	if (NULL == header)
		return;

	//两个辅助指针变量
	struct LinkNode* pPrev = header;
	struct LinkNode* pCurrent = header->next;

	//通过循环遍历查找要删除节点
	while (NULL != pCurrent)
	{
		if (pCurrent->data == delval)
			break;
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

	//出循环分两种情况：1、pCurrent==NULL 2、pCurrent->data==delval
	if (pCurrent == NULL)
	{
		printf("要删除的节点不存在！\n");
		return;
	}
	pPrev->next = pCurrent->next;
	printf("%d节点已删除！\n",pCurrent->data);
	free(pCurrent);
}

//销毁链表
void Destroy_LinkList(struct LinkNode* header)
{
	//可以先调用清空函数，在将头节点销毁
	//此处为了熟悉链表，并回顾清空函数，选择不调用清空函数

	if (header == NULL)
		return;
	//辅助指针变量
	struct LinkNode* pCurrent = header->next;
	//循环
	while (pCurrent != NULL)
	{
		//辅助指针变量来保存下一个节点地址
		struct LinkNode* pTem = pCurrent->next;

		//开始清空
		printf("%d节点已销毁\n", pCurrent->data);
		free(pCurrent);
		pCurrent = pTem;
	}
	//循环结束，只剩头节点，开始清空头节点
	free(header);
	printf("链表已销毁！\n");
}