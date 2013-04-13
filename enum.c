#include <stdio.h>
#include <stdlib.h>

int main()
{
    //枚举类型
    enum response1{no1, yes1, none1};
    enum response1 answer1;

    answer1 = no1;
    printf("Answer1: %d\n", answer1);
    answer1 = yes1;
    printf("Answer1: %d\n", answer1);
    answer1 = none1;
    printf("Answer1: %d\n", answer1);

    enum{no2 = -1, yes2 = 1, none2 = 0, unsure2}answer2;

    answer2 = no2;
    printf("Answer2: %d\n", answer2);
    answer2 = yes2;
    printf("Answer2: %d\n", answer2);
    answer2 = none2;
    printf("Answer2: %d\n", answer2);
    answer2 = unsure2;
    printf("Answer2: %d\n", answer2);

    return 0;
}
