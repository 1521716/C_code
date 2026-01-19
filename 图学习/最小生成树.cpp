/*

************************************************最小生成树*********************************************************




最小生成树：普里姆算法、克鲁斯卡尔算法
		最小生成树的顶点数n和边数e的关系：n = e+1
		克鲁斯卡尔算法针对边，边数少时效率高，对稀疏图有优势
		普里姆算法针对点，边多效率高
		克鲁斯卡尔算法的时间复杂度为O（eloge）,e为边数
		普里姆算法的时间复杂度为O(n*n),n为顶点数
 
*/

//*****************************************************最小生成树-普里姆**********************************************************

//***************先找顶点，在根据小边找新顶点



/*
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define MAX 0x7fffffff;
typedef struct {
	char vertex[MAXSIZE];
	int arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Grph;


//函数声明
//创建图
void create_graph(Mat_Grph* G);
//普里姆
void prim(Mat_Grph* G);
int main()
{
	Mat_Grph G;
	create_graph(&G);
	prim(&G);
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
			if (i == j)
			{
				G->arc[i][j] = 0;
			}
			else
			{
				G->arc[i][j] = MAX;
			}

		}
	}

	//开始连线
	//A-B  A-F
	G->arc[0][1] = 10;
	G->arc[0][5] = 11;
	//B-C  B-G  B-I 
	G->arc[1][2] = 18;
	G->arc[1][6] = 16;
	G->arc[1][8] = 12;
	//C-D  C-I
	G->arc[2][3] = 22;
	G->arc[2][8] = 8;
	//D-E  D-G  D-H  D-I
	G->arc[3][4] = 20;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][8] = 21;
	//E-F  E-H
	G->arc[4][5] = 26;
	G->arc[4][7] = 7;
	//F-G
	G->arc[5][6] = 17;
	//G-H
	G->arc[6][7] = 19;

	//因为是无向图，所以邻接矩阵关于对角线对称
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = i; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}
//普里姆
void prim(Mat_Grph* G)
{
	int weight[MAXSIZE];//侯选边
	int vex_index[MAXSIZE];//值表示出发点，下标表示被指向的点
	int i, j, k,min;

	//先从顶点开始，初始化weight和vex_index
	weight[0] = 0;
	vex_index[0] = 0;

	for (i = 1; i < G->vertex_num; i++)
	{
		weight[i] = G->arc[0][i];
		vex_index[i] = 0;
	}
	//开始循环，不断连接
	for (i = 1; i < G->vertex_num; i++)
	{
		min = MAX;
		j = 0; k = 0;
		//找到最小边，连接
		while (j < G->vertex_num)
		{
			if (weight[j] != 0 && weight[j] < min)
			{
				min = weight[j];
				k = j;
			}
			j++;
		}
		printf("%c->%c\n", G->vertex[vex_index[k]], G->vertex[k]);
		//将weight[k]赋值为0，避免重复连接
		weight[k] = 0;


		//将新节点的待选路径加入weight
		for (j = 0; j < G->vertex_num; j++)
		{
			//与新节点的可连接的路径比较，较小的放入weight
			if (weight[j] != 0 && G->arc[k][j] < weight[j])
			{
				weight[j] = G->arc[k][j];
				//更新vex_index的值
				vex_index[j] = k;
			}
		}
	}
}
*/

//*****************************************************最小生成树-克鲁斯卡尔算法**********************************************************

//***************先找边，再连顶点




#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x7fffffff;


typedef struct {
	char vertex[MAXSIZE];
	int arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Grph;

typedef struct {
	int begin;
	int end;
	int weight;
}Edge;


//函数声明
//创建图
void create_graph(Mat_Grph* G);
//克鲁斯卡尔
void Kruskal(Mat_Grph* G);
//按照权重将边从小到大排序
void sortEdges(Edge* edges  ,  int n );
int main()
{
	Mat_Grph G;
	create_graph(&G);
	Kruskal(&G);
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

	//将邻接矩阵初始
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;
			}
			else
			{
				G->arc[i][j] = MAX;
			}

		}
	}

	//开始连线
	//A-B  A-F
	G->arc[0][1] = 10;
	G->arc[0][5] = 11;
	//B-C  B-G  B-I 
	G->arc[1][2] = 18;
	G->arc[1][6] = 16;
	G->arc[1][8] = 12;
	//C-D  C-I
	G->arc[2][3] = 22;
	G->arc[2][8] = 8;
	//D-E  D-G  D-H  D-I
	G->arc[3][4] = 20;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][8] = 21;
	//E-F  E-H
	G->arc[4][5] = 26;
	G->arc[4][7] = 7;
	//F-G
	G->arc[5][6] = 17;
	//G-H
	G->arc[6][7] = 19;

	//因为是无向图，所以邻接矩阵关于对角线对称
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = i; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}
//按照权重将边从小到大排序
void sortEdges(Edge* edges, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((edges + j)->weight > (edges + j + 1)->weight)
			{
				Edge tem = *(edges + j);
				*(edges + j) = *(edges + j + 1);
				*(edges + j + 1) = tem;
			}
		}
	}
}
int find(int* parent, int num)
{
	while (parent[num] > 0)
	{
		num = parent[num];
	}
	return num;
}
//克鲁斯卡尔
void Kruskal(Mat_Grph* G)
{
	//创建必要辅助变量
	int k = 0;
	Edge edges[MAXEDGE];

	//初始化数组
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = i + 1; j < G->vertex_num; j++)
		{
			if (G->arc[i][j] <1000000 )
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = G->arc[i][j];
				k++;
			}
			
		}
	}

	//按照权重将边从小到大排序
	sortEdges(edges, k);

	//创建辅助数组
	int parent[MAXSIZE];

	//初始化parent
	for (int i = 0; i < G->vertex_num; i++)
	{
		parent[i] = 0;
	}

	int n,m;
	for (int i = 0; i < G->edge_num; i++)
	{
		n = find(parent, edges[i].begin);
		m = find(parent, edges[i].end);

		if (n != m)
		{
			parent[n] = m;
			printf("(%c,%c)	%d\n", G->vertex[edges[i].begin], G->vertex[edges[i].end],edges[i].weight);
		}
	}
}