#include"game.h"
//菜单
void menu()
{
	printf("**************************************************\n");
	printf("************1-play        0-exit******************\n");
	printf("**************************************************\n");
	printf("Please input your option(0-1):");
} 

//清屏
void clear()
{
	system("pause");
	system("cls");
}

//布置地雷 
void Inputmine(int minemap[N+1][N+1],int *mine)
{
    printf("请输入你要设置的雷的个数(1~81):");
    scanf("%d",mine);
    // 校验输入合法性（避免n超过最大可放置数量）
    if(*mine < 1 || *mine > (N-1)*(N-1))
    {
        printf("雷的个数必须在1到81之间！\n");
        return;
    }
    int count = 0;
    while(count < *mine)
    {
        // 随机生成1~9的行和列（有效位置）
        int x = rand() % (N-1) + 1; 
        int y = rand() % (N-1) + 1;
        // 若该位置无雷，则放置
        if(minemap[x][y] != 1)
        {
            minemap[x][y] = 1;
            count++;
        }
    }
}
//初始化玩家视角 
void Init_playermap(char playermap[N-1][N-1])
{
	for(int i = 0;i<N-1;i++)
	{
		for(int j = 0;j<N-1;j++)
		{
			playermap[i][j] = '*';
		}
	}
}

//打印玩家视角
void Output_playermsp(char playermap[N-1][N-1])
{
	for(int i = 0;i<N-1;i++)
	{
		for(int j = 0;j<N-1;j++)
		{
			printf("%c ",playermap[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//打印地雷位置 
void Output_minemap(int minemap[N+1][N+1])
{
	for(int i =1;i<N;i++)
	{
		for(int j = 1;j<N;j++)
		{
			printf("%d ",minemap[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//玩家输入
int Inputbyplayer(int minemap[N+1][N+1],char playermap[N-1][N-1])
{
	//玩家输入 
	printf("请输入你要检查的位置（x,y）:");
	int x,y;
	scanf("%d %d",&x,&y);
	
	//判断是不是雷
	if(minemap[x][y]==1) 
	{
		Output_minemap(minemap);
		printf("game over!\n");
		clear();
		return 0;
	}
	else
	{
		int n = 0;
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (minemap[i][j] == 1)
				{
					n++;
				}
			}
		}
		playermap[x][y] = (char )(n+'0');
		Output_playermsp(playermap);
		clear();
		return 1;
	}
}

//判断雷是否排尽
int Iswin(char playermap[N - 1][N - 1], int* mine)
{
	int n = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (playermap[i][j] == '*')
			{
				n++;
			}
		}
	}
	if (n == *mine)
	{
		printf("game over!you gain win!!!\n");
		clear();
		return 0;
	}
	else
		return 1;
}

//游戏程序
void game()
{
	//初始化地图
	int mine = 0;
	int minemap[N+1][N+1] = {0};
	char playermap[N-1][N-1] = {0};
	Inputmine(minemap,&mine);
	Init_playermap(playermap);
	
	//打印玩家视角
	Output_playermsp(playermap);
	
	int result1 = 1,result2 = 1;
	do
	{
		//玩家输入
		result1 = Inputbyplayer(minemap, playermap);
		//判断非雷位置是否排尽
		result2 = Iswin(playermap,&mine);
	} while (result1 == 1 && result2 == 1);
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
} 
