/************************************************************************
*
* �ļ�����8.1.1.cpp
*
* �ļ���������С������֮Prim�㷨-ʹ���ڽӾ���ʵ��
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-08-15
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

struct Graph
{
    int vexnum;  //�������
    int edge;    //�ߵĸ���
    int ** arc;  //�ڽӾ���
    string *information; //��¼ÿ����������
};

//����ͼ
void createGraph (Graph & g)
{
    cout << "�����붥����������ߵ�����" << endl;
    cin >> g.vexnum; //���붥����
    cin >> g.edge;   //����ߵĸ���
    g.information = new string [g.vexnum];
    g.arc = new int *[g.vexnum];
    int i = 0;

    /*���ٿռ��ͬʱ���������Ƶĳ�ʼ��*/
    for (i = 0; i < g.vexnum; i++)
    {
        g.arc[i] = new int [g.vexnum];
        g.information[i] = "V" + to_string(i+1); //��ÿ���������������to_string����������ת��Ϊstring����

        /*��ʼ���ڽӾ���*/
        for (int k = 0; k < g.vexnum; k++)
        {
            g.arc[i][k] = INT_MAX;
        }

    }

    /*������ͼ����Ȩֵ*/
    cout << "������ÿ�����ϵĶ����ţ������Ŵ�1��ʼ�����Լ��ı��Ȩ�أ�" << endl;
    for (i = 0; i < g.edge; i++)
    {
        int begin;
        int end;
        cin >> begin;
        cin >> end;
        int weight;
        cin >> weight;
        g.arc[begin-1][end-1] = weight; //����ͼ���Ƿ���
        g.arc[end-1][begin-1] = weight;
    }
}

//��ӡͼ
void print (Graph g)
{
    for (int i = 0; i < g.vexnum; i++)
    {
        for (int j = 0; j < g.vexnum; j++)
        {
            if (g.arc[i][j] == INT_MAX)
                cout << "��" << " ";
            else
                cout << g.arc[i][j] << " ";
        }
        cout << endl;
    }
}


/*��Ϊ��¼�ߵ���Ϣ����Щ�߶��Ǵﵽend�����б���Ȩ����С���Ǹ�*/
struct Assis_arry
{
    int start;  //�ߵ����
    int end;    //�ߵ��յ�
    int weight; //�ߵ�Ȩ��
};

/*prim�㷨*/
void Prim(Graph g, int begin)
{
    //close_edge��������¼����ĳ������ĸ������е�Ȩ����С���Ǹ���
    Assis_arry *close_edge = new Assis_arry[g.vexnum];

    int j;

    /*����close_edge��ʼ��,����beginΪ�����ʣ�µ����ж����Ȩֵ��ʼ��*/
    for (j = 0; j < g.vexnum; j++)
    {
        if (j != begin - 1)
        {
            close_edge[j].start = begin - 1;
            close_edge[j].end = j;
            close_edge[j].weight = g.arc[begin-1][j];
        }
    }

    /*������close_edge�е�ֵ����Ϊ-1�������Ѿ����뵽����U��*/
    close_edge[begin-1].weight = -1;

    /*����ʣ�µĶ��㲢���μ��뵽����U��(weightΪ-1)*/
    int sum = 0;
    for (j = 1; j < g.vexnum; j++)
    {
        int min = INT_MAX;
        int k;
        int index;
        //Ѱ������close_edge��Ȩ����С��������
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
        /*��Ȩ����С����һ���ߵ��յ�Ҳ���뵽����U��*/
        close_edge[index].weight = -1;
        //�����Ӧ�ߵ���Ϣ
        cout << g.information[close_edge[index].start] << "-----"
             << g.information[close_edge[index].end]
             << "="
             << g.arc[close_edge[index].start][close_edge[index].end]
             << endl;

        sum += g.arc[close_edge[index].start][close_edge[index].end];

        /*����close_edge����*/
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
    createGraph(g); //һ��Ϊ������ͼ
    print(g);
    Prim(g, 1);

    return 0;
}



