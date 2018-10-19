/************************************************************************
*
* 文件名：2.2.3.cpp
*
* 文件描述：堆栈的链式存储实现
*
* 创建人：  fdk

* 时  间：  2018-07-31
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

/*定义结构体*/
typedef struct Node
{
    int data;
    struct Node *next;
}liststrack;

/*堆栈的初始化*/
liststrack *CreateStack();

/*判断栈是否为空*/
bool IsEmpty(liststrack *ptrs);

/*入栈*/
void Push(liststrack *strs, int x);

/*出栈*/
int Pop(liststrack *ptrs);

/*遍历*/
void TravelListStrack(liststrack *ptrs);

int main()
{
    liststrack *s; //声明一个liststrack类型的指针用于后续操作
    s = CreateStack();
    int i;  //for循环中的变量
    int a[] = {2, 4, 5, 1, -2, 4, 6, 10};
    int lengths = sizeof(a) / sizeof(a[0]);

    /*将元素依次压入栈中*/
    cout << "入栈的顺序为：";
    for (i = 0; i < lengths; i++)
    {
        cout << a[i] << " ";
        Push(s, a[i]); //入栈
    }
    cout << endl;

    /*将栈中的元素依次弹出*/
    cout << "出栈的顺序为：";
    while (s->next != NULL)
    {
        cout << Pop(s) << " "; //出栈
    }
    cout << endl;
    return 0;
}

/*堆栈的初始化*/
liststrack *CreateStack()
{
    /*构建一个堆栈的头结点，并返回指针*/
    liststrack *s;
    s = (liststrack *)malloc(sizeof(liststrack)); //向系统申请分配指定的内存空间
    s->next = NULL;
    return s;
}

/*判断栈是否为空*/
bool IsEmpty(liststrack *ptrs)
{
    /*空返回true，否则返回false*/
    if (ptrs == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*入栈*/
void Push(liststrack *strs, int x)
{
    /*将元素x压入栈中*/
    liststrack *temp;
    temp = (liststrack *)malloc(sizeof(liststrack));  //分配内存空间
    temp->next = strs->next;
    temp->data = x;
    strs->next = temp;
}

/*出栈*/
int Pop(liststrack *ptrs)
{
    liststrack *first; //新建一个liststrack类型的指针用于指向第一个元素
    int temp;
    if (IsEmpty(ptrs))
    {
        cout << "栈空！" << endl;
        exit(0);                 //退出当前程序
    }
    /*获取栈顶元素并将其删除*/
    first = ptrs->next;
    temp = first->data;
    ptrs->next = first->next;
    free(first);     //删除结点
    return temp;
}
