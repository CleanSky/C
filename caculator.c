#include <stdio.h>
#include <stdlib.h>

int main()
{
    //计算器：操作数1 运算符op 操作数2
    int data1, data2;
    char op;

    printf("Please enter the expression: ");
    scanf("%d%c%d", &data1, &op, &data2);//输入表达式

    switch(op){
        case '+'://处理加法
            printf("%d + %d = %d \n", data1, data2, data1 + data2);
            break;
        case '-'://处理减法
            printf("%d - %d = %d \n", data1, data2, data1 - data2);
            break;
        case '*'://处理乘法
            printf("%d * %d = %d \n", data1, data2, data1 * data2);
            break;
        case '/'://处理除法
            if(0 == data2)//为避免出现溢出错误，检验除数是否为0
                printf("Division by zero!\n");
            else
                printf("%d / %d = %d \n", data1, data2, data1 / data2);
            break;
        default:
            printf("Unknown operator!\n");
    }

    return 0;
}
