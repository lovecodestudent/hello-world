/************************************************************************
*
* 文件名：6.1.1.cpp
*
* 文件描述：图的存储结构—-邻接矩阵的代码实现
*
* 创建人：  fdk

* 时  间：  2018-08-18
*
* 版本号：1.0
*
* 修改记录：
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

/*有向图-Digraph、有向网Digraph Network、无向图-Undigraph、无向网Undigraph Network*/
enum Graphkind{DG, DN, UDG, UDN};

/*图结点的定义*/
typedef struct Node
{
    int * vex;  //顶点数组
    int vexnum; //顶点个数
    int edge;   //图的边数
    int ** adjMatrix; //图的邻接矩阵
    enum Graphkind kind;
}MGraph;

void createGraph (MGraph & G, enum Graphkind kind)
{
    cout << "输入顶点的个数：" << endl;
    cin >> G.vexnum;
    cout << "输入边的个数：" << endl;
    cin >> G.edge;

    //输入图的种类
    //cout << "输入图的种类：DG：有向图、DN：有向网、UNG：无向图、UDN：无向网" << endl;
    G.kind = kind;
    //为两个数组开辟空间
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
            /*有向图和无向图*/
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

    cout << "请输入两个有关系的顶点的序号：例如1 2代表1号顶点指向2号顶点" << endl;
    for (i = 0; i < G.vexnum; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;

        /*如果为无向图*/
        if (G.kind == UDG)
        {
            G.adjMatrix[a-1][b-1] = 1;
            G.adjMatrix[b-1][a-1] = 1;
        }
        /*如果为有向图*/
        else if (G.kind == DG)
        {
            G.adjMatrix[a-1][b-1] = 1;
        }
        /*如果为有向网*/
        else if (G.kind == DN)
        {
            int weight;
            cout << "请输入该边的权重：" << endl;
            cin >> weight;
            G.adjMatrix[a-1][b-1] = weight;
        }
        /*如果为无向网*/
        else
        {
            int weight;
            cout << "请输入该边的权重：" << endl;
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
                cout << "∞" << " ";
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
    cout << "有向图的例子：" << endl;
    createGraph(G, DG);
    print(G);
    clear(G);
    cout << endl;

    cout << "无向图的例子：" << endl;
    createGraph(G, UDG);
    print(G);
    clear(G);
    cout << endl;

    cout << "有向网的例子：" << endl;
    createGraph(G, DN);
    print(G);
    clear(G);
    cout << endl;

    cout << "无向网的例子：" << endl;
    createGraph(G, UDN);
    print(G);
    clear(G);
    cout << endl;

    return 0;
}


