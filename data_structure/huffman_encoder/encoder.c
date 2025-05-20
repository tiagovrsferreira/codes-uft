#include "encoder.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _node{
    struct _node* next;
    int freq;
    char key;
}Node;

typedef struct _list{
    Node* root;
}List;

typedef struct _tree{
    struct _tree* left;
    struct _tree* right;
    int freq;
}Tree;

List* List_create() {
    List* new_list = malloc(sizeof(List));
    if(new_list)
        new_list->root = NULL;
    return new_list;
}

Node* Node_create(char key) {
    Node* new_node = malloc(sizeof(Node));
    if(new_node) {
        new_node->freq = 1;
        new_node->next = NULL;
        new_node->key = key;
    }
    return new_node;
}

bool List_add(List* list, char key) {
    Node* node = Node_create(key);
    if(!node) return false;
    if(list->root == NULL) {
        list->root = node;
    }else{
        Node* run = list->root;
        while(run->next != NULL)
            run = run->next;
        run->next = node;
    }return true;
}

bool isRepeated(List* list, char key) {
    if(list->root == NULL) return false;
    Node* run = list->root;
    while(run != NULL) {
        if(key == run->key) 
            return true;
        run = run->next;
    }
    return false;
}

void String_to_list(List* list, char string[]) {
    unsigned int size = strlen(string);
    for(int i = 0; i < size; i++) {
        if(isRepeated(list, string[i])) {
            Node* run = list->root;
            while(run->key != string[i])
                run = run->next;
            run->freq++;
        }else List_add(list, string[i]);
    }
}

int getLessFreq(List* list) {
    Node* run = list->root;
    Node* less = list->root;
    while(run != NULL) {
        if(run->freq == NULL) {
            run = run->next;
            continue;
        }
        if(run->freq < less->freq) {
            less = run;
        }
        run = run->next;
    }
    int freq = less->freq;
    less->freq = NULL;
    return freq;
}