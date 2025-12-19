#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	//文件的打开fopen(打开路径，操作方式);打开成功返回FILE类型指针，打开失败返回NULL
	FILE *pf = fopen("D:\\Cyuyan\\文件练习\\text.txt", "r");
	//检查是否成功打开
	if (pf == NULL)
	{
		return 1;
	}

	//int fputc(int char，文件指针);向文件输入一个字符,成功返回字符的ASCLL值，失败返回EOF。如果文件有内容则清空后写入字符
	//fputc('a', pf);

	//int fgetc(文件指针）；从文件读一个字符，成功返回读入的字符的ASCLL值，失败返回EOF
	/*int ch = 0;
	ch = fgetc(pf);
	printf("%c\n", ch);*/

	//int fputs(要写入的字符串，文件指针)；向文件写入一个字符串，成功返回返回非负整数，失败返回EOF。有文件则清空后写入
	//fputs("liruishidashuaige\n", pf);
	
	//char *fgets(储存读出的字符串的指针，要读的字符个数，文件指针)；从文件读字符串，成功返回char *,失败返回NULL
	/*char str[100];
	fgets(str, sizeof(str), pf);
	printf("%s", str);*/
	
	//size_t fwrite(要写入的数据指针，每个数据的大小，数据的数量，文件指针)；以二进制形式写入数据。返回成功写入的数量
	/*fwrite("liruishidashuaige", sizeof("liruishidashuaige"), 1, pf);*/

	//size_t fread(储存读入数据的指针，每个数据的大小，数据的数量，文件指针)；以二进制形式读出数据。成功返回成功读取的数量，失败返回0.
	/*char str[20] = { 0 };
	fread(str, sizeof(char), 10, pf);
	printf("%s", str);*/

	//int fseek(文件指针，偏移量，起始位置（SEEK_SET文件开头，SEEK_CUR当前位置，SEEK_END文件结尾）)；调整指针位置，选择性读写文件数据成功返回0，否则返回非0值
	/*fseek(pf, 3, SEEK_SET);
	int ch = fgetc(pf);
	printf("%c\n", ch);*/

	//long ftell(文件指针）；查找当前文件位置。成功返回当前文件位置（距离文件开头字节量），失败返回-1L。
	/*int tem = 0;
	fseek(pf, 3, SEEK_SET);
	tem = ftell(pf);
	printf("%d", tem);*/

	//void rewind(文件指针)；使文件位置重置回文件头。无返回值。
	/*int tem = 0;
	fseek(pf, 3, SEEK_SET);
	tem = ftell(pf);
	printf("%d\n", tem);
	rewind(pf);
	tem = ftell(pf);
	printf("%d\n", tem);*/
	//关闭文件
	fclose(pf);
	//防止形成野指针，赋值NULL
	pf = NULL;
	return 0;
}