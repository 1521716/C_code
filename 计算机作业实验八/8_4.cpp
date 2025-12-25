#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Candidate{
	char name[20];
	int num;
}Can;
int main()
{
	//创建链表并输入候选人姓名
	printf("请输入候选人人数N：");
	int N = 0;scanf("%d",&N);getchar();
	Can *can = (Can*)malloc(sizeof(Can)*N);
	for(int i = 0;i<N;i++)
	{
		printf("请输入第%d位候选人名字：",i+1);
		gets(can[i].name);
		can[i].num = 0;
	}
	
	//开始投票并统计
	for(int i = 0;i<10;i++)
	{
		int sign = 0;
		do{
			sign = 0;
			printf("请第%d位选民投票（输入要候选人的名字）:",i+1);
			char option[20] = {0};
			gets(option);
			for(int j = 0;j<N;j++)
			{
				if(strcmp(option,can[j].name)==0)
				{
					can[j].num++;
					break;
				}
				else if(j==N-1)
				{
					printf("姓名输入错误，无该候选人！请重新输入！\n");
					sign = 1;
				} 
			}
		}while(sign);
	 } 
	 //打印结果
	 printf("候选人				票数\n");
	for(int i = 0;i<N-1;i++)
	{
		for(int j = 0;j<N-1-i;j++)
		{
			if(can[j].num<can[j+1].num)
			{
				Can tem = can[j];
				can[j] = can[j+1];
				can[j+1] = tem;
			}
		}
	}
	for(int i = 0;i<N;i++)
	{
		printf("%s				%d\n",can[i].name,can[i].num);
	}
	free(can); 
	return 0;
} 
