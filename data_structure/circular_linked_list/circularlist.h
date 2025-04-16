#ifndef CIRCULARLIST
#define CIRCULARLIST
#include <stdbool.h>

typedef struct _clist CircularList;

CircularList* CircularList_create();
bool CircularList_insert_begin(CircularList*, int);
bool CircularList_insert_end(CircularList*, int);
void CircularList_print(CircularList*);

#endif