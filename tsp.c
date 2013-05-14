#include <stdio.h>
#include <stdlib.h>

/*
 * 货郎问题(Traveling Salesman Problem，简称“TSP”)也叫货郎担问题，中国邮路问题，旅行商问题等,是计算机算法理论历史上的经典问题。
 * 在过去几十年中，它成为许多重要算法思想的测试平台，同时也促使一些新的理论领域的产生，比如多面体理论和复杂性理论。
 * 货郎问题：给定n个结点和任意一对结点{i，j}之间的距离为dist(i，j)，要求找出一条闭合的回路，该回路经过每个结点一次且仅一次，并且该回路的费用最小，这里的费用是指每段路径的距离和。
 * 货郎问题求解其精确解是NP难的，并且求解任意常数因子近以度的解也是NP难的。若将问题限定在欧氏平面上，就成为欧氏平面上的货郎问题,也叫欧几里德旅行商问题(Eculid Traveling Salesman Problem)。
 * 但是，即使是欧氏平面上的货郎问题也是NP难的。因此通常用来解决TSP问题的解法都是近似算法。
 * 其中第一个欧几里德旅行商问题的多项式近似算法是Arora在1996年使用随机平面分割和动态规划方法给出的。
 * J.L. Bentley建议通过只考虑双调旅程(bitonic tour)来简化问题,这种旅程即为从最左点开始，严格地从左到右直至最右点，然后严格地从右到左直至出发点。
 */

const int inf = 1000000000;

int n;
int d[128];
int dp[128][128];

int Min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int i, j, k;
    while(scanf("%d", &n) && n)
    {
        for(i = 1; i <= n; i++)
            scanf("%d", d + i);

        for(i = 0; i <= n; i++)
            for(j = 0; j <= n; j++)
                dp[i][j] = inf;

        dp[0][0] = dp[1][0] = 0;
        for(i = 2; i <= n; i++)
        {
            for(j = i - 1; j >= 0; j--)
                dp[i][i - 1] = Min(dp[i][i - 1], dp[i - 1][j] + (j == 0 ? 0 : abs(d[j] - d[i])));

            for(j = 0; j <= i - 1; j++)
            {
                dp[i][j] = Min(dp[i][j], dp[i - 1][j] + abs(d[i] - d[i - 1]));
            }
        }

        int ans = dp[n][0];
        for(i = 1; i <= n; i++)
        {
            ans = Min(ans, dp[n][i] + abs(d[i] - d[n]));
        }

        printf("%d\n", ans);
    }
}
