/************************************************************************
*
* �ļ�����2.2.5.cpp
*
* �ļ����������е���ʽ�洢ʵ��
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-07-31
*
* �汾�ţ�1.0
*
* �޸ļ�¼�����кͶ�ջһ��Ҳ�ܲ�ȡ��ʽ�洢�������е�ͷfronts����ָ�������ͷ��㣬
*           ���е�βrearָ�������β�ڵ�
*
*
************************************************************************/
#include <iostream>
#include <cstdlib>
#define MAXSIZE 100
using namespace std;

/*�������ӽ�������*/
typedef struct Node
{
    int data;
    struct Node *next;
}LinkNode;

/*��ͷβָ���װ��һ���������*/
typedef struct
{
    LinkNode *fronts; //ָ���ͷ���
    LinkNode *rear;   //ָ���β���
}LinkQueue;

/*��ʼ��*/
void InitLinkQueue(LinkQueue *&q);

/*�ж��Ƿ�Ϊ��*/
bool LinkQueueEmpty(LinkQueue *q);

/*�����*/
void EnLinkQueue(LinkQueue *q,int x);

/*������*/
int DeLinkQueue(LinkQueue *q);
int main()
{
    int i;         //forѭ������
    LinkQueue *q;
    InitLinkQueue(q); //��ʼ��
    int a[] = {2, 4, 5, 1, -2, 4, 6, 10};
    int lengths = sizeof(a) / sizeof(a[0]);

    /*�����*/
    cout << "��ӵ�˳��Ϊ��" << endl;
    for (i = 0; i < lengths; i++)
    {
        cout << a[i] << " ";
        EnLinkQueue(q,a[i]);
    }
    cout << endl;
    /*������*/
    cout << "���ӵ�˳��Ϊ��" << endl;
    while (!LinkQueueEmpty(q))
    {
        cout << DeLinkQueue(q) << " ";
    }
    cout << endl;
    return 0;
}

/*��ʼ��*/
void InitLinkQueue(LinkQueue *&q)
{
    q = (LinkQueue*)malloc(sizeof(LinkQueue));
    LinkNode *p;
    p = (LinkNode*)malloc(sizeof(LinkNode));
    p->next = NULL;
    q->fronts = q->rear = p;
}

/*�ж��Ƿ�Ϊ��*/
bool LinkQueueEmpty(LinkQueue *q)
{
    if (q->fronts == q->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*�����*/
void EnLinkQueue(LinkQueue *q,int x)
{
    /*βָ��ֻ������������Ӳ���*/
    LinkNode *p;
    p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = x;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

/*������*/
int DeLinkQueue(LinkQueue *q)
{
    /*ͷָ����������ɾ������*/
    LinkNode *p;
    if (LinkQueueEmpty(q))
    {
        cout << "�ö���Ϊ�գ�" << endl;
        exit(-1);
    }
    else
    {
        int temp;               //�������ʱ�������ڴ洢��ɾ������ֵ
        p = q->fronts->next;
        q->fronts->next = p->next;
        temp = p->data;
        if(p->next == NULL)      //��������ֻ��һ��Ԫ���Ǳ�ɾ������Ҫ��ͷָ���βָ�����
        {
            q->rear == q->fronts;
        }
        free(p);                //�ͷŸý�㲢���ظý���ֵ
        return temp;
    }
}
