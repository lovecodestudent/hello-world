/************************************************************************
*
* 文件名：5.2.1.cpp
*
* 文件描述：最小堆的构建及输出
*
* 创建人：  fdk

* 时  间：  2018-08-12
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#define MINDATA -1;  //该值为哨兵，比堆中最小的元素还要小
using namespace std;
typedef struct HNode *Heap;         //堆的类型定义
typedef Heap MinHeap;               //最小堆
struct HNode
{
    int *data;    //存储元素的数组
    int sizes;    //堆中当前的元素个数
    int capacity; //堆的最大容量
};

/*创建容量为MaxSize的空的最小堆*/
MinHeap CreatHeap(int MaxSize)
{
    MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
    H->data = (int *)malloc((MaxSize + 1) * sizeof(int)); //堆中的正式元素存放是从下标为1开始的
    H->sizes = 0;
    H->capacity = MaxSize;
    H->data[0] = MINDATA;   //定义哨兵为小于堆中所有可能的值

    return H;
}

/*堆是否满*/
bool IsFull(MinHeap H)
{
    return(H->sizes == H->capacity);
}

/*插入操作*/
bool Insert(MinHeap H, int x)
{
    /*将元素x插入最小堆，其中H->data[0]已经定义为哨兵*/
    int i;
    if (IsFull(H))
    {
        cout << "最小堆已满!" << endl;
        return false;
    }
    i = ++H->sizes; //i指向插入后，堆中的最后一个元素的位置
    for (; H->data[i / 2] > x; i /= 2)
    {
        H->data[i] = H->data[i/2];   //上滤x
    }
    H->data[i] = x;  //将x插入
    return true;
}

/*堆是否为空*/
bool IsEmpty(MinHeap H)
{
    return (H->sizes == 0);
}

/*从最小堆中取出一个结点，并删除一个结点*/
int DeleteMin(MinHeap H)
{
    /*从最小堆H中取出键值为最小的元素，并删除一个结点*/
    int parent;  //父结点
    int child;   //子结点
    int MinItem; //返回的最小元素，也就是根结点
    int x;       //堆中的最后一个元素
    if (IsEmpty(H))
    {
        cout << "最小堆为空！" << endl;
        return -1;
    }
    MinItem = H->data[1]; //取出根结点存放的最大值
    /*用最小堆中的最后一个元素从根结点开始从上到下过滤下层结点*/
    x = H->data[H->sizes--]; //当前堆的规模要减小
    for (parent = 1; parent * 2 <= H->sizes; parent = child)
    {
        child = parent * 2;
        if ((child != H->sizes) && (H->data[child] > H->data[child+1]))
        {
            child++;   //去左右子结点中最小的
        }
        if (x <= H->data[child])
        {
            break;  //找到了合适的位置
        }
        else
        {
            /*下滤*/
            H->data[parent] = H->data[child];
        }
    }
    H->data[parent] = x;

    return MinItem;
}

/*过滤函数与删除函数基本相同（一般将过滤函数写完后，删除函数直接调用，这里为了加深理解多写一遍）*/
void PercDown(MinHeap H, int p)
{
    /*下滤，将H中以H->[p]为根结点的子堆调整为最小堆*/
    int parent;  //父结点
    int child;   //子结点
    int x;
    x = H->data[p]; //取出根结点存放的值
    for (parent = p; parent * 2 <= H->sizes; parent = child)
    {
        child = parent * 2;
        if ((child != H->sizes) && (H->data[child] > H->data[child+1]))
        {
            child++;   //去左右子结点中最小的
        }
        if (x <= H->data[child])
        {
            break;  //找到了合适的位置
        }
        else
        {
            /*下滤*/
            H->data[parent] = H->data[child];
        }
    }
    H->data[parent] = x;
}

/*建堆*/
void BuildHeap(MinHeap H)
{
    /*调整H->data[]中的所有元素，使满足最小堆的有序性*/
    /*这里假设所有H->sizes中的所有元素已经存在在H->data[]中*/
    int i;

    /*从最后一个结点的父结点开始，到根结点*/
    for (i = H->sizes / 2; i > 0; i--)
    {
        PercDown(H, i);
    }
}

int main()
{
    int arr[] = {-1, 99, 5, 36, 7, 22, 17, 46, 12, 2, 19, 25, 28, 1, 92};
    int length = sizeof(arr) / sizeof(arr[0]);

    /*建立最小堆*/
    MinHeap heap;
    heap = CreatHeap(length);
    heap->data = arr;
    heap->sizes = length;
    BuildHeap(heap);
    for (int i = 1; i < length; i++)
    {
        cout << DeleteMin(heap) << " ";
    }
    cout << endl;
    return 0;
}
