#ifndef __SORT_H__
#define __SORT_H__
#include <iostream>
#include <string.h>

#define MAX_DATA  (70000000)
#define LEN(a) (sizeof(a)/sizeof(a[0]))

#define DUMP_DATA(arr, len) do { \
    if (len <= 10) { \
        cout<<"array:"<<endl;  \
        for (int i = 0; i< len; i++) {    \
            cout<<arr[i]<<" ";  \
        }   \
       cout<<endl;  \
    } \
}while (0)
extern void quick_sort(int arr[], int begin, int end);
extern void merge_sort(int arr[], int begin, int end, int temp[]);

#endif