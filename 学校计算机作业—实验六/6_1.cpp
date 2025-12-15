#include<stdio.h>
int Fact(int n);//求阶乘 
int Sum_Fact(int n);//求阶乘和 
int main()
{
	int n = 0;
	printf("enter n:");
	scanf("%d", &n);
	int sum = Sum_Fact(n);
	printf("1到%d的阶乘和为：%d\n", n, sum);
	return 0;
}
int Fact(int n)
{
	int i = n;
	int sum = 1;
	for (i = n; i > 0; i--)
	{
		sum *= i;
	}
	return sum;
}
int Sum_Fact(int n)
{
	int i = 0;
	int sum = 0;
	for (i = 1; i <= n; i++)
	{
		sum += Fact(i);
	}
	return sum;
}
