/*
 * Author: Anton Jonsson
 * 
 * Simple bst implementation without malloc for safety
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

    // Tree attributes
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node;

    // Tree functions
node *createNode(int value) {
    node* result = malloc(sizeof(value));
    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

node *insertNode(node *root, node *newNode) {
    if ((root != NULL) || (newNode->value == root->value)) {
       return root; // handle root before adding 
    }

    return newNode;
}

int main() {
    node *root = createNode(10); // initialize tree basically
    
    printf("%d\n", root->value);
   
    node *rootCh = createNode(5);

    printf("%d\n", rootCh->value);

    root->left = rootCh; 

    printf("%d\n", root->left->value);

    free(rootCh);
    free(root);
    return 0;
}

