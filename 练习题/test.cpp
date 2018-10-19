#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
int main()
{
    int i;
    for (i=0; i<5; i++)
    {
        if (i==3)
            break;
        cout << i << " ";
    }
    cout << endl;

    for (i=0; i<=5; i++)
    {
        if (i==3)
            continue;
        cout << i << " ";
    }
    return 0;
}
//void QuickSort(int *a, int left, int right)
//{
//    int temp, i, j, t;
//    if (left > right)
//        return;
//    temp = a[left];
//    i = left;
//    j = right;
//    while (i != j)
//    {
//        while (a[j] >= temp && i < j)
//            j--;
//        while (a[i] <= temp && i < j)
//            i++;
//        if (i < j)
//        {
//            t = a[j];
//            a[j] = a[i];
//            a[i] = t;
//        }
//    }
//    a[left] = a[i];
//    a[i] = temp;
//    QuickSort(a, left, i - 1);
//    QuickSort(a, i + 1, right);
//}
//int main()
//{
//    int n;
//    cin >> n;
//    int arr[100];
//    srand(time(NULL));
//    int u;
//    for (int i = 0; i < n; i++)
//    {
//        u = (double)rand() / (RAND_MAX + 1) * (100 - 1) + 1;
//        arr[i] = u;
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//    QuickSort(arr, 0, n);
//    for (int i = 0; i < n; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//    return 0;
//}
//
//
//
//
//
//建一颗树，判别其他序列是否与其一致
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
//typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */
//
//typedef struct TreeNode *Tree;
//struct TreeNode
//{
//    ElemType data;
//    Tree left,right;
//    int flag;    //被访问过为1 否则0
//};
//
//Tree NewNode(ElemType data);
//Tree Insert(Tree T,ElemType data);
//Tree MakeTree(int N);
//bool check (Tree T,ElemType data);
//int Judge(Tree T,int N);
//void ResetT(Tree T);
//void FreeTree(Tree T);
//
//Tree NewNode(ElemType data)
//{
//    Tree T = (Tree)malloc(sizeof(struct TreeNode));
//    T->data = data;
//    T->left = T->right = NULL;
//    T->flag = 0;
//    return T;
//}
//
//Tree Insert(Tree T,ElemType data)
//{
//    if( !T )
//        T = NewNode(data);
//    else {
//        if(data > T->data)
//            T->right = Insert(T->right, data);
//        else
//            T->left = Insert(T->left, data);
//    }
//    return T;
//}
//
//Tree MakeTree(int N)
//{
//    Tree T;
//    ElemType data;
//    scanf("%d",&data);
//    T = NewNode(data);
//    for(int i = 1; i < N; i++) {
//        scanf("%d",&data);
//        T = Insert(T,data);
//    }
//    return T;
//}
//
//bool check (Tree T,ElemType data)
//{
//    if(T->flag) {
//        if(data < T->data)
//            return check(T->left,data);
//        else if(data > T->data)
//            return check(T->right,data);
//    }else {
//        if(data == T->data) {    //是要找的结点
//            T->flag = 1;
//            return true;
//        }
//        else return false;            //不是 不一致
//    }
//}
//
//int Judge(Tree T,int N)
//{
//    ElemType data;
//    int flag = 0;//0代表目前仍一致 1代表已经不一致
//    scanf("%d",&data);
//    if(data != T->data)    //    判断根节点是否一致
//        flag = 1;
//    else T->flag = 1;
//    for(int i = 1; i < N; i++) {    //确保L读完
//        scanf("%d",&data);
//        if( (!flag) && (!check(T,data)) )    //不一致
//            flag = 1;
//    }
//    if(flag)     //不一致
//        return 0;
//    else return 1;
//}
//
//void ResetT(Tree T)//清除T中各结点的flag标记
//{
//    if(T->left)
//        ResetT(T->left);
//    if(T->right)
//        ResetT(T->right);
//    T->flag = 0;
//}
//
//void FreeTree(Tree T) //释放T的空间
//{
//    if(T->left)
//        FreeTree(T->left);
//    if(T->right)
//        FreeTree(T->right);
//    free(T);
//}
//
//int main()
//{
//    int N, L;
//    Tree T;
//    scanf("%d",&N);
//    while(N) {
//        scanf("%d",&L);
//        T = MakeTree(N);
//        for(int i = 0; i < L; i++) {
//            if(Judge(T, N))
//                printf("Yes\n");
//            else
//                printf("No\n");
//            ResetT(T);        //清除T中的标记flag
//        }
//        FreeTree(T);
//        scanf("%d",&N);
//    }
//
//    return 0;
//}
