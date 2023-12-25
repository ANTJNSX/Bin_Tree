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
    node* result = malloc(sizeof(node));
    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

int insertNode(node *root, node *newNode) {
    if ((root != NULL) && (newNode != NULL)) { // check if root 
        int rootVal = root->value;
        int nodeVal = newNode->value;
        if (rootVal == newNode->value) {
            return root->value; // handle root before adding 
        }
        
        if (nodeVal > rootVal) { // check right
            if ((root->right == NULL) || (nodeVal == rootVal)) {
                root->right = newNode; 
                return newNode->value;
            }
            insertNode(newNode, root->right);
        }

        if (nodeVal < rootVal) { // check left
            if ((root->left == NULL) || (nodeVal == rootVal)) {
                root->left = newNode; 
                return newNode->value;
            }
            insertNode(newNode, root->left);
        }
    }
}


int getValue(node *root, int value) {
    if ((root != NULL) ) { // check if root 
        int rootVal = root->value;
        if (rootVal == value) {
            return value; // handle root before adding 
        }
        
        if (value > rootVal) { // check right
            if (root->right == NULL) {
                return value;
            }
            getValue(root->right, value);
        }

        if (value < rootVal) { // check left
            if (root->left == NULL) {
                return value;
            }
            getValue(root->left, value);
        }

    }

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
    
    int fiveexists = getValue(root, 5);

    printf("%d\n", fiveexists);

    freeBST(root);
    return 0;
}

