#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, ret;

    printf("Input a and b: ");
    ret = scanf("%d%d", &a, &b);
    printf("ret = %d\n", ret);//显示scanf函数的返回值

    if(ret == 0) {//因遇到非法字符而使得两个数据都未成功读入
        printf("Input data type error!\n");
        fflush(stdin);//清除输入缓冲区中的错误数据
    } else if(ret == EOF) {
        printf("Input failure occurs!\n");
    } else {
        printf("a = %d, b = %d\n", a, b);
    }

    printf("Input a and b: ");
    ret = scanf("%d%d", &a, &b);

    if(ret != 2) {
        printf("Input error!\n");
        fflush(stdin);
    } else {
        printf("a = %d, b = %d\n", a, b);
    }

    return 0;
}
