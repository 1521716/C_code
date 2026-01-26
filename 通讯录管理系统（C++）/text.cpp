#include"text.h"

//菜单
void menu()
{
	cout << "**************************************"<<endl;
	cout << "***********  1、添加联系人  **********"<<endl;
	cout << "***********  2、显示联系人  **********" << endl;
	cout << "***********  3、删除联系人  **********" << endl;
	cout << "***********  4、查找联系人  **********" << endl;
	cout << "***********  5、修改联系人  **********" << endl;
	cout << "***********  6、清空联系人  **********" << endl;
	cout << "***********  0、退出通讯录  **********" << endl;
	cout << "**************************************" << endl;
	cout << "请输入你的选择(0-6)>" << endl;
}

//清屏
void clear()
{
	system("pause");
	system("cls");
}

//添加联系人
void Add_contact(Contact* cons)
{
	int select = 0;
	do {
		if (num >= 1000)
		{
			cout << "通讯录已满，无法添加联系人" << endl;
			return;
		}
		cout << "请输入第" << num + 1 << "个联系人的姓名:";
		cin >> (cons + num)->name;
		getchar();
		cout << "请输入第" << num + 1 << "个联系人的性别:";
		cin >> (cons + num)->sex;
		getchar();
		cout << "请输入第" << num + 1 << "个联系人的年龄:";
		cin >> (cons + num)->age;
		getchar();
		cout << "请输入第" << num + 1 << "个联系人的号码:";
		cin >> (cons + num)->numble;
		getchar();
		cout << "请输入第" << num + 1 << "个联系人的住址:";
		cin >> (cons + num)->address;
		getchar();
		num++;
		cout << "请问是否要继续添加(1-添加  0-退出)>" << endl;
		cin >> select;
		getchar();
	} while (select != 0);
}

//显示联系人
void Show_contacts(const Contact* cons)
{
	cout << "姓名	性别	年龄	号码		住址" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << (cons + i)->name <<"	" << (cons + i)->sex <<"	" << (cons + i)->age <<"	" << (cons + i)->numble<<"		" << (cons + i)->address << endl;
	}
}
//删除联系人
void Del_contact_name(Contact* cons)
{
	int select = 0;
	do {
		cout << "请输入要删除的联系人姓名：";
		string tem;
		cin >> tem;
		getchar();
		int result = 0;
		for (int i = 0; i < num; i++)
		{
			if (tem == (cons + i)->name)
			{
				for (int j = i; j < num - 1; j++)
				{
					*(cons + j) = *(cons + j + 1);
				}
				num--;
				result = 1;
			}
		}
		if (result == 0)
			cout << "未找到联系人，删除失败！" << endl;
		else
			cout << "删除成功！" << endl;
		cout << "请问是否要继续删除(1-删除  0-退出)>" << endl;
		cin >> select;
		getchar();
	} while (select!=0);
}

//查找联系人
void Sear_contact_name(const Contact* cons)
{
	int select = 0;
	do {
		cout << "请输入要查找的联系人姓名：";
		string tem;
		cin >> tem;
		getchar();
		int result = 0; int j;
		for (int i = 0; i < num; i++)
		{
			if (tem == (cons + i)->name)
			{
				j = i;
				result = 1;
			}
		}
		if (result == 0)
			cout << "未找到联系人！" << endl;
		else {
			cout << "成功找到联系人！" << endl;
			cout << "姓名	性别	年龄	号码		住址" << endl;
			cout << (cons + j)->name << "	" << (cons + j)->sex << "	" << (cons + j)->age << "	" << (cons + j)->numble << "		" << (cons + j)->address << endl;
		}
		cout << "请问是否要继续查找(1-查找  0-退出)>" << endl;
		cin >> select;
		getchar();
	} while (select != 0);
}

//修改联系人信息
void Chan_contact_name(Contact* cons)
{
	int select = 0;
	do {
		cout << "请输入要修改的联系人姓名：";
		string tem;
		cin >> tem;
		getchar();
		int result = 0;
		for (int i = 0; i < num; i++)
		{
			if (tem == (cons + i)->name)
			{
				cout << "请输入要修改的姓名:";
				cin >> (cons + i)->name;
				getchar();
				cout << "请输入要修改的性别:";
				cin >> (cons + i)->sex;
				getchar();
				cout << "请输入要修改的年龄:";
				cin >> (cons + i)->age;
				getchar();
				cout << "请输入要修改的号码:";
				cin >> (cons + i)->numble;
				getchar();
				cout << "请输入要修改的住址:";
				cin >> (cons + i)->address;
				getchar();
				result = 1;
			}
		}
		if (result == 0)
			cout << "未找到联系人，修改失败！" << endl;
		cout << "请问是否要继续修改(1-修改  0-退出)>" << endl;
		cin >> select;
		getchar();
	} while (select != 0);
}

//清空通讯录
void Clear_contacts(Contact* cons)
{
	cout << "确认要清空通讯录吗？(1-清空  0-取消)>" << endl;
	int select = 0;
	cin >> select;
	getchar();
	if (select == 1)
	{
		cout << "已清空通讯录！\n";
		num = 0;
	}
	else if (select == 0)
	{
		cout << "已取消清空操作！\n";
	}
	else
	{
		cout << "输入错误，默认取消清空操作！\n";
	}

}