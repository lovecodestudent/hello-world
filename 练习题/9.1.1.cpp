/************************************************************************
*
* �ļ�����9.1.1.cpp
*
* �ļ�������Ͱ����
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
#define max 100
using namespace std;

void BucketSort(int a[], int length)
{
    int i, j, t;
    /*��ʼ��Ϊ0*/
    for (i = 0; i <= length; i++)
    {
        a[i] = 0;
    }
    int num;//����Ԫ�صĸ���
    cin >> num;
    for (j = 0; j < num; j++)
    {
        cin >> t;
        a[t]++;
    }
    /*�����ӡ*/
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < a[i]; j++)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
int main()
{
    int a[11];
    BucketSort(a, 10);
    return 0;
}
