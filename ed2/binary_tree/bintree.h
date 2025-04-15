#ifndef BINTREE_H
#define BINTREE_H
#include <stdbool.h>

typedef struct _no {
    int key;
    struct _no *left, *right, *parent;
}TNo;

typedef struct {
    TNo* root;
}BinTree;

BinTree* BinTree_create();
bool BinTree_insert(BinTree*, int);
TNo* BinTree_search(TNo*, int);
TNo* BinTree_search_r(TNo*, int);
void BinTree_pre(TNo*);
void BinTree_in(TNo*);
void BinTree_pos(TNo*);

#endif