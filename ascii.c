#include <stdio.h>
#include <stdlib.h>

int main()
{
    //ASCII码
    //小写英文字母比大写英文字母的ASCII码大32
    char ch1 = 'a';
    char ch2 = 'A';

    printf("a: %c, %d\n", ch1, ch1);
    printf("A: %c, %d\n", ch2, ch2);
    printf("a-A: %d\n", ch1 - ch2);

    return 0;
}
