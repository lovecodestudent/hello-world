/************************************************************************
*
* 文件名：4.1.1.cpp
*
* 文件描述：二叉排序树（搜索树）的建立、插入、查找、删除
*
* 创建人：  fdk

* 时  间：  2018-08-08
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
typedef struct BSTNode
{
    int value;
    BSTNode *left;
    BSTNode *right;
}BS_Tree, *BSTree;

/*对二叉树进行插入操作*/
BSTree InsertBSTree(BSTree bsTree, int x);

/*对二叉树进行删除操作*/
BSTree DeleteBSTree(BSTree bsTree, int x);

/*对二叉树进行查找操作(递归)*/
BSTree FindBSTree(BSTree bsTree, int x);

/*对二叉树进行查找操作(非递归)*/
BSTree FindBSTree_s(BSTree bsTree, int x);

/*找到树中最大的元素并返回对应的值(递归)*/
BSTree FindMaxBSTree(BSTree bsTree);

/*找到树中最大的元素并返回对应的值(非递归)*/
BSTree FindMaxBSTree_s(BSTree bsTree);

/*找到树中最小的元素并返回对应的值(递归)*/
BSTree FindMinBSTree(BSTree bsTree);

/*找到树中最小的元素并返回对应的值(非递归)*/
BSTree FindMinBSTree_s(BSTree bsTree);

/*前序递归遍历*/
void PreorderTraversal(BSTree bsTree);

/*中序递归遍历*/
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

    cout << "前序遍历：";
    PreorderTraversal(bs_Tree);
    cout << endl;

    cout << "最大的元素为：" << FindMaxBSTree(bs_Tree)->value << endl;
    cout << "最小的元素为：" << FindMinBSTree_s(bs_Tree)->value << endl;

    cout << "插入节点34：" << endl;
    bs_Tree = InsertBSTree(bs_Tree, 34);

    cout << "前序遍历：";
    PreorderTraversal(bs_Tree);
    cout << endl;

    cout << "查找结点34：";
    cout << FindBSTree(bs_Tree, 34)->value << endl;

    cout << "查找结点41：";
    cout << FindBSTree_s(bs_Tree, 41)->value << endl;

    cout << "删除结点41：" << endl;
    bs_Tree = DeleteBSTree(bs_Tree, 41);
    //cout << bs_Tree->value << endl;
    cout << "前序遍历：";
    PreorderTraversal(bs_Tree);
    return 0;
}

/*对二叉树进行插入操作*/
BSTree InsertBSTree(BSTree bsTree, int x)
{
    /*如果树为空，创建并返回一个结点的二叉排序树*/
    if (bsTree == NULL)
    {
        bsTree = (BSTree)malloc(sizeof(BS_Tree));
        bsTree->value = x;
        bsTree->left = NULL;
        bsTree->right = NULL;
    }
    else
    {
        /*小于根结点往左子树遍历*/
        if (bsTree->value > x)
        {
            bsTree->left = InsertBSTree(bsTree->left, x); //递归插入左子树
        }
        /*大于根结点往右子树遍历*/
        else if (bsTree->value < x)
        {
            bsTree->right = InsertBSTree(bsTree->right, x); //递归插入右子树
        }
        else
        {
            cout << "该结点已存在！" << endl;
        }
    }
    return bsTree;
}

/*对二叉树进行删除操作*/
BSTree DeleteBSTree(BSTree bsTree, int x)
{
    BSTree temp;
    if (bsTree)   //树不为空
    {
        if (x < bsTree->value)
        {
            bsTree->left = DeleteBSTree(bsTree->left, x);   //从左子树递归删除
        }
        else if (x > bsTree->value)
        {
            bsTree->right = DeleteBSTree(bsTree->right, x);  //从右子树递归删除
        }
        else  //查找到了删除结点
        {
            /*当左右结点都存在时，一种是选择左子树的最大值，另一种是选择右子树的最小值*/
            /*本文采用左子树的最大值*/
            if(bsTree->left && bsTree->right)
            {
                /*找到左子树的的最大元素填充删除结点*/
                temp = FindMaxBSTree(bsTree->left);
                bsTree->value = temp->value;

                /*从左子树中删除最大元素*/
                bsTree->left = DeleteBSTree(bsTree->left, bsTree->value);
            }
            else   /*被删除结点有一个或者没有结点*/
            {
                temp = bsTree;
                if (!bsTree->left)           //只有右孩子或者无子结点
                {
                    bsTree = bsTree->right;
                }
                else                         //只有左孩子
                {
                    bsTree = bsTree->left;
                }
                free(temp);
            }
        }
    }
    return bsTree;
}

/*对二叉树进行查找操作(递归)*/
BSTree FindBSTree(BSTree bsTree, int x)
{
    if (bsTree)
    {
        /*查找的结点小于父结点*/
        if (bsTree->value > x)
        {
            return FindBSTree(bsTree->left, x);  //左子树递归查找
        }
        else if (bsTree->value < x)
        {
            return FindBSTree(bsTree->right, x); // 右子树递归查找
        }
    }
    else
    {
        cout << "树为空！" << endl;
        exit(-1);
    }
    return bsTree;
}

/*对二叉树进行查找操作(非递归)*/
BSTree FindBSTree_s(BSTree bsTree, int x)
{
    while (bsTree)
    {
        if (bsTree->value > x)
        {
            bsTree = bsTree->left; //往左子树查找
        }
        else if (bsTree->value < x)
        {
            bsTree = bsTree->right; //往右子树查找
        }
        else
        {
            break;
        }
    }
    return bsTree;
}

/*找到树中最大的元素并返回对应的值(递归)*/
BSTree FindMaxBSTree(BSTree bsTree)
{
    /*最大元素在右端点*/
    if (!bsTree)
    {
        cout << "树为空！" << endl;    //空的二叉搜索树退出当前程序
        exit(-1);
    }
    else if (!bsTree->right)
    {
        return bsTree;                //找到最右边的端点并返回
    }
    else
    {
        return FindMaxBSTree(bsTree->right); //递归向右边搜索
    }
}

/*找到树中最大的元素并返回对应的值(非递归)*/
BSTree FindMaxBSTree_s(BSTree bsTree)
{
    if (bsTree)   /*树不为空，向右遍历找到最右边的结点并返回*/
    {
        while (bsTree->right)
        {
            bsTree = bsTree->right;
        }
        return bsTree;
    }
    else
    {
        cout << "树为空！" << endl;
        return NULL;
    }
}

/*找到树中最小的元素并返回对应的值(递归)*/
BSTree FindMinBSTree(BSTree bsTree)
{
    /*最小元素在最左边结点*/
    if (!bsTree)
    {
        cout << "树为空！" << endl;  //空的二叉搜索树退出当前程序
        return NULL;
    }
    else if (!bsTree->left)
    {
        return bsTree;              //找到最左边的结点并返回
    }
    else
    {
        return FindMinBSTree(bsTree->left);  //递归向左边搜索
    }
}

/*找到树中最小的元素并返回对应的值(非递归)*/
BSTree FindMinBSTree_s(BSTree bsTree)
{
    if (bsTree)   /*树不为空，向左遍历找到最左边的结点并返回*/
    {
        while (bsTree->left)
        {
            bsTree = bsTree->left;
        }
        return bsTree;
    }
    else
    {
        cout << "树为空！" << endl;
        return NULL;
    }
}


/*前序递归遍历*/
void PreorderTraversal(BSTree bsTree)
{
    if (bsTree)
    {
     /*不为空先输出根结点上的值再递归调用左子树和右子树*/
        cout << bsTree->value << " ";
        PreorderTraversal(bsTree->left);
        PreorderTraversal(bsTree->right);
    }
}

/*中序递归遍历*/
void InorderTraversal(BSTree bTree)
{
    if (bTree)
    {
        InorderTraversal(bTree->left);
        cout << bTree->value << " ";
        InorderTraversal(bTree->right);
    }
}
