#include <stdio.h>
#include <stdlib.h>

int main()
{
    //九九乘法表
    const int N = 10;
    int i, j;
    char ch;

    printf("    ");

    for(i = 1; i < N; i++){
        printf("%4d", i);
    }

    printf("\n");

    ch = '-';
    for(i = 0; i < N; i++){
        printf("%4c", ch);
    }

    printf("\n");

    for(i = 1; i < N; i++){
        printf("%3d|", i);
        for(j = 1; j < N; j++){
            printf("%4d", i * j);
        }
        printf("\n");
    }

    return 0;
}
