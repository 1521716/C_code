#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10 
//菜单
void menu(); 
//清屏
void clear();
//游戏程序
void game(); 
//布置地雷 
void Inputmine(int minemap[N+1][N+1],int *mine);
//初始化玩家视角 
void Init_playermap(char playermap[N-1][N-1]);
//打印玩家视角
void Output_playermsp(char playermap[N-1][N-1]);
//打印地雷位置 
void Output_minemap(int minemap[N+1][N+1]);
//玩家输入
int Inputbyplayer(int minemap[N+1][N+1],char playermap[N-1][N-1]);
//判断雷是否排尽
int Iswin(char playermap[N - 1][N - 1],int *mine);


