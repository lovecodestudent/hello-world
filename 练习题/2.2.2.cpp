/************************************************************************
*
* �ļ�����2.2.2.cpp
*
* �ļ�����������һ������ʵ��������ջ��Ҫ��������������ռ䣬ʹ����ֻҪ�пռ���ջ�����Ϳ��Գɹ�
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-07-30
*
* �汾�ţ�1.0
*
* �޸ļ�¼������ָ��ֱ��Ӧ�������βȻ�����м��ƶ����������̶ȵ����ÿռ�
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

    /*��ջ1��ջ��ָ��*/
    int top1;

    /*��ջ2��ջ��ָ��*/
    int top2;
}stacks;

/*���ɿն�ջ*/
stacks *CreateStack(int maxs);

/*������ջ����*/
void Push(stacks *ptrs, int x, int tag);

/*���г�ջ����*/
int Pop(stacks *ptrs, int tag, int maxs);
int main()
{
    int i;
    int j;
    int k;
    int a[] = {2, 4, 5, 1, -2, 4, 6, 10};

    /*�õ���ǰ����ĳ���*/
    int maxs = sizeof(a) / sizeof(a[0]);
    cout << maxs << endl;
    stacks *s = CreateStack(maxs);
    cout << s->top1 << " " << s->top2 << endl;//���

    /*������λ���ϵ�Ԫ�ش��뵽ջ1*/
    for (i = 0; i < maxs; i = i + 2)
    {
        Push(s, a[i], 1);
    }
    /*��ż��λ���ϵ�Ԫ�ش��뵽ջ2*/
    for (j = 1; j < maxs; j = j + 2)
    {
        Push(s, a[j], 2);
    }
    /*��ջ�е�����Ԫ�ص���*/
    int m = maxs / 2;
    while (m != 0)
    {
        cout << Pop(s, 1, maxs) << " ";
        cout << Pop(s, 2, maxs) << " ";
        m--;
    }
    return 0;
}

/*���ɿն�ջ*/
stacks *CreateStack(int maxs)
{
    /*����һ����ǰ�Ľṹ��malloc������ϵͳ�������ָ���ڴ�Ŀռ�*/
    stacks *s = (stacks*)malloc(sizeof(stacks));

    /*��ǰջ1Ϊ��ջ*/
    s->top1 = -1;

    /*��ǰջ2Ϊ��ջ*/
    s->top2 = maxs;
    return s;
}

/*������ջ����*/
void Push(stacks *ptrs, int x, int tag)
{
    /*tag��Ϊ����������ջ�ı�־��ȡֵΪ1��2����top2-top1����1ʱΪջ��*/
    if (ptrs->top2 - ptrs->top1 == 1)
    {
        cout << "ջ����" << endl;
        return;
    }
    if (tag == 1)
    {
        /*�Ե�һ��ջ������ջ����*/
        ptrs->data[++(ptrs->top1)] = x;
    }
    else
    {
        /*�Եڶ���ջ������ջ����*/
        ptrs->data[--(ptrs->top2)] = x;
    }
}

/*���г�ջ����*/
int Pop(stacks * ptrs, int tag, int maxs)
{
    if (tag == 1)
    {
        /*��ջ1���г�ջ����*/
        if (ptrs->top1 == -1)
        {
            cout << "ջ�գ�" << endl;
            exit(0);
        }
        else
        {
            return ptrs->data[(ptrs->top1)--];
        }
    }
    else
    {
        /*��ջ2���г�ջ����*/
        if (ptrs->top2 == maxs)
        {
            cout << "ջ�գ�" << endl;
            exit(0);
        }
        else
        {
            return ptrs->data[(ptrs->top2)++];
        }
    }
}
