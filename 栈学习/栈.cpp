#define _CRT_SECURE_NO_WARNINGS
/*
按我的理解，抽象成下面封口，上面开口的容器，从开口放入数据，先放入的数据在最下方（压栈），
先入后出，后入先出
*/

/*
本文件用顺序表和动态单向链表来实现栈的定义及基本函数
*/
/*//顺序表

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100  //顺序表的容积（栈的容积）

//栈的顺序表定义
struct stack {
	int *data;
	int top;			//与顺序表类似，但是指针域由每个数据的下标改为顶部数据下标（由于栈先进后出的性质决定）
};
//重命名
typedef stack Stack;

//函数声明
//初始化栈
Stack* Init_Stack();

//压栈
void Push(Stack* stack);

//出栈
void Pop(Stack* stack);

//销毁栈
void Destory_Stack(Stack* stack);
int main()
{
	//初始化栈
	Stack* stack =  Init_Stack();
	//压栈
	Push(stack);
	Push(stack);
	//出栈
	Pop(stack);
	//销毁栈
	Destory_Stack(stack);

	return 0;
}

//函数定义
//初始化栈
Stack* Init_Stack()
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->data = (int*)malloc(sizeof(int) * MAXSIZE);
	stack->top = -1;
	return stack;
}
//压栈
void Push(Stack* stack)
{
	if (stack->top >= MAXSIZE-1)
	{
		printf("栈区已满，压栈失败！\n");
		return;
	}
	printf("请输入要压栈的数据：");
	stack->top++;
	scanf("%d", &stack->data[stack->top]);
	printf("数据压栈成功！\n");
}
//出栈
void Pop(Stack* stack)
{
	if (stack->top < 0 || stack->top >= MAXSIZE)
	{
		printf("出栈失败！\n");
		return;
	}
	printf("已出栈：%d\n", stack->data[stack->top]);
	stack->top--;
}
//销毁栈
void Destory_Stack(Stack* stack)
{
	stack->top = -1;
	free(stack->data);
	stack->data = NULL;
	free(stack);
	stack = NULL;
	printf("栈已销毁！\n");
}
*/

//动态单向链表


/*#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100  //栈的容积

//栈的顺序表定义
struct stack {
	int data;
	stack* next;	//与单向链表结构相同，栈体现在函数上:因为栈先进后出，后进先出，
					//所以‘压栈’相当于头插数据（因为插入后还可以找到后面数据）
					//‘出栈’相当于输出头节点数据，并删除头节点
};
//重命名
typedef stack Stack;

//函数声明
//初始化栈
Stack* Init_Stack();

int len = 0;//记录已存入数据个数，看栈区是否已满

//压栈
void Push(Stack* stack);

//出栈
void Pop(Stack* stack);

//销毁栈
void Destory_Stack(Stack* stack);
int main()
{
	//初始化栈
	Stack* stack = Init_Stack();
	//压栈
	Push(stack);
	Push(stack);
	//出栈
	Pop(stack);
	Pop(stack);
	//销毁栈
	Destory_Stack(stack);

	return 0;
}

//函数定义
//初始化栈
Stack* Init_Stack()
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->next = NULL;
	return stack;
}
//压栈
void Push(Stack* stack)
{

	if (len>=100)
	{
		printf("栈区已满，压栈失败！\n");
		return;
	}
	Stack* newList = (Stack*)malloc(sizeof(Stack));
	len++;	
	printf("请输入要压栈的数据：");
	scanf("%d", &newList->data);
	newList->next = stack->next;
	stack->next = newList;
	printf("数据压栈成功！\n");
}
//出栈
void Pop(Stack* stack)
{
	if (len<=0||len>=100)
	{
		printf("出栈失败！\n");
		return;
	}
	len--;
	Stack* tem = stack->next;
	printf("已出栈：%d\n", tem->data);
	stack->next = tem->next;
	free(tem);
	tem = NULL;
}
//销毁栈
void Destory_Stack(Stack* stack)
{
	Stack* tem = stack->next;
	while (stack != NULL)
	{
		Stack* temp = stack;
		stack = stack->next;
		free(temp);
	}
	free(stack);
	printf("栈已销毁！\n");
}
*/
