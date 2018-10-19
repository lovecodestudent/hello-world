/************************************************************************
*
* �ļ�����2.2.6.cpp
*
* �ļ�������ʵ�ֶ���ʽ�ļӷ����˷�����
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-08-01
*
* �汾�ţ�1.0
*
* �޸ļ�¼�������ʹ�û����������������Լ����������Ҫ�����ϰ
*
************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

/*����ṹ��*/
typedef struct PolyNode
{
    int coef;   //ϵ��
    int expon; //ָ��
    struct PolyNode *link; //ָ����һ������ָ��
}*Polynomial;

/*�ȽϺ���*/
int Compare(int e1, int e2);

/*��ӽ�㺯��*/
void Attach(int coef, int expon, Polynomial *PtrRear);

/*����ʽ��ͺ���*/
Polynomial PolyAdd(Polynomial p1, Polynomial p2);

/*����ʽ��˻�����*/
Polynomial PolyMul(Polynomial p1, Polynomial p2);

/*�½�һ������ʽ�����ο�����ʽ�͵ĺ�����ÿ��Ԫ�ص�ֵ�ɼ�������*/
Polynomial MakeNew(int n);
int main()
{
    int m;
    int n;
    Polynomial M;//��һ������ʽ
    Polynomial N;//�ڶ�������ʽ
    Polynomial Q;//��һ������ʽ�ӵڶ�������ʽ֮��
    Polynomial T;//��һ������ʽ�͵ڶ�������ʽ֮��

    cout << "�������һ������ʽ��������" << endl;
    cin >> m;
    M = MakeNew(m);

    cout << "������ڶ�������ʽ��������" << endl;
    cin >> n;
    N = MakeNew(n);

    Q = PolyAdd(M, N);
    cout << "��Ӻ�Ľ��Ϊ��" << endl;
    while (Q)
    {
        cout << Q->coef << " " << Q->expon << " ";
        Q = Q->link;
    }
    cout << endl;

    T = PolyMul(M, N);
    while (T)
    {
        cout << T->coef << " " << T->expon << " ";
        T = T->link;
    }
    return 0;
}

/*�ȽϺ���*/
int Compare(int e1, int e2)
{
    if (e1 > e2)
    {
        return 1;
    }
    if (e1 < e2)
    {
        return -1;
    }
    if (e1 == e2)
    {
        return 0;
    }
}

/*��ӽ�㺯��*/
void Attach(int coef, int expon, Polynomial *PtrRear)
{
    /*�����ڱ���������Ҫ�ı䵱ǰ������ʽβ��ָ���ֵ*/
    /*���Ժ������ݽ������ǽ��ָ��ĵ�ַ��*PtrRearָ��β��Ǹ�����ָ��*/
    Polynomial p;
    p = (Polynomial)malloc(sizeof(PolyNode)); //�����½��
    p->coef = coef;
    p->expon = expon;

    /*��pָ����½����뵽��ǰ������ʽβ��ĺ���*/
    (*PtrRear)->link = p;
    *PtrRear = p;      //����βָ��ָ���½��
}

/*����ʽ��ͺ���*/
Polynomial PolyAdd(Polynomial p1, Polynomial p2)
{
    /*fronts����ͷָ�룬rear����βָ�룬temp�����ͷ�ͷ���*/
    Polynomial fronts;
    Polynomial rear;
    Polynomial temp;
    int sum;

    /*Ϊ�����ͷ���룬�Ȳ���һ����ʱ�ս����Ϊ�������ʽ����ͷ*/
    rear = (Polynomial)malloc(sizeof(PolyNode));
    fronts = rear;  //��fronts��¼�������ʽ����ͷ���

    /*����������ʽ���з����������ʱ*/
    while (p1 && p2)
    {
        switch (Compare(p1->expon, p2->expon))
        {
        /*�Ƚ�p1��p2ָ���Ĵ�С��ָ�������һ����ӵ�����ʽ��ȥ*/
        case 1:
            Attach(p1->coef, p1->expon, &rear);
            p1 = p1->link;
            break;
        case -1:
            Attach(p2->coef, p2->expon, &rear);
            p2 = p2->link;
            break;
        case 0:
            sum = p1->coef + p2->coef;
            /*���ϵ���Ͳ�Ϊ0������Ӻ��ϵ����Ϊ������ӵ�����ʽ��*/
            if (sum)
            {
                Attach(sum, p1->expon, &rear);
            }
            p1 = p1->link;
            p2 = p2->link;
            break;
        }
    }
    /*��p1��p2����һ�������󣬽���һ����ʣ��һ�ν��뵽����*/
    while (p1)
    {
        Attach(p1->coef, p1->expon, &rear);
        p1 = p1->link;
    }
    while (p2)
    {
        Attach(p2->coef, p2->expon, &rear);
        p2 = p2->link;
    }
    rear->link = NULL;   //����ʽ��βָ��ָ��Ϊ��

    /*������ʱ����temp��ͷ���ɾ����ʹfrontsָ��ָ���һ��Ԫ��*/
    temp = fronts;
    fronts = fronts->link;
    free(temp);
    return fronts;
}

/*�½�һ������ʽ�����ο�����ʽ�͵ĺ�����ÿ��Ԫ�ص�ֵ�ɼ�������*/
Polynomial MakeNew(int n)
{
    Polynomial fronts,rear,temp;
    int k,c[10],e[10];
    fronts=(Polynomial)malloc(sizeof(struct PolyNode));
    rear=fronts;
    cout << "������ϵ��������ָ����" << endl;
    for(k=0; k<n; k++)
    {
        cin>>c[k];
        cin>>e[k];
        Attach(c[k],e[k],&rear);
    }
    rear->link=NULL;
    temp=fronts;
    fronts=fronts->link;
    free(temp);
    return fronts;
}

/*����ʽ��˻�����*/
Polynomial PolyMul(Polynomial p1, Polynomial p2)
{
    /*����һ������P���ڱ�ʾ��ǰ������м�״̬*/

    Polynomial pResult = NULL;
    Polynomial CopyP2 = p2;

    /*����һ���µĶ���ʽTmpP*/
    Polynomial TmpP;

    /*��p1�е�ÿһ���p2�е�ÿһ�����Ȼ�󽫻�õ��Ķ���ʽ������ӵõ����Ľ��*/
    while (p1)
    {
        while (p2)
        {
            /*����һ����ʱ����TmpP��������*/
            TmpP = (Polynomial)malloc(sizeof(PolyNode));
            TmpP->link = NULL;
            TmpP->coef = (p1->coef)*(p2->coef);     /*ϵ�����ָ�����*/
            TmpP->expon = (p1->expon)+(p2->expon);
            pResult = PolyAdd(pResult, TmpP);
            p2 = p2->link;
        }
        /*��p2��ָ�����ã�����p1��ָ���ƶ�����һ��λ��*/
        p2 = CopyP2;
        p1 = p1->link;
    }
    return pResult;
}

