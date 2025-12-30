#include"game.h"
int main()
{
	//设置种子节点
	srand(time(NULL)); 
	
	int option = 0;
	do{
		//菜单
		menu(); 
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				game();
				break;
			case 0:
				printf("game over!\n");
				break;
			default:
				printf("the option is wrong！Please input other option again!\n");
				scanf("%d",&option);
		}
	}while(option);
	return 0;
}
