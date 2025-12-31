#define _CRT_SECURE_NO_WARNINGS

/*
	本文件内容：
	1、队列理解
	2、用顺序表实现循环队列
*/
/*
	1、队列：最基础的队列为一端近，一端出，且先进先出，队列还有两端近，一端出等结构，但基本原理相同，在此不多赘述
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100//队列最大存储量为MAXSIZE-1
//2、顺序表实现循环队列

//队列结构
struct queue {
	int data[MAXSIZE];
	int head;//指向头位置，从此开始输出
	int tail;//指向最后有数据的下一个位置，便于储存数据
};

typedef queue Queue;
//函数声明
//初始化队列
Queue* Init_Queue();
//向队列存储一个数据
void Input_Queue(Queue* queue);
//从队列输出一个数据
void Output_Queue(Queue* queue);
//清空队列
void Clear_Queue(Queue* queue);
int main()
{
	//初始化队列
	Queue* queue = Init_Queue();
	//向队列存储一个数据
	Input_Queue(queue);
	//向队列存储一个数据
	Input_Queue(queue);
	//向队列存储一个数据
	Input_Queue(queue);
	//从队列输出一个数据
	Output_Queue(queue);
	//清空队列
	Clear_Queue(queue);
	//从队列输出一个数据
	Output_Queue(queue);
	return 0;
}

//函数定义
//初始化队列
Queue* Init_Queue()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->head = 0;
	queue->tail = 0;
	printf("队列初始化成功！\n");
	return queue;
}
//向队列存储一个数据
void Input_Queue(Queue* queue)
{
	if ((queue->tail + 1) % MAXSIZE == queue->head)//(queue->tail + 1) % MAXSIZE == queue->head为队列已满的条件，
		                                           //queue->tail==queue->head为队列为空的条件
	{
		printf("队列已满，无法存储数据！\n");
		return;
	}
	printf("请输入你要存储的数据：");
	scanf("%d", &queue->data[queue->tail]);
	queue->tail++;
	printf("数据存储成功！\n");
}
//从队列输出一个数据
void Output_Queue(Queue* queue)
{
	if (queue->tail == queue->head)
	{
		printf("队列中暂无数据，输出失败！\n");
		return;
	}
	printf("输出的数据为：%d\n", queue->data[queue->head]);
	queue->head++;
}
//清空队列
void Clear_Queue(Queue* queue)
{
	printf("你真的要清空队列吗，清空后不可恢复！\n");
	printf("请输入你的选择（1-清空  0-取消）>");
	int select = 0; scanf("%d", &select);
	if (select==1)
	{
		printf("开始清空队列！\n");
		queue->head = 0;
		queue->tail = 0;
		printf("队列清空成功！\n");
	}
	else if (0 == select)
	{
		printf("已放弃清空队列！\n");
		return;
	}
	else
	{
		printf("输入错误，默认为放弃！\n");
		return;
	}
}
