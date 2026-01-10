#define _CRT_SECURE_NO_WARNINGS

//********************************栈******************************


/*本文件以顺序表实现，链表也可实现，以头结点为栈顶，入栈即头插数据，出栈即删除头节点*/

//后进先出，先进后出

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100


typedef struct stack {
	int *data;
	int len;
}Stack;

//函数声明
//初始化空栈
Stack* Stack_init();
//判断栈是否为空(空0否1)
int Stack_is_empty(const Stack* stack);
//入栈
void Stack_push(Stack* stack, int data);
//出栈
void Stack_pop(Stack* stack);
//获取栈顶元素（不出栈）
void Stack_get_pop(const Stack* stack);
//获取栈的元素个数
int Stack_size(const Stack* stack);
//清空栈中所有元素
void Stack_clear(Stack* stack);
//销毁栈
void Stack_destroy(Stack* stack);

int main()
{
	//初始化空栈
	Stack* stack =Stack_init();
	//判断栈是否为空(空0否1)
	int result = Stack_is_empty(stack);
	printf("%d  \n", result);
	//入栈
	Stack_push(stack,10);
	Stack_push(stack, 30);
	Stack_push(stack, 20);
	//出栈
	Stack_pop(stack);
	//获取栈顶元素（不出栈）
	Stack_get_pop(stack);
	//获取栈的元素个数
	int len = Stack_size(stack);
	printf("栈中元素个数为%d\n", len);
	//清空栈中所有元素
	Stack_clear(stack);
	//销毁栈
	Stack_destroy(stack);
	return 0;
}

//函数定义
//初始化空栈
Stack* Stack_init()
{
	Stack* stack;
	stack = (Stack*)malloc(sizeof(Stack));
	stack->data = (int*)malloc(sizeof(int) * MAXSIZE);
	stack->len = -1;
	printf("栈初始化成功！\n");
	return stack;
}
//判断栈是否为空(空0否1)
int Stack_is_empty(const Stack* stack)
{
	if (stack == NULL)
	{
		return 0;
	}
	if (stack->len == -1)
	{
		return 1;
	}
	return 0;
}
//入栈
void Stack_push(Stack* stack, int data)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->len >= MAXSIZE - 1)
	{
		printf("栈已满，入栈失败！\n");
		return;
	}
	stack->len++;
	stack->data[stack->len] = data;
	printf("入栈成功！\n");
}
//出栈
void Stack_pop(Stack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->len <= -1)
	{
		printf("栈为空，出栈失败！\n");
		return;
	}
	printf("%d已出栈！\n",stack->data[stack->len]);
	stack->len--;
}
//获取栈顶元素（不出栈）
void Stack_get_pop(const Stack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->len <= -1)
	{
		printf("栈为空，获取栈顶元素失败！\n");
		return;
	}
	printf("栈顶元素为%d \n", stack->data[stack->len]);
}
//获取栈的元素个数
int Stack_size(const Stack* stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	return stack->len + 1;
}
//清空栈中所有元素
void Stack_clear(Stack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	stack->len = -1;
	printf("栈已清空！\n");
}
//销毁栈
void Stack_destroy(Stack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack->data);
	free(stack);
	stack = NULL;
	printf("栈已销毁！\n");
}