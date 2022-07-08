#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include <iomanip>

struct NODE{
    int value;
    NODE* left;
    NODE* right;
    NODE* parent;

    // Node constructor.
    NODE(NODE* p, int v){
        value = v;
        left = nullptr;
        right = nullptr;
        parent = p;
    }
};

NODE* insertNode(NODE*, int);
void deleteNode(NODE*, int);
void printTree(NODE*, int=0);

#endif
