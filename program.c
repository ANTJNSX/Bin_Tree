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

void insert(node* tree, int value) {
    if (tree != NULL) {
        if (value > tree->value) {
            if (tree->right == NULL)
                tree->right = createNode(value);
            else
                insert(tree->right, value);
        } else if (value < tree->value) {
            if (tree->left == NULL)
                tree->left = createNode(value);
            else
                insert(tree->left, value);
        }
    }
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
            insertNode(root->right, newNode);
        }

        if (nodeVal < rootVal) { // check left
            if ((root->left == NULL) || (nodeVal == rootVal)) {
                root->left = newNode; 
                return newNode->value;
            }
            insertNode(root->right, newNode);
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

int getSize(node *root) {
    if (root != NULL) {
        
        int sz = 1;
        
        if (root->right != NULL) {
            sz += getSize(root->right);
        }

        if (root->left != NULL) {
            sz += getSize(root->left);
        }

        return sz;

    }

    return 0;

}

int maxDepth(node *root) {
    if (root != NULL) {
        
        int leftDepth = 0;
        int rightDepth = 0;
        
        if (root->right != NULL) {
            rightDepth += maxDepth(root->right);
        }

        if (root->left != NULL) {
            leftDepth += maxDepth(root->left);
        }
        
        if (rightDepth > leftDepth) return rightDepth + 1; else return leftDepth + 1;

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
    node *root = createNode(4); // initialize tree basically
 
    printf("Printed 'root->value': %d\n", root->value);
   
        // CreateNode test

    node *rootCh = createNode(2);

    insertNode(root, rootCh);
    
        // getValue test

    int fiveexists = getValue(root, 5);

    printf("Get value test(5): %d\n", fiveexists);

        // getSize test

    int sz = getSize(root);
    printf("BST Size: %d\n", sz);

        // maxDepth test

    printf("Number 1-9 inserted\n");
    for (int i = 0; i < 10; i++) {
        insert(root, i);
    }

    printf("Max depth after insertion: %d\n", maxDepth(root));

        // free tree
    
    freeBST(root);
    printf("BST Freed\n");
    return 0;
}

