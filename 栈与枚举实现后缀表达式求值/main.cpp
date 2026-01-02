/*
本文件用栈与枚举实现后缀表达式的实现(不考虑两位数，此为简单实现)

后缀表达式计算原理：对于一串后缀表达式，从头开始读取，
如果是数字，便进行压栈操作，若是运算符，则进行两次出栈操作，
并按照“栈顶元素的下一个元素  运算符  栈顶元素”进行运算，
将运算结果压栈，知道遇到\0结束，此时栈内便为结果


*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100//最大栈容量
typedef int ElemType;//类型重命名，方便后续大规模修改

typedef struct {
	ElemType* data;//储存数据数组
	int top;//栈顶指针
}Stack;//重命名

typedef enum {
	LEFT_PARE,RIGHT_PARE,//‘（’‘）’
	ADD,SUB,MUL,DIV,MOD,//‘+’‘-’‘*’‘/’‘%’
	EOS,NUM//‘\0’'数字'
}contentType;//枚举，重命名

char text[] = "82/2+56*-";//定义后缀表达式，用于测试程序正确性，此式与“8/2+2-5*6"等价，结果为-24

//函数声明
//初始化
Stack* initStack();
//遍历后缀表达式，确认下步操作
contentType getToken(char* symbol, int* index);
//压栈
void push(Stack* s, int n);
//出栈
void pop(Stack* s, ElemType* n);
//计算程序函数
int eval(Stack* s);

int main()
{
	Stack* s = initStack();

	eval(s);

	return 0;
}

//函数定义
//初始化
Stack* initStack()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	s->top = -1;
	return s;
}

//遍历后缀表达式，确认下步操作
contentType getToken(char* symbol, int* index)
{
	*symbol = text[*index];
	(*index)++;
	switch (*symbol)
	{
	case '(':
		return LEFT_PARE;
	case ')':
		return RIGHT_PARE;
	case '+':
		return ADD;
	case '-':
		return SUB;
	case '*':
		return MUL;
	case '/':
		return DIV;
	case '%':
		return MOD;
	case '\0':
		return EOS;
	default :
		return NUM;
	}
}

//压栈
void push(Stack* s, int n)
{
	if (s->top == MAXSIZE - 1)
	{
		printf("栈已满，无法进行压栈操作！\n");
		return;
	}
	(s->top)++;
	s->data[s->top] = n;
}
//出栈
void pop(Stack* s, ElemType* n)
{
	if (s->top == -1)
	{
		printf("出栈失败，当前栈内无数据！\n");
		return;
	}
	*n = s->data[s->top];
	(s->top)--;
}

//计算程序函数
int eval(Stack* s)
{
	char symbol;//储存运算符
	ElemType op1, op2;//储存两个数据
	int index = 0;//起到下标的作用，用于遍历后缀表达式
	contentType token;//定于枚举类型变量，该变量只能被赋予枚举里面的数值（ADD,NUM等）
	token = getToken(&symbol, &index);//遍历后缀表达式，据情况给token赋值
	ElemType result;
	while (token != EOS)
	{
		if (token == NUM)
		{
			push(s, symbol - '0');
		}
		else
		{
			pop(s, &op2);
			pop(s, &op1);

			switch (token)
			{
			case ADD:
				push(s, op1 + op2);
				break;
			case SUB:
				push(s, op1 - op2);
				break;
			case MUL:
				push(s, op1 * op2);
				break;
			case DIV:
				push(s, op1 / op2);
				break;
			case MOD:
				push(s, op1 % op2);
				break;
			default:
				break;
			}
		}
		token = getToken(&symbol, &index);
	}
	pop(s, &result);
	printf("%s的结果为%d\n", text, result);
	return 1;
}


