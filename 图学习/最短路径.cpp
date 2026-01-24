/*

*********************************最短路径*********************************

*/



//最短路径----迪杰斯特拉

#include<stdio.h>
#include<stdlib.h>
#define MAX 0x10000
#define MAXSIZE 100
#define MAXEDGE 200

typedef struct {
	int vertex[MAXSIZE];
	int arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;

//函数声明
//创建图
void createGraph(Mat_Graph* G);
//选择下一个顶点
int choose(int* distance, int* found, int size);
//迪杰斯特拉算法
void dijkstra(Mat_Graph* G, int begin);


int main()
{
	Mat_Graph G;
	createGraph(&G);
	//迪杰斯特拉算法
	dijkstra(&G,0);
	return 0;
}

//函数定义
//创建图
void createGraph(Mat_Graph* G)
{
	G->vertex_num = 9;
	G->edge_num = 16;

	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;
	}

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;
			}
			else
				G->arc[i][j] = MAX;
		}
	}

	G->arc[0][1] = 1;
	G->arc[0][2] = 5;

	G->arc[1][2] = 3;
	G->arc[1][3] = 7;
	G->arc[1][4] = 5;

	G->arc[2][4] = 1;
	G->arc[2][5] = 7;

	G->arc[3][4] = 2;
	G->arc[3][6] = 3;

	G->arc[4][5] = 3;
	G->arc[4][6] = 6;
	G->arc[4][7] = 9;

	G->arc[5][7] = 5;

	G->arc[6][7] = 2;
	G->arc[6][8] = 7;

	G->arc[7][8] = 4;

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = i; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}
//选择下一个顶点
int choose(int* distance, int* found, int size)
{
	int min = MAX;
	int minPos = -1;
	for (int i = 0; i < size; i++)
	{
		if (found[i] == 0 && distance[i] < min)
		{
			min = distance[i];
			minPos = i;
		}
	}
	return minPos;
}
//迪杰斯特拉算法
void dijkstra(Mat_Graph* G, int begin)
{
	//创建辅助数组，变量
	int found[MAXSIZE];//判断顶点是否遍历过
	int distance[MAXSIZE];//记录0到该顶点的最小权值
	int path[MAXSIZE];//路径

	//初始化数组
	for (int i = 0; i < G->vertex_num; i++)
	{
		found[i] = 0;
		path[i] = -1;
		distance[i] = G->arc[begin][i];
	}

	found[begin] = 1;
	distance[begin] = 0;
	//记录下一个顶点
	int next;
	//开始循环
	for (int i = 1; i < G->vertex_num; i++)
	{
		next = choose(distance, found, G->vertex_num);
		found[next] = 1;

		//更新distance,path数组
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (found[j] == 0)
			{
				if (distance[next] + G->arc[next][j] < distance[j])
				{
					distance[j] = distance[next] + G->arc[next][j];
					path[j] = next;
				}
			}
		}
	}

	//打印路径
	for (int i = 1; i < G->vertex_num; i++)
	{
		printf("V0 -> V%d : %d\n", i,distance[i]);
		int j = i;
		printf("V%d <- ", i);
		while (path[j] != -1)
		{
			printf("V%d <- ", path[j]);
			j = path[j];
		}
		printf("V0\n");
	}
}

















