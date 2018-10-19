/************************************************************************
*
* 文件名：2.1.1.cpp
*
* 文件描述：使用线性表的顺序表来实现初始化、查找、插入、删除
*
* 创建人：  凡定坤

* 时  间：  2018-07-28
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/
#include <iostream>
#include <cstdlib>
/*定义最大长度是1000*/
#define MAXSIZE 1000
using namespace std;

/*定义结构体*/
typedef struct
{
    int data[MAXSIZE];
    int last;
}List;

/*初始化函数，建立空的顺序表*/
List* MakeEmpty();

/*查找某一特定值，并返回下标*/
int Find(int x, List* Ptrl);

/*插入，在第i个位置上插入值为X的新元素*/
void Insert(int x, int i, List* Ptrl);

/*删除，删除表上的第i个位置的元素*/
void Delete(int i, List* Ptrl);

/*遍历，将一个顺序表上的所有元素遍历一遍*/
void OutPrint(List* Ptrl);
int main()
{
    int arrays[] = {2, 4, 5, 1, -2, 4, 6, 10};

    List* l = MakeEmpty();

    /*给顺序表赋值*/
    for (int i = 1; i <= 8; i++)
    {
        Insert(arrays[i-1], i, l);
    }
    /*遍历输出*/
    OutPrint(l);

    /*查找第5个位置上的元素*/
    cout << Find(5, l) << endl;

    /*插入在8个位置插入18*/
    Insert(18, 8, l);

    /*删除表上第1个元素*/
    Delete(1, l);

    /*遍历处理后的顺序表*/
    OutPrint(l);
    return 0;
}

/*初始化函数，建立空的顺序表*/
List* MakeEmpty()
{
    List* Ptrl;

    /*申请一个当前的结构，malloc函数向系统申请分配指定内存的空间*/
    Ptrl = (List*)malloc(sizeof (List));

    /*表示当前表没有元素*/
    Ptrl->last = -1;
    return Ptrl;
}

/*查找某一特定值，并返回下标*/
int Find(int x, List* Ptrl)
{
    int i = 0;
    while (i <= Ptrl->last && Ptrl->data[i] != x)
    {
        i++;
    }
    /*如果没有找到，返回-1*/
    if (i > Ptrl->last)
    {
        return -1;
    }
    /*返回下标*/
    else
    {
        return i;
    }
}

/*插入，在第i个位置上插入值为X的新元素*/
void Insert(int x, int i, List* Ptrl)
{
    int j;

    /*如果表满，则不能插入*/
    if (Ptrl->last == MAXSIZE -1)
    {
        cout << "表满不能插入" << endl;
        return;
    }
    if (i < 1 || i > Ptrl->last + 2)
    {
        cout << "位置不合法！" << endl;
        return;
    }
    /*将i-1之后的位置全部后移*/
    for (j = Ptrl->last; j >= i - 1; j--)
    {
        Ptrl->data[j+1] = Ptrl->data[j];
    }
    /*将新元素x插入*/
    Ptrl->data[i-1] = x;

    /*last仍指向最后一个元素*/
    Ptrl->last++;
}

/*删除，删除表上的第i个位置的元素*/
void Delete(int i, List* Ptrl)
{
    int j;
    if (i < 1 || i > Ptrl->last + 1)
    {
        cout << "删除有误，不存在该位置的元素" << endl;
        return;
    }
    /*将第i个位置之后的元素依次往前移动*/
    for (j = i; j <= Ptrl->last; j++)
    {
        Ptrl->data[j-1] = Ptrl->data[j];
    }
    /*last仍指向最后一个元素*/
    Ptrl->last--;
    return;
}

/*遍历，将一个顺序表上的所有元素遍历一遍*/
void OutPrint(List* Ptrl)
{
    for (int i = 0; i <= Ptrl->last; i++)
    {
        cout << Ptrl->data[i] << " ";
    }
    cout << endl;
}
