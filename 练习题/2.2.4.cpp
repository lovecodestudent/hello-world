/************************************************************************
*
* 文件名：2.2.4.cpp
*
* 文件描述：循环队列的顺序存储实现（创建、插入、删除）
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

/*定义数组的最大长度为100*/
#define MAXSIZE 100
using namespace std;
typedef struct
{
    int data[MAXSIZE];
    int rear;    /*队尾指针*/
    int fronts; /*队首指针*/
}queues;

/*队列的初始化*/
queues *CreateQueue();

/*入队操作*/
bool AddQ(queues *ptrq, int x);

/*出队操作*/
int DeleteQ(queues *ptrq);
int main()
{
    int i; //for循环变量
    queues *s; //声明一个queues型指针用于后续操作
    s = CreateQueue();
    int a[] = {2, 4, 5, 1, -2, 4, 6, 10};
    int lengths = sizeof(a) / sizeof(a[0]);

    /*入队列*/
    cout << "入队的顺序为：" << endl;
    for (i = 0; i < lengths; i++)
    {
        cout << a[i] << " ";
        AddQ(s,a[i]);
    }
    cout << endl;
    /*出队列*/
    cout << "出队的顺序为：" << endl;
    while (s->rear != s->fronts)
    {
        cout << DeleteQ(s) << " ";
    }
    cout << endl;
    return 0;
}

/*队列的初始化*/
queues *CreateQueue()
{
    /*初始队列的创建*/
    queues *q;
    q = (queues*)malloc(sizeof(queues));
    q->fronts = 0; //空队列时首指针和尾指针都为0
    q->rear = 0;
}

/*入队操作*/
bool AddQ(queues *ptrq, int x)
{
    /*判断队列是否为满队列*/
    if ((ptrq->rear + 1) % MAXSIZE == ptrq->fronts)
    {
        cout << "队列满！"<< endl;
        return false;
    }
    else
    {
        /*加1取余顺序循环*/
        ptrq->rear = (ptrq->rear +1) % MAXSIZE;
        ptrq->data[ptrq->rear] = x;
        return true;
    }
}

/*出队操作*/
int DeleteQ(queues *ptrq)
{
    /*判断队列是否为空*/
    if (ptrq->fronts == ptrq->rear)
    {
        cout << "队列为空：" << endl;
        exit(0);
    }
    else
    {
        /*由于第一个位置不用来存放元素所以下标要加1*/
        ptrq->fronts = (ptrq->fronts + 1) % MAXSIZE;
        return ptrq->data[ptrq->fronts];
    }
}
