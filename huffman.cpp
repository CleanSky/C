#include <iostream>
using namespace std;

struct HuffNode			//哈夫曼树结点结构
{
    int weight;			//权值
    int parent;			//父结点
    int lchild;			//左儿子
    int rchild;			//右儿子
};


struct HuffCode			//哈夫曼编码结构
{
    int bit[10];		//存储哈夫曼编码
    int start;			//哈夫曼编码在数组中的起始位置
    int weight;			//权值
};


//实现哈夫曼编码
void Huffman(int w[],int n,HuffNode hn[],HuffCode hc[])
{
    int m1,m2;			//分别存放最小，次小权值
    int x1,x2;			//分别表示当前结点左右儿子
    HuffCode cd;
    int child,parent;
    int i,j;

    for(i=0; i<2*n-1; i++) //初始化哈夫曼树
    {
        if(i<n)
            hn[i].weight = w[i];
        else
            hn[i].weight = 0;
        hn[i].parent = 0;
        hn[i].lchild = -1;
        hn[i].rchild = -1;
    }


    for(i=0; i<n-1; i++)	//构造哈夫曼树的n-1个分支结点
    {
        m1 = m2 =1000;
        x1 = x2 =0;
        for(j=0; j<n+i; j++)
        {

            if(hn[j].weight<m1&&hn[j].parent==0)//最小保存到次小
            {
                m2 = m1;
                m1 = hn[j].weight;
                x2 = x1;
                x1 = j;
            }
            else if(hn[j].weight<m2&&hn[j].parent==0)
            {
                m2 = hn[j].weight;
                x2 = j;
            }
        }
        hn[n+i].weight = hn[x1].weight+hn[x2].weight;
        hn[x1].parent = n+i;
        hn[x2].parent = n+i;
        hn[n+i].lchild = x1;
        hn[n+i].rchild = x2;
    }


    for(i=0; i<n; i++)	//由哈夫曼树生成哈夫曼编码
    {
        cd.weight = hn[i].weight;
        cd.start = n-1;
        child = i;
        parent = hn[i].parent;
        while(parent!=0)
        {
            if(hn[parent].lchild==child)
                cd.bit[cd.start] = 0;
            else if(hn[parent].rchild==child)
                cd.bit[cd.start] = 1;
            cd.start--;
            child = parent;
            parent = hn[child].parent;
        }
        hc[i].weight = cd.weight;
        hc[i].start = cd.start;
        for(j=hc[i].start+1; j<n; j++)
            hc[i].bit[j] = cd.bit[j];
    }

}


int main(int argc, char* argv[])
{
    int w[] = {4,2,6,8,3,2,1};
    int n = 7;
    HuffNode *hn = new HuffNode[2*n-1];
    HuffCode *hc = new HuffCode[n];
    Huffman(w,n,hn,hc);
    cout<<"哈夫曼编码如下:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"weight="<<hc[i].weight<<"    "<<"code=";
        for(int j=hc[i].start+1; j<n; j++)
            cout<<hc[i].bit[j];
        cout<<endl;
    }

    return 0;
}
