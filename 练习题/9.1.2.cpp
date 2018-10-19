/************************************************************************
*
* �ļ�����9.1.2.cpp
*
* �ļ���������������
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-09-25
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<limits.h>
using namespace std;

/*��ȡ�����е����ֵ*/
int getMax(int a[], int n)
{
    int i, max;
    max = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

/*�����鰴�ա�ĳ��λ��������Ͱ����*/
void countSort(int a[], int n, int exp)
{
    int output[n];  //�洢���������ݵ���ʱ����
    int i, buckets[10] = {0};

    /*�����ݳ��ֵĴ����洢��buckets[]��*/
    for (i = 0; i < n; i++)
    {
        buckets[(a[i] / exp) % 10]++;
    }

    /*����buckets[i]��Ŀ�����ø��ĺ��buckets[i]��ֵ���Ǹ�������output[]�е�λ��*/
    for (i = 1; i < 10; i++)
    {
        buckets[i] += buckets[i-1];
    }

    /*�����ݴ洢����ʱ����output[]��*/
    for (i = n-1; i >= 0; i--)
    {
        output[buckets[(a[i] / exp) % 10]-1] = a[i];
        buckets[(a[i]/exp) % 10] --;
    }

    /*������õ����ݸ�ֵ��a[]*/
    for (i = 0; i < n; i++)
    {
        a[i] = output[i];
    }

}

/*��������*/
void radixSort(int a[], int n)
{
    int exp;  //ָ���������鰴��λ��������ʱ��exp = 1; ��ʮλ��������ʱ��exp=10
    int max = getMax(a, n); //����a�е����ֵ

    //�Ӹ�λ��ʼ��������a��ָ����������
    for (exp = 1; max/exp > 0; exp *= 10)
    {
        countSort(a, n, exp);
    }
}
int main()
{
    int i;
    int a[] = {64, 8, 216, 512, 27, 729, 0, 1, 343, 125};
    int ilen = (sizeof(a)) / (sizeof(a[0]));

    cout << "����֮ǰ��˳��Ϊ��";
    for (i = 0; i < ilen; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    radixSort(a, ilen); //��������

    cout << "����֮���˳��Ϊ��";
    for (i = 0; i < ilen; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;


    return 0;
}
