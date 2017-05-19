#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>

#include <sys/time.h>

#include "sort.h"

using namespace std;

#define DEBUG

#define DATA_FILE "dat.txt"
#define RESULT_FILE "result.txt"

#define GET_TIME(time) (gettimeofday(&time,0))
#define DIFF_TIME(starttime, endtime, timeuse) do { \
    GET_TIME(endtime);  \
    timeuse = 1000000*(endtime.tv_sec - starttime.tv_sec) + endtime.tv_usec - starttime.tv_usec;  \
    timeuse /=1000;   \
} while (0)

int arr[MAX_DATA];
int temp[MAX_DATA];

void random_dat(void)
{
    srand((unsigned)time( NULL ) );
    for (int i= 0; i< MAX_DATA; i++) {
        arr[i] = rand()%MAX_DATA;
    }
}

int write_dat(const char *file)
{
    int i;
    FILE *fp;

    cout<<"writing "<<file<<endl;
    fp = fopen(file, "w");
    if(fp == NULL) {
        cerr<<"fopen"<<endl;
        return -1;
    }
    for (i=0; i < MAX_DATA; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);

    return 0;
}

int read_dat(const char *file)
{
    int i;
    FILE *fp;

    cout<<"Reading from:"<<file<<endl;
    fp = fopen(file, "r");
    if(fp == NULL) {
        cerr<<"fopen"<<endl;
        return -1;
    }

    for (i=0; i < MAX_DATA; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    return 0;
}

int cmp ( const void *a , const void *b ) 
{ 
return *(int *)a - *(int *)b; 
} 

int main(int argc, char **argv)
{
   double timeuse;
   timeval starttime,endtime;
//   int arr[] = {12, 3 , 6, 40, 21, 50, 1, 60, 38, 10};

#if 0
   random_dat();
   write_dat(DATA_FILE);
#endif
   read_dat(DATA_FILE);


#ifdef DEBUG 
   cout<<"input data:"<<endl;
   DUMP_DATA(arr, LEN(arr));
#endif

   cout<<"sorting:"<<endl;
   GET_TIME(starttime);
#if 1
   quick_sort(arr, 0, LEN(arr)-1);
//   merge_sort(arr, 0, LEN(arr)-1, temp);
//   sort(arr, arr+LEN(arr));
//   qsort(arr,LEN(arr),sizeof(arr[0]),cmp); 
#endif

   DIFF_TIME(starttime, endtime, timeuse);
   cout<<"Time used:"<<timeuse<<"ms"<<endl;
   write_dat(RESULT_FILE);

#ifdef DEBUG   
   cout<<"After sorted:"<<endl;
   DUMP_DATA(arr, LEN(arr));
#endif

   return 0;
}
