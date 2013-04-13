#include <stdio.h>
#include <stdlib.h>

int main()
{
    //将一个实型常量赋给float和double型变量时所接受的有效数字位数是不同的
    //数据截断错误：如double赋给float时就会发生
    float a = 123456.789e4;
    double b = 123456.789e4;

    printf("a: %f\nb: %lf\n", a, b);

    return 0;
}
