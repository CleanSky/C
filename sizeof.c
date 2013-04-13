#include <stdio.h>
#include <stdlib.h>

int main()
{
    //类型的字节数
    printf("Data type           Number of bytes\n");
    printf("---------           ---------------\n");
    printf("char                %d\n", sizeof(char));
    printf("int                 %d\n", sizeof(int));
    printf("short int           %d\n", sizeof(short));
    printf("long int            %d\n", sizeof(long));
    printf("long long int       %d\n", sizeof(long long));
    printf("float               %d\n", sizeof(float));
    printf("double              %d\n", sizeof(double));

    return 0;
}
