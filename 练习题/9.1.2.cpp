/************************************************************************
*
* 文件名：9.1.2.cpp
*
* 文件描述：基数排序
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
using namespace std;

/*获取数组中的最大值*/
int getMax(int a[], int n)
{
    int i, max;
    max = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

/*对数组按照“某个位数”进行桶排序*/
void countSort(int a[], int n, int exp)
{
    int output[n];  //存储被排序数据的临时数组
    int i, buckets[10] = {0};

    /*将数据出现的次数存储在buckets[]中*/
    for (i = 0; i < n; i++)
    {
        buckets[(a[i] / exp) % 10]++;
    }

    /*更改buckets[i]。目的是让更改后的buckets[i]的值，是该数据在output[]中的位置*/
    for (i = 1; i < 10; i++)
    {
        buckets[i] += buckets[i-1];
    }

    /*将数据存储到临时数组output[]中*/
    for (i = n-1; i >= 0; i--)
    {
        output[buckets[(a[i] / exp) % 10]-1] = a[i];
        buckets[(a[i]/exp) % 10] --;
    }

    /*将排序好的数据赋值给a[]*/
    for (i = 0; i < n; i++)
    {
        a[i] = output[i];
    }

}

/*基数排序*/
void radixSort(int a[], int n)
{
    int exp;  //指数。当数组按各位进行排序时，exp = 1; 按十位进行排序时，exp=10
    int max = getMax(a, n); //数组a中的最大值

    //从个位开始，对数组a按指数进行排序
    for (exp = 1; max/exp > 0; exp *= 10)
    {
        countSort(a, n, exp);
    }
}
int main()
{
    int i;
    int a[] = {64, 8, 216, 512, 27, 729, 0, 1, 343, 125};
    int ilen = (sizeof(a)) / (sizeof(a[0]));

    cout << "排序之前的顺序为：";
    for (i = 0; i < ilen; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    radixSort(a, ilen); //基数排序

    cout << "排序之后的顺序为：";
    for (i = 0; i < ilen; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;


    return 0;
}
