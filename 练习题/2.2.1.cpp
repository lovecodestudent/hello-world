/************************************************************************
*
* 文件名：2.2.1.cpp
*
* 文件描述：栈的顺序存储实现
*
* 创建人：  fdk

* 时  间：  2018-07-30
*
* 版本号：1.0
*
* 修改记录：
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

    /*记录栈顶元素位置的变量*/
    int top;
}stacks;

/*生成空堆栈*/
stacks *CreateStack();

/*进行入栈操作*/
void Push(stacks *ptrs, int x);

/*进行出栈操作*/
int Pop(stacks *ptrs);
int main()
{
    int i;
    int j;
    int a[] = {2, 4, 5, 1, -2, 4, 6, 10};
    stacks *s = CreateStack();

    /*循环进栈*/
    cout << "进栈顺序为：";
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << " ";
        Push(s, a[i]);
    }
    cout << endl;

    /*循环出栈*/
    cout << "出栈顺序为：";
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << Pop(s) << " ";
    }
    cout << endl;
    return 0;
}

/*生成空堆栈*/
stacks *CreateStack()
{
    /*申请一个当前的结构，malloc函数向系统申请分配指定内存的空间*/
    stacks *s = (stacks*)malloc(sizeof(stacks));

    /*当前栈为空栈*/
    s->top = -1;
    return s;
}

/*进行入栈操作*/
void Push(stacks *ptrs, int x)
{
    if (ptrs->top == MAXSIZE - 1)
    {
        cout << "当前栈满！" << endl;
        return;
    }
    else
    {
        /*将值压入并将栈顶指针上移*/
        ptrs->data[++(ptrs->top)] = x;
        return;
    }
}

/*进行出栈操作*/
int Pop(stacks *ptrs)
{
    if (ptrs->top == -1)
    {
        cout << "栈空！" << endl;
        exit(0);
    }
    else
    {
        /*返回栈顶元素并将指针下移*/
        return (ptrs->data[(ptrs->top)--]);
    }
}
