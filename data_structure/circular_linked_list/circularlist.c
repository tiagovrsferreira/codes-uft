#include "circularlist.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
}Node;

struct _clist {
    Node *start;
};

Node* Node_create(int data) {
    Node* new_node = malloc(sizeof(Node));
    if(new_node) {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

CircularList* CircularList_create() {
    CircularList* new_list = malloc(sizeof(CircularList));
    if(new_list)
        new_list->start = NULL;
    return new_list;
}

bool CircularList_insert_begin(CircularList* list, int data) {
    Node* node = Node_create(data);
    if(!node) return false;
    if(!list->start) {
        node->next = node;
        list->start = node;
    }else{
        Node* run = list->start;
        while(run->next != list->start) 
            run = run->next;
        run->next = node;
        node->next = list->start;
        list->start = node;
    }
    return true;
}

bool CircularList_insert_end(CircularList* list, int data) {
    Node* node = Node_create(data);
    if(!node) return false;
    if(!list->start) {
        node->next = node;
        list->start = node;
    }else{
        Node* run = list->start;
        while(run->next != list->start) 
            run = run->next;
        run->next = node;
        node->next = list->start;
    }
    return true;
}

void CircularList_print(CircularList* list) {
    Node* run = list->start;
    do{
        printf("%d ", run->data);
        run = run->next;
    }while(run != list->start);
}