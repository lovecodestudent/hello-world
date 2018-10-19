/************************************************************************
*
* �ļ�����4.1.1.cpp
*
* �ļ����������������������������Ľ��������롢���ҡ�ɾ��
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-08-08
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

/*�������Ľṹ*/
typedef struct BSTNode
{
    int value;
    BSTNode *left;
    BSTNode *right;
}BS_Tree, *BSTree;

/*�Զ��������в������*/
BSTree InsertBSTree(BSTree bsTree, int x);

/*�Զ���������ɾ������*/
BSTree DeleteBSTree(BSTree bsTree, int x);

/*�Զ��������в��Ҳ���(�ݹ�)*/
BSTree FindBSTree(BSTree bsTree, int x);

/*�Զ��������в��Ҳ���(�ǵݹ�)*/
BSTree FindBSTree_s(BSTree bsTree, int x);

/*�ҵ���������Ԫ�ز����ض�Ӧ��ֵ(�ݹ�)*/
BSTree FindMaxBSTree(BSTree bsTree);

/*�ҵ���������Ԫ�ز����ض�Ӧ��ֵ(�ǵݹ�)*/
BSTree FindMaxBSTree_s(BSTree bsTree);

/*�ҵ�������С��Ԫ�ز����ض�Ӧ��ֵ(�ݹ�)*/
BSTree FindMinBSTree(BSTree bsTree);

/*�ҵ�������С��Ԫ�ز����ض�Ӧ��ֵ(�ǵݹ�)*/
BSTree FindMinBSTree_s(BSTree bsTree);

/*ǰ��ݹ����*/
void PreorderTraversal(BSTree bsTree);

/*����ݹ����*/
void InorderTraversal(BSTree bTree);

int main()
{
    BSTree bs_Tree = NULL;
    int a[] = {30, 15, 41, 33, 50, 35};
    int lengths = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < lengths; i++)
    {
       bs_Tree = InsertBSTree(bs_Tree, a[i]);
    }

    cout << "ǰ�������";
    PreorderTraversal(bs_Tree);
    cout << endl;

    cout << "����Ԫ��Ϊ��" << FindMaxBSTree(bs_Tree)->value << endl;
    cout << "��С��Ԫ��Ϊ��" << FindMinBSTree_s(bs_Tree)->value << endl;

    cout << "����ڵ�34��" << endl;
    bs_Tree = InsertBSTree(bs_Tree, 34);

    cout << "ǰ�������";
    PreorderTraversal(bs_Tree);
    cout << endl;

    cout << "���ҽ��34��";
    cout << FindBSTree(bs_Tree, 34)->value << endl;

    cout << "���ҽ��41��";
    cout << FindBSTree_s(bs_Tree, 41)->value << endl;

    cout << "ɾ�����41��" << endl;
    bs_Tree = DeleteBSTree(bs_Tree, 41);
    //cout << bs_Tree->value << endl;
    cout << "ǰ�������";
    PreorderTraversal(bs_Tree);
    return 0;
}

/*�Զ��������в������*/
BSTree InsertBSTree(BSTree bsTree, int x)
{
    /*�����Ϊ�գ�����������һ�����Ķ���������*/
    if (bsTree == NULL)
    {
        bsTree = (BSTree)malloc(sizeof(BS_Tree));
        bsTree->value = x;
        bsTree->left = NULL;
        bsTree->right = NULL;
    }
    else
    {
        /*С�ڸ����������������*/
        if (bsTree->value > x)
        {
            bsTree->left = InsertBSTree(bsTree->left, x); //�ݹ����������
        }
        /*���ڸ����������������*/
        else if (bsTree->value < x)
        {
            bsTree->right = InsertBSTree(bsTree->right, x); //�ݹ����������
        }
        else
        {
            cout << "�ý���Ѵ��ڣ�" << endl;
        }
    }
    return bsTree;
}

/*�Զ���������ɾ������*/
BSTree DeleteBSTree(BSTree bsTree, int x)
{
    BSTree temp;
    if (bsTree)   //����Ϊ��
    {
        if (x < bsTree->value)
        {
            bsTree->left = DeleteBSTree(bsTree->left, x);   //���������ݹ�ɾ��
        }
        else if (x > bsTree->value)
        {
            bsTree->right = DeleteBSTree(bsTree->right, x);  //���������ݹ�ɾ��
        }
        else  //���ҵ���ɾ�����
        {
            /*�����ҽ�㶼����ʱ��һ����ѡ�������������ֵ����һ����ѡ������������Сֵ*/
            /*���Ĳ��������������ֵ*/
            if(bsTree->left && bsTree->right)
            {
                /*�ҵ��������ĵ����Ԫ�����ɾ�����*/
                temp = FindMaxBSTree(bsTree->left);
                bsTree->value = temp->value;

                /*����������ɾ�����Ԫ��*/
                bsTree->left = DeleteBSTree(bsTree->left, bsTree->value);
            }
            else   /*��ɾ�������һ������û�н��*/
            {
                temp = bsTree;
                if (!bsTree->left)           //ֻ���Һ��ӻ������ӽ��
                {
                    bsTree = bsTree->right;
                }
                else                         //ֻ������
                {
                    bsTree = bsTree->left;
                }
                free(temp);
            }
        }
    }
    return bsTree;
}

/*�Զ��������в��Ҳ���(�ݹ�)*/
BSTree FindBSTree(BSTree bsTree, int x)
{
    if (bsTree)
    {
        /*���ҵĽ��С�ڸ����*/
        if (bsTree->value > x)
        {
            return FindBSTree(bsTree->left, x);  //�������ݹ����
        }
        else if (bsTree->value < x)
        {
            return FindBSTree(bsTree->right, x); // �������ݹ����
        }
    }
    else
    {
        cout << "��Ϊ�գ�" << endl;
        exit(-1);
    }
    return bsTree;
}

/*�Զ��������в��Ҳ���(�ǵݹ�)*/
BSTree FindBSTree_s(BSTree bsTree, int x)
{
    while (bsTree)
    {
        if (bsTree->value > x)
        {
            bsTree = bsTree->left; //������������
        }
        else if (bsTree->value < x)
        {
            bsTree = bsTree->right; //������������
        }
        else
        {
            break;
        }
    }
    return bsTree;
}

/*�ҵ���������Ԫ�ز����ض�Ӧ��ֵ(�ݹ�)*/
BSTree FindMaxBSTree(BSTree bsTree)
{
    /*���Ԫ�����Ҷ˵�*/
    if (!bsTree)
    {
        cout << "��Ϊ�գ�" << endl;    //�յĶ����������˳���ǰ����
        exit(-1);
    }
    else if (!bsTree->right)
    {
        return bsTree;                //�ҵ����ұߵĶ˵㲢����
    }
    else
    {
        return FindMaxBSTree(bsTree->right); //�ݹ����ұ�����
    }
}

/*�ҵ���������Ԫ�ز����ض�Ӧ��ֵ(�ǵݹ�)*/
BSTree FindMaxBSTree_s(BSTree bsTree)
{
    if (bsTree)   /*����Ϊ�գ����ұ����ҵ����ұߵĽ�㲢����*/
    {
        while (bsTree->right)
        {
            bsTree = bsTree->right;
        }
        return bsTree;
    }
    else
    {
        cout << "��Ϊ�գ�" << endl;
        return NULL;
    }
}

/*�ҵ�������С��Ԫ�ز����ض�Ӧ��ֵ(�ݹ�)*/
BSTree FindMinBSTree(BSTree bsTree)
{
    /*��СԪ��������߽��*/
    if (!bsTree)
    {
        cout << "��Ϊ�գ�" << endl;  //�յĶ����������˳���ǰ����
        return NULL;
    }
    else if (!bsTree->left)
    {
        return bsTree;              //�ҵ�����ߵĽ�㲢����
    }
    else
    {
        return FindMinBSTree(bsTree->left);  //�ݹ����������
    }
}

/*�ҵ�������С��Ԫ�ز����ض�Ӧ��ֵ(�ǵݹ�)*/
BSTree FindMinBSTree_s(BSTree bsTree)
{
    if (bsTree)   /*����Ϊ�գ���������ҵ�����ߵĽ�㲢����*/
    {
        while (bsTree->left)
        {
            bsTree = bsTree->left;
        }
        return bsTree;
    }
    else
    {
        cout << "��Ϊ�գ�" << endl;
        return NULL;
    }
}


/*ǰ��ݹ����*/
void PreorderTraversal(BSTree bsTree)
{
    if (bsTree)
    {
     /*��Ϊ�������������ϵ�ֵ�ٵݹ������������������*/
        cout << bsTree->value << " ";
        PreorderTraversal(bsTree->left);
        PreorderTraversal(bsTree->right);
    }
}

/*����ݹ����*/
void InorderTraversal(BSTree bTree)
{
    if (bTree)
    {
        InorderTraversal(bTree->left);
        cout << bTree->value << " ";
        InorderTraversal(bTree->right);
    }
}
