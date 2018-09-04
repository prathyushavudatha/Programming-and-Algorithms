
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <sys/time.h>/* timeval, gettimeofday() */
#include "vector.h"
#include "list.h"
#include "data.h"


void profileInsert(Vector * vect, List *list)
{
int i;
struct timeval start, stop;
gettimeofday(&start, NULL);
for (i=1;i<=1000;i++)
{
    insertVector(Vect, i, (Data) {i});

}

gettimeofday(&stop, NULL);
time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
float profile_time = stop_time - start_time;
printf("start_time:%ld",start_time);
printf("stop_time:%ld",stop_time);
printf("profile_time:%lf",profile_time);

gettimeofday(&start, NULL);
for (i=1;i<=1000;i++)
{
    insertList(List, i, (Data) {i});

}

gettimeofday(&stop, NULL);
time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
float profile_time = stop_time - start_time;
printf("start_time:%ld",start_time);
printf("stop_time:%ld",stop_time);
printf("profile_time:%lf",profile_time);

}


void profileRead(Vector * vect, List *list)
{
struct timeval start, stop;
gettimeofday(&start, NULL);
int index;
for (index=0; index<100;index++)
{
    index =rand()%100;
    readVector(vect, index);
}
gettimeofday(&stop, NULL);
time_t start_time_list = (start.tv_sec* 1000000) + start.tv_usec;
time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
float profile_time = stop_time - start_time;
printf("start_time:%ld",start_time);
printf("stop_time:%ld",stop_time);
printf("profile_time:%lf",profile_time);


gettimeofday(&start, NULL);
int index;
for (index=0; index<100;index++)
{
    index =rand()%100;
    readData(list, index);
}
gettimeofday(&stop, NULL);
time_t start_time_list = (start.tv_sec* 1000000) + start.tv_usec;
time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
float profile_time = stop_time - start_time;
printf("start_time:%ld",start_time);
printf("stop_time:%ld",stop_time);
printf("profile_time:%lf",profile_time);

}


void profileRemove(Vector *, List *)
{
    struct timeval start_vector, stop_vector, start_list, stop_list;
    gettimeofday(&start_vector, NULL);
    int index=0;
    for(index = 0 ; index < 100 ; i++){

        removeVector(vect, index);
    }
    gettimeofday(&stop_vector, NULL);
    time_t start_time_vector = (start_vector.tv_sec* 1000000) + start_vector.tv_usec;
    time_t stop_time_vector = (stop_vector.tv_sec* 1000000) + stop_vector.tv_usec;
    float profile_time_vector = stop_time_vector - start_time_vector;
    printf("start_time:%ld",start_time);
    printf("stop_time:%ld",stop_time);
    printf("profile_time:%lf",profile_time);

    gettimeofday(&start_vector, NULL);
    int index=0;
    for(index = 0 ; index < 100 ; i++){

        removeData(lsit, index);
    }
    gettimeofday(&stop_vector, NULL);
    time_t start_time_vector = (start_vector.tv_sec* 1000000) + start_vector.tv_usec;
    time_t stop_time_vector = (stop_vector.tv_sec* 1000000) + stop_vector.tv_usec;
    float profile_time_vector = stop_time_vector - start_time_vector;
    printf("start_time:%ld",start_time);
    printf("stop_time:%ld",stop_time);
    printf("profile_time:%lf",profile_time);


}
