#include"text.h"

int main()
{
	Contact cons[1000];
	//用户选择
	int select = 1;
	while (select)
	{
		//菜单
		menu();
		
		cin >> select;
		while (select < 0 || select>6)
		{
			cout << "输入操作数非法，请重新输入！" << endl;
			cin >> select;
		}
		switch (select)
		{
		case Add:
		{
			Add_contact(cons);
			clear();
		}
		break;
		case Show:
		{
			Show_contacts(cons);
			clear();
		}
		break;
		case Del:
		{
			Del_contact_name(cons);
			clear();
		}
			break;
		case Sear:
		{
			Sear_contact_name(cons);
			clear();
		}
			break;
		case Chan:
		{
			Chan_contact_name(cons);
			clear();
		}
			break;
		case Clear:
		{
			Clear_contacts(cons);
			clear();
		}
			break;
		case Exit:
		{
			cout << "通讯录已退出！" << endl;
		}
		break;
		}
	}
	
	return 0;
}
