/************************************************************************
*
* �ļ�����5.2.1.cpp
*
* �ļ���������������
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-08-12
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#define MAXSIZE 164
#define MinData -100
using namespace std;
typedef struct HTNode Node; //������������
struct HTNode
{
    int weight;  //���Ȩֵ
    Node *left;  //ָ��������
    Node *right; //ָ��������
};

typedef struct HNode Heap;         //�ѵ����Ͷ���
struct HNode
{
    int sizes;    //���е�ǰ��Ԫ�ظ���
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

/*�������*/
void Insert(Heap *MinHeap, Node *node)
{
    /*��Ԫ��x������С�ѣ�����H->datas[0]�Ѿ�����Ϊ�ڱ�*/
    int i;
    i = ++MinHeap->sizes; //iָ�����󣬶��е����һ��Ԫ�ص�λ��
    for (; MinHeap->datas[i / 2].weight > node->weight; i /= 2)
    {
        MinHeap->datas[i] = MinHeap->datas[i/2];   //����
    }
    MinHeap->datas[i] = *node;  //���½�����
}

/*������С��*/
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




/*����С����ȡ��һ����㣬��ɾ��һ�����*/
Node * DeleteMin(Heap * minHeap)
{
    /*����С����ȡ����ֵΪ��С��Ԫ�أ���ɾ��һ�����*/
    int sizes = minHeap->sizes;


    int resultsizes = minHeap->sizes--;
    Node * datas = minHeap->datas;
    Node lastnode = minHeap->datas[sizes];

    Node *firstnode = CreateNode(datas[1].weight);
    firstnode->left = datas[1].left;
    firstnode->right = datas[1].right;

    int parent;  //�����
    int child;   //�ӽ��
    for (parent = 1; parent * 2 <= resultsizes; parent = child)
    {
        child = parent * 2;
        if ((child != resultsizes) && (datas[child].weight > datas[child+1].weight))
        {
            child++;   //ȥ�����ӽ������С��
        }
        if (lastnode.weight <= datas[child].weight)
        {
            break;  //�ҵ��˺��ʵ�λ��
        }
        else
        {
            /*����*/
            minHeap->datas[parent] = minHeap->datas[child];
        }
    }
    minHeap->datas[parent] = lastnode;

    return firstnode;
}


/*��������*/
Node * BuildHuffman(Heap * minHeap)
{
    int sizes = minHeap->sizes;
    Node * newNode;
    /*��N-1�κϲ�*/
    for (int i = 0; i < sizes - 1; i++)
    {
        newNode = CreateNode(0);       //����һ���µĸ����
        newNode->left = DeleteMin(minHeap);  //����С����ɾ��һ����㣬��Ϊ��T�����ӽ��
        newNode->right = DeleteMin(minHeap); //����С����ɾ��һ����㣬��Ϊ��T�����ӽ��
        newNode->weight = newNode->left->weight + newNode->right->weight;

        Insert(minHeap, newNode);
    }
    newNode = CreateNode(0);
    newNode = DeleteMin(minHeap);
    return newNode;
}

/*��ӡҶ�ӽ��*/
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

/*�ݹ�ǰ�����*/
void PreOrderTraversal(Node *node)
{
    if (node)
    {
        cout << node->weight << " ";
        PreOrderTraversal(node->left);
        PreOrderTraversal(node->right);
    }
}

/*�ݹ��������*/
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
