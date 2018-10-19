/************************************************************************
*
* 文件名：7.1.1.cpp
*
* 文件描述：Dijkstra算法的实现（好久没写代码了，看来我还是适合codeing不适合paper）
*
* 创建人：  fdk

* 时  间：  2018-09-03
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
#define M 100
#define N 100
using namespace std;

typedef struct node
{
    int matrix[N][M];    //邻接矩阵
    int n;               //顶点数
    int e;               //边数
}MGraph;

void DijkstraPath(MGraph g, int *dist, int *path, int v0) //v0表示原顶点
{
    int i, j, k;
    bool visited[g.n];
    for (i = 0; i < g.n; i++)    //初始化
    {
        if (g.matrix[v0][i] > 0 && i != v0)
        {
            dist[i] = g.matrix[v0][i];
            path[i] = v0;              //path记录最短路径上v0到i的前一个顶点
        }
        else
        {
            dist[i] = INT_MAX;         //如果i不与v0直接相连，则权值为无穷大
            path[i] = -1;
        }
        visited[i] = false;            //初始化都未被访问过
    }
    dist[v0] = 0;                      //初始化最短距离为0
    visited[v0] = true;

    for (i = 0; i < g.n; i++)          //循环扩展n-1次
    {
        int min = INT_MAX;
        int u;
        for (j = 0; j < g.n; j++)     //寻找未被扩展的的权值最小的顶点
        {
            if (visited[j] == false && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = true;

        /*更新dist数组的值和路径的值*/
        for (k = 0; k < g.n; k++)
        {
            if (visited[k] == false && g.matrix[u][k] > 0 && min + g.matrix[u][k] < dist[k])
            {
                dist[k] = min + g.matrix[u][k];   //如果新加入的结点使得k的结点值变小则更新
                path[k] = u;
            }
        }

    }
}


void showPrint(int *path, int v, int v0)
{
    /*打印时需要从后往前推导，借用堆栈来实现顺序输出*/
    stack<int> s;
    int u = v;
    while (v != v0)
    {
        s.push(v);
        v = path[v];
    }
    s.push(v);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
int main()
{
    int n, e; //n为顶点数，e为边数
    while (cin >> n >> e && e != 0)
    {
        int i, j;
        int s, t, w; //表示存在一条边s->t,权值为w
        MGraph g;
        int v0;

        int *dist = new int[n]; //最短距离
        int *path = new int[n]; //路径
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                g.matrix[i][j] = 0;
            }
        }
        g.n = n;
        g.e = e;
        for (i = 0; i < e; i++)
        {
            cin >> s >> t >> w;
            g.matrix[s][t] = w;
        }
        cin >> v0;              //输入源顶点
        DijkstraPath(g, dist ,path , v0);
        for (i = 0; i < n; i++)
        {
            if (i != v0)
            {
                showPrint(path, i, v0);
                cout << dist[i] << endl;
            }
        }
    }
    return 0;
}


