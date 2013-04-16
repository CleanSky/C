#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //存储字符串时，'\0'字符串结束标志也占一个字节的存储单元
    char str1[6] = {'C', 'h', 'i', 'n', 'a', '\0'};
    char str2[] =  {'C', 'h', 'i', 'n', 'a', '\0'};
    char str3[] =  {'C', 'h', 'i', 'n', 'a'};
    char str4[6] = {"China"};
    char str5[6] = "China";
    char str6[] = {"China"};
    char str7[15] = "China";
    //char str8[5] = {"China"}//错误

    int temp = 0;

    //定义数组时第二维的长度声明不能省略
    char weekday1[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    char weekday2[][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    //char weekday2[][] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};//错误

    //字符串的输入输出
    scanf("%s", str1);
    printf("str1: %s\n", str1);

    //gets(str2);
    puts(str2);

    //字符串的处理函数
    printf("str1的长度：%d\n", strlen(str1));
    printf("复制前，str2是: %s\n", str2);
    strcpy(str2, str1);//将str1复制到str2中
    printf("复制后，str2是: %s\n", str2);
    temp = strcmp(str1, str3);//比较str1和str2的大小，str1-str3，ASCII码值逐个相比
    printf("str1 - str3: %s - %s = %d\n", str1, str3, temp);
    printf("连接前，str7是: %s\n", str7);
    strcat(str7, str1);//将str1连接到str7后面
    printf("连接后，str7是: %s\n", str7);

    return 0;
}
