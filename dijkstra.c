#include <stdio.h>
#define I 999 /* 代表两点间无直接相连 */

/*  Dijstra Algorithm

    procedure SHORTEST-PATHS(v,COST,DIST,n)
     //G是一个n结点有向图，它由其成本邻接矩阵COST(n,n)表示。DIST(j)被置
       从结点v到结点j的最短路径长度，这里1≤j≤n。DIST(v)被置成零//
    boolean S(1:n);real COST(1:n,1:n),DIST(1:n)
    integer u,v,n,num,i,w //v为起点，n为结点数目
    for i←1 to n do //将集合S初始化为空//
       S(i) ←0;DIST(i) ←COST(v,i)  //  若<v, i>不存在，则DIST(i)=∞//
    repeat
    S(v) ←1;DIST(v) ←0  //结点v计入S//
    for num←2 to n-1 do //确定由结点v出发的n-1条路//
        选取结点u,它使得DIST(u)= min{dist(1:n)}
        S(u) ←1 //结点u计入S//
        for 所有S(w)＝0的结点w do  //修改DIST(w)//
            DIST(w) = min(DIST(w), DIST(u) + COST(u,w))
        repeat
    repeat
  end SHORTEST-PATHS
*/

/* 求dist[]中的最小值(已在S[]中的结点除外) */
int f_min(int *dist);

int S[6] = {0};
int dist[6] = {0};
/* example data
   cost[][] 为有向图的带权矩阵 */
int cost[6][6] = {{ 0, 50, 10,  I, 45, I},
    { I,  0, 15,  I, 10, I},
    {20,  I,  0, 15,  I, I},
    { I, 20,  I,  0, 35, I},
    { I,  I,  I, 30,  0, I},
    { I,  I,  I,  3,  I, 0}
};

/* v    起点
   n    结点数目
   u    当前dist[w]最小的结点（已在S[]中的结点除外）
   i,w,num 中间变量 */
int u, w, num, i, v=2, n=6;
int main ()
{
    for (i = 0; i < n; i++)
        dist[i] = cost[v-1][i];
    S[v-1] = 1;
    dist[v-1] = 0;

    for(num = 0; num < n; num++)
    {
        u = f_min(dist);
        S[u-1] = 1;
        w = 1;
        while(w <= n)
        {
            if(dist[w-1] > dist[u-1]+cost[u-1][w-1] && !S[w-1])
                dist[w-1] = dist[u-1]+cost[u-1][w-1];
            w++;
        }
    }
    i = 0;
    printf("the shortest path: \n");
    while(i < n)
    {
        printf("    from 2 to %d : %d\n", (i++)+1, (dist[i]==I)?(-1):dist[i]);
    }
    return 0;
}

int f_min (int *dist)
{
    int i, j = 0, temp = I;
    for(i = 0; i < n; i++)
    {
        if (S[i])
            ;
        else
            (temp >= dist[i]) ? (temp = dist[i], j = i) : 1;
    }
    return j+1;
}
