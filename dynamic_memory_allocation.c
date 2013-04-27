#include <stdio.h>
#include <stdlib.h>

/*
malloc()用于分配若干字节的内存空间，返回一个纸箱该存储区地址的指针；若系统不能提供足够的内存单元，函数将返回空指针(NULL)。
calloc()用于给若干同一类型的数据项分配连续的存储空间，其中每个数据项的长度单位为字节，初值均为0。
free()用于释放动态申请的由指针指向的存储空间，该函数无返回值。
realloc()用于改变原来分配的存储空间的大小。
*/

/*
使用const修饰指针变量
const int *p = &a;*p是一个常量，即只读的，而p不是。*p不可以在程序中被修改，但是p可以。
int const *p = &a;*p是一个常量，即只读的，而p不是。*p不可以在程序中被修改，但是p可以。
int* const p = &a;p是一个常量，即只读的，而*p不是。p不可以在程序中被修改，但是*p可以。
const int* const p = &a;p和*p都是一个常量，即只读的。
*/

int main()
{
    int *p = NULL, n, i, sum;
    int *pScore = NULL, x, y;

    printf("Please enter array size: ");
    scanf("%d", &n);

    /*向系统申请n个sizeof(int)字节的连续存储空间*/
    p = (int *) malloc(n * sizeof(int));
    if (p == NULL) {//确保指针使用前是非空指针，当p为空指针时结束程序运行
        printf("No Enough Memory!\n");
        exit(0);
    }

    printf("Please enter the score: ");
    for (i = 0; i < n; i++) {
        scanf("%d", p + i);//输入每个学生的分数
    }

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += *(p + i);//计算总分数
    }

    printf("aver = %d\n", sum / n);//打印平均分
    free(p);//释放向系统申请的存储空间

    printf("Please enter array size x,y: ");
    scanf("%d,%d", &m, &n);

    /*申请x*y个sizeof(int)字节的存储空间*/
    pScore = (int *) calloc(x*y, sizeof(int));
    if (pScore == NULL) {
        printf("No Enough Memory!\n");
        exit(0);
    }

    free(pScore);

    return 0;
}
