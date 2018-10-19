/************************************************************************
*
* 文件名：2.1.2.cpp
*
* 文件描述：线性表（链表）的查找、插入、删除
*
* 创建人：  凡定坤

* 时  间：  2018-07-28
*
* 版本号：1.0
*
* 修改记录：头结点的作用：
1、防止单链表是空的而设的.当链表为空的时候,带头结点的头指针就指向头结点.如果当链表为空的时候,单链表没有带头结点,那么它的头指针就为NULL.
2、是为了方便单链表的特殊操作,插入在表头或者删除第一个结点.这样就保持了单链表操作的统一性!
3、单链表加上头结点之后，无论单链表是否为空，头指针始终指向头结点，因此空表和非空表的处理也统一了，方便了单链表的操作，也减少了程序的复杂性和出现bug的机会。
4、对单链表的多数操作应明确对哪个结点以及该结点的前驱。不带头结点的链表对首元结点、中间结点分别处理等；而带头结点的链表因为有头结点，首元结点、中间结点的操作相同 ,从而减少分支，使算法变得简单 ,流程清晰。对单链表进行插入、删除操作时，如果在首元结点之前插入或删除的是首元结点，不带头结点的单链表需改变头指针的值，在C 算法的函数形参表中头指针一般使用指针的指针(在C+ +中使用引用 &)；而带头结点的单链表不需改变头指针的值，函数参数表中头结点使用指针变量即可。
单链表的掌握还不够熟练，需要多加练习。特别是建表的方法不仅要看懂更要能写出来。
*
************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

/*定义结点*/
typedef struct Node
{
    int data;
    struct Node* next;
}lists;

/*初始化链表*/
lists *MakeEmpty();

/*尾插法建表*/
void CreatList(lists *ptrl, int a[]);

/*求表长*/
int Length(lists *ptrl);

/*按序号查找*/
lists *FindKth(int k, lists *ptrl);

/*按值查找*/
int Find(int x, lists *ptrl);

/*插入在第i-1个结点后插入一个值为x的新结点*/
void Insert(int x, int i, lists *ptrl);

/*删除i位置上的结点*/
void Delete(int i, lists *ptrl);

/*遍历链表*/
void TravelList(lists *ptrl);
int main()
{
    int a[] = {2, 4, 5, 1, -2, 4, 6, 10};

    /*初始化链表*/
    lists *l = MakeEmpty();

    CreatList(l, a);

    /*遍历链表*/
    TravelList(l);

    /*求链表的长度*/
    cout << "链表的长度为：" << Length(l) << endl;

    /*按序号查找第k个位置上的元素*/
    lists* p1 = FindKth(4, l);
    cout << "第4个位置上的元素为：" << p1->data << endl;

    /*按值查找值为1的元素所在的位置*/
    cout << "值为1的元素所在的位置为：" << Find(1, l) << endl;

    /*在第i个位置后插入一个值为7的结点*/
    Insert(7, 1, l);

    Insert(15, 2, l);

    /*删除第8个位置上的元素*/
    Delete(8, l);

    /*遍历链表*/
    TravelList(l);
    return 0;
}

/*初始化链表*/
lists *MakeEmpty()
{
    lists* Ptrl;

    /*申请一个当前的结构，malloc函数向系统申请分配指定内存的空间*/
    Ptrl = (lists*)malloc(sizeof (lists));
    if (Ptrl == NULL)
    {
        cout << "初始化失败" << endl;
        exit(-1);
    }
    /*表示当前表没有元素*/
    Ptrl->next = NULL;
    return Ptrl;
}

/*求表长*/
int Length(lists *ptrl)
{
    /*p指向的是表的第一个结点*/
    lists *p = ptrl->next;
    int num = 0;
    while (p)
    {
        /*当前p指向的是第j个结点*/
        p = p->next;
        num++;
    }
    return num;
}

/*按序号查找*/
lists *FindKth(int k, lists *ptrl)
{
    lists *p = ptrl->next;
    int num = 1;
    while (p != NULL && num < k)
    {
        p = p->next;
        num++;
    }
    if (num == k)
    {
        /*如果找到返回指针*/
        return p;
    }
    else
    {
        /*如果没有找到返回NULL*/
        return NULL;
    }
}

/*按值查找*/
int Find(int x, lists *ptrl)
{
    lists *p = ptrl->next;
    int num = 1;
    while (p->data != x && p != NULL)
    {
        p = p->next;
        num++;
    }
    /*找到了返回对应的指针没找到返回NULL*/
    return num;
}

/*插入在第i-1个结点后插入一个值为x的新结点*/
void Insert(int x, int i, lists *ptrl)
{
    /*s用来当插入结点的头结点*/
    lists *s;

    /*p用来找到第i-1个结点*/
    lists *p;

    if( i == 1)
    {
        /*新结点插在表头*/
        s = (lists *)malloc(sizeof(lists));
        /*申请、装填结点*/
        s->data = x;
        s->next = ptrl->next;
        ptrl->next = s;
        return;
    }
    /*查找第i-1个结点的位置*/
    p = FindKth(i-1, ptrl);

    if (p == NULL)
    {
        cout << "参数出错！" << endl;
        return;
    }
    else
    {
        s = (lists *)malloc(sizeof(lists));
        /*插入第i个结点*/
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}

/*删除i位置上的结点*/
void Delete(int i, lists *ptrl)
{
    /*用来找到第i-1个结点的位置*/
    lists *p;

    /*用来删除第一个结点*/
    lists *s;

    /*若要删除的是第一个结点*/
    if (i == 1)
    {
        /*s指向第一个结点*/
        s = ptrl;

       /*从链表中删除*/
       if (ptrl != NULL)
       {
           ptrl = ptrl->next;
       }
       else
       {
           return;
       }
       free(s);
    }

    /*查找第i个结点*/
    p = FindKth(i-1, ptrl);
    if (p == NULL)
    {
        cout << "第" << i -1 << "个结点不存在" << endl;
        return;
    }
    else if (p->next == NULL)
    {
        cout << "第" << i << "个结点不存在" << endl;
    }
    else
    {
        /*s指向第i个结点*/
        s = p->next;

        /*从链表中删除*/
        p->next = s->next;

        /*释放被删除结点*/
        free(s);
    }
}

/*遍历链表*/
void TravelList(lists *ptrl)
{
    lists* p = ptrl->next;
    cout << "链表中的元素依次为：";
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

/*尾插法建表*/
void CreatList(lists *ptrl, int a[])
{
    /*尾插法的建表顺序与输入一致，头插法则想反*/
    int i;

    /*新建结点*/
    lists *pnew;
    lists *p;
    p = ptrl;
    for (i = 1; i <= 8; i++)
    {
        /*申请装填结点*/
        pnew = (lists *)malloc(sizeof(lists));
        cout << a[i-1] << endl;
        pnew->data = a[i-1];

        /*新结点插入表尾*/
        p->next = pnew;
        p = pnew;
    }
    p->next = NULL;
}
