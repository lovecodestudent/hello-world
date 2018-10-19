/************************************************************************
*
* 文件名：3.1.1.cpp
*
* 文件描述：二分查找算法
*
* 创建人：  fdk

* 时  间：  2018-08-02
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

/*定义结构体*/
typedef struct
{
    int *arr;
    int length;
}Dynamic;

/*二分查找*/
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

/*二分查找*/
int BinarySearch(Dynamic *d, int key)
{
    /*在数组中查找值为key的元素并返回下标值*/
    int left;
    int right;
    int mid;


    left = 1; //初始化左边界
    right = d->length; //初始化右边界
    while (left <= right)
    {
        mid = (left + right) / 2;  //计算中间元素坐标
        if (d->arr[mid] > key)
        {
            right = mid - 1;      //调整右边界
        }
        if (d->arr[mid] < key)
        {
            left = mid + 1;      //调整左边界
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
