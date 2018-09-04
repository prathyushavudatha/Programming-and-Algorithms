#include "list.h"
#include <stdlib.h>

List* newList()
{
    List *newlist = malloc(sizeof(List));
	newlist->head = newlist->tail = NULL;
    newlist->insert = insertList;
	newlist->read = readList;
	newlist->remove = removeList;
	newlist->delete = deleteList;
	return newlist;
}

void insertList(List* list,int index,Data data)
{
	Node *N = malloc(sizeof(Node));
	N->data = data;
	N->next = N->prev = NULL;
	if(list->head == NULL)      // Accessing the head of the list
    {
		list->head =  N;
		list->tail = N;
		return;
    }
	Node *Iter =  malloc(sizeof(Node));
	Iter = list->head;
	int i;
	for(i=0;i<index;i++)        // Find the node currently at index i
    {
        if(Iter->next != NULL)
        Iter = Iter->next;
	}
    Iter->next = N;
    N->prev = Iter;
    list->tail = N;
    N->next = NULL;
}
Data * readList(List *list,int index)
{
	int i;
	Node *Iter = list->head;
	for(i=0;i<index;i++)
        if(Iter->next != NULL)
            Iter=Iter->next;
        else
            return NULL;
    return &Iter->data;
}

void removeList(List *list,int index)
{
    if(index==0)
    {
        if(list->head == list->tail)
        {
            list->head = NULL;
            list->tail = NULL;
            return;
        }
    }
	Node *Iter = malloc(sizeof(Node));
    Iter = list->head;
    int i;
    for(i=0;i<index;i++)
        if(Iter->next != NULL)
            Iter=Iter->next;
	if(list->head == list->tail)
    {   // check for empty list
		list->head = list->tail = NULL;
        free(Iter);
		return;
	}
	if(Iter->next == NULL)
    {
		Iter->prev->next = NULL;
		list->tail = Iter->prev;
		Iter->prev = NULL;
        free(Iter);
		return;
	}
	if(Iter->prev == NULL)
	{
		list->head = Iter->next;
		Iter->next->prev = NULL;
		Iter->next = NULL;
        free(Iter);
		return;
	}
    Iter->next->prev = Iter->prev;
    Iter->prev->next = Iter->next;
    Iter->next = Iter->prev = NULL;
	free(Iter);
	return;
}

void deleteList(List *list)
{
	free(list->tail);
	free(list->head);
	free(list);
}
