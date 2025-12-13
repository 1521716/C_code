#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//定义节点数据类型
struct LinkNode {
	int data;
	struct LinkNode* next;
};

//初始化链表
struct LinkNode* Init_LinkList();
//遍历链表
void Foreach_LinkList(struct LinkNode* header);
//插入新节点
void InsertByValue_LinkList(struct LinkNode* header, int oldval, int newval);
//清空链表
void Clear_LinkList(struct LinkNode* header);
//删除节点
void RemoveByValue_LinkList(struct LinkNode* header, int delval);
//销毁链表
void Destroy_LinkList(struct LinkNode* header);
















