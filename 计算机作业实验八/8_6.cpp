#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
struct Node{
	int ID;
	char name[20];
	double score;
	struct Node*next;
};

//设置辅助全局变量
int sum = 0;
Node*pHead = NULL;
Node*pPear = NULL;

//函数声明
//初始化链表
Node *Init(); 
//插入节点
void Insert(Node*LinkList); 
//输出链表
void Show(Node*LinkList); 
//查找函数
Node* Search(Node*LinkList,char *search); 
int main()
{
	//初始化链表
	Node *LinkList = Init(); 
	//插入节点
	Insert(LinkList);
	Insert(LinkList);
	Insert(LinkList);
	
	/*//输出链表
	Show(LinkList); */
	
	//查找
	char search[20] = {0};
	printf("请输入要查找的姓名：");
	scanf("%s",search);
	getchar();
	Node* result = Search(LinkList,search); 
	if(result==NULL)
	{
		printf("该学生不存在。\n");
	}
	else
	{
		printf("查找结果：\n");
		printf("%d	%s	%.2lf\n",result->ID,result->name,result->score);
	}
	free(LinkList);
	return 0;
}

//函数定义
//初始化链表
Node *Init()
{
	Node*LinkList = (Node*)malloc(sizeof(Node));
	LinkList->next = NULL;	
	return LinkList;
} 
//插入节点
void Insert(Node*LinkList)
{
	sum++;
	//创建新节点
	Node*newnode = (Node*)malloc(sizeof(Node));
	printf("请输入数据（学号、姓名、成绩）：");
	scanf("%d%s%lf",&newnode->ID,newnode->name,&newnode->score);
	newnode->next = NULL;
	//插入节点
	if(1==sum)
	{
		printf("链表中暂无节点，默认放在第一位。\n");
		pPear = LinkList;
		pPear->next = newnode;
		pPear = pPear->next;
	}
	else
	{	int select = 1;
		while(select)
		{
			printf("请输入插入位置（1-头插  2-尾插  0-退出）>");
			scanf("%d",&select);
			switch(select)
			{
				case 1:
					newnode->next = LinkList->next;
					LinkList->next = newnode;
					return; 
				case 2:
					pPear->next = newnode;
					pPear = pPear->next; 
					return;
				case 0:
					printf("已退出插入功能！\n");
					return;
				default:
					printf("输入错误，请重新输入！\n");
					scanf("%d",select);	
			}
		}
	}
}

//输出链表
void Show(Node*LinkList)
{
	pHead = LinkList->next;
	printf("学号	姓名	分数\n");
	while(pHead!=NULL)
	{
		printf("%d	%s	%lf\n",pHead->ID,pHead->name,pHead->score);
		pHead = pHead->next;
	}
}
//查找函数
Node* Search(Node*LinkList,char *search)
{
	pHead = LinkList->next;
	while(pHead!=NULL)
	{
		if(strcmp(search,pHead->name)==0)
			return pHead;
		pHead=pHead->next;
	}
	return NULL;
}
