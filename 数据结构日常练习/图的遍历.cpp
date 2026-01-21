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
//深度优先遍历
void dfs(Mat_Grph G, int n);
//广度优先遍历
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
	//深度优先遍历
	dfs(G, 0);
	printf("\n");
	//初始化辅助数组，未遍历为0，已遍历为1
	for (int i = 0; i < G.vertex_num; i++)
	{
		visited[i] = 0;
	}
	//广度优先遍历
	bfs(G);
	printf("\n");
	return 0;
}

//函数定义
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
//深度优先遍历（利用递归）
void dfs(Mat_Grph G, int n)
{
	//第一次n = 0，表示最顶点，此图的A
	//给visited赋值，表示已经访问过该顶点
	visited[n] = 1;
	printf("%c ", G.vertex[n]);
	//遍历邻接矩阵，寻找有连线的顶点
	for (int i = 0; i < G.vertex_num; i++)
	{
		//找连线，并且该店未被访问
		if (G.arc[n][i] == 1 && visited[i] == 0)
		{
			//递归调用
			dfs(G, i);
		}
		
	}
}
//广度优先遍历
void bfs(Mat_Grph G)
{
	//初始化n，开始为顶点（A）
	int n = 0;
	//将顶点入队
	queue[0] = n;
	tail = 1;
	//表示已经访问该顶点
	visited[n] = 1;
	//类似于层序遍历
	while (tail != head)
	{
		printf("%c ", G.vertex[queue[head]]);
		//更改n值，为寻找下一个顶点
		n = queue[head];
		//出队
		head++;
		//循环，寻找有连线且未被访问顶点
		for (int i = 0; i < G.vertex_num; i++)
		{
			if (G.arc[n][i] == 1 && visited[i] == 0)
			{
				queue[tail] = i;
				tail++;
				visited[i] = 1;
			}
		}
		
	}
}