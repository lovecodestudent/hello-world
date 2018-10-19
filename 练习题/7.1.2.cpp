/************************************************************************
*
* �ļ�����7.1.2.cpp
*
* �ļ����������������㷨����Դ���·�����ʺϳ���ͼ
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-09-05
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
#define N 100
#define M 100
using namespace std;

/*�������ṹ*/
typedef struct node
{
    int matrix[N][M];    //�����ڽӾ���
    int v;               //�����
    int e;               //����
}MGraph;

/*���������㷨*/
void Floyd(MGraph g, int path[10][10])
{
    int i, j, k;
    cout << "-----����ǰ·��------" << endl;
    for (i = 1; i <= g.v; i++)
    {
        for (j = 1; j <= g.v; j++)
        {
            /*�������i�Ͷ���j֮�䲻����ͨ·�����������������Сֵ*/
            if (g.matrix[i][j] == 9999)
                cout << "��" << " ";
            else
                cout << g.matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-----���º�path·��------" << endl;
    for (i = 1; i <= g.v; i++)
    {
        for (j = 1; j <= g.v; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }

    /*�������º��Ĵ���5��*/

    //��i�Ŷ��㵽j�Ŷ��㣬ֻ����ǰk�Ŷ�������·��
    for (k = 1; k <= g.v; k++)
        for (i = 1; i <= g.v; i++)
            for(j = 1; j <= g.v; j++)
                if (g.matrix[i][j] > g.matrix[i][k] + g.matrix[k][j])
                {
                    /*������ڶ���kʹ��i��j�ľ����̣�����¾���*/
                    g.matrix[i][j] = g.matrix[i][k] + g.matrix[k][j];
                    path[i][j] = path[i][k];  //����·����Ϊ��˳�����
                }
    cout << "-----���º�·��------" << endl;
    for (i = 1; i <= g.v; i++)
    {
        for (j = 1; j <= g.v; j++)
        {
            if (g.matrix[i][j] == 9999)
                cout << "��" << " ";
            else
                cout << g.matrix[i][j] << " ";
        }
        cout << endl;
    }

    /*��ӡ���º��path*/
    cout << "-----���º�path·��------" << endl;
    for (i = 1; i <= g.v; i++)
    {
        for (j = 1; j <= g.v; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
    /*��ӡ·��*/
    for (i = 1; i <= g.v; i++)
    {
        for (j = 1; j <= g.v; j++)
        {
            if (g.matrix[i][j] == 9999)
            {
                cout << "�ӵ�" << i << "����" << j << "������ͨ·" << endl;
            }
            else
            {
                cout << "�ӵ�" << i << "����" << j << "�����·��Ϊ" << g.matrix[i][j];
                cout << " �����ĵ�Ϊ: " << i << " ";
                /*˳�����·���ϵĶ���*/
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
    int v, e;  //vΪ����eΪ��
    cin >> v >> e;

    int i, j;

    int s, t, w;  //�Ӷ���s������tȨֵΪw

    int path[10][10];
    MGraph g;
    g.e = e;
    g.v = v;
    /*��ʼ��*/
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

    /*�����Ȩ��·��*/
    for (i = 1; i <= e; i++)
    {
        cin >> s >> t >> w;
        g.matrix[s][t] = w;
    }

    Floyd(g, path);
    return 0;
}


