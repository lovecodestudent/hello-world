/************************************************************************
*
* 文件名：2.2.2.cpp
*
* 文件描述：请用一个数组实现两个堆栈，要求最大地利用数组空间，使数组只要有空间入栈操作就可以成功
*
* 创建人：  fdk

* 时  间：  2018-07-30
*
* 版本号：1.0
*
* 修改记录：两个指针分别对应数组的首尾然后向中间移动，可以最大程度的利用空间
*
************************************************************************/
#include <iostream>
#include <cstdlib>

/*定义数组的最大长度为100*/
#define MAXSIZE 100
using namespace std;

/*定义结构体*/
typedef struct
{
    /*一维数组*/
    int data[MAXSIZE];

    /*堆栈1的栈顶指针*/
    int top1;

    /*堆栈2的栈顶指针*/
    int top2;
}stacks;

/*生成空堆栈*/
stacks *CreateStack(int maxs);

/*进行入栈操作*/
void Push(stacks *ptrs, int x, int tag);

/*进行出栈操作*/
int Pop(stacks *ptrs, int tag, int maxs);
int main()
{
    int i;
    int j;
    int k;
    int a[] = {2, 4, 5, 1, -2, 4, 6, 10};

    /*得到当前数组的长度*/
    int maxs = sizeof(a) / sizeof(a[0]);
    cout << maxs << endl;
    stacks *s = CreateStack(maxs);
    cout << s->top1 << " " << s->top2 << endl;//输出

    /*将奇数位置上的元素存入到栈1*/
    for (i = 0; i < maxs; i = i + 2)
    {
        Push(s, a[i], 1);
    }
    /*将偶数位置上的元素存入到栈2*/
    for (j = 1; j < maxs; j = j + 2)
    {
        Push(s, a[j], 2);
    }
    /*将栈中的所有元素弹出*/
    int m = maxs / 2;
    while (m != 0)
    {
        cout << Pop(s, 1, maxs) << " ";
        cout << Pop(s, 2, maxs) << " ";
        m--;
    }
    return 0;
}

/*生成空堆栈*/
stacks *CreateStack(int maxs)
{
    /*申请一个当前的结构，malloc函数向系统申请分配指定内存的空间*/
    stacks *s = (stacks*)malloc(sizeof(stacks));

    /*当前栈1为空栈*/
    s->top1 = -1;

    /*当前栈2为空栈*/
    s->top2 = maxs;
    return s;
}

/*进行入栈操作*/
void Push(stacks *ptrs, int x, int tag)
{
    /*tag作为区分两个堆栈的标志，取值为1和2，当top2-top1等于1时为栈满*/
    if (ptrs->top2 - ptrs->top1 == 1)
    {
        cout << "栈满！" << endl;
        return;
    }
    if (tag == 1)
    {
        /*对第一个栈进行入栈操作*/
        ptrs->data[++(ptrs->top1)] = x;
    }
    else
    {
        /*对第二个栈进行入栈操作*/
        ptrs->data[--(ptrs->top2)] = x;
    }
}

/*进行出栈操作*/
int Pop(stacks * ptrs, int tag, int maxs)
{
    if (tag == 1)
    {
        /*对栈1进行出栈操作*/
        if (ptrs->top1 == -1)
        {
            cout << "栈空！" << endl;
            exit(0);
        }
        else
        {
            return ptrs->data[(ptrs->top1)--];
        }
    }
    else
    {
        /*对栈2进行出栈操作*/
        if (ptrs->top2 == maxs)
        {
            cout << "栈空！" << endl;
            exit(0);
        }
        else
        {
            return ptrs->data[(ptrs->top2)++];
        }
    }
}
