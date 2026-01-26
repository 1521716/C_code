#pragma once
/*
通讯录管理系统：
				添加联系人
				显示联系人
				删除联系人
				查找联系人
				修改联系人
				清空联系人
				退出通讯录

*/
#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

typedef struct {
	string name;
	char sex;
	int age;
	int numble;
	string address;
}Contact;

enum Fun {
	Exit,Add,Show,Del,Sear,Chan,Clear
};

//菜单
void menu();

//清屏
void clear();

//全局变量，储存联系人个数
static int num = 0;

//添加联系人
void Add_contact(Contact* cons);
//显示联系人
void Show_contacts(const Contact* cons);
//删除联系人
void Del_contact_name(Contact* cons);
//查找联系人
void Sear_contact_name(const Contact* cons);
//修改联系人信息
void Chan_contact_name(Contact* cons);
//清空通讯录
void Clear_contacts(Contact* cons);

