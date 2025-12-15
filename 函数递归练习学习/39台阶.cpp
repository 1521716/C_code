#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Way(int n);
int main()
{
	int n = 39;
	int way = Way(n);
	printf("上%d阶台阶共有%d种方法\n", n, way);
	return 0;
}
int Way(int n)
{
	if (n == 1 || n == 2)
		return n;
	else
		return Way(n - 1) + Way(n - 2);
}