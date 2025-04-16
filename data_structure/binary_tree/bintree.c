#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

Node* Node_create(int key) {
    Node* new_node = malloc(sizeof(Node));
    if(new_node) {
        new_node->key = key;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->parent = NULL;
    }
    return new_node;
}

BinTree* BinTree_create() {
    BinTree* new_tree = malloc(sizeof(BinTree));
    if(new_tree)
        new_tree->root = NULL;
    return new_tree;
}

bool BinTree_insert(BinTree* tree, int key) {
    Node *new_node = Node_create(key);
    if(new_node == NULL) return false;
    
    Node *run_tree = tree->root, *new_parents = NULL;
    while(run_tree != NULL) {
        new_parents = run_tree;
        if(new_node->key < run_tree->key) {
            run_tree = run_tree->left;
        }else run_tree = run_tree->right;
    }

    new_node->parent = new_parents;
    if(new_parents == NULL) {
        tree->root = new_node;
    }else{
        if(new_node->key < new_parents->key) {
            new_parents->left = new_node;
        }else{
            new_parents->right = new_node;
        }
    }
    return true;
}

Node* BinTree_search(Node* root, int key) {
    Node* node = root;

    while(node->key != key && node != NULL) {
        if(key < node->key)
            node = node->left;
        else node = node->right;
    }
    return node;
}

Node* BinTree_search_r(Node* node, int key) {
    if(node == NULL || key == node->key) 
        return node;
    if(key < node->key)
        return BinTree_search_r(node->left, key);
    else return BinTree_search_r(node->right, key);
}

void BinTree_pre(Node* node) {
    if(node != NULL) {
        printf("%d ", node->key);
        BinTree_pre(node->left);
        BinTree_pre(node->right);
    }
}

void BinTree_in(Node* node) {
    if(node != NULL) {
        BinTree_in(node->left);
        printf("%d ", node->key);
        BinTree_in(node->right);
    }
}

void BinTree_pos(Node* node) {
    if(node != NULL) {
        BinTree_pos(node->left);
        BinTree_pos(node->right);
        printf("%d ", node->key);
    }
}
