#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void Shift(char arr[20]);
int main()
{
	char arr[20];
	printf("enter string:");
	scanf("%s", arr);
	printf("Ô­×Ö·û´®£º%s\n", arr);
	Shift(arr);
	printf("µô×ªºó×Ö·û´®£º%s\n", arr);
	return 0;
}
void Shift(char arr[20])
{
	int left = 0, right = strlen(arr)-1;
	while (left < right)
	{
		char tem = arr[left];
		arr[left] = arr[right];
		arr[right] = tem;
		left++;
		right--;
	}
}