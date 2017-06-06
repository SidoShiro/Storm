#include <stdlib.h>
#include <stdio.h>

// type Binary Tree
struct binT {
    struct binT *left;
    struct binT *right;
    int val;
};

// Functions

struct binT* createBT(int val, struct binT* left, struct binT* right) {
    struct binT* node = malloc(sizeof(struct binT));
    node->val = val;
    node->left = left;
    node->right = right;
    return node;
}

struct binT* buildrecTree(int nodes) {
    if (nodes < 0) {
        printf("Argument error in buildrecTree");
        return NULL;
    }

    struct binT* root = createBT(0, NULL, NULL);
    
    int x = 1;
    int y = 2;

    while(x <= nodes && y <= nodes)
    {
        
        x = x * 2 + 1;
        y = y * 2;
    }


    return root;
}


