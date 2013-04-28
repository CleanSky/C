#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 80

char *MyStrcat(char *dstStr, char *srcStr);

int main()
{
    char first[ARR_SIZE] = "hello ";
    char second[ARR_SIZE] = "world";
    char *result = NULL;

    result = MyStrcat(first, second);
    printf("The result is : %s\n", result);

    return 0;
}

/*
函数功能：完成两个字符串的连接
函数参数：字符型指针变量的dstString，为连接后的字符指针
            字符型指针变量srcString，为指向待添加到dstString字符串后面的字符串指针
函数返回值：返回指向连接后的字符串的指针
*/
char *MyStrcat(char *dstStr, char *srcStr) {
    char *pStr = dstStr;//保存字符串首地址指针

    //将指针移动字符串末尾
    while(*dstStr != '\0') {
        dstStr++;
    }

    //将字符串2内容复制到字符串1的后面
    for (; *srcStr != '\0'; dstStr++, srcStr++) {
        *dstStr = *srcStr;
    }

    *dstStr = '\0';

    return pStr;//返回连接后的字符串的首地址指针
}
