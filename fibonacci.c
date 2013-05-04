#include <stdio.h>
#include <stdlib.h>

/*
数学和计算科学是有区别的。数学要求严谨和简洁的表达，而计算科学需要尽快地得出结果。好的数学公式未必是好的计算公式。
*/

int fibonacci(int n);//求斐波那契数列的函数原型

int main()
{
    int n = 0;

    printf("Enter the number: ");
    scanf("%d", &n);

    printf("The %d number is %d.", n, fibonacci(n));

    return 0;
}

/*
函数功能：利用非递归的方法求出斐波那契数列的第n个数
函数参数：斐波那契序列的序号
函数返回值：斐波那契序列的序号对应的数
*/
int fibonacci(int n) {
    int m1 = 1, m2 = 1;
    int i = 0;

    if (n < 1) {
        printf("The number is wrong!\n");
        return -1;
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        for (i = 3; i <= n; i++) {
            m2 = m1 + m2;
            m1 = m2 - m1;
        }
        return m2;
    }
}
