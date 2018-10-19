/************************************************************************
*
* �ļ�����2.2.4.cpp
*
* �ļ�������ѭ�����е�˳��洢ʵ�֣����������롢ɾ����
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-07-31
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/
#include <iostream>
#include <cstdlib>

/*�����������󳤶�Ϊ100*/
#define MAXSIZE 100
using namespace std;
typedef struct
{
    int data[MAXSIZE];
    int rear;    /*��βָ��*/
    int fronts; /*����ָ��*/
}queues;

/*���еĳ�ʼ��*/
queues *CreateQueue();

/*��Ӳ���*/
bool AddQ(queues *ptrq, int x);

/*���Ӳ���*/
int DeleteQ(queues *ptrq);
int main()
{
    int i; //forѭ������
    queues *s; //����һ��queues��ָ�����ں�������
    s = CreateQueue();
    int a[] = {2, 4, 5, 1, -2, 4, 6, 10};
    int lengths = sizeof(a) / sizeof(a[0]);

    /*�����*/
    cout << "��ӵ�˳��Ϊ��" << endl;
    for (i = 0; i < lengths; i++)
    {
        cout << a[i] << " ";
        AddQ(s,a[i]);
    }
    cout << endl;
    /*������*/
    cout << "���ӵ�˳��Ϊ��" << endl;
    while (s->rear != s->fronts)
    {
        cout << DeleteQ(s) << " ";
    }
    cout << endl;
    return 0;
}

/*���еĳ�ʼ��*/
queues *CreateQueue()
{
    /*��ʼ���еĴ���*/
    queues *q;
    q = (queues*)malloc(sizeof(queues));
    q->fronts = 0; //�ն���ʱ��ָ���βָ�붼Ϊ0
    q->rear = 0;
}

/*��Ӳ���*/
bool AddQ(queues *ptrq, int x)
{
    /*�ж϶����Ƿ�Ϊ������*/
    if ((ptrq->rear + 1) % MAXSIZE == ptrq->fronts)
    {
        cout << "��������"<< endl;
        return false;
    }
    else
    {
        /*��1ȡ��˳��ѭ��*/
        ptrq->rear = (ptrq->rear +1) % MAXSIZE;
        ptrq->data[ptrq->rear] = x;
        return true;
    }
}

/*���Ӳ���*/
int DeleteQ(queues *ptrq)
{
    /*�ж϶����Ƿ�Ϊ��*/
    if (ptrq->fronts == ptrq->rear)
    {
        cout << "����Ϊ�գ�" << endl;
        exit(0);
    }
    else
    {
        /*���ڵ�һ��λ�ò��������Ԫ�������±�Ҫ��1*/
        ptrq->fronts = (ptrq->fronts + 1) % MAXSIZE;
        return ptrq->data[ptrq->fronts];
    }
}
