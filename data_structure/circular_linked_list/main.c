#include "circularlist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    CircularList* list = CircularList_create();
    
    CircularList_insert_begin(list, 5);
    CircularList_insert_end(list, 8);
    CircularList_insert_end(list, 10);
    CircularList_insert_end(list, 13);
    CircularList_insert_begin(list, 20);
    
    CircularList_print(list);
}
