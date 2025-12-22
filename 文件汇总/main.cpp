C语言文件操作
一、常用文件操作函数
1. 打开和关闭文件
c
// 打开文件
FILE * fopen(const char* filename, const char* mode);

// 关闭文件
int fclose(FILE* stream);
2. 字符读写函数
c
// 读一个字符
int fgetc(FILE * stream);
int getc(FILE* stream);    // 宏版本

// 写一个字符
int fputc(int c, FILE* stream);
int putc(int c, FILE* stream);  // 宏版本
3. 字符串读写函数
c
// 读字符串
char* fgets(char* str, int n, FILE * stream);

// 写字符串
int fputs(const char* str, FILE* stream);
4. 格式化读写函数
c
// 格式化读
int fscanf(FILE * stream, const char* format, ...);

// 格式化写
int fprintf(FILE* stream, const char* format, ...);
5. 数据块读写函数
c
// 读数据块
size_t fread(void* ptr, size_t size, size_t count, FILE * stream);

// 写数据块
size_t fwrite(const void* ptr, size_t size, size_t count, FILE* stream);
6. 文件定位函数
c
// 重定位文件指针
int fseek(FILE * stream, long offset, int whence);

// 获取当前位置
long ftell(FILE* stream);

// 重置到文件开头
void rewind(FILE* stream);
7. 文件状态函数
c
// 检测文件结束
int feof(FILE * stream);

// 检测错误
int ferror(FILE* stream);

// 清除错误标志
void clearerr(FILE* stream);
二、文件打开模式
1. 文本文件模式
模式	含义	文件必须存在	文件存在时处理
"r"	只读	是	打开现有文件
"w"	只写	否	创建新文件 / 清空原内容
"a"	追加	否	创建新文件 / 追加到末尾
"r+"	读写	是	打开现有文件
"w+"	读写	否	创建新文件 / 清空原内容
"a+"	读写	否	创建新文件 / 读写追加
2. 二进制文件模式
模式	含义	文件必须存在	文件存在时处理
"rb"	二进制只读	是	打开现有文件
"wb"	二进制只写	否	创建新文件 / 清空原内容
"ab"	二进制追加	否	创建新文件 / 追加到末尾
"rb+"	二进制读写	是	打开现有文件
"wb+"	二进制读写	否	创建新文件 / 清空原内容
"ab+"	二进制读写	否	创建新文件 / 读写追加
三、使用示例
1. 基本文件读写
c
#include <stdio.h>

int main() {
    FILE* fp;

    // 写文件
    fp = fopen("test.txt", "w");
    if (fp == NULL) {
        perror("打开文件失败");
        return 1;
    }
    fprintf(fp, "Hello, World!\n");
    fclose(fp);

    // 读文件
    char buffer[100];
    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        perror("打开文件失败");
        return 1;
    }
    fgets(buffer, sizeof(buffer), fp);
    printf("读取内容: %s", buffer);
    fclose(fp);

    return 0;
}
2. 二进制文件操作
c
#include <stdio.h>

struct Student {
    int id;
    char name[20];
    float score;
};

int main() {
    FILE* fp;
    struct Student stu = { 1, "张三", 90.5 };

    // 写结构体到二进制文件
    fp = fopen("data.bin", "wb");
    fwrite(&stu, sizeof(struct Student), 1, fp);
    fclose(fp);

    // 从二进制文件读结构体
    struct Student stu2;
    fp = fopen("data.bin", "rb");
    fread(&stu2, sizeof(struct Student), 1, fp);
    printf("ID: %d, 姓名: %s, 分数: %.1f\n",
        stu2.id, stu2.name, stu2.score);
    fclose(fp);

    return 0;
}
3. 文件定位示例
c
#include <stdio.h>

int main() {
    FILE* fp = fopen("example.txt", "w+");

    // 写入数据
    fprintf(fp, "0123456789");

    // 移动到第5个字节
    fseek(fp, 5, SEEK_SET);

    // 从当前位置读取
    char ch = fgetc(fp);
    printf("位置5的字符: %c\n", ch);  // 输出: 5

    // 获取当前位置
    long pos = ftell(fp);
    printf("当前位置: %ld\n", pos);  // 输出: 6

    // 回到文件开头
    rewind(fp);
    ch = fgetc(fp);
    printf("重新读取第一个字符: %c\n", ch);  // 输出: 0

    fclose(fp);
    return 0;
}
四、注意事项
错误检查：始终检查fopen()返回值是否为NULL

及时关闭：使用后务必用fclose()关闭文件

缓冲区刷新：输出操作后可使用fflush()强制刷新缓冲区

文件指针：读写操作会移动文件指针位置

二进制模式：Windows系统中处理二进制文件时使用"b"模式

性能考虑：大量小数据读写考虑使用缓冲区

五、完整示例：文件复制
c
#include <stdio.h>

int copy_file(const char* src, const char* dst) {
    FILE* src_fp, * dst_fp;
    char buffer[4096];
    size_t bytes;

    src_fp = fopen(src, "rb");
    if (!src_fp) {
        perror("打开源文件失败");
        return -1;
    }

    dst_fp = fopen(dst, "wb");
    if (!dst_fp) {
        perror("打开目标文件失败");
        fclose(src_fp);
        return -1;
    }

    while ((bytes = fread(buffer, 1, sizeof(buffer), src_fp)) > 0) {
        fwrite(buffer, 1, bytes, dst_fp);
    }

    fclose(src_fp);
    fclose(dst_fp);
    return 0;
}

int main() {
    if (copy_file("source.txt", "dest.txt") == 0) {
        printf("文件复制成功\n");
    }
    return 0;
}
这些函数和模式组合可以满足大多数文件操作需求，选择合适的方法取决于具体应用场景。

