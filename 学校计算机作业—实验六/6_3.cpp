#include<stdio.h>
int Gcd1(int n, int m);//最大公约数（非递归）
/*int Gcd2(int n,int m);//最大公约数（递归） */
int Glm(int n, int m);//最小公倍数 
int main()
{
	int n = 0, m = 0;
	printf("enter n、m:");
	scanf("%d%d", &n, &m);
	int x = Gcd1(n, m);
	int y = Glm(n, m);
	printf("Gcd = %d\tGlm = %d\n", x, y);
	return 0;
}
int Gcd1(int n, int m)
{
	int max = m > n ? m : n;
	int min = m < n ? m : n;
	while (min != 0)
	{
		int tem = max % min;
		max = min;
		min = tem;
	}
	return max;
}
int Glm(int n, int m)
{
	int glm = n * m / Gcd1(n, m);
	return glm;
}

/*int Gcd2(int n,int m)
{
	int max = m>n?m:n;
	int min = m<n?m:n;
	int tem = max%min;
	if(tem == 0)
		return min;
	else
	{
		Gcd(min,tem);
	}
} */