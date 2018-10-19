/************************************************************************
*
* 文件名：6.1.2.cpp
*
* 文件描述：图的存储结构—邻接表
*
* 创建人：  fdk

* 时  间：  2018-08-19
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

typedef string Vertextype;

//表结点结构
struct ArcNode
{
    int adjvex; //与头结点相连的结点的位置（一般是数组的下标）
    ArcNode *nextarc; //指向下一个表结点
    int weight;       //这个只有网图才需要用
};

//头结点
struct Vnode
{
    Vertextype data;  //这个是记录每个顶点的信息（一般不怎么需要使用）
    ArcNode *firstarc;//指向第一条与该结点相关联结点的信息（表结点）
};

//图结点
struct Graph
{
    int kind;     //图的种类（有向图：0，无向图：1，有向网：2，无向网：3）
    int vexnum;   //图的顶点数
    int edge;     //图的边数
    Vnode * node; //图的（顶点）头结点数组
};

/*创建图*/
void createGraph(Graph & g, int kind)
{
    cout << "请输入顶点的个数：" << endl;
    cin >> g.vexnum;
    cout << "请输入边的个数(无向图、无向网要乘以2)：" << endl;
    cin >> g.edge;
    g.kind = kind; //图的种类
    g.node = new Vnode[g.vexnum];
    int i;
    cout << "输入每个顶点的信息：" << endl; //记录每个顶点的信息
    for (i = 0; i < g.vexnum; i++)
    {
        cin >> g.node[i].data;
        g.node[i].firstarc = NULL;
    }

    cout << "请输入每条边的起点和终点编号：" << endl;
    for (i = 0; i < g.edge; i++)
    {
        int a;
        int b;
        cin >> a; //起点
        cin >> b; //终点

        ArcNode *next = new ArcNode; //ArcNode为表结点
        next->adjvex = b - 1;
        if (kind == 0 || kind == 1)
        {
            next->weight = -1;
        }
        else
        {
            cout << "输入该边的权重：";
            cin >> next->weight;
        }
        next->nextarc = NULL;

        /*将边串联起来,如果为第一个表结点则直接插入如果不是则找到最后一个表结点再插入*/
        if (g.node[a-1].firstarc == NULL) //g.node[a-1]为头结点
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

/*打印图*/
void print (Graph g)
{
    int i;
    cout << "图的邻接表为：" << endl;
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
    cout << "有向图的例子：" << endl;
    createGraph(g, 0);
    print(g);
    cout << endl;

    cout << "无向图的例子：" << endl;
    createGraph(g, 1);
    print(g);
    cout << endl;

    return 0;
}
