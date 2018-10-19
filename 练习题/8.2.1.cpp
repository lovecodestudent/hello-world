/************************************************************************
*
* �ļ�����8.2.1.cpp
*
* �ļ����������������ʵ��
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-09-14
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
#define max 100
using namespace std;

/*�ṹ��Ķ���*/

struct node
{
    //�߱���Ķ���
    int vex;     //��ͷ������ڵĽ���λ��
    node *next;  //ָ����һ���߱���
};

/*ͷ���*/
struct vernode
{
    int data;   //��Ŷ�����Ϣ���������������V1��
    node *first;//ָ���һ����ͷ������ڵĽ�����Ϣ
    int indegree;//ͷ���������
};

/*ͼ�Ķ���*/
struct graph
{
    vernode v[max];//ͼ�ģ����㣩ͷ�������
    int vnums;     //������
    int enums;     //����
};

/*��������ͼ���ڽӱ�*/
void creategraph(graph &g, int n, int e)
{
    int i, j, k;
    g.vnums = n;  //������
    g.enums = e;  //����

    for (i = 1; i <= n; i++)
    {
        cin >> g.v[i].data;
        g.v[i].first = NULL;  //��ʼ��ͷ�����ڽӵ�Ϊ��
    }

    for (k = 1; k <= e; k++)
    {
        node *p = new node; //�½�һ����㣬���ڼ��뵽ͷ���֮��
        cin >> i; //���
        cin >> j; //�յ�
        p->vex = j;
        p->next = NULL;
        /*���߽�㴮���������������ı���Ϊͷ���ĵ�һ�������ֱ�Ӳ��룬�����ҵ����һ�������ٲ���*/
        if (g.v[i].first == NULL)
        {
            g.v[i].first = p;
        }
        else
        {
            node *nextp = g.v[i].first; //nextpΪͷ���֮��ĵ�һ������
            while (nextp->next)
            {
                nextp = nextp->next;
            }
            nextp->next = p;
        }
    }
}

/*��ӡ�ڽӱ�*/
void printg(graph g)
{
    int i;
    cout << "ͼ���ڽӱ�Ϊ��" << endl;
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
/*��������*/
bool topsort(graph &g)
{
    queue<int> q;
    node *p;
    int counts = 0;//countsΪ������������������ĸ�����ͼ�еĶ�������������ͼ�л�·
    int i, j;

    /*��ʼ�����Ϊ0*/
    for (i = 1; i <= g.vnums; i++)
    {
        g.v[i].indegree = 0;
    }

    /*���������������*/
    for (i = 1; i <= g.vnums; i++)
    {
        p = g.v[i].first;
        while (p)
        {
            //�������
            g.v[p->vex].indegree++;
            p = p->next;
        }
    }
    for (i = 1; i <= g.vnums; i++)
    {
        if (g.v[i].indegree == 0)
        {
            q.push(i);  //����Ϊ0�Ķ�������У���������е������Ϊ0�Ķ����������е�λ��
        }
    }

    cout << "�������������Ϊ:" << endl;
    while (!q.empty())
    {
        j = q.front(); //���ص�һ��Ԫ��
        q.pop();       //����һ��Ԫ�شӶ���ɾ��
        cout << g.v[j].data << " "; //���ջ��Ԫ��
        counts++;
        p = g.v[j].first;  //��pָ�����Ϊ0�ĵ�һ���ڵ�

        /*���붥��i�����ڶ������ȼ�һ*/
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
        cout << "�������гɹ�" << endl;
    }
    else
    {
        cout << "��������ʧ��" << endl;
    }
    return 0;
}
















