#include <stdio.h>

/*
�������ظ�������ĸ�Ч�㷨
���µĺ���permutation���ڲ�����0��n-1�����ظ������������������浽����z_array�С�
������ʹ��buffer��Ϊ��ʹ��������ļ�¼���飬�ٶ���һ�β���һ��������ģ�����������ķ�Χ�ڲ�����С��rand()%(n-i)��Ϊz��
����buffer��ͳ�Ʋ����ڸ����������ʹ�ù���������ĸ�������Ϊk����z+k��ӽ�z_array�У���Ϊ��������һ�������������ظ���
�����������˴�0��n-1�����ظ����������
*/

void permutation(int n, int *z_array)
{
    int i, j, k, z;
    int buffer[N];

    /* ��ʼ������ */
    for (i=0; i<n; i++)
        buffer[i]=0;

    /* ׼�����������,�Ե�ǰʱ��Ϊ���� */
    srand((unsigned)time((long *)0));

    /* ��ò��ظ���������� */
    for (i=0; i<n; i++)
    {
        /* ���0~��n-i����������� */
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
