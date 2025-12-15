#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void PrintNSpace(int i,int n);
void PrintNStar(int n);
int main()
{
	int n = 0;
	printf("enter n:");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		PrintNSpace(i,n);
		PrintNStar(i);
	}
	return 0;
}
void PrintNStar(int n)
{
	int i = 0;
	for (i = 0; i < 2*n-1; i++)
	{
		printf("*");
	}
	printf("\n");
}
void PrintNSpace(int i,int n)
{
	int j = 0;
	for (j = 0; j < n-i; j++)
	{
		printf(" ");
	}
}