#include <stdio.h>
#include <stdlib.h>

int Max(int ma, int mb, int mc);//声明函数

int main()
{
    int a, b, c, max = 0;
    int (*p)();//定义函数指针时，后一个括号内可以列出函数各种参数类型，也可省略不写

    printf("Please input 3 numbers (a, b, c): ");
    scanf("%d,%d,%d", &a, &b, &c);//从键盘获得a，b，c三个数

    p = Max;//将函数指针指向Max函数的首地址
    //以下四种写法完全等效
    //函数调用有两种方法：一是用函数名调用，二是用函数指针调用
    //任何一个函数的函数名同时又是指向该函数的入口地址的指针
    //定义函数指针时，该指针不是固定指向哪个函数的。
    //对函数指针变量进行自增自减运算时无意义的。
    printf("\nThe max number is : %d\n", (*p)(a, b, c));
    printf("\nThe max number is : %d\n", Max(a, b, c));
    printf("\nThe max number is : %d\n", (*Max)(a, b, c));
    printf("\nThe max number is : %d\n", p(a, b, c));

    return 0;
}

int Max(int ma, int mb, int mc) {
    int tempMax;

    tempMax = ma > mb ? ma : mb;
    tempMax = tempMax > mc ? tempMax : mc;

    return tempMax;
}
