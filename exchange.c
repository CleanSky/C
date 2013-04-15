#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number[2] = {100, 200};
    int temp = 0;

    printf("%d %d\n", number[0], number[1]);

    //使用中间变量交换两个数
    temp = number[0];
    number[0] = number[1];
    number[1] = temp;
    printf("%d %d\n", number[0], number[1]);

    //不用中间变量交换两个数
    number[0] = number[0] + number[1];
    number[1] = number[0] - number[1];
    number[0] = number[0] - number[1];
    printf("%d %d\n", number[0], number[1]);

    //采用异或交换两个数
    number[0] = number[0] ^ number[1];
    number[1] = number[0] ^ number[1];
    number[0] = number[0] ^ number[1];
    printf("%d %d\n", number[0], number[1]);

    return 0;
}
