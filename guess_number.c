#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //猜数游戏
    int magic;
    int number;
    int count = 0;

    srand(time(NULL));//用标准库函数srand()为函数rand()设置随机数种子

    magic = rand() % 100 + 1;

    do {
        printf("Please input the number: ");
        scanf("%d", &number);

        if(number > magic){
            printf("The number you guessed is large!\n");
        }else if (number < magic){
            printf("The number you guessed is small!\n");
        }else{
            printf("Congratulations!\n");
            break;
        }

        count++;
    }while(count < 5);

    return 0;
}
