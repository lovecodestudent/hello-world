/************************************************************************
*
* �ļ�����2.1.1.cpp
*
* �ļ�������ʹ�����Ա��˳�����ʵ�ֳ�ʼ�������ҡ����롢ɾ��
*
* �����ˣ�  ������

* ʱ  �䣺  2018-07-28
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/
#include <iostream>
#include <cstdlib>
/*������󳤶���1000*/
#define MAXSIZE 1000
using namespace std;

/*����ṹ��*/
typedef struct
{
    int data[MAXSIZE];
    int last;
}List;

/*��ʼ�������������յ�˳���*/
List* MakeEmpty();

/*����ĳһ�ض�ֵ���������±�*/
int Find(int x, List* Ptrl);

/*���룬�ڵ�i��λ���ϲ���ֵΪX����Ԫ��*/
void Insert(int x, int i, List* Ptrl);

/*ɾ����ɾ�����ϵĵ�i��λ�õ�Ԫ��*/
void Delete(int i, List* Ptrl);

/*��������һ��˳����ϵ�����Ԫ�ر���һ��*/
void OutPrint(List* Ptrl);
int main()
{
    int arrays[] = {2, 4, 5, 1, -2, 4, 6, 10};

    List* l = MakeEmpty();

    /*��˳���ֵ*/
    for (int i = 1; i <= 8; i++)
    {
        Insert(arrays[i-1], i, l);
    }
    /*�������*/
    OutPrint(l);

    /*���ҵ�5��λ���ϵ�Ԫ��*/
    cout << Find(5, l) << endl;

    /*������8��λ�ò���18*/
    Insert(18, 8, l);

    /*ɾ�����ϵ�1��Ԫ��*/
    Delete(1, l);

    /*����������˳���*/
    OutPrint(l);
    return 0;
}

/*��ʼ�������������յ�˳���*/
List* MakeEmpty()
{
    List* Ptrl;

    /*����һ����ǰ�Ľṹ��malloc������ϵͳ�������ָ���ڴ�Ŀռ�*/
    Ptrl = (List*)malloc(sizeof (List));

    /*��ʾ��ǰ��û��Ԫ��*/
    Ptrl->last = -1;
    return Ptrl;
}

/*����ĳһ�ض�ֵ���������±�*/
int Find(int x, List* Ptrl)
{
    int i = 0;
    while (i <= Ptrl->last && Ptrl->data[i] != x)
    {
        i++;
    }
    /*���û���ҵ�������-1*/
    if (i > Ptrl->last)
    {
        return -1;
    }
    /*�����±�*/
    else
    {
        return i;
    }
}

/*���룬�ڵ�i��λ���ϲ���ֵΪX����Ԫ��*/
void Insert(int x, int i, List* Ptrl)
{
    int j;

    /*������������ܲ���*/
    if (Ptrl->last == MAXSIZE -1)
    {
        cout << "�������ܲ���" << endl;
        return;
    }
    if (i < 1 || i > Ptrl->last + 2)
    {
        cout << "λ�ò��Ϸ���" << endl;
        return;
    }
    /*��i-1֮���λ��ȫ������*/
    for (j = Ptrl->last; j >= i - 1; j--)
    {
        Ptrl->data[j+1] = Ptrl->data[j];
    }
    /*����Ԫ��x����*/
    Ptrl->data[i-1] = x;

    /*last��ָ�����һ��Ԫ��*/
    Ptrl->last++;
}

/*ɾ����ɾ�����ϵĵ�i��λ�õ�Ԫ��*/
void Delete(int i, List* Ptrl)
{
    int j;
    if (i < 1 || i > Ptrl->last + 1)
    {
        cout << "ɾ�����󣬲����ڸ�λ�õ�Ԫ��" << endl;
        return;
    }
    /*����i��λ��֮���Ԫ��������ǰ�ƶ�*/
    for (j = i; j <= Ptrl->last; j++)
    {
        Ptrl->data[j-1] = Ptrl->data[j];
    }
    /*last��ָ�����һ��Ԫ��*/
    Ptrl->last--;
    return;
}

/*��������һ��˳����ϵ�����Ԫ�ر���һ��*/
void OutPrint(List* Ptrl)
{
    for (int i = 0; i <= Ptrl->last; i++)
    {
        cout << Ptrl->data[i] << " ";
    }
    cout << endl;
}
