/************************************************************************
*
* �ļ�����2.2.3.cpp
*
* �ļ���������ջ����ʽ�洢ʵ��
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
using namespace std;

/*����ṹ��*/
typedef struct Node
{
    int data;
    struct Node *next;
}liststrack;

/*��ջ�ĳ�ʼ��*/
liststrack *CreateStack();

/*�ж�ջ�Ƿ�Ϊ��*/
bool IsEmpty(liststrack *ptrs);

/*��ջ*/
void Push(liststrack *strs, int x);

/*��ջ*/
int Pop(liststrack *ptrs);

/*����*/
void TravelListStrack(liststrack *ptrs);

int main()
{
    liststrack *s; //����һ��liststrack���͵�ָ�����ں�������
    s = CreateStack();
    int i;  //forѭ���еı���
    int a[] = {2, 4, 5, 1, -2, 4, 6, 10};
    int lengths = sizeof(a) / sizeof(a[0]);

    /*��Ԫ������ѹ��ջ��*/
    cout << "��ջ��˳��Ϊ��";
    for (i = 0; i < lengths; i++)
    {
        cout << a[i] << " ";
        Push(s, a[i]); //��ջ
    }
    cout << endl;

    /*��ջ�е�Ԫ�����ε���*/
    cout << "��ջ��˳��Ϊ��";
    while (s->next != NULL)
    {
        cout << Pop(s) << " "; //��ջ
    }
    cout << endl;
    return 0;
}

/*��ջ�ĳ�ʼ��*/
liststrack *CreateStack()
{
    /*����һ����ջ��ͷ��㣬������ָ��*/
    liststrack *s;
    s = (liststrack *)malloc(sizeof(liststrack)); //��ϵͳ�������ָ�����ڴ�ռ�
    s->next = NULL;
    return s;
}

/*�ж�ջ�Ƿ�Ϊ��*/
bool IsEmpty(liststrack *ptrs)
{
    /*�շ���true�����򷵻�false*/
    if (ptrs == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*��ջ*/
void Push(liststrack *strs, int x)
{
    /*��Ԫ��xѹ��ջ��*/
    liststrack *temp;
    temp = (liststrack *)malloc(sizeof(liststrack));  //�����ڴ�ռ�
    temp->next = strs->next;
    temp->data = x;
    strs->next = temp;
}

/*��ջ*/
int Pop(liststrack *ptrs)
{
    liststrack *first; //�½�һ��liststrack���͵�ָ������ָ���һ��Ԫ��
    int temp;
    if (IsEmpty(ptrs))
    {
        cout << "ջ�գ�" << endl;
        exit(0);                 //�˳���ǰ����
    }
    /*��ȡջ��Ԫ�ز�����ɾ��*/
    first = ptrs->next;
    temp = first->data;
    ptrs->next = first->next;
    free(first);     //ɾ�����
    return temp;
}
