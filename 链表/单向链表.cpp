/*
本文件内容：
单向链表的结构(动态)（因为静态太局限）
初始化
插入（头插、尾插、指定位置插）
遍历链表
删除（头节点、尾节点、指定位置节点、指定值节点）
获取链表长度
反转链表
销毁
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//重命名数据域数据类型名，方便以后改变
typedef int datatype;

//链表的结构定义
struct LinkList{
	datatype data;//数据域
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
void Input_Tail(List* LinkList, List **ptail);
//指定位置插入
void Posinput_List(List* LinkList, int len);

//遍历链表
void Print_List(List* LinkList);

//获取链表长度
int Len_List(List* LinkList );

//删除
//删除头节点
void Deletehead_List(List* LinkList, List** phead);
//删除尾节点
void Deletetail_List(List* LinkList,List** ptail);
//删除指定位置节点
void Deletepos_List(List* LinkList,int len);
//删除指定值节点
void Deletenum_List(List* LinkList, List** phead, List** ptail);

//反转链表
List* Shift(List* LinkList, List** phead, List** ptail);

//销毁链表
void Destory(List* LinkList, List** phead, List** ptail);




int main()
{
	//获取链表
	List* LinkList = Init_List();
	//创建尾部指针、头部指针、当前位置指针
	static List* ptail = LinkList;
	List* phead = LinkList;
	List* pcurr = LinkList;
	//头插一个数据
	Input_Head(LinkList,&phead,&ptail);

	//尾插一个数据
	Input_Tail(LinkList, &ptail);

	//多插入一些数据
	Input_Head(LinkList, &phead, &ptail); 
	Input_Head(LinkList, &phead, &ptail);
	Input_Tail(LinkList, &ptail);
	Input_Tail(LinkList, &ptail);

	//遍历链表
	Print_List(LinkList);
	//反转链表
	LinkList = Shift(LinkList, &phead, &ptail);

	//计算长度
	int len = Len_List(LinkList);
	printf("链表的长度为：%d\n", len);

	//插入一个数据
	Posinput_List(LinkList, len);

	//遍历链表
	Print_List(LinkList);

	//删除头节点
	Deletehead_List(LinkList,&phead);
	//删除尾节点
	Deletetail_List(LinkList,&ptail);
	//遍历链表
	Print_List(LinkList);

	//删除指定位置节点
	len = Len_List(LinkList);
	Deletepos_List(LinkList,len);
	Print_List(LinkList);
	//删除指定值节点
	Deletenum_List(LinkList, &phead, &ptail);

	//遍历链表
	Print_List(LinkList);

	//销毁链表
	Destory(LinkList,&phead, &ptail);

	return 0;
}

//函数定义
//初始化一个链表
List* Init_List()
{
	List* LinkList = (List*)malloc(sizeof(List));
	LinkList->next = NULL;
	LinkList->data = 0;
	return LinkList;
}
//插入
//头插
void Input_Head(List* LinkList,List** phead, List** ptail)
{
	//初始化节点并找相应位置插入
	List* Node = (List*)malloc(sizeof(List));
	printf("请输入要插入数据:");
	scanf("%d", &Node->data);
	//判断链表中是否已经有节点，据实际情况插入
	if (LinkList->next != NULL)
	{
		Node->next = LinkList->next;
		LinkList->next = Node;
		*phead = Node;
	}
	else
	{
		Node->next = NULL;
		LinkList->next = Node;
		*phead = Node;
		*ptail = Node;
	}
}
//尾插
void Input_Tail(List* LinkList, List** ptail)
{
	//初始化节点并找相应位置插入
	List* Node = (List*)malloc(sizeof(List));
	printf("请输入要插入数据:");
	scanf("%d", &Node->data);
	Node->next = NULL;
	(*ptail)->next = Node;
	//更新尾部节点
	*ptail = (*ptail)->next;
}
//指定位置插入
void Posinput_List(List* LinkList,int len)
{
	List* temp = (List*)malloc(sizeof(List));
	int pos = 0;
	printf("请输入你要插入的位置：");
	scanf("%d", &pos);
	if (len >= 1 && pos > 0 && pos <= len)
	{
		printf("请输入要插入的数据大小：");
		scanf("%d", &temp->data);
		List* current = LinkList;
		for (int i = 0; i < pos-1; i++)
		{
			current = current->next;
		}
		temp->next = current->next;
		current->next = temp;
	}
	else if (len < 1)
	{
		printf("链表无节点，插入失败！\n");
		free(temp);
	}
	else
	{
		printf("链表长度不足，无法插入！\n");
		free(temp);
	}
}

//遍历链表
void Print_List(List* LinkList)
{
	printf("当前链表的数据为：\n");
	List* pcurrent = LinkList->next;
	while (pcurrent != NULL)
	{
		printf("%d ", pcurrent->data);
		pcurrent = pcurrent->next;
	}
	printf("\n");
}


//获取链表长度
int Len_List(List* LinkList)
{
	//创建统计长度变量
	int len = 0;
	//遍历链表，统计长度，并返回尾部指针
	List* pcur = LinkList->next;
	while (pcur != NULL)
	{
		len++;
		pcur = pcur->next;
	}
	return len;
}

//删除
//删除头节点
void Deletehead_List(List* LinkList, List** phead)
{
	//储存头节点地址
	List* tem = LinkList->next;

	//连接链表头与二节点
	LinkList->next = tem->next;
	*phead = LinkList->next;

	//释放头节点
	free(tem);
}
//删除尾节点
void Deletetail_List(List* LinkList, List** ptail)
{
	//定义两个辅助指针
	List* slow = LinkList;
	List* fast = LinkList->next;
	//循环，找到尾节点
	while (fast->next != NULL)
	{
		slow = fast;
		fast = fast->next;
	}
	//更新尾节点
	slow->next = NULL;
	(*ptail) = slow;
	//清空空间
	free(fast);
}
//删除指定位置节点
void Deletepos_List(List* LinkList, int len)
{
	int pos = 0;
	printf("请输入你要删除节点的位置：");
	scanf("%d", &pos);
	List* cur = LinkList;
	if (len > 1 && pos > 1 && pos < len)
	{
		for (int i = 0; i < pos - 1; i++)
		{
			cur = cur->next;
		}
		List* tem = cur->next;
		cur->next = tem->next;
		free(tem);
	}
	else if (len < 1)
	{
		printf("链表无节点，删除失败！\n");
	}
	else
		printf("链表长度不足，删除失败！");
}
//删除指定值节点
void Deletenum_List(List* LinkList, List** phead, List** ptail)
{
	printf("请输入要删除的数值：");
	int dele = 0;
	scanf("%d", &dele);
	List* slow = LinkList;
	List* fast = LinkList->next;
	while (fast != NULL)
	{
		if (fast->data == dele)
		{
			List*tem = fast;
			slow->next = fast->next;
			fast = fast->next;
			free(tem);
		}
		else
		{
			slow = fast;
			fast = fast->next;
		}
	}
	(*phead) = LinkList->next;
	List* cur = LinkList;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	(*ptail) = cur;
	printf("删除成功！\n");
	
}

//反转链表
List*  Shift(List* LinkList, List** phead, List** ptail)
{
	if(LinkList->next == NULL || LinkList->next->next == NULL)
	{
		printf("链表长度过短，无法反转！\n");
		return LinkList;
	}
	//设置三个辅助针
	List* pre = NULL;
	List* cur = *phead;
	List* aft = NULL;
	//设置新的头
	List* newLinkList = (List*)malloc(sizeof(List));
	//开始反向连接
	while (cur!=NULL)
	{
		aft = cur->next;
		cur->next = pre;
		pre = cur;
		cur = aft;
	}
	newLinkList->next = pre;

	//更新头尾针
	*phead = newLinkList;
	while (pre->next != NULL)
	{
		pre = pre->next;
	}
	*ptail = pre;
	free(LinkList);
	LinkList = NULL;

	printf("反转完成！\n");

	Print_List(newLinkList);
	return newLinkList;
}

//销毁链表
void Destory(List* LinkList, List** phead, List** ptail)
{
	//设置辅助针，以便销毁节点
	List* tem = *phead;
	while (tem->next != NULL)
	{
		List* temp = tem->next;
		free(tem);
		tem = temp;
	}
	//重置头针，尾针，头节点
	LinkList->next = NULL;
	*phead = LinkList;
	*ptail = LinkList;

	printf("链表已销毁！\n");
}


