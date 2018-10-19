/************************************************************************
*
* 文件名：3.2.1.cpp
*
* 文件描述：二叉树的建立、插入、删除、遍历（前中后的递归及非递归遍历和层次遍历）、求树高及叶子结点等
*
* 创建人：  fdk

* 时  间：  2018-08-06
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <time.h>
#include <queue>
using namespace std;

/*定义二叉树的结构*/
typedef struct Node
{
    int value; //存储结点的值为整形
    struct Node *left;  //左子树
    struct Node *right; //右子树
}*BTree,btree;

typedef struct Node1
{
    BTree bNode;
    bool isFirst;
} BTNode;

BTree bTree;

/*建立一颗树*/
void CreateTree(int x)
{
    BTree newNode;    //定义一个新的结点
    BTree currentNode; //定义一个当前结点用于比较value的值

    int flag = 0;      //判断当前是否插入新结点，当flag为1时插入结点

    /*给新结点赋值*/
    newNode = (BTree)malloc(sizeof(btree)); //分配空间
    newNode->value = x;
    newNode->left = NULL;
    newNode->right = NULL;

    /*如果当前树为空就将创建的新结点赋值当前树*/
    if (bTree == NULL)
    {
        bTree = newNode;
    }
    else
    {
        currentNode = bTree; //如果不为空就将树的根结点赋值给当前结点

        /*没有插入新结点则一直循环下去*/
        while (!flag)
        {
            /*当前结点的值大于要插入的值，且左子树为空则将新结点插入到当前结点的左子树中*/
            if (currentNode->value > x)
            {
                if (currentNode->left == NULL)
                {
                    currentNode->left = newNode;
                    flag = 1;   //新结点插入后将flag改为1
                }
                else
                {
                    currentNode = currentNode->left; //左子树不为空继续向下遍历
                }
            }
            else
            {
                /*右子树为空则将新结点插入*/
                if (currentNode->right == NULL)
                {
                    currentNode->right = newNode;
                    flag = 1;   //新结点插入后将flag改为1
                }
                else
                {
                    currentNode = currentNode->right;// 不为空则继续遍向下遍历
                }
            }
        }
    }
}

/*递归前序遍历*/
void PreorderTraversal(BTree bTree)
{
    if (bTree)
    {
     /*不为空先输出根结点上的值再递归调用左子树和右子树*/
        cout << bTree->value << " ";
        PreorderTraversal(bTree->left);
        PreorderTraversal(bTree->right);
    }
}

/*非递归前序遍历*/
void PreorderTraversals(BTree bTree)
{
    BTree b;
    stack <BTree> s;      //声明一个栈，栈内元素的类型为BTree
    b = bTree;            //从根结点开始

    /*当树不为空或者堆栈不为空，循环持续下去*/
    while (b || !s.empty())
    {
        /*一直向左并将沿途的结点压入堆栈*/
        while (b)
        {
            cout << b->value << " ";  //打印结点
            s.push(b);
            b = b->left;
        }
        b = s.top();
        s.pop();
        b = b->right;    //转向右子树
    }
}

/*递归中序遍历*/
void InorderTraversal(BTree bTree)
{
    if (bTree)
    {
        InorderTraversal(bTree->left);
        cout << bTree->value << " ";
        InorderTraversal(bTree->right);
    }
}

/*非递归中序遍历*/
void InorderTraversals(BTree bTree)
{
    BTree T;
    stack <BTree> s;
    T = bTree;         //从根结点出发
    while (T || !s.empty())
    {
        /*一直向左并将沿途结点压入堆栈*/
        while (T)
        {
            s.push(T);
            T = T->left;
        }
        T = s.top();
        cout << T->value << " "; //打印结点
        s.pop();          //弹出堆栈
        T = T->right;                //转向右子树
    }
}

/*递归后序遍历*/
void PostorderTraversal(BTree bTree)
{
    if (bTree)
    {
        PostorderTraversal(bTree->left);
        PostorderTraversal(bTree->right);
        cout << bTree->value << " ";
    }
}

/*非递归后序遍历*/
void PostorderTraversals(BTree bTree)
{
    BTree T;
    stack <BTNode*> s;
    T = bTree;        //从根结点开始
    BTNode *temp;
    while (T || !s.empty())
    {
        /*一直向左并将沿途结点压入栈中*/
        while (T)
        {
            BTNode *btn = (BTNode *)malloc(sizeof(BTNode)); //分配空间
            btn->bNode = T;
            btn->isFirst = true;
            s.push(btn);
            T = T->left;
        }
        if (!s.empty())
        {
            /*弹出栈中的元素第一次弹出则重新压入栈中*/
            temp = s.top();
            s.pop();
            if (temp->isFirst)
            {
                temp->isFirst = false;
                s.push(temp);
                T = temp->bNode->right;
            }
            /*第二次弹出则直接输出*/
            else
            {
                cout << temp->bNode->value << " ";
                T = NULL;
            }
        }
    }
}

/*层次遍历*/
void LevelorderTraversal (BTree bTree)
{
    BTree T;
    queue <BTree> q;
    T = bTree;
    if (bTree == NULL)  /*若是空树则跳出程序*/
    {
        exit(-1);
    }

    q.push(T);
    while (!q.empty())
    {
        T = q.front();

        /*输出当前结点的值，并将左右子树添加到队列中*/
        cout << T->value << " ";
        if (T->left)
        {
            q.push(T->left);
        }
        if (T->right)
        {
            q.push(T->right);
        }
        q.pop();      //从队列中删除
    }
}

/*输出二叉树中的所有叶子结点*/
void PreorderPrintLeave(BTree bTree)
{
    if (bTree)
    {
        if (!bTree->left && !bTree->right) //如果bTree结点是叶子结点
        {
            cout << bTree->value << " ";
        }
        PreorderPrintLeave(bTree->left);
        PreorderPrintLeave(bTree->right);
    }
}

/*求二叉树的高度*/
int GetHight(BTree bTree)
{
    int hl;
    int hh;   //右子树高
    int maxh; //最大高度
    if (bTree)
    {
        hl = GetHight(bTree->left);    //返回左子树高
        hh = GetHight(bTree->right);   //返回右子树高
        maxh = hl > hh ? hl : hh;      //取左右子树中较大的高度
        return (maxh + 1);             //返回树的高度
    }
    else
    {
        return 0;    //空树高度为0
    }
}
int main()
{
    int n;
    cin >> n;
    srand(time(NULL));
    int u;
    cout << "随机生成的序列为:";
    for (int i = 0; i < n; i++)
    {
        u = (double)rand() / (RAND_MAX + 1) * (100 - 1) + 1;
        cout << u << " ";
        CreateTree(u);
    }
    cout << endl;

    cout << "递归前序遍历：";
    PreorderTraversal(bTree);
    cout << "非递归前序遍历：";
    PreorderTraversals(bTree);
    cout << endl;

    cout << "递归中序遍历：";
    InorderTraversal(bTree);
    cout << "非递归中序遍历：";
    InorderTraversals(bTree);
    cout << endl;

    cout << "递归后序遍历：";
    PostorderTraversal(bTree);
    cout << "非递归后序遍历：";
    PostorderTraversals(bTree);
    cout << endl;

    cout << "层次遍历：";
    LevelorderTraversal(bTree);
    cout << endl;

    cout << "树的叶子结点为：";
    PreorderPrintLeave(bTree);
    cout << endl;

    cout << "树的高度为：";
    cout << GetHight(bTree);
    return 0;
}










