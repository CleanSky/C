#include <stdio.h>
#include <stdlib.h>

//交换两个整形数，以指针作为形参
void swap(int *a, int *b);

int main()
{
    int m = 14, n = 16;
    int *x = &m, *y;
    y = &n;

    printf("Before swap, m is %d, n is %d\n", m, n);
    swap(&m, &n);
    printf("After the first swap, m is %d, n is %d\n", m, n);
    swap(x, y);
    printf("After the second swap, m is %d, n is %d\n", m, n);

    return 0;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
