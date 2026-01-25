//用new和delete管理某个班的学生成绩：输入输出

/*
框架：
	输入学生个数n
	定义一个储存n个学生成绩的数组
	输入n个学生成绩
	输出n个学生的成绩

*/
#include<iostream>
using namespace std;

int main()
{
	//输入学生个数n
	int n;
	cout << "Input n:";
	cin >> n;
	//定义一个储存n个学生成绩的数组
	double* score = new double[n];
	//输入n个学生成绩
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "个学生的成绩：";
		cin >> score[i];
	}
	//输出n个学生的成绩
	for (int j = 0; j < n; j++)
	{
		cout << score[j] << " ";
	}
	//撤销空间
	delete[] score;
	return 0;
}