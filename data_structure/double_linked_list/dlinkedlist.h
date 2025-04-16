#ifndef DLINKEDLIST
#define DLINKEDLIST
#include <stdbool.h>

typedef struct _list DLinkedList;
DLinkedList* DLinkedList_create();
bool DLinkedList_insert_begin(DLinkedList*, int);
bool DLinkedList_insert_end(DLinkedList*, int);
void DLinkedList_print(DLinkedList*);
void DLinkedList_print_reverse(DLinkedList*);

#endif