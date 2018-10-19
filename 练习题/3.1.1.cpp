/************************************************************************
*
* �ļ�����3.1.1.cpp
*
* �ļ����������ֲ����㷨
*
* �����ˣ�  fdk

* ʱ  �䣺  2018-08-02
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

/*����ṹ��*/
typedef struct
{
    int *arr;
    int length;
}Dynamic;

/*���ֲ���*/
int BinarySearch(Dynamic *d, int key);
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(a) / sizeof (a[0]);
    Dynamic *arrs;
    arrs->arr = a;
    arrs->length = length;
    cout << BinarySearch(arrs, 5);
    return 0;
}

/*���ֲ���*/
int BinarySearch(Dynamic *d, int key)
{
    /*�������в���ֵΪkey��Ԫ�ز������±�ֵ*/
    int left;
    int right;
    int mid;


    left = 1; //��ʼ����߽�
    right = d->length; //��ʼ���ұ߽�
    while (left <= right)
    {
        mid = (left + right) / 2;  //�����м�Ԫ������
        if (d->arr[mid] > key)
        {
            right = mid - 1;      //�����ұ߽�
        }
        if (d->arr[mid] < key)
        {
            left = mid + 1;      //������߽�
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
