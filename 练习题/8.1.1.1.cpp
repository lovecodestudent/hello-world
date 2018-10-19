/************************************************************************
*
* 文件名：8.1.1.cpp
*
* 文件描述：最小生成树之Prim算法-使用邻接矩阵实现
*
* 创建人：  fdk

* 时  间：  2018-08-15
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

struct Graph
{
    int vexnum;  //顶点个数
    int edge;    //边的个数
    int ** arc;  //邻接矩阵
    string *information; //记录每个顶点名称
};

//创建图
void createGraph (Graph & g)
{
    cout << "请输入顶点数：输入边的条数" << endl;
    cin >> g.vexnum; //输入顶点数
    cin >> g.edge;   //输入边的个数
    g.information = new string [g.vexnum];
    g.arc = new int *[g.vexnum];
    int i = 0;

    /*开辟空间的同时，进行名称的初始化*/
    for (i = 0; i < g.vexnum; i++)
    {
        g.arc[i] = new int [g.vexnum];
        g.information[i] = "V" + to_string(i+1); //对每个顶点进行命名，to_string函数将数字转换为string类型

        /*初始化邻接矩阵*/
        for (int k = 0; k < g.vexnum; k++)
        {
            g.arc[i][k] = INT_MAX;
        }

    }

    /*给无向图赋上权值*/
    cout << "请输入每条边上的顶点编号（顶点编号从1开始），以及改变的权重：" << endl;
    for (i = 0; i < g.edge; i++)
    {
        int begin;
        int end;
        cin >> begin;
        cin >> end;
        int weight;
        cin >> weight;
        g.arc[begin-1][end-1] = weight; //无向图边是反的
        g.arc[end-1][begin-1] = weight;
    }
}

//打印图
void print (Graph g)
{
    for (int i = 0; i < g.vexnum; i++)
    {
        for (int j = 0; j < g.vexnum; j++)
        {
            if (g.arc[i][j] == INT_MAX)
                cout << "∞" << " ";
            else
                cout << g.arc[i][j] << " ";
        }
        cout << endl;
    }
}


/*作为记录边的信息，这些边都是达到end的所有变中权重最小的那个*/
struct Assis_arry
{
    int start;  //边的起点
    int end;    //边的终点
    int weight; //边的权重
};

/*prim算法*/
void Prim(Graph g, int begin)
{
    //close_edge这个数组记录到达某个顶点的各个边中的权重最小的那个边
    Assis_arry *close_edge = new Assis_arry[g.vexnum];

    int j;

    /*进行close_edge初始化,把以begin为顶点的剩下的所有顶点的权值初始化*/
    for (j = 0; j < g.vexnum; j++)
    {
        if (j != begin - 1)
        {
            close_edge[j].start = begin - 1;
            close_edge[j].end = j;
            close_edge[j].weight = g.arc[begin-1][j];
        }
    }

    /*把起点的close_edge中的值设置为-1，代表已经加入到集合U中*/
    close_edge[begin-1].weight = -1;

    /*访问剩下的顶点并依次加入到集合U中(weight为-1)*/
    int sum = 0;
    for (j = 1; j < g.vexnum; j++)
    {
        int min = INT_MAX;
        int k;
        int index;
        //寻找数组close_edge中权重最小的那条边
        for (k = 0; k < g.vexnum; k++)
        {
            if (close_edge[k].weight != -1)
            {
                if (close_edge[k].weight < min)
                {
                    min = close_edge[k].weight;
                    index = k;
                }
            }
        }
        /*将权重最小的那一条边的终点也加入到集合U中*/
        close_edge[index].weight = -1;
        //输出对应边的信息
        cout << g.information[close_edge[index].start] << "-----"
             << g.information[close_edge[index].end]
             << "="
             << g.arc[close_edge[index].start][close_edge[index].end]
             << endl;

        sum += g.arc[close_edge[index].start][close_edge[index].end];

        /*更新close_edge数组*/
        for (k = 0; k < g.vexnum; k++)
        {
            if (g.arc[close_edge[index].end][k] < close_edge[index].weight)
            {
                close_edge[k].weight = g.arc[close_edge[index].end][k];
                close_edge[k].start = close_edge[index].end;
                close_edge[index].end = k;
            }
        }
    }
    cout << sum << endl;
}
int main()
{
    Graph g;
    createGraph(g); //一般为无向网图
    print(g);
    Prim(g, 1);

    return 0;
}



