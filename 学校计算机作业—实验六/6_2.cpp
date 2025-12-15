#include<stdio.h>
#include<math.h>
int Gold(int n);//验证猜想 
int sushu(int x);//判断是否为素数 
int main()
{
	int n = 0;
	printf("请输入大于等于6的偶数：");
	scanf("%d", &n);
	int test = Gold(n);
	if (test == 1)
	{
		printf("验证哥德巴赫猜想成功\n");
	}
	else
	{
		printf("验证哥德巴赫猜想失败\n");
	}
	return 0;
}
int sushu(int x)
{
	int i = 2, k = sqrt(x);
	for (i = 2; i < k + 1; i++)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}
int Gold(int n)
{
	int x = 2, y;
	for (x = 2; x < n / 2; x++)
	{
		y = n - x;
		if (sushu(x) && sushu(y))
		{
			printf("%d=%d+%d\n", n, x, y);
			return 1;
		}
	}
	return 0;
}