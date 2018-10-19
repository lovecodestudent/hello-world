/************************************************************************
*
* �ļ�����4.2.1.cpp
*
* �ļ�������AVL���Ľ����������ɾ��
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-08-10
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
typedef struct AVLNode
{
    int value;             //�������
    struct AVLNode *left;  //ָ��������
    struct AVLNode *right; //ָ��������
    int hight;             //����
}*AVLTree, AVL_Tree;

/*�������ֵ*/
int Max(int a, int b)
{
    return a > b ? a:b;
}

/*��������ĸ߶�*/
int GetHight(AVLTree T)
{
    if (T)
    {
        return (T->hight);             //�������ĸ߶�
    }
    else
    {
        return 0;    //�����߶�Ϊ0
    }
}

/*LL��ת-��������*/
AVLTree SingleLeftRotation(AVLTree A)
{
    /*��A��B��LL��ת������A��B�ĸ߶ȣ������µĸ����B*/
    AVLTree B = A->left;
    A->left = B->right;
    B->right = A;
    A->hight = Max(GetHight(A->left), GetHight(A->right)) + 1;
    B->hight = Max(GetHight(B->left), A->hight) + 1;
    return B;
}

/*RR��ת-���ҵ�����*/
AVLTree SingleRightRotation(AVLTree A)
{
    /*��A��B��RR��ת������A��B�ĸ߶ȣ������µĸ����B*/
    AVLTree B = A->right;
    A->right = B->left;
    B->left = A;
    A->hight = Max(GetHight(A->left), GetHight(A->right)) + 1;
    B->hight = Max(GetHight(B->right), A->hight) + 1;
    return B;
}

/*LR��ת����-��˫����*/
AVLTree DoubleLeftRightRotation(AVLTree A)
{
    /*LR���൱���������ε����������ҵ���ת����������ת*/
    A->left = SingleRightRotation(A->left);  //�ҵ���ת

    return SingleLeftRotation(A);           //����ת
}

/*RL��ת����-��˫����*/
AVLTree DoubleRightLeftRotation(AVLTree A)
{
    /*RL���൱���������ε�������������ת�������ҵ���ת*/
    A->right = SingleLeftRotation(A->right); //����ת
    return SingleRightRotation(A);
}

/*����*/
AVLTree Insert(AVLTree T, int x)
{
    /*��x���뵽AVL���У����ҷ��ص������AVL��*/
    if (T == NULL)
    {
        /*����Ϊ���������½�����һ��������*/
        T = (AVLTree)malloc(sizeof(AVL_Tree));
        T->value = x;
        T->hight = 1;
        T->left = NULL;
        T->right = NULL;
    }
    else
    {
        if (x < T->value)
        {
            /*����T��������*/
            T->left = Insert(T->left, x);

            /*�����Ҫ����*/
            if (GetHight(T->left) - GetHight(T->right) == 2)
            {
                if (x < T->left->value)
                {
                    T = SingleLeftRotation(T);  //����
                }
                else
                {
                    T = DoubleLeftRightRotation(T); //��-��˫��
                }
            }
        }
        else if (x > T->value)
        {
            /*����������*/
            T->right = Insert(T->right, x);

            /*�����Ҫ����*/
            if (GetHight(T->right) - GetHight(T->left) == 2)
            {
                if (x > T->right->value)
                {
                    T = SingleRightRotation(T);     //�ҵ���
                }
                else
                {
                    T = DoubleRightLeftRotation(T);  //��-����ת
                }
            }
        }
        else
        {
            cout << "�ý���Ѵ��ڣ�" << endl;
        }
    }
    T->hight = Max(GetHight(T->left), GetHight(T->right)) + 1; //��������
    return T;
}

/*ɾ�����*/
AVLTree Delete(AVLTree T, int x)
{
    AVLTree temp;
    if (T)        //����Ϊ��
    {
        if (x < T->value)  //XС�ڸý��
        {
            T ->left = Delete(T->left, x); //���xС�ڽ���ֵ�ͼ����ڽ����������еݹ�ɾ��

            if (GetHight(T->right) - GetHight(T->left) == 2)
            {
                if (T->right->left != NULL && GetHight(T->right->left) > GetHight(T->right->right))
                {
                    T = DoubleRightLeftRotation(T); //R-L
                }
                else
                {
                    T = SingleRightRotation(T);    //R-R
                }
            }
        }

        else if (x > T->value)  //Xֵ���ڸý��
        {
            T->right = Delete(T->right, x); //���X���ڽ���ֵ�ͼ����ڽ����������ݹ�ɾ��

            if (GetHight(T->left) - GetHight(T->right) == 2)
            {
                if (T->left->right != NULL && GetHight(T->left->right) > GetHight(T->left->left))
                {
                    T = DoubleLeftRightRotation(T);  //L-R
                }
                else
                {
                    T = SingleLeftRotation(T);   //L-L
                }
            }
        }
        else  //X���ڸý�㣬��Ϊ��ɾ���Ľ��
        {
            if (T->left && T->right) //�˽������������
            {
                /*������������Сֵ�����汻ɾ���Ľ��*/
                temp = T->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                T->value = temp->value;
                T->right = Delete(T->right, temp->value);
                if (GetHight(T->left) - GetHight(T->right) == 2)
                {
                    if (T->left->right && GetHight(T->left->right) > GetHight(T->left->left))
                    {
                        T = DoubleLeftRightRotation(T);  //L-R
                    }
                    else
                    {
                        T = SingleLeftRotation(T);   //L-L
                    }
                }
            }

            else //�˽����һ������û�ж���
            {
                temp = T;
                if (T->left == NULL) //���Ҷ��ӻ���û�ж���
                {
                    T = T->right;
                }
                else
                {
                    T = T->left;
                }
                free(temp);
            }
        }
    }

    T->hight = Max(GetHight(T->left), GetHight(T->right)) + 1;
    return T;
}

/*����ݹ����*/
void InorderTraversal(AVLTree T)
{
    if (T)
    {
        InorderTraversal(T->left);
        cout << T->value << " ";
        InorderTraversal(T->right);
    }
}

/*����ݹ����*/
void PreorderTraversal(AVLTree T)
{
    if (T)
    {
        cout << T->value << " ";
        PreorderTraversal(T->left);
        PreorderTraversal(T->right);
    }
}

int main()
{
    AVLTree T = NULL;
    int a[] = {80, 50, 100, 40, 60, 90, 140, 45, 83, 95, 150, 81};
    int lengths = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < lengths; i++)
    {
       T = Insert(T, a[i]);
    }
    //cout << "ǰ��ݹ������";
    PreorderTraversal(T);
    cout << endl;

    //cout << "����ݹ������";
    InorderTraversal(T);
    cout << endl;

    //cout << "ɾ��140���";
    Delete(T, 140);
    cout << endl;

    //cout << "ǰ��ݹ������";
    PreorderTraversal(T);
    cout << endl;

    //cout << "����ݹ������";
    InorderTraversal(T);
    cout << endl;
    return 0;
}
