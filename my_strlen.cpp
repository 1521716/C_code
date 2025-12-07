#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int my_strlen(char* str);
int count = 0;
int main()
{
	printf("ÇëÊäÈë×Ö·û´®£º");
	char str[100] = { 0 };
	gets_s(str);
	int len = my_strlen(str);
	printf("×Ö·û´®³¤¶ÈÎª£º%d\n",len);
	return 0;
}
int my_strlen(char* str)
{
	if (*str == '\0')
		return count;
	else
	{
		count++;
		return my_strlen(str + 1);
	}
}