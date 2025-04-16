#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next; 
}Node;

struct _list {
    Node* start;
};

Node* Node_create(int data) {
    Node* node = malloc(sizeof(Node));
    if(node != NULL) {
        node->next = NULL;
        node->data = data;
    }
    return node;
}

LinkedList* LinkedList_create() {
    LinkedList* list = malloc(sizeof(LinkedList));
    if(list != NULL) 
        list->start = NULL;
    return list;
}

bool LinkedList_insert_begin(LinkedList* list, int data) {
    Node* node = Node_create(data);
    if(node == NULL) return false;
    if(list->start != NULL)
        node->next = list->start;
    list->start = node;
    return true;
}

bool LinkedList_insert_end(LinkedList* list, int data) {
    Node* node = Node_create(data);
    if(node == NULL) return false;
    if(list->start == NULL) {
        list->start = node;
    }else{
        Node* aux = list->start;
        while(aux->next != NULL) 
            aux = aux->next;
        aux->next = node;
    }
    return true;
}

void LinkedList_print(LinkedList* list) {
    Node* aux = list->start;
    while(aux->next != NULL) {
        printf("%d ", aux->data);
        aux = aux->next;
    }
}
