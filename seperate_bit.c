#include <stdio.h>
#include <stdlib.h>

int main()
{
    //任意从键盘输入一个三位整数，正确分离它的个位，十位和百位
    int x, b0, b1, b2;

    printf("Input a three-bit integer: ");
    scanf("%d", &x);

    b0 = x % 10;
    x /= 10;
    b1 = x % 10;
    x /= 10;
    b2 = x % 10;

    printf("个位数：%d\n", b0);
    printf("十位数：%d\n", b1);
    printf("百位数：%d\n", b2);

    return 0;
}
