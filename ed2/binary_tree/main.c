#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    BinTree* tree = BinTree_create();

    BinTree_insert(tree, 10);
    BinTree_insert(tree, 5);
    BinTree_insert(tree, 7);
    BinTree_insert(tree, 2);
    BinTree_insert(tree, -2);

    puts("printing using pre-ordem: ");
    BinTree_pre(tree->root);
    putchar('\n');

    puts("printing using in-ordem: ");
    BinTree_in(tree->root);
    putchar('\n');

    puts("printing using pos-ordem: ");
    BinTree_pos(tree->root);
    putchar('\n');

    printf("adress of node with key 2: %p", BinTree_search(tree->root, 2));

    return 0;
}