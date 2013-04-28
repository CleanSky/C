#include <stdio.h>
#include <stdlib.h>

void Hanoi(int n, char a, char b, char c);
void Move(int num, char from, char to);

/*
汉诺塔问题
第n个盘子从源木桩A，借助于木桩C移动到目的木桩B。
Step 1: Hanoi(n-1, a, c, b);
Step 2: Move(n, a, b);
Step 3: Hanoi(n-1, c, b, a);
*/
int main()
{
    int n;

    printf("Input the number of disk: ");
    scanf("%d", &n);
    printf("The step of moving %3d disk: \n", n);
    Hanoi(n, 'A', 'B', 'C');

    return 0;
}

/*
函数功能：将第n个盘子从源木桩A，借助于木桩C移动到目的木桩B
函数功能：整型变量n，表示第n个盘子
            字符型变量a，表示源木桩a
            字符型变量b，表示目的木桩b
            字符型变量c，表示过渡木桩c
函数返回值：无
*/
void Hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        Move(n, a, b);//第n个盘子由a->b
    } else {
        Hanoi(n - 1, a, c, b);//将第n-1个盘子借助于b由a移动到c
        Move(n, a, b);//第n个盘子由a->b
        Hanoi(n - 1, c, b, a);//将第n-1个盘子借助于b由a移动到c
    }
}

/*
函数功能：显示移动过程
函数参数：整型变量num，表示第num个盘子
            字符型变量from，表示源木桩
            字符型变量to，表示目的木桩
函数返回值：无
*/
void Move(int num, char from, char to) {
    printf("Move %d: from %c to %c\n", num, from, to);
}
