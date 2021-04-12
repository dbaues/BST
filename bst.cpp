#include "bst.h"

NODE* insertNode(NODE* node, int value){
    if(node == nullptr){ return new NODE(node, value); }
    else if(value < node->value){
        if(node->left == nullptr)
            node->left = new NODE(node, value);
        else{ insertNode(node->left, value); }
    }
    else if(value > node->value){
        if(node->right == nullptr)
            node->right = new NODE(node, value);
        else{ insertNode(node->right, value); }
    }
    else{ std::cerr << "Cannot support duplicate values.\n"; }
    return node;
}

void deleteNode(NODE* node, int value){
    if(node == nullptr){ return; }
    else if(value < node->value){ deleteNode(node->left, value); }
    else if(value > node->value){ deleteNode(node->right, value); }
    else{
        if(node->left == nullptr && node->right == nullptr){
            NODE* parent = node->parent;
            if(parent != nullptr){
                if(parent->left == node){ parent->left = nullptr; }
                else if(parent->right == node){ parent->right = nullptr; }
            }
            delete(node);
        }
        else if(node->right == nullptr){
            NODE* predecessor = node->left;
            while(true){
                if(predecessor->right == nullptr){ break; }
                else{ predecessor = predecessor->right; }
            }
            node->value = predecessor->value;
            deleteNode(predecessor, predecessor->value);
        }
        else{
            NODE* successor = node->right;
            while(true){
                if(successor->left == nullptr){ break; }
                else{ successor = successor->left; }
            }
            node->value = successor->value;
            deleteNode(successor, successor->value);
        }
    }
}

void printTree(NODE *node, int indent){
    if(node == NULL){ return; }
    else{
        printTree(node->left, indent+4);
        if( indent ){ std::cout << std::setw(indent) << " "; }
        std::cout << node->value << std::endl;
        printTree(node->right, indent+4);
    }
}