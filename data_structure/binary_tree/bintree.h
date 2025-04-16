#ifndef BINTREE_H
#define BINTREE_H
#include <stdbool.h>

typedef struct _no {
    int key;
    struct _no *left, *right, *parent;
}Node;

typedef struct {
    Node* root;
}BinTree;

BinTree* BinTree_create();
bool BinTree_insert(BinTree*, int);
Node* BinTree_search(Node*, int);
Node* BinTree_search_r(Node*, int);
void BinTree_pre(Node*);
void BinTree_in(Node*);
void BinTree_pos(Node*);

#endif