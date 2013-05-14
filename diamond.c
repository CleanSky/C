#include <stdio.h>

int diamond(int n, char star)
{
    int i, j, k;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= abs(i-(n+1)/2); j++)
            printf("\t");
        for (k = 1; k <= n - 2*abs(i - (n+1)/2); k++)
            printf("%c\t", star);
        printf("\n");
    }
}

int main()
{
    diamond(7, '$');
    return 0;
}
