#include <stdio.h>
#include <stdlib.h>

#define max1(A, B) ((A) > (B) ? (A) : (B))
#define max2(A, B) A > B ? A : B
#define USE_INT 0

int main()
{
    printf("%d\n", max1(max1(2, 1), 3));
    printf("%d\n", max2(max2(2, 1), 3));

    //条件编译：精简版、专业版、豪华版
    #if USE_INT
    int foo = 0;
    int bar = 0;
    #else
    long foo = 1;
    long bar = 1;
    #endif

    printf("foo: %d\n", foo);
    printf("bar: %d\n", bar);

    return 0;
}
