#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"

int main()
{
	//初始化链表
	struct LinkNode* LinkList = Init_LinkList();
	//遍历打印链表
	Foreach_LinkList(LinkList);
	//插入新节点
	InsertByValue_LinkList(LinkList,900,666);
	Foreach_LinkList(LinkList);
	//删除节点
	RemoveByValue_LinkList(LinkList,100);
	Foreach_LinkList(LinkList);
	/*
	//清空链表
	Clear_LinkList(LinkList);
	*/
	//销毁链表
	Destroy_LinkList(LinkList);
	return 0;
}
