#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100//顺序表的最大容纳量，宏定义便于后续更改

typedef int _int;//将int 重命名为_int，后续如果更改表中数据类型更加方便

typedef struct {					//定义顺序表结构，并重命名
	_int *data;
	int len;
}SqList;

//函数声明
//初始化顺序表
SqList* InitList();

//遍历输出顺序表
void PrintfList(SqList* L);

//尾部添加函数
void Addtail(SqList* L, _int n);

//插入函数
void InsertList(SqList* L, int pos, _int n);

//删除
void DeleteList(SqList* L, int pos);

//按值查找
int FindList(SqList* L,_int f,int*pos);



