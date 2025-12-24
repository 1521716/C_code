#include"text.h"

//函数定义
//初始化顺序表函数
SqList* InitList()
{
	SqList* List = (SqList*)malloc(sizeof(SqList));//动态分配空间
	List->data = (_int*)malloc(sizeof(_int) * MAXSIZE);
	List->len = 0;
	return List;
}

//遍历输出顺序表
void PrintfList(SqList* L)
{
	int i = 0;
	for (i = 0; i < L->len; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

//尾部添加函数
void Addtail(SqList* L, _int n)
{
	if (L->len >= MAXSIZE)
	{
		printf("顺序表已满！\n");
		return;
	}
	L->data[L->len] = n;
	L->len++;
}

//插入函数
void InsertList(SqList* L, int pos, _int n)
{
	if (pos<1 || pos>MAXSIZE || pos > L->len + 1 || L->len >= MAXSIZE)
	{
		return;
	}
	for (int i = L->len-1; i >= pos - 1; i--)
	{
		L->data[i+1] = L->data[i];
	}
	L->data[pos - 1] = n;
	L->len++;
}

//删除
void DeleteList(SqList* L, int pos)
{
	if (pos > L->len||pos<1)
		return;
	_int tem = L->data[pos - 1];
	for (int i = pos; i < L->len; i++)
	{
		L->data[pos - 1] = L->data[pos];
	}
	L->len--;
}

//按值查找
int FindList(SqList* L, _int f,int *pos)
{
	int j = 0;
	for (int i = 0; i < L->len; i++)
	{
		if (L->data[i] == f)
		{
			pos[j] = i + 1;
			j++;
		}
	}
	return j;
}