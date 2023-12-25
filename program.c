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
    if ((root != NULL) && (newNode != NULL)) { // check if root 
        int rootVal = root->value;
        int nodeVal = newNode->value;
        if (rootVal == newNode->value) {
            return root; // handle root before adding 
        }
        
        if (nodeVal > rootVal) { // check right
            if (root->right == NULL) {
                root->right = newNode; 
                return newNode->value;
            }
            instertNode(newNode, root->right);
        }

        if (nodeVal < rootVal) { // check left
            if (root->left == NULL) {
                root->left = newNode; 
                return newNode->value;
            }
            instertNode(newNode, root->left);
        }

    }

    return newNode;
}

void freeBST(node* root) {
    if (root == NULL) {
        return;
    }

    freeBST(root->left);
    freeBST(root->right);
    free(root);
}
        

int main() {
    node *root = createNode(10); // initialize tree basically
 
    printf("%d\n", root->value);
   
    node *rootCh = createNode(5);

    insertNode(root, rootCh);

    printf("%d\n", root->left->value);

    freeBST(root);
    return 0;
}

