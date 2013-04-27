#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
指针不仅可以用于指向一个数组，还可作为数组的元素，形成指针数组。
指针数组是有若干基类型相同的指针所构成的数组。指针数组的每个元素都是一个指针，且指向相同数据类型的变量。
指针数组比二维数组更常用、更有效，尤其是涉及多个字符串处理的操作中。
用二维数组存储多个字符串时，需按最长的字符串的长度来定义这个二维数组的列数，然后每行存储一个字符串，存完第一行再存第二行。
用指针数组存储每个字符串的首地址时，各个字符串在内存中不占用连续的存储单元，它们的长度可以不同，字符串的实际长度与所占的存储空间相同。
用二维数组存储多个字符串时，由于需要移动字符串的存储位置，故字符串排序的速度很慢，这是物理排序。
用指针数组存储每个字符串的首地址时，字符串不需要改变字符串在内存中的存放位置，只要改变指针数组中各元素的指向即可，故字符串排序的速度较快，这是索引排序。
*/

#define MAX_LEN 9//字符串最大长度
#define N 5//字符串个数

int main()
{
    int i, j;
    char temp[MAX_LEN];
    char str[N][MAX_LEN] = {"Pascal", "Basic", "Fortran", "Java", "Visual C"};//定义二维数组
    char *tmp = NULL;
    char *ptr[N] = {"Pascal", "Basic", "Fortran", "Java", "Visual C"};//定义指针数组

    /*用二维数组编写程序*/
    printf("Before sorted:\n");

    for (i = 0; i < N; i++) {
        puts(str[i]);//输出排序前的N个字符
    }

    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            //若str[j]小于str[i]，则交换str[j]与str[i]
            if (strcmp(str[j], str[i]) < 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("\nAfter sorted:\n");

    for (i = 0; i < N; i++) {
        puts(str[i]);//输出排序后的字符串
    }

    /*用指针数组编写程序*/
    printf("\n\n\nBefore sorted:\n");

    for (i = 0; i < N; i++) {
        puts(ptr[i]);//输出排序前的N个字符串
    }

    for (i = 0; i < N - 1; i++) {
        for (j = i; j < N; j++) {
            if (strcmp(ptr[j], ptr[i]) < 0) {
                tmp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = tmp;
            }
        }
    }

    printf("\nAfter sorted:\n");

    for (i = 0; i < N; i++) {
        puts(ptr[i]);//输出排序后的N个字符串
    }

    return 0;
}
