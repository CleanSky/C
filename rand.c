#include <stdio.h>

/*
产生无重复随机数的高效算法
以下的函数permutation用于产生从0到n-1的无重复随机数，并将结果保存到数组z_array中。
程序中使用buffer作为已使用随机数的记录数组，假定下一次产生一个随机数的（产生随机数的范围在不断缩小：rand()%(n-i)）为z，
遍历buffer，统计不大于该随机数且已使用过的随机数的个数，记为k，将z+k添加进z_array中，作为产生的下一个随机数，如此重复。
这样便生成了从0到n-1的无重复的随机数。
*/

void permutation(int n, int *z_array)
{
    int i, j, k, z;
    int buffer[N];

    /* 初始化数组 */
    for (i=0; i<n; i++)
        buffer[i]=0;

    /* 准备生成随机数,以当前时间为种子 */
    srand((unsigned)time((long *)0));

    /* 获得不重复的随机数据 */
    for (i=0; i<n; i++)
    {
        /* 获得0~（n-i）的随机数据 */
        z = rand()%(n-i);
        j=0;
        k=0;
        while (j<=z)
        {
            if (buffer[j+k]==0) j++;
            else k++;
        }
        buffer[j+k-1]=1;
        z_array[i]=j+k-1;
    }
    return;
}

int main() {
    print("Hello World!\n")
    return 0;
}
