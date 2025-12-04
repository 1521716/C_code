#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int TST(int n,int arr[32]);
int main()
{
	int arr[32] = { 0 };
	int n;
	printf("enter n:");
	scanf("%d", &n);
	printf("n的二进制为：");
	int len = TST(n,arr);
	for (int k = len - 1; k >= 0; k--)
	{
		printf("%d", arr[k]);
	}
	return 0;
}
int TST(int n, int arr[32])
{
	int i = 0, x = 0;

	while (n > 0)
	{
		i = n % 2;
		n = n / 2;
		arr[x] = i;
		x++;
	}
	return x;
}