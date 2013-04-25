#include <stdio.h>
#include <stdlib.h>

void MyStrcpy(char *dstStr, char *srcStr) {
    while (*srcStr != '\0') {
        *dstStr = *srcStr;
        dstStr++;
        srcStr++;
    }
    *dstStr = '\0';
}

int main()
{
    char str1[10];
    char str2[10] = {"China"};
    char *pstr1;
    char *pstr2 = "China";
    char *pstr3;

    pstr1 = "China";
    strcpy(str1, "Chi");

    pstr3 = str1;
    scanf("%s", pstr3);
    printf("%s\n", pstr3);

    MyStrcpy(str1, str2);//将字符数组str2中的字符串复制到str1中

    printf("The copy is ");
    puts(str1);

    return 0;
}
