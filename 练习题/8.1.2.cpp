/************************************************************************
*
* 文件名：8.1.2.cpp
*
* 文件描述：最小生成树之克鲁斯卡尔算法（Kruskal）
*
* 创建人：  fdk

* 时  间：  2018-09-13
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

/*定义结构类型*/
struct edge
{
    int u;
    int v;
    int w;
}; //为了方便排序，这里创建了一个结构体用来存储边的关系

struct edge e[20];//结构数组的大小根据实际情况来设置，要比边的数量大

int n, m; //n为顶点的个数，m为边的个数

int f[7] = {0};
int sum = 0, counts = 0;  //并查集的一些变量。数组的大小要根据实际情况设定，要比顶点数多一

/*快速排序，把权值从小到大排序*/
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
        //基准数为左边话，要从右边开始找
        while (e[j].w >= e[i].w && i < j)
        {
            j--;
        }

        //再从左边开始找
        while (e[i].w <= e[j].w && i < j)
        {
            i++;
        }
        //交换
        if (i < j)
        {
            t = e[i];
            e[i] = e[j];
            e[j] = t;
        }
    }
    //最终将基准数归位，将left和i互换
    t = e[left];
    e[left] = e[i];
    e[i] = t;

    QuickSort(left, i-1); //继续处理左边的，这里是一个递归调用的过程
    QuickSort(i+1, right);//继续处理右边的，这里是一个递归调用的过程
    return;
}

/*并查集寻找祖先函数*/
int getf(int v)
{
    if (f[v] == v)
    {
        return v;
    }
    else
    {
        //这里是路径压缩
        f[v] = getf(f[v]);
        return f[v];
    }
}

//并查集合并两子集合的函数
int merge(int v, int u)
{
    int t1, t2;
    t1 = getf(v);
    t2 = getf(u);
    if (t1 != t2) //判断两个点是否在同一个集合中
    {
        f[t2] = t1;
        return 1;
    }
    return 0;
}
int main()
{
    int i;

    /*读入到n和m，n表示顶点个数，m表示边的个数*/
    cin >> n >> m;

    /*读入带权边*/
    for (i = 1; i <= m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    QuickSort(1, m); //按权值从小到大进行快速排序

    //并查集初始化
    for (i = 1; i <= n; i++)
    {
        f[i] = i;
    }

    /*Kruscal算法核心部分*/
    for (i = 1; i <= m; i++) //开始从小到大枚举每一条边
    {
        //判断一条边的两个顶点是否连通，即判断是否再同一个集合中
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
