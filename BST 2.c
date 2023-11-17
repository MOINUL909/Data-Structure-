#include <stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *left, *right;
};

struct Node *createNode(int data) {
  struct Node *node = malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void insertNode(struct Node *root, int data) {
  if (root == NULL) {
    root = createNode(data);
  } else if (data < root->data) {
    insertNode(root->left, data);
  } else {
    insertNode(root->right, data);
  }
}

void printInOrder(struct Node *root) {
  if (root == NULL) {
    return;
  }
  printInOrder(root->left);
  printf("%d\n", root->data);
  printInOrder(root->right);
}

int main() {
  struct Node *root = NULL;
  insertNode(root, 10);
  insertNode(root, 5);
  insertNode(root, 15);
  insertNode(root, 20);
  insertNode(root, 7);
  printInOrder(root);
  return 0;
}
