#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <io.h>
#include <fcntl.h>
#include <string.h>
#include <dir.h>

#define FILENAME "test.bin"
#define MAXPATH 4096

/*
对于文件操作来说，一个比较好的设计理念是将分散的数据集中，然后一起写入。读出时也一起读出，再分散数据。
这样不仅方便集中处理错误，保证稳定，而且减少了I/O操作次数，可提高速度。
*/

int CopyFile(const char* srcName, const char* dstName);

int main()
{
    //创建test.bin文件
    int i = 100;
    float f = 100.0;
    char string[] = "100";
    int fh, rtn;

    fh = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, 0666);

    if (fh == -1) {
        perror(FILENAME);
        return;
    }

    rtn = write(fh, &i, sizeof(i));
    if (rtn < 0) {
        perror(FILENAME);
        return;
    }

    rtn = write(fh, &f, sizeof(f));
    if (rtn < 0) {
        perror(FILENAME);
        return;
    }

    rtn = write(fh, string, sizeof(string));
    if (rtn < 0) {
        perror(FILENAME);
        return;
    }

    rtn = write(fh, "END", strlen("END") + 1);
    if (rtn < 0) {
        perror(FILENAME);
        return;
    }

    close(fh);



    //读出test.bin文件
    int m, n;
    float ft;
    char str[32];
    int fn, ret;

    fn = open(FILENAME, O_RDONLY | O_BINARY);
    if (fn == -1) {
        perror(FILENAME);
        return;
    }

    ret = read(fn, &m, sizeof(m));
    if (ret < 0) {
        perror(FILENAME);
        return;
    }
    printf("The int is %d\n", i);

    ret = read(fn, &ft, sizeof(ft));
    if (ret < 0) {
        perror(FILENAME);
        return;
    }
    printf("The float is %f\n", ft);

    ret = read(fn, str, sizeof(str));
    if (ret < 0) {
        perror(FILENAME);
        return;
    }

    printf("The string is ");
    for (n = 0; n < rtn; n++) {
        putchar(str[n]);
    }

    close(fn);




    //利用高级文件操作函数复制文件
    char srcFilename[MAXPATH];//源文件名
    char dstFilename[MAXPATH];//目标文件名

    printf("The source filename: ");
    scanf("%s", srcFilename);
    printf("The destination filename: ");
    scanf("%s", dstFilename);

    if (CopyFile(srcFilename, dstFilename)) {
        printf("Copy Succeed.\n");
    } else {
        perror("Copy Failed.\n");
    }

    return 0;
}

/*
函数功能：把srcName文件内容复制到dstName
函数入口参数：文件路径
函数返回值：非0表示复制成功，否则出错
*/
int CopyFile(const char* srcName, const char* dstName) {
    FILE* fpSrc = NULL;
    FILE* fpDst = NULL;
    int ch, rval = 1;

    //打开文件
    fpSrc = fopen(srcName, "rb");
    if (fpSrc == NULL) {
        goto ERROR;
    }

    fpDst = fopen(dstName, "wb");
    if (fpDst == NULL) {
        goto ERROR;
    }

    //复制文件
    while ((ch = fgetc(fpSrc)) != EOF) {
        if (fputc(ch, fpDst) == EOF) {
            goto ERROR;
        }
    }

    fflush(fpDst);//确保存盘
    goto EXIT;

ERROR:
    rval = 0;
EXIT:
    if (fpSrc != NULL) {
        fclose(fpSrc);
    }
    if (fpDst != NULL) {
        fclose(fpDst);
    }

    return rval;
}
