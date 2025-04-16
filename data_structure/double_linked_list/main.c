#include "dlinkedlist.h"
#include <stdio.h>

int main() {
    DLinkedList* list = DLinkedList_create();

    DLinkedList_insert_end(list, 5);
    DLinkedList_insert_end(list, 2);
    DLinkedList_insert_end(list, 3);
    DLinkedList_insert_end(list, 8);
    DLinkedList_insert_begin(list, 0);

    puts("printing double linked list: ");
    DLinkedList_print(list);
    putchar('\n');

    puts("printing reverse double linked list: ");
    DLinkedList_print_reverse(list);
    putchar('\n');

    return 0;
}