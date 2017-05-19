#include <iostream>
#include "sort.h"

using namespace std;

void quick_sort(int arr[], int begin, int end)
{
    int i, j, base;
    int index;

    if (begin >= end) {
        return ;
    }
    base = arr[begin];
    i =  begin;
    j = end;

    while (i < j) {
        while (j > i && arr[j] >= base) {
            j--;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= base) {
            i++;
        }
        arr[j] = arr[i];
    }

    arr[i] = base;

    quick_sort(arr, begin, i-1);
    quick_sort(arr, i+1, end);

    return;
}

void merge_array(int a[], int begin, int mid, int end, int temp[])
{
    int i, j ,k;

    i =begin;
    j=mid+1;
    k = 0;
 
    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= end) {
        temp[k++] = a[j++];
    }

    memcpy(a+begin, temp, k*sizeof(int));

    return;
}

void merge_sort(int arr[], int begin, int end, int temp[])
{
    int mid;

    if (begin >= end) {
        return;
    }
    mid = (begin + end) >> 1;
    merge_sort(arr, begin, mid, temp);
    merge_sort(arr, mid+1, end, temp);
    merge_array(arr, begin, mid, end, temp);

    return;
}

#define shift(i) (i >> 5)
#define mask(i)  (i & 0x1f)

void bit_sort(int arr, int begin, int end)
{
    int i;
    int bit_arr[shift(MAX_DATA)] = {0}; 

    bit_arr[shift(arr)] |= (1 << mask(arr));
    
}
