/************************************************************************
*
* 文件名：8.2.1.cpp
*
* 文件描述：拓扑排序的实现
*
* 创建人：  fdk

* 时  间：  2018-09-14
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
#define max 100
using namespace std;

/*结构体的定义*/

struct node
{
    //边表结点的定义
    int vex;     //与头结点相邻的结点的位置
    node *next;  //指向下一个边表结点
};

/*头结点*/
struct vernode
{
    int data;   //存放顶点信息（顶点的名称例如V1）
    node *first;//指向第一个与头结点相邻的结点的信息
    int indegree;//头结点的入度数
};

/*图的定义*/
struct graph
{
    vernode v[max];//图的（顶点）头结点数组
    int vnums;     //顶点数
    int enums;     //边数
};

/*创建有向图的邻接表*/
void creategraph(graph &g, int n, int e)
{
    int i, j, k;
    g.vnums = n;  //顶点数
    g.enums = e;  //边数

    for (i = 1; i <= n; i++)
    {
        cin >> g.v[i].data;
        g.v[i].first = NULL;  //初始化头结点的邻接点为空
    }

    for (k = 1; k <= e; k++)
    {
        node *p = new node; //新建一个结点，用于加入到头结点之后
        cin >> i; //起点
        cin >> j; //终点
        p->vex = j;
        p->next = NULL;
        /*将边结点串联起来，如果加入的表结点为头结点的第一个结点则直接插入，否则找到最后一个表结点再插入*/
        if (g.v[i].first == NULL)
        {
            g.v[i].first = p;
        }
        else
        {
            node *nextp = g.v[i].first; //nextp为头结点之后的第一个表结点
            while (nextp->next)
            {
                nextp = nextp->next;
            }
            nextp->next = p;
        }
    }
}

/*打印邻接表*/
void printg(graph g)
{
    int i;
    cout << "图的邻接表为：" << endl;
    for (i = 1; i <= g.vnums; i++)
    {
        cout << g.v[i].data << ":" << " ";
        node *now;
        now = g.v[i].first;
        while (now)
        {
            cout << now->vex << " ";
            now = now->next;
        }
        cout << endl;
    }
}
/*拓扑排序*/
bool topsort(graph &g)
{
    queue<int> q;
    node *p;
    int counts = 0;//counts为计数器，如果输出顶点的个数与图中的顶点数不相等则该图有回路
    int i, j;

    /*初始化入度为0*/
    for (i = 1; i <= g.vnums; i++)
    {
        g.v[i].indegree = 0;
    }

    /*计算各个顶点的入度*/
    for (i = 1; i <= g.vnums; i++)
    {
        p = g.v[i].first;
        while (p)
        {
            //计算入度
            g.v[p->vex].indegree++;
            p = p->next;
        }
    }
    for (i = 1; i <= g.vnums; i++)
    {
        if (g.v[i].indegree == 0)
        {
            q.push(i);  //将度为0的顶点入队列，这里入队列的是入度为0的顶点在数组中的位置
        }
    }

    cout << "拓扑排序的序列为:" << endl;
    while (!q.empty())
    {
        j = q.front(); //返回第一个元素
        q.pop();       //将第一个元素从队列删除
        cout << g.v[j].data << " "; //输出栈顶元素
        counts++;
        p = g.v[j].first;  //让p指向入度为0的第一个节点

        /*将与顶点i的相邻顶点的入度减一*/
        while (p)
        {
            g.v[p->vex].indegree--;
            if (g.v[p->vex].indegree == 0)
            {
                q.push(p->vex);
            }
            p = p->next;
        }
    }
    cout << endl;

    if (counts != g.vnums)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    graph g;
    creategraph(g, 6, 8);
    printg(g);
    if (topsort(g))
    {
        cout << "拓扑序列成功" << endl;
    }
    else
    {
        cout << "拓扑序列失败" << endl;
    }
    return 0;
}
















