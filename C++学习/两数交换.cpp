
//两数交换函数：利用C++的引用，实现两数交换的函数

#include<iostream>
using namespace std;
//函数声明
void my_swap(int& x, int& y);
int main()
{
	int x = 10, y = 20;
	cout << "x = " << x << "  " << "y = " << y << endl;
	my_swap(x, y);
	cout << "x = " << x << "  " << "y = " << y << endl;
	return 0;
}
//函数定义
void my_swap(int& x, int& y)
{
	int tem;
	tem = x;
	x = y;
	y = tem;
}