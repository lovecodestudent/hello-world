/************************************************************************
*
* 文件名：2.2.6.cpp
*
* 文件描述：实现多项式的加法及乘法运算
*
* 创建人：  fdk

* 时  间：  2018-08-01
*
* 版本号：1.0
*
* 修改记录：链表的使用还不够熟练，不能自己独立完成需要多加练习
*
************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

/*定义结构体*/
typedef struct PolyNode
{
    int coef;   //系数
    int expon; //指数
    struct PolyNode *link; //指向下一个结点的指针
}*Polynomial;

/*比较函数*/
int Compare(int e1, int e2);

/*添加结点函数*/
void Attach(int coef, int expon, Polynomial *PtrRear);

/*多项式求和函数*/
Polynomial PolyAdd(Polynomial p1, Polynomial p2);

/*多项式求乘积函数*/
Polynomial PolyMul(Polynomial p1, Polynomial p2);

/*新建一个多项式链表，参考多项式和的函数，每个元素的值由键盘输入*/
Polynomial MakeNew(int n);
int main()
{
    int m;
    int n;
    Polynomial M;//第一个多项式
    Polynomial N;//第二个多项式
    Polynomial Q;//第一个多项式加第二个多项式之和
    Polynomial T;//第一个多项式和第二个多项式之积

    cout << "请输入第一个多项式的项数！" << endl;
    cin >> m;
    M = MakeNew(m);

    cout << "请输入第二个多项式的项数！" << endl;
    cin >> n;
    N = MakeNew(n);

    Q = PolyAdd(M, N);
    cout << "相加后的结果为：" << endl;
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

/*比较函数*/
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

/*添加结点函数*/
void Attach(int coef, int expon, Polynomial *PtrRear)
{
    /*由于在本函数中需要改变当前结果表达式尾项指针的值*/
    /*所以函数传递进来的是结点指针的地址，*PtrRear指向尾项，是个二级指针*/
    Polynomial p;
    p = (Polynomial)malloc(sizeof(PolyNode)); //申请新结点
    p->coef = coef;
    p->expon = expon;

    /*将p指向的新结点插入到当前结果表达式尾项的后面*/
    (*PtrRear)->link = p;
    *PtrRear = p;      //链表尾指针指向新结点
}

/*多项式求和函数*/
Polynomial PolyAdd(Polynomial p1, Polynomial p2)
{
    /*fronts链表头指针，rear链表尾指针，temp用于释放头结点*/
    Polynomial fronts;
    Polynomial rear;
    Polynomial temp;
    int sum;

    /*为方便表头插入，先产生一个临时空结点作为结果多项式链表头*/
    rear = (Polynomial)malloc(sizeof(PolyNode));
    fronts = rear;  //由fronts记录结果多项式链表头结点

    /*当两个多项式都有非零项待处理时*/
    while (p1 && p2)
    {
        switch (Compare(p1->expon, p2->expon))
        {
        /*比较p1和p2指数的大小将指数大的那一项添加到多项式中去*/
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
            /*如果系数和不为0，将相加后的系数作为参数添加到多项式中*/
            if (sum)
            {
                Attach(sum, p1->expon, &rear);
            }
            p1 = p1->link;
            p2 = p2->link;
            break;
        }
    }
    /*当p1和p2中有一个结束后，将另一个的剩余一次接入到后面*/
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
    rear->link = NULL;   //多项式的尾指针指向为空

    /*利用临时变量temp将头结点删除，使fronts指针指向第一个元素*/
    temp = fronts;
    fronts = fronts->link;
    free(temp);
    return fronts;
}

/*新建一个多项式链表，参考多项式和的函数，每个元素的值由键盘输入*/
Polynomial MakeNew(int n)
{
    Polynomial fronts,rear,temp;
    int k,c[10],e[10];
    fronts=(Polynomial)malloc(sizeof(struct PolyNode));
    rear=fronts;
    cout << "先输入系数后输入指数！" << endl;
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

/*多项式求乘积函数*/
Polynomial PolyMul(Polynomial p1, Polynomial p2)
{
    /*创建一个链表P用于表示当前运算的中间状态*/

    Polynomial pResult = NULL;
    Polynomial CopyP2 = p2;

    /*创建一个新的多项式TmpP*/
    Polynomial TmpP;

    /*让p1中的每一项和p2中的每一项相乘然后将获得到的多项式依次相加得到最后的结果*/
    while (p1)
    {
        while (p2)
        {
            /*定义一个临时变量TmpP用来计算*/
            TmpP = (Polynomial)malloc(sizeof(PolyNode));
            TmpP->link = NULL;
            TmpP->coef = (p1->coef)*(p2->coef);     /*系数相乘指数相加*/
            TmpP->expon = (p1->expon)+(p2->expon);
            pResult = PolyAdd(pResult, TmpP);
            p2 = p2->link;
        }
        /*将p2的指针重置，并将p1的指针移动到下一个位置*/
        p2 = CopyP2;
        p1 = p1->link;
    }
    return pResult;
}

