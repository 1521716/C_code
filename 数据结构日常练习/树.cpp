#define _CRT_SECURE_NO_WARNINGS

//********************************二叉树*****************************



#include<stdio.h>
#include<stdlib.h>



typedef struct TreeNode
{
	int data;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;

//函数声明
//初始化根节点
TreeNode* tree_create();
//为指父节点插入左孩子
void tree_input_lchild(TreeNode* parent, int data);
//为指父节点插入右孩子
void tree_input_rchild(TreeNode* parent, int data);
//获取指定父节点的左孩子结点地址
TreeNode* tree_get_lchild(TreeNode* parent);
//获取指定父节点的右孩子结点地址
TreeNode* tree_get_rchild(TreeNode* parent);
//获取指定结点储存的数据
int tree_get_data(TreeNode* node);
//修改指定结点的数据
void tree_turn_data(TreeNode* node, int data);
//前序遍历树
void tree_get_tlr(TreeNode* curr);
//中序遍历树
void tree_get_ltr(TreeNode* curr);
//后序遍历树
void tree_get_lrt(TreeNode* curr);
//查找指定值的结点
TreeNode* tree_find_x(int x, TreeNode* curr);
//销毁树
void tree_destroy( TreeNode* curr);


int main()
{
	//初始化根节点
	TreeNode* root = tree_create();
	root->data = 0;
	//设置一个结点，用于遍历
	TreeNode*curr = root;
	//为指父节点插入左孩子
	tree_input_lchild(root,10);
	//为指父节点插入右孩子
	tree_input_rchild(root,11);
	tree_input_lchild(root->lchild, 20);
	tree_input_rchild(root->lchild, 21);
	//获取指定结点储存的数据
	printf("%d\n",tree_get_data(root));
	//修改指定结点的数据
	tree_turn_data(root,99);
	printf("%d\n", tree_get_data(root));
	//前序遍历树
	printf("前序遍历：\n");
	tree_get_tlr(curr);
	printf("\n");
	//中序遍历树
	printf("中序遍历：\n");
	tree_get_ltr( curr);
	printf("\n");
	//后序遍历树
	printf("后序遍历：\n");
	tree_get_lrt( curr);
	printf("\n");
	//查找指定值的结点
	TreeNode*result = tree_find_x( 21, curr);
	if (result == NULL)
	{
		printf("树中无该结点！\n");
	}
	else
		printf("结点已找到，该结点的值为：%d \n", result->data);
	//重置辅助指针
	curr = root;
	//销毁树
	tree_destroy(curr);
	root = NULL;
	printf("树已销毁！\n");
	return 0;
}

//函数声明
//初始化根节点
TreeNode* tree_create()
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->lchild = NULL;
	root->rchild = NULL;
	printf("初始化根节点成功！\n");
	return root;
}
//为指父节点插入左孩子
void tree_input_lchild(TreeNode* parent, int data)
{
	if (parent->lchild != NULL)
	{
		printf("该父结点已有左孩子，插入失败！\n");
		return;
	}
	TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
	newnode->data = data;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	parent->lchild = newnode;
	printf("左孩子插入成功！\n");
}
//为指父节点插入右孩子
void tree_input_rchild(TreeNode* parent, int data)
{

	if (parent->rchild != NULL)
	{
		printf("该父结点已有右孩子，插入失败！\n");
		return;
	}
	TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
	newnode->data = data;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	parent->rchild = newnode;
	printf("右孩子插入成功！\n");
}
//获取指定父节点的左孩子结点地址
TreeNode* tree_get_lchild(TreeNode* parent)
{
	if (parent == NULL)
	{
		printf("该父结点不存在，获取失败\n");
		return NULL;
	}
	return parent->lchild;
}
//获取指定父节点的右孩子结点地址
TreeNode* tree_get_rchild(TreeNode* parent)
{
	if (parent == NULL)
	{
		printf("该父结点不存在，获取失败\n");
		return NULL;
	}
	return parent->rchild;
}
//获取指定结点储存的数据
int tree_get_data(TreeNode* node)
{
	if (node == NULL)
	{
		printf("树中无该结点，获取失败！\n");
		return -1;
	}
	printf("获取成功！\n");
	return node->data;
}
//修改指定结点的数据
void tree_turn_data(TreeNode* node, int data)
{
	if (node == NULL)
	{
		printf("树中无该结点，修改失败！\n");
		return;
	}
	node->data = data;
	printf("修改成功！\n");
}
//前序遍历树
void tree_get_tlr(TreeNode* curr)
{
	if (curr == NULL)
	{
		return;
	}
	printf("%d ", curr->data);
	tree_get_tlr(curr->lchild);
	tree_get_tlr(curr->rchild);
}
//中序遍历树
void tree_get_ltr(TreeNode* curr)
{
	if (curr == NULL)
	{
		return;
	}
	tree_get_ltr(curr->lchild);
	printf("%d ", curr->data);
	tree_get_ltr(curr->rchild);
}
//后序遍历树
void tree_get_lrt(TreeNode* curr)
{
	if (curr == NULL)
	{
		return;
	}
	tree_get_lrt( curr->lchild);
	tree_get_lrt( curr->rchild);
	printf("%d ", curr->data);
}
//查找指定值的结点
TreeNode* tree_find_x(int x,TreeNode* curr)
{
	if (curr == NULL) {
		return NULL;
	}

	// 如果当前节点就是目标
	if (curr->data == x) {
		return curr;
	}

	// 先在左子树中查找
	TreeNode* leftResult = tree_find_x( x,curr->lchild);
	if (leftResult != NULL) {
		return leftResult;
	}

	// 先在右子树中查找
	TreeNode* rightResult = tree_find_x( x,curr->rchild);
	if (rightResult != NULL) {
		return rightResult;
	}
	return NULL;
}
//销毁树
void tree_destroy(TreeNode* curr)
{
	if (curr == NULL)
	{
		return;
	}
	TreeNode* tem = curr;
	tree_destroy( curr->lchild);
	tree_destroy( curr->rchild);
	free(tem);
	tem = NULL;
}