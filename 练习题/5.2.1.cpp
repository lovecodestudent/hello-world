/************************************************************************
*
* 文件名：5.2.1.cpp
*
* 文件描述：哈夫曼树
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
#define MAXSIZE 164
#define MinData -100
using namespace std;
typedef struct HTNode Node; //哈夫曼树类型
struct HTNode
{
    int weight;  //结点权值
    Node *left;  //指向左子树
    Node *right; //指向右子树
};

typedef struct HNode Heap;         //堆的类型定义
struct HNode
{
    int sizes;    //堆中当前的元素个数
    Node datas[MAXSIZE];
};


Node * CreateNode(int v)
{
    Node * node = (Node*)malloc(sizeof(struct HTNode));
    node->weight = v;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/*插入操作*/
void Insert(Heap *MinHeap, Node *node)
{
    /*将元素x插入最小堆，其中H->datas[0]已经定义为哨兵*/
    int i;
    i = ++MinHeap->sizes; //i指向插入后，堆中的最后一个元素的位置
    for (; MinHeap->datas[i / 2].weight > node->weight; i /= 2)
    {
        MinHeap->datas[i] = MinHeap->datas[i/2];   //上滤
    }
    MinHeap->datas[i] = *node;  //将新结点插入
}

/*创建最小堆*/
Heap * BuildHeap(int arr[], int n)
{
    Heap * MinHeap = (Heap*)malloc(sizeof(struct HNode));
    MinHeap->sizes = 0;
    MinHeap->datas[0] = *CreateNode(MinData);

    for (int i = 0; i < n; i++)
    {
        Node * node = CreateNode(arr[i]);
        Insert(MinHeap, node);
    }
    return MinHeap;
}




/*从最小堆中取出一个结点，并删除一个结点*/
Node * DeleteMin(Heap * minHeap)
{
    /*从最小堆中取出键值为最小的元素，并删除一个结点*/
    int sizes = minHeap->sizes;


    int resultsizes = minHeap->sizes--;
    Node * datas = minHeap->datas;
    Node lastnode = minHeap->datas[sizes];

    Node *firstnode = CreateNode(datas[1].weight);
    firstnode->left = datas[1].left;
    firstnode->right = datas[1].right;

    int parent;  //父结点
    int child;   //子结点
    for (parent = 1; parent * 2 <= resultsizes; parent = child)
    {
        child = parent * 2;
        if ((child != resultsizes) && (datas[child].weight > datas[child+1].weight))
        {
            child++;   //去左右子结点中最小的
        }
        if (lastnode.weight <= datas[child].weight)
        {
            break;  //找到了合适的位置
        }
        else
        {
            /*下滤*/
            minHeap->datas[parent] = minHeap->datas[child];
        }
    }
    minHeap->datas[parent] = lastnode;

    return firstnode;
}


/*哈夫曼树*/
Node * BuildHuffman(Heap * minHeap)
{
    int sizes = minHeap->sizes;
    Node * newNode;
    /*做N-1次合并*/
    for (int i = 0; i < sizes - 1; i++)
    {
        newNode = CreateNode(0);       //建立一个新的根结点
        newNode->left = DeleteMin(minHeap);  //从最小堆中删除一个结点，作为新T的左子结点
        newNode->right = DeleteMin(minHeap); //从最小堆中删除一个结点，作为新T的右子结点
        newNode->weight = newNode->left->weight + newNode->right->weight;

        Insert(minHeap, newNode);
    }
    newNode = CreateNode(0);
    newNode = DeleteMin(minHeap);
    return newNode;
}

/*打印叶子结点*/
void PrintLeaves(Node * node)
{
    if (node)
    {
        if (!node->left && !node->right)
        {
            cout << node->weight << " ";
        }
        PrintLeaves(node->left);
        PrintLeaves(node->right);
    }
}

/*递归前序遍历*/
void PreOrderTraversal(Node *node)
{
    if (node)
    {
        cout << node->weight << " ";
        PreOrderTraversal(node->left);
        PreOrderTraversal(node->right);
    }
}

/*递归中序遍历*/
void InOrderTraversal(Node *node)
{
    if (node)
    {
        InOrderTraversal(node->left);
        cout << node->weight << " ";
        InOrderTraversal(node->right);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(arr) / sizeof(arr[0]);

    Heap *MinHeap = BuildHeap(arr, length);

    Node *Huffman = BuildHuffman(MinHeap);

    PreOrderTraversal(Huffman);
    cout << endl;

    InOrderTraversal(Huffman);
    cout << endl;

    PrintLeaves(Huffman);
    return 0;
}
