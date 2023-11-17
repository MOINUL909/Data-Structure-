#include <stdio.h>
#include <stdlib.h>


struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};


struct BSTNode* createNode(int data) {
    struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct BSTNode* insert(struct BSTNode* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}


void convertToMaxHeap(struct BSTNode* root) {
    if (root == NULL) {
        return;
    }


    struct BSTNode* temp = root->left;
    root->left = root->right;
    root->right = temp;


    convertToMaxHeap(root->left);
    convertToMaxHeap(root->right);
}


void convertToMinHeap(struct BSTNode* root) {
    if (root == NULL) {
        return;
    }


    struct BSTNode* temp = root->left;
    root->left = root->right;
    root->right = temp;


    convertToMinHeap(root->left);
    convertToMinHeap(root->right);
}


void printInorder(struct BSTNode* root) {
    if (root == NULL) {
        return;
    }

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    struct BSTNode* root = NULL;


    root = insert(root, 10);
    root = insert(root, 16);
    root = insert(root, 4);
    root = insert(root, 25);
    root = insert(root, 54);
    root = insert(root, 12);
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 20);
    root = insert(root, 32);

    printf("Binary Search Tree (Inorder): ");
    printInorder(root);
    printf("\n");


    convertToMaxHeap(root);

    printf("Max Heap (Inorder): ");
    printInorder(root);
    printf("\n");


    convertToMinHeap(root);

    printf("Min Heap (Inorder): ");
    printInorder(root);
    printf("\n");
    return 0;
}
