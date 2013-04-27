#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N1 1000
#define N2 5000
#define N3 500

struct first_node {
    char data[N3];
    int number1;
    int number2;
    int numbers[N2];
};
typedef struct first_node first;
first nodes[N1];

int main()
{
    FILE *fp = fopen("network_tf_operon.txt", "r");//以只读方式打开文件
    int ch;//读取的字符
    char temp[N3] = "\0";//中间字符数组
    int count = 0;//记录树的个数
    int i = 0, j = 0;
    int flag1 = 0;//标识根节点已识别完成
    int flag2 = 0;//标识开始识别第三层的节点
    int flag3 = 0;//标识完成识别第三层的节点

    for (i = 0; i < N1; i++) {
        for (j = 0; j < N3; j++) {
            nodes[i].data[j] = '\0';
        }
        nodes[i].number1 = 0;
        nodes[i].number2 = 0;
        for (j = 0; j < N2; j++) {
            nodes[i].numbers[j] = 0;
        }
    }

    i = 0;

    while ((ch = fgetc(fp)) != EOF) {//是否读到文件末尾
        if ('#' == ch) {//忽略以#开头的行
            while ((ch = fgetc(fp)) == '\n') {
                break;
            }
        } else {//处理不以#开头的行
            temp[i++] = (char)ch;
            while ((ch = fgetc(fp))) {//读文件
                if ('\n' == ch) {//到行尾清空相关变量
                    i = 0;

                    for (j = 0; j < N3; j++) {
                        temp[j] = '\0';
                    }

                    flag1 = 0;
                    flag2 = 0;
                    flag3 = 0;
                    break;
                } else if (('\t' == ch) && (0 == flag1) && (0 == strcmp(nodes[count].data, temp))) {//相同根节点
                    nodes[count].number1++;
                    flag1 = 1;
                    i = 0;
                } else if (('\t' == ch) && (0 == flag1) && (0 != strcmp(nodes[count].data, temp))){//不同根节点
                    count++;
                    strcpy(nodes[count].data, temp);
                    nodes[count].number1++;
                    flag1 = 1;
                    i = 0;
                } else if (0 == flag1) {//记录根节点内容
                    temp[i] = (char)ch;
                    i++;
                } else if (('[' == ch) && (0 == flag2)) {//开始识别第三层的节点并记录其个数
                    flag2 = 1;
                    nodes[count].number2++;
                } else if ((',' == ch) && (1 == flag2) && (0 == flag3)) {//识别第三层的节点并记录其个数
                    nodes[count].number2++;
                } else if ((']' == ch) && (0 == flag3)) {//结束识别第三层的节点
                    flag3 = 1;
                }
            }
        }
    }

    printf("树编号\t根节点\t第二层节点数\t第三层节点数\n");

    for (i = 1; i < count; i++) {//汇总输出
        printf("%d\t%s\t%d\t\t%d\n", i, nodes[i].data, nodes[i].number1, nodes[i].number2);
    }

    printf("\n\n\n两两相似的树列表如下：\n树编号1\t树编号2\n");
    for (i = 1; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if ((nodes[i].number1 == nodes[j].number1) && (nodes[i].number2 == nodes[j].number2)) {
                printf("%d\t%d\n", i, j);
            }
        }
    }

    return 0;
}
