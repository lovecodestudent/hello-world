/************************************************************************
*
* �ļ�����2.1.2.cpp
*
* �ļ����������Ա������Ĳ��ҡ����롢ɾ��
*
* �����ˣ�  ������

* ʱ  �䣺  2018-07-28
*
* �汾�ţ�1.0
*
* �޸ļ�¼��ͷ�������ã�
1����ֹ�������ǿյĶ����.������Ϊ�յ�ʱ��,��ͷ����ͷָ���ָ��ͷ���.���������Ϊ�յ�ʱ��,������û�д�ͷ���,��ô����ͷָ���ΪNULL.
2����Ϊ�˷��㵥������������,�����ڱ�ͷ����ɾ����һ�����.�����ͱ����˵����������ͳһ��!
3�����������ͷ���֮�����۵������Ƿ�Ϊ�գ�ͷָ��ʼ��ָ��ͷ��㣬��˿ձ�ͷǿձ�Ĵ���Ҳͳһ�ˣ������˵�����Ĳ�����Ҳ�����˳���ĸ����Ժͳ���bug�Ļ��ᡣ
4���Ե�����Ķ�������Ӧ��ȷ���ĸ�����Լ��ý���ǰ��������ͷ�����������Ԫ��㡢�м���ֱ���ȣ�����ͷ����������Ϊ��ͷ��㣬��Ԫ��㡢�м���Ĳ�����ͬ ,�Ӷ����ٷ�֧��ʹ�㷨��ü� ,�����������Ե�������в��롢ɾ������ʱ���������Ԫ���֮ǰ�����ɾ��������Ԫ��㣬����ͷ���ĵ�������ı�ͷָ���ֵ����C �㷨�ĺ����βα���ͷָ��һ��ʹ��ָ���ָ��(��C+ +��ʹ������ &)������ͷ���ĵ�������ı�ͷָ���ֵ��������������ͷ���ʹ��ָ��������ɡ�
����������ջ�������������Ҫ�����ϰ���ر��ǽ���ķ�������Ҫ������Ҫ��д������
*
************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

/*������*/
typedef struct Node
{
    int data;
    struct Node* next;
}lists;

/*��ʼ������*/
lists *MakeEmpty();

/*β�巨����*/
void CreatList(lists *ptrl, int a[]);

/*���*/
int Length(lists *ptrl);

/*����Ų���*/
lists *FindKth(int k, lists *ptrl);

/*��ֵ����*/
int Find(int x, lists *ptrl);

/*�����ڵ�i-1���������һ��ֵΪx���½��*/
void Insert(int x, int i, lists *ptrl);

/*ɾ��iλ���ϵĽ��*/
void Delete(int i, lists *ptrl);

/*��������*/
void TravelList(lists *ptrl);
int main()
{
    int a[] = {2, 4, 5, 1, -2, 4, 6, 10};

    /*��ʼ������*/
    lists *l = MakeEmpty();

    CreatList(l, a);

    /*��������*/
    TravelList(l);

    /*������ĳ���*/
    cout << "����ĳ���Ϊ��" << Length(l) << endl;

    /*����Ų��ҵ�k��λ���ϵ�Ԫ��*/
    lists* p1 = FindKth(4, l);
    cout << "��4��λ���ϵ�Ԫ��Ϊ��" << p1->data << endl;

    /*��ֵ����ֵΪ1��Ԫ�����ڵ�λ��*/
    cout << "ֵΪ1��Ԫ�����ڵ�λ��Ϊ��" << Find(1, l) << endl;

    /*�ڵ�i��λ�ú����һ��ֵΪ7�Ľ��*/
    Insert(7, 1, l);

    Insert(15, 2, l);

    /*ɾ����8��λ���ϵ�Ԫ��*/
    Delete(8, l);

    /*��������*/
    TravelList(l);
    return 0;
}

/*��ʼ������*/
lists *MakeEmpty()
{
    lists* Ptrl;

    /*����һ����ǰ�Ľṹ��malloc������ϵͳ�������ָ���ڴ�Ŀռ�*/
    Ptrl = (lists*)malloc(sizeof (lists));
    if (Ptrl == NULL)
    {
        cout << "��ʼ��ʧ��" << endl;
        exit(-1);
    }
    /*��ʾ��ǰ��û��Ԫ��*/
    Ptrl->next = NULL;
    return Ptrl;
}

/*���*/
int Length(lists *ptrl)
{
    /*pָ����Ǳ�ĵ�һ�����*/
    lists *p = ptrl->next;
    int num = 0;
    while (p)
    {
        /*��ǰpָ����ǵ�j�����*/
        p = p->next;
        num++;
    }
    return num;
}

/*����Ų���*/
lists *FindKth(int k, lists *ptrl)
{
    lists *p = ptrl->next;
    int num = 1;
    while (p != NULL && num < k)
    {
        p = p->next;
        num++;
    }
    if (num == k)
    {
        /*����ҵ�����ָ��*/
        return p;
    }
    else
    {
        /*���û���ҵ�����NULL*/
        return NULL;
    }
}

/*��ֵ����*/
int Find(int x, lists *ptrl)
{
    lists *p = ptrl->next;
    int num = 1;
    while (p->data != x && p != NULL)
    {
        p = p->next;
        num++;
    }
    /*�ҵ��˷��ض�Ӧ��ָ��û�ҵ�����NULL*/
    return num;
}

/*�����ڵ�i-1���������һ��ֵΪx���½��*/
void Insert(int x, int i, lists *ptrl)
{
    /*s�������������ͷ���*/
    lists *s;

    /*p�����ҵ���i-1�����*/
    lists *p;

    if( i == 1)
    {
        /*�½����ڱ�ͷ*/
        s = (lists *)malloc(sizeof(lists));
        /*���롢װ����*/
        s->data = x;
        s->next = ptrl->next;
        ptrl->next = s;
        return;
    }
    /*���ҵ�i-1������λ��*/
    p = FindKth(i-1, ptrl);

    if (p == NULL)
    {
        cout << "��������" << endl;
        return;
    }
    else
    {
        s = (lists *)malloc(sizeof(lists));
        /*�����i�����*/
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}

/*ɾ��iλ���ϵĽ��*/
void Delete(int i, lists *ptrl)
{
    /*�����ҵ���i-1������λ��*/
    lists *p;

    /*����ɾ����һ�����*/
    lists *s;

    /*��Ҫɾ�����ǵ�һ�����*/
    if (i == 1)
    {
        /*sָ���һ�����*/
        s = ptrl;

       /*��������ɾ��*/
       if (ptrl != NULL)
       {
           ptrl = ptrl->next;
       }
       else
       {
           return;
       }
       free(s);
    }

    /*���ҵ�i�����*/
    p = FindKth(i-1, ptrl);
    if (p == NULL)
    {
        cout << "��" << i -1 << "����㲻����" << endl;
        return;
    }
    else if (p->next == NULL)
    {
        cout << "��" << i << "����㲻����" << endl;
    }
    else
    {
        /*sָ���i�����*/
        s = p->next;

        /*��������ɾ��*/
        p->next = s->next;

        /*�ͷű�ɾ�����*/
        free(s);
    }
}

/*��������*/
void TravelList(lists *ptrl)
{
    lists* p = ptrl->next;
    cout << "�����е�Ԫ������Ϊ��";
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

/*β�巨����*/
void CreatList(lists *ptrl, int a[])
{
    /*β�巨�Ľ���˳��������һ�£�ͷ�巨���뷴*/
    int i;

    /*�½����*/
    lists *pnew;
    lists *p;
    p = ptrl;
    for (i = 1; i <= 8; i++)
    {
        /*����װ����*/
        pnew = (lists *)malloc(sizeof(lists));
        cout << a[i-1] << endl;
        pnew->data = a[i-1];

        /*�½������β*/
        p->next = pnew;
        p = pnew;
    }
    p->next = NULL;
}
