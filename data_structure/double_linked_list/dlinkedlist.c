#include "dlinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node {
    int data;
    struct _node *next, *prev;
}Node;

struct _list {
    Node *start, *end;
};

Node* Node_create(int data) {
    Node* new_node = malloc(sizeof(Node));
    if(new_node != NULL) {
        new_node->data = data;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    return new_node;
}

DLinkedList* DLinkedList_create() {
    DLinkedList* new_list = malloc(sizeof(DLinkedList));
    if(new_list != NULL) {
        new_list->start = NULL;
        new_list->end = NULL;
    }
    return new_list;
}

bool DLinkedList_insert_begin(DLinkedList* list, int data) {
    Node* node = Node_create(data);
    if (node == NULL) return false;
    if(list->start == NULL) {
        list->start = node;
        list->end = node;
    }else{
        node->next = list->start;
        list->start->prev = node;
        list->start = node;
    }
    return true;
}

bool DLinkedList_insert_end(DLinkedList* list, int data) {
    Node* node = Node_create(data);
    if(node == NULL) return false;
    if(list->start == NULL) {
        list->start = node;
        list->end = node;
    }else{
        list->end->next = node;
        node->prev = list->end;
        list->end = node;
    }
    return true;
}

void DLinkedList_print(DLinkedList* list) {
    Node* run = list->start;
    while(run != NULL) {
        printf("%d ", run->data);
        run = run->next;
    }
}

void DLinkedList_print_reverse(DLinkedList* list) {
    Node* run = list->end;
    while(run != NULL) {
        printf("%d ", run->data);
        run = run->prev;
    }
}