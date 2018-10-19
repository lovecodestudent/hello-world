/************************************************************************
*
* �ļ�����7.1.1.cpp
*
* �ļ�������Dijkstra�㷨��ʵ�֣��þ�ûд�����ˣ������һ����ʺ�codeing���ʺ�paper��
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-09-03
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
#define M 100
#define N 100
using namespace std;

typedef struct node
{
    int matrix[N][M];    //�ڽӾ���
    int n;               //������
    int e;               //����
}MGraph;

void DijkstraPath(MGraph g, int *dist, int *path, int v0) //v0��ʾԭ����
{
    int i, j, k;
    bool visited[g.n];
    for (i = 0; i < g.n; i++)    //��ʼ��
    {
        if (g.matrix[v0][i] > 0 && i != v0)
        {
            dist[i] = g.matrix[v0][i];
            path[i] = v0;              //path��¼���·����v0��i��ǰһ������
        }
        else
        {
            dist[i] = INT_MAX;         //���i����v0ֱ����������ȨֵΪ�����
            path[i] = -1;
        }
        visited[i] = false;            //��ʼ����δ�����ʹ�
    }
    dist[v0] = 0;                      //��ʼ����̾���Ϊ0
    visited[v0] = true;

    for (i = 0; i < g.n; i++)          //ѭ����չn-1��
    {
        int min = INT_MAX;
        int u;
        for (j = 0; j < g.n; j++)     //Ѱ��δ����չ�ĵ�Ȩֵ��С�Ķ���
        {
            if (visited[j] == false && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = true;

        /*����dist�����ֵ��·����ֵ*/
        for (k = 0; k < g.n; k++)
        {
            if (visited[k] == false && g.matrix[u][k] > 0 && min + g.matrix[u][k] < dist[k])
            {
                dist[k] = min + g.matrix[u][k];   //����¼���Ľ��ʹ��k�Ľ��ֵ��С�����
                path[k] = u;
            }
        }

    }
}


void showPrint(int *path, int v, int v0)
{
    /*��ӡʱ��Ҫ�Ӻ���ǰ�Ƶ������ö�ջ��ʵ��˳�����*/
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
    int n, e; //nΪ��������eΪ����
    while (cin >> n >> e && e != 0)
    {
        int i, j;
        int s, t, w; //��ʾ����һ����s->t,ȨֵΪw
        MGraph g;
        int v0;

        int *dist = new int[n]; //��̾���
        int *path = new int[n]; //·��
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
        cin >> v0;              //����Դ����
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


