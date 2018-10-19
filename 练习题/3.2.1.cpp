/************************************************************************
*
* �ļ�����3.2.1.cpp
*
* �ļ��������������Ľ��������롢ɾ����������ǰ�к�ĵݹ鼰�ǵݹ�����Ͳ�α������������߼�Ҷ�ӽ���
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-08-06
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <time.h>
#include <queue>
using namespace std;

/*����������Ľṹ*/
typedef struct Node
{
    int value; //�洢����ֵΪ����
    struct Node *left;  //������
    struct Node *right; //������
}*BTree,btree;

typedef struct Node1
{
    BTree bNode;
    bool isFirst;
} BTNode;

BTree bTree;

/*����һ����*/
void CreateTree(int x)
{
    BTree newNode;    //����һ���µĽ��
    BTree currentNode; //����һ����ǰ������ڱȽ�value��ֵ

    int flag = 0;      //�жϵ�ǰ�Ƿ�����½�㣬��flagΪ1ʱ������

    /*���½�㸳ֵ*/
    newNode = (BTree)malloc(sizeof(btree)); //����ռ�
    newNode->value = x;
    newNode->left = NULL;
    newNode->right = NULL;

    /*�����ǰ��Ϊ�վͽ��������½�㸳ֵ��ǰ��*/
    if (bTree == NULL)
    {
        bTree = newNode;
    }
    else
    {
        currentNode = bTree; //�����Ϊ�վͽ����ĸ���㸳ֵ����ǰ���

        /*û�в����½����һֱѭ����ȥ*/
        while (!flag)
        {
            /*��ǰ����ֵ����Ҫ�����ֵ����������Ϊ�����½����뵽��ǰ������������*/
            if (currentNode->value > x)
            {
                if (currentNode->left == NULL)
                {
                    currentNode->left = newNode;
                    flag = 1;   //�½������flag��Ϊ1
                }
                else
                {
                    currentNode = currentNode->left; //��������Ϊ�ռ������±���
                }
            }
            else
            {
                /*������Ϊ�����½�����*/
                if (currentNode->right == NULL)
                {
                    currentNode->right = newNode;
                    flag = 1;   //�½������flag��Ϊ1
                }
                else
                {
                    currentNode = currentNode->right;// ��Ϊ������������±���
                }
            }
        }
    }
}

/*�ݹ�ǰ�����*/
void PreorderTraversal(BTree bTree)
{
    if (bTree)
    {
     /*��Ϊ�������������ϵ�ֵ�ٵݹ������������������*/
        cout << bTree->value << " ";
        PreorderTraversal(bTree->left);
        PreorderTraversal(bTree->right);
    }
}

/*�ǵݹ�ǰ�����*/
void PreorderTraversals(BTree bTree)
{
    BTree b;
    stack <BTree> s;      //����һ��ջ��ջ��Ԫ�ص�����ΪBTree
    b = bTree;            //�Ӹ���㿪ʼ

    /*������Ϊ�ջ��߶�ջ��Ϊ�գ�ѭ��������ȥ*/
    while (b || !s.empty())
    {
        /*һֱ���󲢽���;�Ľ��ѹ���ջ*/
        while (b)
        {
            cout << b->value << " ";  //��ӡ���
            s.push(b);
            b = b->left;
        }
        b = s.top();
        s.pop();
        b = b->right;    //ת��������
    }
}

/*�ݹ��������*/
void InorderTraversal(BTree bTree)
{
    if (bTree)
    {
        InorderTraversal(bTree->left);
        cout << bTree->value << " ";
        InorderTraversal(bTree->right);
    }
}

/*�ǵݹ��������*/
void InorderTraversals(BTree bTree)
{
    BTree T;
    stack <BTree> s;
    T = bTree;         //�Ӹ�������
    while (T || !s.empty())
    {
        /*һֱ���󲢽���;���ѹ���ջ*/
        while (T)
        {
            s.push(T);
            T = T->left;
        }
        T = s.top();
        cout << T->value << " "; //��ӡ���
        s.pop();          //������ջ
        T = T->right;                //ת��������
    }
}

/*�ݹ�������*/
void PostorderTraversal(BTree bTree)
{
    if (bTree)
    {
        PostorderTraversal(bTree->left);
        PostorderTraversal(bTree->right);
        cout << bTree->value << " ";
    }
}

/*�ǵݹ�������*/
void PostorderTraversals(BTree bTree)
{
    BTree T;
    stack <BTNode*> s;
    T = bTree;        //�Ӹ���㿪ʼ
    BTNode *temp;
    while (T || !s.empty())
    {
        /*һֱ���󲢽���;���ѹ��ջ��*/
        while (T)
        {
            BTNode *btn = (BTNode *)malloc(sizeof(BTNode)); //����ռ�
            btn->bNode = T;
            btn->isFirst = true;
            s.push(btn);
            T = T->left;
        }
        if (!s.empty())
        {
            /*����ջ�е�Ԫ�ص�һ�ε���������ѹ��ջ��*/
            temp = s.top();
            s.pop();
            if (temp->isFirst)
            {
                temp->isFirst = false;
                s.push(temp);
                T = temp->bNode->right;
            }
            /*�ڶ��ε�����ֱ�����*/
            else
            {
                cout << temp->bNode->value << " ";
                T = NULL;
            }
        }
    }
}

/*��α���*/
void LevelorderTraversal (BTree bTree)
{
    BTree T;
    queue <BTree> q;
    T = bTree;
    if (bTree == NULL)  /*���ǿ�������������*/
    {
        exit(-1);
    }

    q.push(T);
    while (!q.empty())
    {
        T = q.front();

        /*�����ǰ����ֵ����������������ӵ�������*/
        cout << T->value << " ";
        if (T->left)
        {
            q.push(T->left);
        }
        if (T->right)
        {
            q.push(T->right);
        }
        q.pop();      //�Ӷ�����ɾ��
    }
}

/*����������е�����Ҷ�ӽ��*/
void PreorderPrintLeave(BTree bTree)
{
    if (bTree)
    {
        if (!bTree->left && !bTree->right) //���bTree�����Ҷ�ӽ��
        {
            cout << bTree->value << " ";
        }
        PreorderPrintLeave(bTree->left);
        PreorderPrintLeave(bTree->right);
    }
}

/*��������ĸ߶�*/
int GetHight(BTree bTree)
{
    int hl;
    int hh;   //��������
    int maxh; //���߶�
    if (bTree)
    {
        hl = GetHight(bTree->left);    //������������
        hh = GetHight(bTree->right);   //������������
        maxh = hl > hh ? hl : hh;      //ȡ���������нϴ�ĸ߶�
        return (maxh + 1);             //�������ĸ߶�
    }
    else
    {
        return 0;    //�����߶�Ϊ0
    }
}
int main()
{
    int n;
    cin >> n;
    srand(time(NULL));
    int u;
    cout << "������ɵ�����Ϊ:";
    for (int i = 0; i < n; i++)
    {
        u = (double)rand() / (RAND_MAX + 1) * (100 - 1) + 1;
        cout << u << " ";
        CreateTree(u);
    }
    cout << endl;

    cout << "�ݹ�ǰ�������";
    PreorderTraversal(bTree);
    cout << "�ǵݹ�ǰ�������";
    PreorderTraversals(bTree);
    cout << endl;

    cout << "�ݹ����������";
    InorderTraversal(bTree);
    cout << "�ǵݹ����������";
    InorderTraversals(bTree);
    cout << endl;

    cout << "�ݹ���������";
    PostorderTraversal(bTree);
    cout << "�ǵݹ���������";
    PostorderTraversals(bTree);
    cout << endl;

    cout << "��α�����";
    LevelorderTraversal(bTree);
    cout << endl;

    cout << "����Ҷ�ӽ��Ϊ��";
    PreorderPrintLeave(bTree);
    cout << endl;

    cout << "���ĸ߶�Ϊ��";
    cout << GetHight(bTree);
    return 0;
}










