#include<stdio.h>
#include<stdlib.h>

/*
//************************************创建一个普通二叉树+前序遍历*****************************************

typedef char ElemType;//方便后续大量更改，采用重命名

typedef struct TreeNode {
	ElemType data;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;//定义树结点，并重命名

typedef TreeNode* BiTree;//重命名

char str[] = "ABDH##I##EJ###CF##G##";//按照前序遍历得到的顺序，以此顺序创建树（#代表空）
int index = 0;//起数组下标的作用
//函数声明
//创建二叉树
void createTree(BiTree* T);

//遍历二叉树(根左右)
void PrintTree(BiTree* T);

int main()
{
	//创建一个树空间
	BiTree T;
	//创建二叉树
	createTree(&T);
	printf("创建二叉树成功！\n");

	//遍历二叉树(前序)
	printf("前序遍历二叉树的结果为：\n");
	PrintTree(&T);
	return 0;
}

//函数定义
//创建二叉树
void createTree(BiTree* T)
{
	ElemType ch = str[index++];//开始读取字符串
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		//创建新结点
		*T = (BiTree)malloc(sizeof(TreeNode));

		//给节点赋值
		(*T)->data = ch;

		//通过递归，给其左右孩子赋值
		createTree(&((*T)->lchild));
		createTree(&((*T)->rchild));
	}
}

//遍历二叉树(前序)
void PrintTree(BiTree* T)
{
	if ((*T) == NULL)
	{
		return;
	}
	printf("%c  ", (*T)->data);
	PrintTree(&((*T)->lchild));
	PrintTree(&((*T)->rchild));
}
*/


/*
//**********************************创建一个中序线索二叉树+中序遍历*******************************************



typedef char ElemType;//方便后续大量更改，采用重命名

typedef struct ThreadNode {
	ElemType data;
	ThreadNode* lchild;
	ThreadNode* rchild;
	int ltag;		//tag用来判断左右指针是孩子还是线索，0为孩子，1为线索
	int rtag;
}ThreadNode;//定义树结点，并重命名

typedef ThreadNode* ThreadTree;//重命名

char str[] = "ABDH##I##EJ###CF##G##";//按照前序遍历得到的顺序，以此顺序创建树（#代表空）
int index = 0;//起数组下标的作用

ThreadTree prev;//保留上一个访问的结点

//函数声明
//创建线索二叉树
void createTree(ThreadTree* T);

//具体线索化
void Threading(ThreadTree* T);

//线索化
void inOrderThreading(ThreadTree*head,ThreadTree T);

//遍历线索二叉树(中序遍历)
void inOrder(ThreadTree T);

int main()
{
	ThreadTree T,head;
	//创建二叉树
	createTree(&T);
	printf("创建二叉树成功！\n");

	//线索化
	inOrderThreading(&head, T);
	printf("二叉树线索化成功！\n");

	//遍历线索二叉树(中序遍历)
	inOrder(head);


	return 0;
}

//函数定义
//创建线索二叉树
void createTree(ThreadTree* T)
{
	//遍历字符串，准备赋值
	ElemType ch = str[index++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		//分配空间
		*T = (ThreadTree)malloc(sizeof(ThreadNode));

		//赋值
		(*T)->data = ch;

		//通过递归，为左右孩子赋值
		createTree(&((*T)->lchild));
		//判断线索与否
		if (&((*T)->lchild) != NULL)
		{
			(*T)->ltag = 0;
		}

		createTree(&((*T)->rchild));
		if (&((*T)->rchild) != NULL)
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
	//给头结点分配空间
	*head = (ThreadTree)malloc(sizeof(ThreadNode));
	//开始线索化头节点
	(*head)->ltag = 0;
	(*head)->rtag = 1;
	(*head)->lchild = T;
	(*head)->rchild = *head;
	if (T == NULL)
	{
		(*head)->lchild = *head;
	}
	else
	{
		prev = *head;

		//具体线索化
		Threading(T);

		//最后一个结点线索化
		prev->rtag = 1;
		prev->rchild = *head;
		//头节点右孩子线索化
		(*head)->rchild = prev;
	}
}

//遍历线索二叉树(中序遍历)
void inOrder(ThreadTree T)
{
	ThreadTree curr = T->lchild;
	while (curr != T)
	{
		while (curr->ltag == 0)
		{
			curr = curr->lchild;
		}
		printf("%c  ", curr->data);
		while (curr->rtag == 1 && curr->rchild != T)
		{
			curr = curr->rchild;
			printf("%c  ", curr->data);
		}
		curr = curr->rchild;
	}
	printf("\n");
}
*/



