/************************************************************************
*
* �ļ�����5.2.1.cpp
*
* �ļ���������С�ѵĹ��������
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
#define MINDATA -1;  //��ֵΪ�ڱ����ȶ�����С��Ԫ�ػ�ҪС
using namespace std;
typedef struct HNode *Heap;         //�ѵ����Ͷ���
typedef Heap MinHeap;               //��С��
struct HNode
{
    int *data;    //�洢Ԫ�ص�����
    int sizes;    //���е�ǰ��Ԫ�ظ���
    int capacity; //�ѵ��������
};

/*��������ΪMaxSize�Ŀյ���С��*/
MinHeap CreatHeap(int MaxSize)
{
    MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
    H->data = (int *)malloc((MaxSize + 1) * sizeof(int)); //���е���ʽԪ�ش���Ǵ��±�Ϊ1��ʼ��
    H->sizes = 0;
    H->capacity = MaxSize;
    H->data[0] = MINDATA;   //�����ڱ�ΪС�ڶ������п��ܵ�ֵ

    return H;
}

/*���Ƿ���*/
bool IsFull(MinHeap H)
{
    return(H->sizes == H->capacity);
}

/*�������*/
bool Insert(MinHeap H, int x)
{
    /*��Ԫ��x������С�ѣ�����H->data[0]�Ѿ�����Ϊ�ڱ�*/
    int i;
    if (IsFull(H))
    {
        cout << "��С������!" << endl;
        return false;
    }
    i = ++H->sizes; //iָ�����󣬶��е����һ��Ԫ�ص�λ��
    for (; H->data[i / 2] > x; i /= 2)
    {
        H->data[i] = H->data[i/2];   //����x
    }
    H->data[i] = x;  //��x����
    return true;
}

/*���Ƿ�Ϊ��*/
bool IsEmpty(MinHeap H)
{
    return (H->sizes == 0);
}

/*����С����ȡ��һ����㣬��ɾ��һ�����*/
int DeleteMin(MinHeap H)
{
    /*����С��H��ȡ����ֵΪ��С��Ԫ�أ���ɾ��һ�����*/
    int parent;  //�����
    int child;   //�ӽ��
    int MinItem; //���ص���СԪ�أ�Ҳ���Ǹ����
    int x;       //���е����һ��Ԫ��
    if (IsEmpty(H))
    {
        cout << "��С��Ϊ�գ�" << endl;
        return -1;
    }
    MinItem = H->data[1]; //ȡ��������ŵ����ֵ
    /*����С���е����һ��Ԫ�شӸ���㿪ʼ���ϵ��¹����²���*/
    x = H->data[H->sizes--]; //��ǰ�ѵĹ�ģҪ��С
    for (parent = 1; parent * 2 <= H->sizes; parent = child)
    {
        child = parent * 2;
        if ((child != H->sizes) && (H->data[child] > H->data[child+1]))
        {
            child++;   //ȥ�����ӽ������С��
        }
        if (x <= H->data[child])
        {
            break;  //�ҵ��˺��ʵ�λ��
        }
        else
        {
            /*����*/
            H->data[parent] = H->data[child];
        }
    }
    H->data[parent] = x;

    return MinItem;
}

/*���˺�����ɾ������������ͬ��һ�㽫���˺���д���ɾ������ֱ�ӵ��ã�����Ϊ�˼�������дһ�飩*/
void PercDown(MinHeap H, int p)
{
    /*���ˣ���H����H->[p]Ϊ�������Ӷѵ���Ϊ��С��*/
    int parent;  //�����
    int child;   //�ӽ��
    int x;
    x = H->data[p]; //ȡ��������ŵ�ֵ
    for (parent = p; parent * 2 <= H->sizes; parent = child)
    {
        child = parent * 2;
        if ((child != H->sizes) && (H->data[child] > H->data[child+1]))
        {
            child++;   //ȥ�����ӽ������С��
        }
        if (x <= H->data[child])
        {
            break;  //�ҵ��˺��ʵ�λ��
        }
        else
        {
            /*����*/
            H->data[parent] = H->data[child];
        }
    }
    H->data[parent] = x;
}

/*����*/
void BuildHeap(MinHeap H)
{
    /*����H->data[]�е�����Ԫ�أ�ʹ������С�ѵ�������*/
    /*�����������H->sizes�е�����Ԫ���Ѿ�������H->data[]��*/
    int i;

    /*�����һ�����ĸ���㿪ʼ���������*/
    for (i = H->sizes / 2; i > 0; i--)
    {
        PercDown(H, i);
    }
}

int main()
{
    int arr[] = {-1, 99, 5, 36, 7, 22, 17, 46, 12, 2, 19, 25, 28, 1, 92};
    int length = sizeof(arr) / sizeof(arr[0]);

    /*������С��*/
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
