#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

Vector * newVector()
{
    Vector * newVec = malloc(sizeof(Vector));
    newVec->current_size = 0;
    newVec->max_size = 0;
    newVec->data = NULL;
    newVec->insert = insertVector;
    newVec->read = readVector;
    newVec->remove = removeVector;
    newVec->delete = deleteVector;
    return newVec;
}
void insertVector(Vector * array, int index, Data value)
{
    if(array->max_size <= index)
    {
        array->max_size = 2*index +1;
        array->data = (Data *)realloc(array->data, array->max_size * sizeof(Data));
        int i;
        for(i=array->current_size; i<=array->max_size; i++)
        {
            array->data[i].value = -1;
            printf("\ni value = %d\n", i);
        }
        array->data[index].value = value.value;
        array->current_size = index+1;
        return;
    }
    array->data[index].value = value.value;
    if(array->current_size<=index)
        array->current_size = index+1;
    printf("\nCurrent size: %d\n", array->current_size);
    return;
}
Data * readVector(Vector * array, int index)
{
    if(index>array->max_size)
        return NULL;
    return &array->data[index];
}
void removeVector(Vector * array, int index)
{
    if(index<array->current_size)
    {
        int i = index;
        int len = array->current_size;
        while(i<len)
        {
            array->data[i].value = array->data[i+1].value;
            array->data[i+1].value = -1;
            i++;
        }
        array->current_size -=1;
    }
}
void * deleteVector(Vector * array)
{
    free(array->current_size);
    free(array->max_size);
    free(array->data);
    array->data = NULL;
    return NULL;
}
