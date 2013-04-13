#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //判断一个数是否为素数
    int x;
    int y;
    int i;
    int flag = 1;

    printf("Please input the number: ");
    scanf("%d", &x);

    y = sqrt(x);

    for(i = 2; i <= y; i++) {
        if(x % i == 0){
            flag = 0;
            printf("%d\n", i);
        }
    }

    if(flag == 1){
        printf("No divisor! It is a prime number.\n");
    }

    return 0;
}
