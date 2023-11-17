#include <stdio.h>
#include <stdlib.h>
struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};
typedef struct BSTNode SM;
SM *createNode(int data)
{
    SM*sami;
    sami=(SM*)malloc(sizeof(SM));
    sami->data=data;
    sami->left=NULL;
    sami->right=NULL;
    return sami;
}


SM*insert(SM*root,int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}


void convertToMaxHeap(SM* root) {
    if (root == NULL) {
        return;
    }


    SM* moinul = root->left;
    root->left = root->right;
    root->right = moinul;


    convertToMaxHeap(root->left);
    convertToMaxHeap(root->right);
}


void convertToMinHeap(SM* root) {
    if (root == NULL) {
        return;
    }


    SM* moinul = root->left;
    root->left = root->right;
    root->right = moinul;


    convertToMinHeap(root->left);
    convertToMinHeap(root->right);
}


void printInorder(SM* root) {
    if (root == NULL) {
        return;
    }

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    SM* root = NULL;


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
