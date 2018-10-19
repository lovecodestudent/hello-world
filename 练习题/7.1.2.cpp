/************************************************************************
*
* 文件名：7.1.2.cpp
*
* 文件描述：弗洛伊德算法（多源最短路径）适合稠密图
*
* 创建人：  fdk

* 时  间：  2018-09-05
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
#define N 100
#define M 100
using namespace std;

/*定义矩阵结构*/
typedef struct node
{
    int matrix[N][M];    //定义邻接矩阵
    int v;               //结点数
    int e;               //边数
}MGraph;

/*弗洛伊德算法*/
void Floyd(MGraph g, int path[10][10])
{
    int i, j, k;
    cout << "-----更新前路径------" << endl;
    for (i = 1; i <= g.v; i++)
    {
        for (j = 1; j <= g.v; j++)
        {
            /*如果顶点i和顶点j之间不存在通路则输出无穷，否则输出最小值*/
            if (g.matrix[i][j] == 9999)
                cout << "∞" << " ";
            else
                cout << g.matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-----更新后path路径------" << endl;
    for (i = 1; i <= g.v; i++)
    {
        for (j = 1; j <= g.v; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }

    /*弗洛伊德核心代码5行*/

    //从i号顶点到j号顶点，只经过前k号顶点的最短路程
    for (k = 1; k <= g.v; k++)
        for (i = 1; i <= g.v; i++)
            for(j = 1; j <= g.v; j++)
                if (g.matrix[i][j] > g.matrix[i][k] + g.matrix[k][j])
                {
                    /*如果存在顶点k使得i到j的距离变短，则更新距离*/
                    g.matrix[i][j] = g.matrix[i][k] + g.matrix[k][j];
                    path[i][j] = path[i][k];  //更新路径，为了顺序输出
                }
    cout << "-----更新后路径------" << endl;
    for (i = 1; i <= g.v; i++)
    {
        for (j = 1; j <= g.v; j++)
        {
            if (g.matrix[i][j] == 9999)
                cout << "∞" << " ";
            else
                cout << g.matrix[i][j] << " ";
        }
        cout << endl;
    }

    /*打印更新后的path*/
    cout << "-----更新后path路径------" << endl;
    for (i = 1; i <= g.v; i++)
    {
        for (j = 1; j <= g.v; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
    /*打印路径*/
    for (i = 1; i <= g.v; i++)
    {
        for (j = 1; j <= g.v; j++)
        {
            if (g.matrix[i][j] == 9999)
            {
                cout << "从点" << i << "到点" << j << "不存在通路" << endl;
            }
            else
            {
                cout << "从点" << i << "到点" << j << "的最短路径为" << g.matrix[i][j];
                cout << " 经过的点为: " << i << " ";
                /*顺序输出路径上的顶点*/
                k = path[i][j];
                while (k != j)
                {
                    cout << k << " ";
                    k = path[k][j];
                }
                cout << j;
            }
            cout << endl;
        }
    }
}


int main()
{
    int v, e;  //v为顶点e为边
    cin >> v >> e;

    int i, j;

    int s, t, w;  //从顶点s到顶点t权值为w

    int path[10][10];
    MGraph g;
    g.e = e;
    g.v = v;
    /*初始化*/
    for (i = 1; i <= v; i++)
    {
        for (j = 1; j <= v; j++)
        {
            if (i == j)
                g.matrix[i][j] = 0;
            else
                g.matrix[i][j] = 9999;
            path[i][j] = j;
        }
    }

    /*输入带权的路径*/
    for (i = 1; i <= e; i++)
    {
        cin >> s >> t >> w;
        g.matrix[s][t] = w;
    }

    Floyd(g, path);
    return 0;
}


