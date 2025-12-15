#include <stdio.h>
#include<stdlib.h>
int main()
{	
	int against = 1;
	while (against)
	{
		system("cls");
		//框架，数组完成，循环
		char hen[] = "-------------";
		char shu[3][14] = { {"|   |   |   |"},{"|   |   |   |"},{"|   |   |   |"} };
		int i, j;
		for (i = 0; i < 4; i++)
		{
			printf("%s", hen);
			printf("\n");
			if (i == 3)
				break;
			printf("%s", shu[i]);
			printf("\n");
		}
		// 数组输棋子
		int end = 1, num1 = 0, num2 = 0;
		int a, b;
		int qizi = 1;
		while (end)
		{
			switch (qizi)
			{
			case 1:
			{
				printf("请输入%d子落子坐标（行 列）：", qizi);
				scanf_s("%d %d", &a, &b);
				system("cls");
				a -= 1;
				if (b == 1)
				{
					b = 2;
				}
				else if (b == 2)
				{
					b = 6;
				}
				else
				{
					b = 10;
				}
				shu[a][b] = '1';
				for (i = 0; i < 4; i++)
				{
					printf("%s", hen);
					printf("\n");
					if (i == 3)
						break;
					printf("%s", shu[i]);
					printf("\n");
				}
				//判断是否获胜
				for (i = 0; i < 3; i++)//每行
				{
					for (j = 0; j < 14; j++)
					{
						if ('1' == shu[i][j])
							num1++;
						else if ('0' == shu[i][j])
							num2++;
					}
					if (num1 == 3)
					{
						end = 0;
						printf("1方获胜\n");
					}
					else if (num2 == 3)
					{
						end = 0;
						printf("0方获胜\n");
					}
					num1 = 0; num2 = 0;
				}
				for (j = 2; j < 11; j += 4)//每列
				{
					for (i = 0; i < 3; i++)
					{

						if ('1' == shu[i][j])
							num1++;
						else if ('0' == shu[i][j])
							num2++;
					}
					if (num1 == 3)
					{
						end = 0;
						printf("1方获胜\n");
					}
					else if (num2 == 3)
					{
						end = 0;
						printf("0方获胜\n");
					}
					num1 = 0; num2 = 0;
				}
				for (i = 0, j = 2; i < 3, j < 11; j += 4, i++)//右对角
				{

					if ('1' == shu[i][j])
						num1++;
					else if ('0' == shu[i][j])
						num2++;
				}
				if (num1 == 3)
				{
					end = 0;
					printf("1方获胜\n");
				}
				else if (num2 == 3)
				{
					end = 0;
					printf("0方获胜\n");
				}
				num1 = 0; num2 = 0;
				for (i = 2, j = 10; i >= 0, j >= 1; i--, j -= 4)//左对角
				{
					if ('1' == shu[i][j])
						num1++;
					else if ('0' == shu[i][j])
						num2++;
				}
				if (num1 == 3)
				{
					end = 0;
					printf("1方获胜\n");
				}
				else if (num2 == 3)
				{
					end = 0;
					printf("0方获胜\n");
				}
				num1 = 0; num2 = 0;
				qizi--;
			}break;
			case 0:
			{
				printf("请输入%d子落子坐标（行 列）：", qizi);
				scanf_s("%d %d", &a, &b);
				system("cls");
				a -= 1;
				if (b == 1)
				{
					b = 2;
				}
				else if (b == 2)
				{
					b = 6;
				}
				else
				{
					b = 10;
				}
				shu[a][b] = '0';

				for (i = 0; i < 4; i++)
				{
					printf("%s", hen);
					printf("\n");
					if (i == 3)
						break;
					printf("%s", shu[i]);
					printf("\n");
				}
				for (i = 0; i < 3; i++)//每行
				{
					for (j = 0; j < 14; j++)
					{
						if ('1' == shu[i][j])
							num1++;
						else if ('0' == shu[i][j])
							num2++;
					}
					if (num1 == 3)
					{
						end = 0;
						printf("1方获胜\n");
					}
					else if (num2 == 3)
					{
						end = 0;
						printf("0方获胜\n");
					}
					num1 = 0; num2 = 0;
				}
				for (j = 2; j < 11; j += 4)//每列
				{
					for (i = 0; i < 3; i++)
					{

						if ('1' == shu[i][j])
							num1++;
						else if ('0' == shu[i][j])
							num2++;
					}
					if (num1 == 3)
					{
						end = 0;
						printf("1方获胜\n");
					}
					else if (num2 == 3)
					{
						end = 0;
						printf("0方获胜\n");
					}
					num1 = 0; num2 = 0;
				}
				for (i = 0, j = 2; i < 3, j < 11; j += 4, i++)//右对角
				{

					if ('1' == shu[i][j])
						num1++;
					else if ('0' == shu[i][j])
						num2++;
				}
				if (num1 == 3)
				{
					end = 0;
					printf("1方获胜\n");
				}
				else if (num2 == 3)
				{
					end = 0;
					printf("0方获胜\n");
				}
				num1 = 0; num2 = 0;
				for (i = 2, j = 10; i >= 0, j >= 1; i--, j -= 4)//左对角
				{
					if ('1' == shu[i][j])
						num1++;
					else if ('0' == shu[i][j])
						num2++;
				}
				if (num1 == 3)
				{
					end = 0;
					printf("1方获胜\n");
				}
				else if (num2 == 3)
				{
					end = 0;
					printf("0方获胜\n");
				}
				num1 = 0; num2 = 0;
				qizi++;
			}break;
			}
		}
		printf("是否再来一局（1||0）：");//是否再来一局
		scanf_s("%d", &against);
	}
		printf("游戏结束，祝您玩的开心！！！\n");
	return 0;
}
















