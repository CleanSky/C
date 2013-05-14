#include <stdio.h>
#define I 999 /* �����������ֱ������ */

/*  Dijstra Algorithm

    procedure SHORTEST-PATHS(v,COST,DIST,n)
     //G��һ��n�������ͼ��������ɱ��ڽӾ���COST(n,n)��ʾ��DIST(j)����
       �ӽ��v�����j�����·�����ȣ�����1��j��n��DIST(v)���ó���//
    boolean S(1:n);real COST(1:n,1:n),DIST(1:n)
    integer u,v,n,num,i,w //vΪ��㣬nΪ�����Ŀ
    for i��1 to n do //������S��ʼ��Ϊ��//
       S(i) ��0;DIST(i) ��COST(v,i)  //  ��<v, i>�����ڣ���DIST(i)=��//
    repeat
    S(v) ��1;DIST(v) ��0  //���v����S//
    for num��2 to n-1 do //ȷ���ɽ��v������n-1��·//
        ѡȡ���u,��ʹ��DIST(u)= min{dist(1:n)}
        S(u) ��1 //���u����S//
        for ����S(w)��0�Ľ��w do  //�޸�DIST(w)//
            DIST(w) = min(DIST(w), DIST(u) + COST(u,w))
        repeat
    repeat
  end SHORTEST-PATHS
*/

/* ��dist[]�е���Сֵ(����S[]�еĽ�����) */
int f_min(int *dist);

int S[6] = {0};
int dist[6] = {0};
/* example data
   cost[][] Ϊ����ͼ�Ĵ�Ȩ���� */
int cost[6][6] = {{ 0, 50, 10,  I, 45, I},
    { I,  0, 15,  I, 10, I},
    {20,  I,  0, 15,  I, I},
    { I, 20,  I,  0, 35, I},
    { I,  I,  I, 30,  0, I},
    { I,  I,  I,  3,  I, 0}
};

/* v    ���
   n    �����Ŀ
   u    ��ǰdist[w]��С�Ľ�㣨����S[]�еĽ����⣩
   i,w,num �м���� */
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
