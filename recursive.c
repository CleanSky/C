#include <stdio.h>
#include <stdlib.h>

long fact(long n);//函数原型

int main()
{
    int n, i;
    long result1, result2;

    printf("Input n: ");
    scanf("%d", &n);

    result1 = 1;
    for (i = 1; i <= n; i++) {
        result1 *= i;//用迭代法实现n!
    }

    printf("%d! = %ld\n", n, result1);

    result2 = fact(n);

    if (result2 == -1)
        printf("n < 0, data error!\n");
    else
        printf("%d! = %ld\n", n, result2);

    return 0;
}

/*
函数功能：利用递归公式n! = n * (n-1)!计算n!
函数参数：长整形变量n表示阶乘的阶数
函数返回值：返回n!的值，当n<0时返回-1，表示数据错误
*/
long fact(long n) {
    long result;

    if (n < 0) {
        return -1;//如果n<0，则返回-1
    } else if (n == 0 || n == 1) {
        return 1;//递归终止条件
    } else {
        return (n * fact(n -1));//递归调用
    }
}
