/************************************************************************
*
* �ļ�����6.1.2.cpp
*
* �ļ�������ͼ�Ĵ洢�ṹ���ڽӱ�
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-08-19
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<limits.h>
using namespace std;

typedef string Vertextype;

//����ṹ
struct ArcNode
{
    int adjvex; //��ͷ��������Ľ���λ�ã�һ����������±꣩
    ArcNode *nextarc; //ָ����һ������
    int weight;       //���ֻ����ͼ����Ҫ��
};

//ͷ���
struct Vnode
{
    Vertextype data;  //����Ǽ�¼ÿ���������Ϣ��һ�㲻��ô��Ҫʹ�ã�
    ArcNode *firstarc;//ָ���һ����ý�������������Ϣ�����㣩
};

//ͼ���
struct Graph
{
    int kind;     //ͼ�����ࣨ����ͼ��0������ͼ��1����������2����������3��
    int vexnum;   //ͼ�Ķ�����
    int edge;     //ͼ�ı���
    Vnode * node; //ͼ�ģ����㣩ͷ�������
};

/*����ͼ*/
void createGraph(Graph & g, int kind)
{
    cout << "�����붥��ĸ�����" << endl;
    cin >> g.vexnum;
    cout << "������ߵĸ���(����ͼ��������Ҫ����2)��" << endl;
    cin >> g.edge;
    g.kind = kind; //ͼ������
    g.node = new Vnode[g.vexnum];
    int i;
    cout << "����ÿ���������Ϣ��" << endl; //��¼ÿ���������Ϣ
    for (i = 0; i < g.vexnum; i++)
    {
        cin >> g.node[i].data;
        g.node[i].firstarc = NULL;
    }

    cout << "������ÿ���ߵ������յ��ţ�" << endl;
    for (i = 0; i < g.edge; i++)
    {
        int a;
        int b;
        cin >> a; //���
        cin >> b; //�յ�

        ArcNode *next = new ArcNode; //ArcNodeΪ����
        next->adjvex = b - 1;
        if (kind == 0 || kind == 1)
        {
            next->weight = -1;
        }
        else
        {
            cout << "����ñߵ�Ȩ�أ�";
            cin >> next->weight;
        }
        next->nextarc = NULL;

        /*���ߴ�������,���Ϊ��һ��������ֱ�Ӳ�������������ҵ����һ�������ٲ���*/
        if (g.node[a-1].firstarc == NULL) //g.node[a-1]Ϊͷ���
        {
            g.node[a-1].firstarc = next;
        }
        else
        {
            ArcNode *p;
            p = g.node[a-1].firstarc;
            while (p->nextarc)
            {
                p = p->nextarc;
            }
            p->nextarc = next;
        }

    }
}

/*��ӡͼ*/
void print (Graph g)
{
    int i;
    cout << "ͼ���ڽӱ�Ϊ��" << endl;
    for (i = 0; i < g.vexnum; i++)
    {
        cout << g.node[i].data << " ";
        ArcNode *now;
        now = g.node[i].firstarc;
        while (now)
        {
            cout << now->adjvex << " ";
            now = now->nextarc;
        }
        cout << endl;
    }
}
int main()
{
    Graph g;
    cout << "����ͼ�����ӣ�" << endl;
    createGraph(g, 0);
    print(g);
    cout << endl;

    cout << "����ͼ�����ӣ�" << endl;
    createGraph(g, 1);
    print(g);
    cout << endl;

    return 0;
}
