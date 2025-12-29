#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//链表结构体
struct LinkNode {
	int ID;
	char name[20];
	double score;
	struct LinkNode* next;
};

void clear();

//链表初始化
struct LinkNode* Init_LinkList();

//打印菜单
void menu();

//1-录入
void Input_Studentdata(struct LinkNode* Student, struct LinkNode* pHead, struct LinkNode** pPear);

//2-删除（清空）
void Remove_Studentdata(struct LinkNode* Student);

//3-修改
void Change_Studentdata(struct LinkNode* Student, struct LinkNode* pHead);

//4-显示
void Output_Studentdata(struct LinkNode* Student);

//5-查找
void Search_Studentdata(struct LinkNode* Student, struct LinkNode* pHead);

//6-排序
void Sort_Studentdata(struct LinkNode* Student, struct LinkNode* pHead);