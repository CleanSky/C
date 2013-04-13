#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;

    printf("Please input a and b: ");
    //域宽m(正整数)——指定输入数据的宽度（列数），系统自动按此宽度截取所需数据
    //忽略输入修饰符*——表示对应的输入项在读入后不赋给相应的变量
    scanf("%2d%*2d%2d", &a, &b);

    printf("a = %d, b = %d, a + b = %d\n", a, b, a + b);

    scanf("%d %d", &a, &b);
    printf("a = %d, b = %d\n", a, b);

    scanf("%d, %d", &a, &b);
    printf("a = %d, b = %d\n", a, b);

    scanf("%2d%2d", &a, &b);
    printf("a = %d, b = %d\n", a, b);

    scanf("%d%*c%d", &a, &b);
    printf("a = %d, b = %d\n", a, b);

    //按照变量声明顺序的逆序读入字符数据
    char ch1, ch2, ch3;

    printf("Please input ch3: ");
    scanf("%1s", &ch3);
    printf("Please input ch2: ");
    scanf("%1s", &ch2);
    printf("Please input ch1: ");
    scanf("%1s", &ch1);

    printf("ch3=%c, ch2=%c, ch1=%c\n", ch3, ch2, ch1);
    printf("ASCII: ch3:%d, ch2:%d, ch1:%d\n", ch3, ch2, ch1);

    //用getchar()将前面数据输入时存于缓冲区中的回车符读入，避免被后面的字符型变量作为有效字符读入
    printf("Please input ch3: ");
    scanf("%c", &ch3);
    getchar();
    printf("Please input ch2: ");
    scanf("%c", &ch2);
    getchar();
    printf("Please input ch1: ");
    scanf("%c", &ch1);
    getchar();

    printf("ch3=%c, ch2=%c, ch1=%c\n", ch3, ch2, ch1);
    printf("ASCII: ch3:%d, ch2:%d, ch1:%d\n", ch3, ch2, ch1);

    printf("Please input ch3: ");
    scanf("%c", &ch3);
    printf("Please input ch2: ");
    scanf(" %c", &ch2);
    printf("Please input ch1: ");
    scanf(" %c", &ch1);

    printf("ch3=%c, ch2=%c, ch1=%c\n", ch3, ch2, ch1);
    printf("ASCII: ch3:%d, ch2:%d, ch1:%d\n", ch3, ch2, ch1);

    return 0;
}
