#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include "data.h"


typedef struct Vec Vector;
typedef struct Vec
{
    Data *data;
    unsigned int current_size;
    unsigned int max_size;
    void (*insert)(Vector* array, int index, Data value);
    Data * (*read)(Vector * array, int index);
    void (*remove)(Vector * array, int index);
    void (*delete)(Vector * array);
}Vector;

Vector* newVector();
void insertVector(Vector * array, int index, Data value);
Data * readVector(Vector * array, int index);
void removeVector(Vector * array, int index);
void * deleteVector(Vector * array);

#endif // VECTOR_H_INCLUDED
