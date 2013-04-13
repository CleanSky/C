#include <stdio.h>
#include <stdlib.h>

int main()
{
    //printf输出格式
    double f11 = 1.0e+10;
    double f22 = 3.14;

    //%f以十进制小数形式输出实数，整数部分全部输出，隐含输出6位小数
    printf("%%f: %f\n", f11);
    //%e以指数形式（小写e表示指数部分）输出实数，要求小数点前必须有且仅有1位非零数字
    printf("%%e: %e\n", f11);
    //%g自动选取f或e格式中输出宽度较小的一种使用，且不输出无意义的0
    printf("%%g: %g\n", f11);

    printf("%%f: %f\n", f22);
    printf("%%e: %e\n", f22);
    printf("%%g: %g\n", f22);

    int var = 12;

    //%p以主机的格式显示指针，即变量的地址
    printf("%%p: %p\n", &var);
    //%x以无符号十六进制整数行驶（小写）输出，不输出前导符0x
    printf("%%x: %x\n", &var);
    //%X以无符号十六进制整数行驶（答谢）输出，不输出前导符0x
    printf("%%X: %X\n", &var);

    //%n令printf()把自己到%n位置已经输出的字符总数放到后面相应的输出项所指向的整形变量中
    printf("This is%n a test program\n", &var);
    printf("var = %d \n", var);

    float f1 = 100.15799, f2 = 12.55, f3 = 1.7;
    int n1 = 123, n2 = 45, n3 = 6;

    printf("printf without width or precision specifications:\n");
    printf("%f\n%f\n%f\n", f1, f2, f3);
    printf("%d\n%d\n%d\n", n1, n2, n3);

    printf("printf with width and precision specifications:\n");
    //m.n m指定输出项输出时所占的列数，n为精度修饰符
    printf("%5.2f\n%6.1f\n%3.0f\n", f1, f2, f3);
    printf("%5d\n%6d\n%3d\n\n", n1, n2, n3);

    return 0;
}
