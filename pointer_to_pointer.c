#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
指向指针的指针指的是指针变量中保存的是另一个指针变量的地址。
指向指针的指针实际上是一种多级指针，实质就是多级间接寻址。
指向指针的指针常常和指针数组结合使用，用于对多个字符串处理的场合。
间接寻址的级数不受限制，但实际中极少使用二级以上的指针，因为过深的间接寻址不但难以理解，而且极易出错。
C程序的main()函数是通过形参获得程序的原始参数的。
main(int argc, char *argv[])中，argc是整形数，用于存放命令行中参数的个数，程序名也算在内，故argc的值最小为1；
argv是字符指针数组，数组中的每个元素都是一个字符串指针，指向命令行中的一个命令行参数，所有命令行参数都是字符串。
*/

#define ARR_SIZE 5 //数组元素的个数

int main(int argc, char *argv[])
{
    int a = 5;
    int *b = &a;
    int **c = &b;
    int i;
    char *ptr[ARR_SIZE] = {"Pascal", "Basic", "Fortran", "Java", "Visual C"};
    char **p;

    printf("a = %d, **c = %d\n", a, **c);
    **c = 10;
    printf("a = %d, **c = %d\n", a, **c);

    p = ptr;//让p指向指针数组ptr的首地址，即ptr[0]
    for (i = 0; i < ARR_SIZE; i++) {
        printf("%s\n", *p);//输出指针*p指向的字符串
        p++;//让p指向指针数组ptr的下一个元素
    }

    printf("The number of command line arguments is: %d\n", argc);
    printf("The program name is: %s\n", argv[0]);

    if (argc > 1) {
        printf("The other arguments are following: \n");
        for (i = 1; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
    }

    return 0;
}
