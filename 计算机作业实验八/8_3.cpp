#include<stdio.h>

//定义静态链表
struct Student{
	int ID;
	char name[20];
	double score;
	int next;
}; 
int main()
{
	//建立静态链表
	struct Student stus[3];
	
	//建立头插、尾插
	int pHead = -1;
	int pPear = -1;
	
	//当前位置
	int pCur = 0; 
	//输入数据
	for(int i = 1;i<=3;i++)
	{
		printf("请输入第%d个学生的数据（学号、姓名、分数）：",i);
		scanf("%d%s%lf",&stus[pCur].ID,stus[pCur].name,&stus[pCur].score);
		stus[pCur].next = -1; 
		//设置头插，尾插的位置
		pHead = 0;
		pPear = pCur; 
		if(pCur!=0)
		{
			stus[pPear-1].next = pCur;
		}
		pCur++;
	}
	//输出链表数据、统计总分 
	double sum = 0; 
	printf("学号	姓名	成绩\n");
	int tem = pHead;
	while(tem!=-1)
	{
		sum+=stus[tem].score;
		printf("%d	%s	%.2lf\n",stus[tem].ID,stus[tem].name,stus[tem].score);
		tem = stus[tem].next;
	} 
	printf("学生的平均成绩为%.2lf\n",sum/(pPear+1));
	return 0;
}
