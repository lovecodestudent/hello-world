/************************************************************************
*
* �ļ�����2.2.1.cpp
*
* �ļ�������ջ��˳��洢ʵ��
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-07-30
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

/*����ṹ��*/
typedef struct
{
    /*һά����*/
    int data[MAXSIZE];

    /*��¼ջ��Ԫ��λ�õı���*/
    int top;
}stacks;

/*���ɿն�ջ*/
stacks *CreateStack();

/*������ջ����*/
void Push(stacks *ptrs, int x);

/*���г�ջ����*/
int Pop(stacks *ptrs);
int main()
{
    int i;
    int j;
    int a[] = {2, 4, 5, 1, -2, 4, 6, 10};
    stacks *s = CreateStack();

    /*ѭ����ջ*/
    cout << "��ջ˳��Ϊ��";
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << " ";
        Push(s, a[i]);
    }
    cout << endl;

    /*ѭ����ջ*/
    cout << "��ջ˳��Ϊ��";
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << Pop(s) << " ";
    }
    cout << endl;
    return 0;
}

/*���ɿն�ջ*/
stacks *CreateStack()
{
    /*����һ����ǰ�Ľṹ��malloc������ϵͳ�������ָ���ڴ�Ŀռ�*/
    stacks *s = (stacks*)malloc(sizeof(stacks));

    /*��ǰջΪ��ջ*/
    s->top = -1;
    return s;
}

/*������ջ����*/
void Push(stacks *ptrs, int x)
{
    if (ptrs->top == MAXSIZE - 1)
    {
        cout << "��ǰջ����" << endl;
        return;
    }
    else
    {
        /*��ֵѹ�벢��ջ��ָ������*/
        ptrs->data[++(ptrs->top)] = x;
        return;
    }
}

/*���г�ջ����*/
int Pop(stacks *ptrs)
{
    if (ptrs->top == -1)
    {
        cout << "ջ�գ�" << endl;
        exit(0);
    }
    else
    {
        /*����ջ��Ԫ�ز���ָ������*/
        return (ptrs->data[(ptrs->top)--]);
    }
}
