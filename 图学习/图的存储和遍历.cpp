/*



******************************图的存储和遍历********************************



存储：邻接矩阵
	  邻接矩阵-无向
	  邻接矩阵-有向
	  邻接矩阵-带权值
	  邻接表-无向
	  邻接表-有向
	  逆邻接表-有向
	  十字链表-横出边纵入边
	  邻接多重表
	  *************************上述内容在此不宜表达****************************



遍历：深度优先遍历
      广度优先遍历 

*/


#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

//图结构
typedef struct {
	char vertex[MAXSIZE];
	int arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Grph;

//判断该顶点是否已被遍历（哈希表？）
int visited[MAXSIZE];

//建立一个简易队列,非循环
int queue[MAXSIZE];
int head = 0;
int tail = 0;

//函数声明
//创建图
void create_graph(Mat_Grph* G);
//广度优先遍历
void dfs(Mat_Grph G, int n);
//深度优先遍历
void bfs(Mat_Grph G);

int main()
{
	//创建图
	Mat_Grph G;
	create_graph(&G);
	//初始化辅助数组，未遍历为0，已遍历为1
	for (int i = 0; i < G.vertex_num; i++)
	{
		visited[i] = 0;
	}
	//广度优先遍历
	dfs(G, 0);
	printf("\n");
	//初始化辅助数组，未遍历为0，已遍历为1
	for (int i = 0; i < G.vertex_num; i++)
	{
		visited[i] = 0;
	}
	//深度优先遍历
	bfs(G);
	printf("\n");
	return 0;
}

//函数声明
//创建图
void create_graph(Mat_Grph* G)
{
	G->vertex_num = 9;
	G->edge_num = 15;
	//顶点下标与顶点的值
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';

	//将邻接矩阵初始为0
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[i][j] = 0;
		}
	}
	
	//开始连线
	//A-B  A-F
	G->arc[0][1] = 1;
	G->arc[0][5] = 1;
	//B-C  B-G  B-I 
	G->arc[1][2] = 1;
	G->arc[1][6] = 1;
	G->arc[1][8] = 1;
	//C-D  C-I
	G->arc[2][3] = 1;
	G->arc[2][8] = 1;
	//D-E  D-G  D-H  D-I
	G->arc[3][4] = 1;
	G->arc[3][6] = 1;
	G->arc[3][7] = 1;
	G->arc[3][8] = 1;
	//E-F  E-H
	G->arc[4][5] = 1;
	G->arc[4][7] = 1;
	//F-G
	G->arc[5][6] = 1;
	//G-H
	G->arc[6][7] = 1;

	//因为是无向图，所以邻接矩阵关于对角线对称
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = i; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}
//广度优先遍历
void dfs(Mat_Grph G, int n)
{
	visited[n] = 1;
	printf("%c ", G.vertex[n]);
	for (int i = 0; i < G.vertex_num; i++)
	{
		if (G.arc[n][i] == 1 && visited[i] == 0)
		{
			dfs(G, i);
		}
	}
}

//深度优先遍历
void bfs(Mat_Grph G)
{
	int i = 0;
	visited[i] = 1;
	printf("%c ", G.vertex[i]);
	queue[tail] = i;
	tail++;
	while (head != tail)
	{
		i = queue[head];
		head++;
		for (int j = 0; j < G.vertex_num; j++)
		{
			if (G.arc[i][j] == 1 && visited[j] == 0)
			{
				visited[j] = 1;
				printf("%c ", G.vertex[j]);
				queue[tail] = j;
				tail++;
			}
		}
	}
}












