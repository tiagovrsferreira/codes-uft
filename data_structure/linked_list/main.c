#include "linkedlist.h"
#include <stdio.h>

int main() {
    LinkedList* list = LinkedList_create();

    LinkedList_insert_begin(list, 5);
    LinkedList_insert_end(list, 8);
    LinkedList_insert_end(list, 3);
    LinkedList_insert_end(list, 2);
    LinkedList_insert_end(list, 7);
    LinkedList_insert_end(list, 15);

    LinkedList_print(list);
}
