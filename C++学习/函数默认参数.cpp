#include<iostream>
using namespace std;
//与c相比，c++函数形参可以有默认参数

//语法：返回值类型  函数名  （形参（ = 默认值））{}

int func1(int a, int b, int c)
{
	return a + b + c;
}
int func2(int a, int b = 20, int c = 30)
{
	return a + b + c;
}


int main()
{
	cout << func1(10, 20, 30) << endl;
	cout << func2(10) << endl;
	//如果我们自己传入数据，就用我们传入的数据，否则用默认值
	cout << func2(10, 30) << endl;
	return 0;
}
/*
注意事项：
		1、如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值
		2、函数的声明和函数的实现如果有默认值，那么仅能在一处有默认参数（声明有，实现不能有；实现有，声明不能有）

*/

