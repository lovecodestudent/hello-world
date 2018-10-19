/************************************************************************
*
* 文件名：4.2.1.cpp
*
* 文件描述：AVL树的建立，插入和删除
*
* 创建人：  fdk

* 时  间：  2018-08-10
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

/*定义树的结构*/
typedef struct AVLNode
{
    int value;             //结点数据
    struct AVLNode *left;  //指向左子树
    struct AVLNode *right; //指向右子树
    int hight;             //树高
}*AVLTree, AVL_Tree;

/*返回最大值*/
int Max(int a, int b)
{
    return a > b ? a:b;
}

/*求二叉树的高度*/
int GetHight(AVLTree T)
{
    if (T)
    {
        return (T->hight);             //返回树的高度
    }
    else
    {
        return 0;    //空树高度为0
    }
}

/*LL旋转-（左单旋）*/
AVLTree SingleLeftRotation(AVLTree A)
{
    /*将A与B做LL旋转，更新A与B的高度，返回新的根结点B*/
    AVLTree B = A->left;
    A->left = B->right;
    B->right = A;
    A->hight = Max(GetHight(A->left), GetHight(A->right)) + 1;
    B->hight = Max(GetHight(B->left), A->hight) + 1;
    return B;
}

/*RR旋转-（右单旋）*/
AVLTree SingleRightRotation(AVLTree A)
{
    /*将A与B做RR旋转，更新A与B的高度，返回新的根结点B*/
    AVLTree B = A->right;
    A->right = B->left;
    B->left = A;
    A->hight = Max(GetHight(A->left), GetHight(A->right)) + 1;
    B->hight = Max(GetHight(B->right), A->hight) + 1;
    return B;
}

/*LR旋转（左-右双旋）*/
AVLTree DoubleLeftRightRotation(AVLTree A)
{
    /*LR就相当于做了两次单旋，先是右单旋转，再是左单旋转*/
    A->left = SingleRightRotation(A->left);  //右单旋转

    return SingleLeftRotation(A);           //左单旋转
}

/*RL旋转（右-左双旋）*/
AVLTree DoubleRightLeftRotation(AVLTree A)
{
    /*RL就相当于做了两次单旋，先是左单旋转，再是右单旋转*/
    A->right = SingleLeftRotation(A->right); //左单旋转
    return SingleRightRotation(A);
}

/*插入*/
AVLTree Insert(AVLTree T, int x)
{
    /*将x插入到AVL树中，并且返回调整后的AVL树*/
    if (T == NULL)
    {
        /*若树为空树，则新建包含一个结点的树*/
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
            /*插入T的左子树*/
            T->left = Insert(T->left, x);

            /*如果需要左旋*/
            if (GetHight(T->left) - GetHight(T->right) == 2)
            {
                if (x < T->left->value)
                {
                    T = SingleLeftRotation(T);  //左单旋
                }
                else
                {
                    T = DoubleLeftRightRotation(T); //左-右双旋
                }
            }
        }
        else if (x > T->value)
        {
            /*插入右子树*/
            T->right = Insert(T->right, x);

            /*如果需要右旋*/
            if (GetHight(T->right) - GetHight(T->left) == 2)
            {
                if (x > T->right->value)
                {
                    T = SingleRightRotation(T);     //右单旋
                }
                else
                {
                    T = DoubleRightLeftRotation(T);  //右-左旋转
                }
            }
        }
        else
        {
            cout << "该结点已存在！" << endl;
        }
    }
    T->hight = Max(GetHight(T->left), GetHight(T->right)) + 1; //更新树高
    return T;
}

/*删除结点*/
AVLTree Delete(AVLTree T, int x)
{
    AVLTree temp;
    if (T)        //树不为空
    {
        if (x < T->value)  //X小于该结点
        {
            T ->left = Delete(T->left, x); //如果x小于结点的值就继续在结点的左子树中递归删除

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

        else if (x > T->value)  //X值大于该结点
        {
            T->right = Delete(T->right, x); //如果X大于结点的值就继续在结点的右子树递归删除

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
        else  //X等于该结点，即为该删除的结点
        {
            if (T->left && T->right) //此结点有两个儿子
            {
                /*用右子树的最小值来代替被删除的结点*/
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

            else //此结点有一个或者没有儿子
            {
                temp = T;
                if (T->left == NULL) //有右儿子或者没有儿子
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

/*中序递归遍历*/
void InorderTraversal(AVLTree T)
{
    if (T)
    {
        InorderTraversal(T->left);
        cout << T->value << " ";
        InorderTraversal(T->right);
    }
}

/*中序递归遍历*/
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
    //cout << "前序递归遍历：";
    PreorderTraversal(T);
    cout << endl;

    //cout << "中序递归遍历：";
    InorderTraversal(T);
    cout << endl;

    //cout << "删除140结点";
    Delete(T, 140);
    cout << endl;

    //cout << "前序递归遍历：";
    PreorderTraversal(T);
    cout << endl;

    //cout << "中序递归遍历：";
    InorderTraversal(T);
    cout << endl;
    return 0;
}
