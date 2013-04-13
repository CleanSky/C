#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;

    //空行增加程序的可读性和结构的清晰性
    printf("Press a key and then press Enter: ");
    //从键盘输入一个字符，按回车键结束键入，该字符被存入变量ch
    ch = getchar();

    printf("You pressed ");
    //在屏幕上显示变量ch中的字符
    putchar(ch);
    //输出一个回车换行控制符
    putchar('\n');

    return 0;
}
