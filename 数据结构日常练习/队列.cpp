#define _CRT_SECURE_NO_WARNINGS

//********************************循环队列******************************


//先进先出

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct queue {
	int* data;
	int head;
	int tail;
}Queue;

//函数声明
//初始化空队列
Queue* Queue_init();
//判断队列是否为空
int Queue_is_empty(const Queue* queue);
//判断队列是否已满
int Queue_is_full(const Queue* queue);
//入队
void Queue_enqueue(Queue* queue, int data);
//出队
void Queue_dequeue(Queue* queue);
//获取队头元素
int Queue_get_queue_head(const Queue* queue);
//获取队列中元素个数
int Queue_size(const Queue* queue);
//清空所有元素
void Queue_clear(Queue* queue);
//销毁
void Queue_destroy(Queue* queue);

int main()
{

	//初始化空队列
	Queue*queue =  Queue_init();
	//判断队列是否为空
	int result01 =  Queue_is_empty(queue);
	printf("%d\n", result01);
	//判断队列是否已满
	int result02 =  Queue_is_full(queue);
	printf("%d\n", result02);
	//入队
	Queue_enqueue(queue,10);
	Queue_enqueue(queue, 30);
	Queue_enqueue(queue, 20);
	//出队
	Queue_dequeue(queue);
	Queue_dequeue(queue);
	//获取队头元素
	int num = Queue_get_queue_head(queue);
	printf("队头元素为%d\n", num);
	//获取队列中元素个数
	int len =  Queue_size(queue);
	printf("队列的长度为%d\n", len);
	//清空所有元素
	Queue_clear(queue);
	//销毁
	Queue_destroy(queue);
	return 0;
}

//函数声明
//初始化空队列
Queue* Queue_init()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->data = (int*)malloc(sizeof(int) * MAXSIZE);
	queue->head = -1;
	queue->tail = -1;
	printf("队列初始化成功！\n");
	return queue;
}
//判断队列是否为空
int Queue_is_empty(const Queue* queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	if (queue->head == queue->tail)
	{
		return 1;
	}
	return 0;
}
//判断队列是否已满
int Queue_is_full(const Queue* queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	if ((queue->tail + 1) % MAXSIZE == queue->head)
	{
		return 1;
	}
	return 0;
}
//入队
void Queue_enqueue(Queue* queue, int data)
{
	if (queue == NULL)
	{
		return;
	}
	if ((queue->tail + 1) % MAXSIZE == queue->head)
	{
		printf("队列已满,入队失败！\n");
		return;
	}
	if (queue->head == queue->tail)
	{
		queue->head = 0;
		queue->tail = 0;
	}
	queue->data[queue->tail] = data;
	queue->tail = (queue->tail+1)%MAXSIZE;
	printf("入队成功！\n");
}
//出队
void Queue_dequeue(Queue* queue)
{
	if (queue == NULL)
	{
		return;
	}
	if (queue->head == queue->tail)
	{
		printf("队列为空，出队失败！\n");
		return;
	}
	printf("%d已出队！\n",queue->data[queue->head]);
	queue->head = (queue->head + 1) % MAXSIZE;
}
//获取队头元素
int Queue_get_queue_head(const Queue* queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	if (queue->head == queue->tail)
	{
		printf("队列为空，获取失败！\n");
		return -1;
	}
	return queue->data[queue->head];
}
//获取队列中元素个数
int Queue_size(const Queue* queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	return queue->tail - queue->head;
}
//清空所有元素
void Queue_clear(Queue* queue)
{
	if (queue == NULL)
	{
		return;
	}
	if (queue->head == queue->tail)
	{
		printf("队列为空，无需清空！\n");
		return;
	}
	queue->head = -1;
	queue->tail = -1;
	printf("清空成功！\n");
}
//销毁
void Queue_destroy(Queue* queue)
{
	free(queue->data);
	free(queue);
	queue = NULL;
	printf("队列已销毁！\n");
}

