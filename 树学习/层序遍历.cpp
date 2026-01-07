/*

*************************层序遍历******************************



*/


#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

//定义树节点并重命名
typedef struct TreeNode
{
	int data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;

//定义队列
typedef struct {
	BiTree* data;
	int head;
	int tail;
}Queue;

int str[] = {
	1,                    // 第1层：根节点
	2,                    // 第2层：左子节点
	4,                    // 第3层：左子节点
	8,                    // 第4层：左子节点
	16, -1, -1,           // 第5层：左子节点，左右子树为空
	9, -1, -1,            // 第4层：右子节点
	5,                    // 第3层：右子节点
	10, -1, -1,           // 第4层：左子节点
	11, -1, -1,           // 第4层：右子节点
	3,                    // 第2层：右子节点
	6,                    // 第3层：左子节点
	12, -1, -1,           // 第4层：左子节点
	13, -1, -1,           // 第4层：右子节点
	7,                    // 第3层：右子节点
	14, -1, -1,           // 第4层：左子节点
	15, -1, -1,           // 第4层：右子节点
	-1                    // 添加这个结束标记！
}; int index = 0;

//函数定义
//创建树
void createTree(BiTree* T);
//创建空队列
Queue* initQueue();
//入列
void equeue(Queue* q, TreeNode* T);
//判断队列是否为空
int isEmpty(Queue* q);
//统计队列中数量
int queueSize(Queue* q);
//出队
void dequeue(Queue* q, BiTree* curr);
//层序遍历，返回最深层层数
int maxDepth(TreeNode* T);

int main()
{
	BiTree T;
	createTree(&T);
	printf("创建树成功！\n");
	int dep = maxDepth(T);
	printf("%d", dep);


	return 0;
}

//函数声明
//创建树
 void createTree(BiTree* T)
{
	int tem = str[index++];
	if (tem == -1)
	{
		*T = NULL;
	}
	else 
	{
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = tem;
		createTree(&(*T)->lchild);
		createTree(&(*T)->rchild);
	}
}
 //创建空队列
 Queue* initQueue()
 {
	 Queue* q = (Queue*)malloc(sizeof(Queue));
	 q->data = (BiTree*)malloc(sizeof(BiTree) * MAXSIZE);
	 q->head = 0;
	 q->tail = 0;
	 return q;
 }
 //入列
 void equeue(Queue* q, TreeNode* T)
 {
	 if ((q->tail+1)%MAXSIZE==q->head)
	 {
		 printf("队列已满！\n");
	 }
	 else {
		 q->data[q->tail] = T;
		 q->tail = (q->tail + 1) % MAXSIZE;
	 }
 }
 //判断队列是否为空
 int isEmpty(Queue* q)
 {
	 if (q->tail == q->head)
	 {
		 return 1;
	 }
	 return 0;
 }
 //统计队列中数量
 int queueSize(Queue* q)
 {
	 int tem = q->head;
	 int count = 0;
	 while (tem != q->tail)
	 {
		 tem++;
		 count++;
	 }
	 return count;
 }
 //出队
 void dequeue(Queue* q, BiTree* curr)
 {
	 if (q->head == q->tail)
	 {
		 printf("空的！\n");
		 return;
	 }
	 *curr = q->data[q->head];
	 q->head = (q->head + 1) % MAXSIZE;
 }

 //层序遍历，返回最深层层数
 int maxDepth(TreeNode* T)
 {
	 if (T == NULL)
	 {
		 return 0;
	 }
	 int depth = 0;
	 Queue* q = initQueue();
	 equeue(q, T);

	 while (!isEmpty(q))
	 {
		 int count = queueSize(q);
		 while (count > 0)
		 {
			 TreeNode* curr;
			 dequeue(q, &curr);
			 if (curr->lchild != NULL)
			 {
				 equeue(q, curr->lchild);
			 }
			 if (curr->rchild != NULL)
			 {
				 equeue(q, curr->rchild);
			 }
			 count--;
		 }
		 depth++;
	 }
	 return depth;
 }