/************************************************************************
*
* 文件名：2.2.5.cpp
*
* 文件描述：队列的链式存储实现
*
* 创建人：  fdk

* 时  间：  2018-07-31
*
* 版本号：1.0
*
* 修改记录：队列和堆栈一样也能采取链式存储，但队列的头fronts必须指向链表的头结点，
*           队列的尾rear指向链表的尾节点
*
*
************************************************************************/
#include <iostream>
#include <cstdlib>
#define MAXSIZE 100
using namespace std;

/*定义链队结点的类型*/
typedef struct Node
{
    int data;
    struct Node *next;
}LinkNode;

/*将头尾指针封装在一起的链队列*/
typedef struct
{
    LinkNode *fronts; //指向队头结点
    LinkNode *rear;   //指向队尾结点
}LinkQueue;

/*初始化*/
void InitLinkQueue(LinkQueue *&q);

/*判断是否为空*/
bool LinkQueueEmpty(LinkQueue *q);

/*入队列*/
void EnLinkQueue(LinkQueue *q,int x);

/*出队列*/
int DeLinkQueue(LinkQueue *q);
int main()
{
    int i;         //for循环变量
    LinkQueue *q;
    InitLinkQueue(q); //初始化
    int a[] = {2, 4, 5, 1, -2, 4, 6, 10};
    int lengths = sizeof(a) / sizeof(a[0]);

    /*入队列*/
    cout << "入队的顺序为：" << endl;
    for (i = 0; i < lengths; i++)
    {
        cout << a[i] << " ";
        EnLinkQueue(q,a[i]);
    }
    cout << endl;
    /*出队列*/
    cout << "出队的顺序为：" << endl;
    while (!LinkQueueEmpty(q))
    {
        cout << DeLinkQueue(q) << " ";
    }
    cout << endl;
    return 0;
}

/*初始化*/
void InitLinkQueue(LinkQueue *&q)
{
    q = (LinkQueue*)malloc(sizeof(LinkQueue));
    LinkNode *p;
    p = (LinkNode*)malloc(sizeof(LinkNode));
    p->next = NULL;
    q->fronts = q->rear = p;
}

/*判断是否为空*/
bool LinkQueueEmpty(LinkQueue *q)
{
    if (q->fronts == q->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*入队列*/
void EnLinkQueue(LinkQueue *q,int x)
{
    /*尾指针只能用来进行添加操作*/
    LinkNode *p;
    p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = x;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

/*出队列*/
int DeLinkQueue(LinkQueue *q)
{
    /*头指针用来进行删除操作*/
    LinkNode *p;
    if (LinkQueueEmpty(q))
    {
        cout << "该队列为空！" << endl;
        exit(-1);
    }
    else
    {
        int temp;               //定义的临时变量用于存储被删除结点的值
        p = q->fronts->next;
        q->fronts->next = p->next;
        temp = p->data;
        if(p->next == NULL)      //当队列中只有一个元素是被删除后需要将头指针和尾指针相等
        {
            q->rear == q->fronts;
        }
        free(p);                //释放该结点并返回该结点的值
        return temp;
    }
}
