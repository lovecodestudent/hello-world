/************************************************************************
*
* 文件名：5.1.1.cpp
*
* 文件描述：堆的建立、插入、删除以及堆排序
*
* 创建人：  fdk

* 时  间：  2018-08-11
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>
using namespace std;
int h[] = {99, 5, 36, 7, 22, 17, 46, 12, 2, 19, 25, 28, 1, 92};  //用来存放堆中元素的数组
int n;          // 堆的大小

/*交换函数用来交换堆中的两个元素的值*/
void Swap (int x, int y)
{
    int temp;
    temp = h[x];
    h[x] = h[y];
    h[y] = temp;
}

/*向下调整函数*/
void SiftDown(int i) //传入一个需要向下调整的结点i，当i为1时即为从堆顶开始向下调整
{
    int t;
    int flag = 0; //flag用来标记是否继续向下调整

    /*当i结点有儿子（其实是至少有左儿子）且需要继续调整的时候循环就执行*/
    while (i * 2 + 1 <= n && flag == 0)
    {
        //首先判断它和左儿子的关系，并用t来记录值较小的结点编号
        if (h[i] > h[i*2+1])
        {
            t = i * 2 + 1;
        }
        else
        {
            t = i;
        }
        /*如果它有右儿子，再对右儿子进行讨论*/
        if (i * 2 + 2 <= n)
        {
            //如果右儿子更小，则更新较小的结点编号
            if (h[t] > h[i*2+2])
            {
                t = i * 2 + 2;
            }
        }
        /*如果发现最小的结点不是自己,说明了子结点中有比父结点更小的*/
        if (t != i)
        {
            Swap(t, i);  //交换t和i
            i = t;       //更新i为刚才的与它交换的儿子结点的编号，便于接下来继续向下调整
        }
        else
        {
            flag = 1;    //否则则说明当前的父结点已经比两个子结点都要小了，不需要再进行调整了
        }
    }
}

/*建立堆函数*/
void Creat()
{
    int i;
    /*从最后一个非叶结点到第一个结点依次进行向下调整*/
    for (i = n / 2; i >= 0; i--)
    {
        SiftDown(i);
    }
}

int DeleteMax()
{
    int t;
    t = h[0];    //用一个临时变量记录堆栈的值
    h[0] = h[n]; //将堆的最后一个点复制到堆顶
    n--;         //堆的元素减少1
    SiftDown(0); //向下调整
    return t;    //返回之前记录的堆的顶点的最小值
}
int main()
{
    n = sizeof(h) / sizeof(h[0]) - 1;
    int num = n;
    cout << n << endl;
    cout << "排序前的序列为：";
    for (int i = 0; i <= num; i++)
    {
        cout << h[i] << " ";
    }
    cout << endl;

    cout << "建堆之后的序列为：";
    Creat();
    for (int i = 0; i <= num; i++)
    {
        cout << h[i] << " ";
    }
    cout << endl;

    cout << "排序后的序列：";
    for (int j = 0; j <= num; j++)
    {
        cout << DeleteMax() << " ";
    }
    cout << endl;
    return 0;
}
