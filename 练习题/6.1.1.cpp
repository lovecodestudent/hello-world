/************************************************************************
*
* �ļ�����6.1.1.cpp
*
* �ļ�������ͼ�Ĵ洢�ṹ��-�ڽӾ���Ĵ���ʵ��
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-08-18
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

/*����ͼ-Digraph��������Digraph Network������ͼ-Undigraph��������Undigraph Network*/
enum Graphkind{DG, DN, UDG, UDN};

/*ͼ���Ķ���*/
typedef struct Node
{
    int * vex;  //��������
    int vexnum; //�������
    int edge;   //ͼ�ı���
    int ** adjMatrix; //ͼ���ڽӾ���
    enum Graphkind kind;
}MGraph;

void createGraph (MGraph & G, enum Graphkind kind)
{
    cout << "���붥��ĸ�����" << endl;
    cin >> G.vexnum;
    cout << "����ߵĸ�����" << endl;
    cin >> G.edge;

    //����ͼ������
    //cout << "����ͼ�����ࣺDG������ͼ��DN����������UNG������ͼ��UDN��������" << endl;
    G.kind = kind;
    //Ϊ�������鿪�ٿռ�
    G.vex = new int [G.vexnum];
    G.adjMatrix = new int*[G.vexnum];
    cout << G.vexnum << endl;
    int i;
    for (i = 0; i < G.vexnum; i++)
    {
        G.adjMatrix[i] = new int[G.vexnum];
    }

    for (i = 0; i < G.vexnum; i++)
    {
        for (int k = 0; k < G.vexnum; k++)
        {
            /*����ͼ������ͼ*/
            if (G.kind == DG || G.kind == UDG )
            {
                G.adjMatrix[i][k] = 0;
            }
            else
            {
                G.adjMatrix[i][k] = INT_MAX;
            }
        }
    }

    cout << "�����������й�ϵ�Ķ������ţ�����1 2����1�Ŷ���ָ��2�Ŷ���" << endl;
    for (i = 0; i < G.vexnum; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;

        /*���Ϊ����ͼ*/
        if (G.kind == UDG)
        {
            G.adjMatrix[a-1][b-1] = 1;
            G.adjMatrix[b-1][a-1] = 1;
        }
        /*���Ϊ����ͼ*/
        else if (G.kind == DG)
        {
            G.adjMatrix[a-1][b-1] = 1;
        }
        /*���Ϊ������*/
        else if (G.kind == DN)
        {
            int weight;
            cout << "������ñߵ�Ȩ�أ�" << endl;
            cin >> weight;
            G.adjMatrix[a-1][b-1] = weight;
        }
        /*���Ϊ������*/
        else
        {
            int weight;
            cout << "������ñߵ�Ȩ�أ�" << endl;
            cin >> weight;
            G.adjMatrix[a-1][b-1] = weight;
            G.adjMatrix[b-1][a-1] = weight;
        }
    }
}

void print (MGraph g)
{
    int i, j;
    for (i = 0; i < g.vexnum; i++)
    {
        for (j = 0; j < g.vexnum; j++)
        {
            if (g.adjMatrix[i][j] == INT_MAX)
            {
                cout << "��" << " ";
            }
            else
            {
                cout << g.adjMatrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void clear (MGraph G)
{
    delete G.vex;
    G.vex = NULL;
    for (int i = 0; i < G.vexnum; i++)
    {
        delete G.adjMatrix[i];
        G.adjMatrix[i] = NULL;
    }
    delete G.adjMatrix;
}
int main()
{
    MGraph G;
    cout << "����ͼ�����ӣ�" << endl;
    createGraph(G, DG);
    print(G);
    clear(G);
    cout << endl;

    cout << "����ͼ�����ӣ�" << endl;
    createGraph(G, UDG);
    print(G);
    clear(G);
    cout << endl;

    cout << "�����������ӣ�" << endl;
    createGraph(G, DN);
    print(G);
    clear(G);
    cout << endl;

    cout << "�����������ӣ�" << endl;
    createGraph(G, UDN);
    print(G);
    clear(G);
    cout << endl;

    return 0;
}


