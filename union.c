#include <stdio.h>
#include <stdlib.h>

/*
共用体是将不同的数据类型组合在一起，共同占有同一段内存的用户自定义数据类型。
共用体的内存空间的大小有占据最大内存空间成员所占的空间数决定。
共用体采用与开始地址对齐的方式分配地址空间。
共用体在同一时刻只有一个成员是有意义的，即共用体的成员具有唯一性。
共用体不能进行比较操作。
共用体在初始化时，只能对第一个成员的数据类型初始化。
*/

union number {
    int x;
    float y;
};
typedef union number Num;

int main()
{
    Num wNumber;

    wNumber.x = 10;//给共用体的int成员赋值，共用体的float域无意义
    printf("%s\n%s\n%s%d\n%s%f\n\n", "Put a value in the integer member", "and print both member", "int : ", wNumber.x, "float : ", wNumber.y);

    wNumber.y = 100.0;//给共用体的float成员赋值，共用体的int域无意义
    printf("%s\n%s\n%s%d\n%s%f\n\n", "Put a value in the float member", "and print both member", "int : ", wNumber.x, "float : ", wNumber.y);

    return 0;
}
