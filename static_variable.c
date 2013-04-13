#include <stdio.h>
#include <stdlib.h>

//静态变量
void Func1(void);
void Func2(void);

int main()
{
    int i;

    for (i = 0; i < 10; i++) {
        Func1();
    }

    printf("\n\n\n");

    for (i = 0; i < 10; i++) {
        Func2();
    }

    return 0;
}

void Func1(void) {
    int times = 1;
    printf("Func1() was called %d time(s).\n", times++);
}

void Func2(void) {
    static int times = 1;
    printf("Func2() was called %d time(s).\n", times++);
}
