#include <stdio.h>
#include <stdlib.h>

int main()
{
    //复合语句中声明的变量只能在复合语句中使用
    int a = 0;

    {
        int a = 1;
        printf("In: a = %d\n", a);
    }

    printf("Out: a = %d\n", a);

    return 0;
}
