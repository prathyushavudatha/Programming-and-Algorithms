#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "data.h"

typedef struct Node{
    Data data;
	struct Node *next;
	struct Node *prev;
}Node;

typedef struct List{
	Node *head,*tail;
	void (*insert)(struct List*,int,Data);
	Data* (*read)(struct List*,int);
	void (*remove)(struct List*,int);
	void (*delete)(struct List*);
}List;

List* newList();
void insertList(List *,int,Data);
Data* readList(List *,int);
void removeList(List *,int);
void deleteList(List *);

#endif // LIST_H_INCLUDED
