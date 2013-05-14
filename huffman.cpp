#include <iostream>
using namespace std;

struct HuffNode			//�����������ṹ
{
    int weight;			//Ȩֵ
    int parent;			//�����
    int lchild;			//�����
    int rchild;			//�Ҷ���
};


struct HuffCode			//����������ṹ
{
    int bit[10];		//�洢����������
    int start;			//�����������������е���ʼλ��
    int weight;			//Ȩֵ
};


//ʵ�ֹ���������
void Huffman(int w[],int n,HuffNode hn[],HuffCode hc[])
{
    int m1,m2;			//�ֱ�����С����СȨֵ
    int x1,x2;			//�ֱ��ʾ��ǰ������Ҷ���
    HuffCode cd;
    int child,parent;
    int i,j;

    for(i=0; i<2*n-1; i++) //��ʼ����������
    {
        if(i<n)
            hn[i].weight = w[i];
        else
            hn[i].weight = 0;
        hn[i].parent = 0;
        hn[i].lchild = -1;
        hn[i].rchild = -1;
    }


    for(i=0; i<n-1; i++)	//�������������n-1����֧���
    {
        m1 = m2 =1000;
        x1 = x2 =0;
        for(j=0; j<n+i; j++)
        {

            if(hn[j].weight<m1&&hn[j].parent==0)//��С���浽��С
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


    for(i=0; i<n; i++)	//�ɹ����������ɹ���������
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
    cout<<"��������������:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"weight="<<hc[i].weight<<"    "<<"code=";
        for(int j=hc[i].start+1; j<n; j++)
            cout<<hc[i].bit[j];
        cout<<endl;
    }

    return 0;
}
