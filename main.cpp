#include "bst.h"

using namespace std;

int main(){
    NODE* root = nullptr;
    int arr[] = {34, 23, 75, 3, 27, 94, 53, 68, 12, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    // Insert into tree.
    for(int i = 0; i < len; ++i)
        root = insertNode(root, arr[i]);

    printTree(root);

    int tmp = 0;
    for(int i = 0; i < len; ++i){
        deleteNode(root, tmp);
        printTree(root);
        std::cout << "Pick number to delete...\n0 to exit.\n";
        std::cin >> tmp;
        if(tmp == 0){ break; }
    }
}