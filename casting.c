#include <stdio.h>
#include <stdlib.h>

int main()
{
    //强制转换运算符
    int m = 5;

    printf("m / 2 = %d\n", m / 2);
    printf("(float)(m / 2) = %f\n", (float)(m / 2));
    printf("(float) m / 2 = %f\n", (float) m / 2);
    printf("m = %d\n", m);

    return 0;
}
