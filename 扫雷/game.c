#include"game.h"
//菜单
void menu()
{
	printf("**************************************************\n");
	printf("************1-play        0-exit******************\n");
	printf("**************************************************\n");
	printf("Please input your option(0-1):");
} 

//布置地雷 
void Inputmine(int minemap[N+1][N+1])
{
    int n = 0;
    printf("请输入你要设置的雷的个数(1~81):");
    scanf("%d",&n);
    // 校验输入合法性（避免n超过最大可放置数量）
    if(n < 1 || n > (N-1)*(N-1))
    {
        printf("雷的个数必须在1到81之间！\n");
        return;
    }
    int count = 0;
    while(count < n)
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
void Inputbyplayer(int minemap[N+1][N+1],char playermap[N-1][N-1])
{
	//玩家输入 
	printf("请输入你要检查的位置（x,y）:");
	int x,y;
	scanf("%d %d",&x,&y);
	
	//判断是不是雷
	if(minemap[x][y]==1) 
	{
		printf("game over!\n");
		
	}
}

//游戏程序
void game()
{
	//初始化地图
	int minemap[N+1][N+1] = {0};
	char playermap[N-1][N-1] = {0};
	Inputmine(minemap);
	Init_playermap(playermap);
	
	//打印玩家视角
	Output_playermsp(playermap);
	
	//玩家输入
	Inputbyplayer(); 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
} 
