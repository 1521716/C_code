#include<stdio.h>
#include<stdlib.h>

/******************线索二叉树创建+遍历*******************************/

typedef struct ThreadNode {
	char data;
	ThreadNode* lchild;
	ThreadNode* rchild;
	int ltag;
	int rtag;
}ThreadNode;

typedef ThreadNode* ThreadTree;

char str[] = "ABDH##I##EJ###CF##G##";
int idx = 0;

ThreadTree prev;

//函数声明
//创建线索二叉树
void createTree(ThreadTree* T);
//具体线索化
void Threading(ThreadTree T);
//线索化
void inOrderThreading(ThreadTree* head, ThreadTree T);
//基于线索化的遍历
void inOrder(ThreadTree head);

int main()
{
	ThreadTree head;
	ThreadTree T;
	//创建线索二叉树
	createTree(&T);
	printf("线索二叉树创建成功！\n");
	//线索化
	inOrderThreading(&head,  T);
	//基于线索化的遍历
	inOrder(head);
	return 0;
}

//函数定义
//创建线索二叉树
void createTree(ThreadTree* T)
{
	char ch = str[idx++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else 
	{
		*T = (ThreadTree)malloc(sizeof(ThreadNode));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		if ((*T)->lchild != NULL)
		{
			(*T)->ltag = 0;
		}
		createTree(&(*T)->rchild);
		if ((*T)->rchild != NULL)
		{
			(*T)->rtag = 0;
		}
	}
}
//具体线索化
void Threading(ThreadTree T)
{
	if (T != NULL)
	{
		Threading(T->lchild);
		if (T->lchild == NULL)
		{
			T->ltag = 1;
			T->lchild = prev;
		}
		if (prev->rchild == NULL)
		{
			prev->rtag = 1;
			prev->rchild = T;
		}
		prev = T;
		Threading(T->rchild);
	}
}
//线索化
void inOrderThreading(ThreadTree* head, ThreadTree T)
{
	*head = (ThreadTree)malloc(sizeof(ThreadNode));
	(*head)->ltag = 0;
	(*head)->lchild = T;
	(*head)->rtag = 1;
	(*head)->rchild = *head;
	prev = *head;
	Threading(T);
	prev->rtag = 1;
	prev->rchild = *head;
	(*head)->rchild = prev;
}
//基于线索化的遍历
void inOrder(ThreadTree head)
{
	ThreadTree curr = head->lchild;
	while (curr != head)
	{
		while (curr->ltag == 0)
		{
			curr = curr->lchild;
		}
		printf("%c ", curr->data);
		while (curr->rtag == 1 && curr->rchild != head)
		{
			curr = curr->rchild;
			printf("%c ", curr->data);
		}
		curr = curr->rchild;
	}
	printf("\n");
}