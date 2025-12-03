#include<stdio.h>
#include<string.h>
void Inputname(char name[5][20]);
void Sort(char name[5][20]);
void Outputname(char name[5][20]);
int main()
{
	char name[5][20];
	Inputname(name);
	Sort(name);
	Outputname(name);
	return 0;
}
void Inputname(char name[5][20])
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%s", name[i], 20);
	}
}
void Sort(char name[5][20])
{
	int i = 0, j = 0;
	for (i = 0; i < 5 - 1; i++)
	{
		for (j = 0; j < 5 - 1 - i; j++)
		{
			if (strcmp(name[j], name[j + 1]) > 0)
			{
				char tem[20];
				strcpy(tem, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], tem);
			}
		}
	}
}
void Outputname(char name[5][20])
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%s\n", name[i]);
	}
}