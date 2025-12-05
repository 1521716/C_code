#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//汉诺塔问题
int sum = 0;
void Hannuota(int n, char start, char get, char tem);
int main()
{
    int n;
    printf("enter n:");
    scanf("%d", &n);
    char start = 'a', tem = 'b', get = 'c';
    if (n < 1)
    {
        printf("n need bigger than 1!\n");
        return 1;
    }
    Hannuota(n, start, get, tem);

    return 0;
}
void Hannuota(int n, char start, char get, char tem)
{
    if (n == 1)
    {
        sum++;
        printf("第%d次移动：盘子1从%c->%c\n", sum, start, get);
        return;
    }
    Hannuota(n - 1, start, tem, get);
    sum++;
    printf("第%d次移动：盘子%d从%c->%c\n", sum,n, start, get);
    Hannuota(n - 1, tem, get, start);
}
