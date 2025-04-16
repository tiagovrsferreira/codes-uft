#ifndef LINKEDLIST
#define LINKEDLIST
#include <stdbool.h>

typedef struct _list LinkedList;
LinkedList* LinkedList_create();
bool LinkedList_insert_begin(LinkedList*, int);
bool LinkedList_insert_end(LinkedList*, int);
void LinkedList_print(LinkedList*);

#endif