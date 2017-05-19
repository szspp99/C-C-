#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LEN_BAND 100

bool __binary_search(int a[], int begin, int end, int key) 
{
    int mid;

    if (begin > end) {
        return false;
    }
    mid = (begin + end) >> 1;
    if (key < a[mid]) {
        return __binary_search(a, begin, mid -1, key);
    } else if (key > a[mid]) {
        return __binary_search(a, mid + 1, end, key);
    } else {
        return true;
    }

}

/*
@len 根据len的长度选择二分查找算法：当len小于100时选择递归，大于100时选择非递归
*/
bool binary_search(int a[], int len, int key)
{
    int begin, mid, end;

    begin = 0;
    end = len - 1;

    if (len < MAX_LEN_BAND) {
        return __binary_search(a, begin, end, key); //递归查找
    }

    while (begin <= end) {
        mid = (begin + end) >> 1;
        if (a[mid] == key) {
            return true;
        } else if (a[mid] < key) {
            begin = mid + 1;
        } else {
            end = mid -1;
        }
    }

    return false;
}

int main(int argc, char *argv[])
{
    int a[] = {1,3,7,9,10,16,19,20,30};
    int key = 1;
    int i;
    int len = sizeof(a)/sizeof(a[0]);

    for (i=0; i<len; i++) {
        printf("%d  ", a[i]);
    }

    if (argc == 2) {
        key = atoi(argv[1]);
    }

    printf("\nkey = %d.\n", key);
    if (binary_search(a, len, key)) {
        printf("find ok!\n");
    } else {
        printf("Not find!\n");
    }

    return 0;
}
