/************************************************************************
*
* 文件名：9.1.1.cpp
*
* 文件描述：桶排序
*
* 创建人：  fdk

* 时  间：  2018-09-25
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

void BucketSort(int a[], int length)
{
    int i, j, t;
    /*初始化为0*/
    for (i = 0; i <= length; i++)
    {
        a[i] = 0;
    }
    int num;//输入元素的个数
    cin >> num;
    for (j = 0; j < num; j++)
    {
        cin >> t;
        a[t]++;
    }
    /*输出打印*/
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < a[i]; j++)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
int main()
{
    int a[11];
    BucketSort(a, 10);
    return 0;
}
