/************************************************************************
*
* �ļ�����8.1.2.cpp
*
* �ļ���������С������֮��³˹�����㷨��Kruskal��
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-09-13
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

/*����ṹ����*/
struct edge
{
    int u;
    int v;
    int w;
}; //Ϊ�˷����������ﴴ����һ���ṹ�������洢�ߵĹ�ϵ

struct edge e[20];//�ṹ����Ĵ�С����ʵ����������ã�Ҫ�ȱߵ�������

int n, m; //nΪ����ĸ�����mΪ�ߵĸ���

int f[7] = {0};
int sum = 0, counts = 0;  //���鼯��һЩ����������Ĵ�СҪ����ʵ������趨��Ҫ�ȶ�������һ

/*�������򣬰�Ȩֵ��С��������*/
void QuickSort(int left, int right)
{
    int i, j;
    struct edge t;
    if (left > right)
    {
        return;
    }
    i = left;
    j = right;

    while (i != j)
    {
        //��׼��Ϊ��߻���Ҫ���ұ߿�ʼ��
        while (e[j].w >= e[i].w && i < j)
        {
            j--;
        }

        //�ٴ���߿�ʼ��
        while (e[i].w <= e[j].w && i < j)
        {
            i++;
        }
        //����
        if (i < j)
        {
            t = e[i];
            e[i] = e[j];
            e[j] = t;
        }
    }
    //���ս���׼����λ����left��i����
    t = e[left];
    e[left] = e[i];
    e[i] = t;

    QuickSort(left, i-1); //����������ߵģ�������һ���ݹ���õĹ���
    QuickSort(i+1, right);//���������ұߵģ�������һ���ݹ���õĹ���
    return;
}

/*���鼯Ѱ�����Ⱥ���*/
int getf(int v)
{
    if (f[v] == v)
    {
        return v;
    }
    else
    {
        //������·��ѹ��
        f[v] = getf(f[v]);
        return f[v];
    }
}

//���鼯�ϲ����Ӽ��ϵĺ���
int merge(int v, int u)
{
    int t1, t2;
    t1 = getf(v);
    t2 = getf(u);
    if (t1 != t2) //�ж��������Ƿ���ͬһ��������
    {
        f[t2] = t1;
        return 1;
    }
    return 0;
}
int main()
{
    int i;

    /*���뵽n��m��n��ʾ���������m��ʾ�ߵĸ���*/
    cin >> n >> m;

    /*�����Ȩ��*/
    for (i = 1; i <= m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    QuickSort(1, m); //��Ȩֵ��С������п�������

    //���鼯��ʼ��
    for (i = 1; i <= n; i++)
    {
        f[i] = i;
    }

    /*Kruscal�㷨���Ĳ���*/
    for (i = 1; i <= m; i++) //��ʼ��С����ö��ÿһ����
    {
        //�ж�һ���ߵ����������Ƿ���ͨ�����ж��Ƿ���ͬһ��������
        if (merge(e[i].u, e[i].v))
        {
            counts++;
            sum = sum + e[i].w;
        }
        if (counts == n-1)
        {
            break;
        }
    }
    cout << sum << endl;
    return 0;
}
