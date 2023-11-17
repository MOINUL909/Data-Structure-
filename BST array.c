#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left, *right;
};

struct Node *newNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void insert(struct Node **root, int data) {
  if (*root == NULL) {
    *root = newNode(data);
  } else {
    if (data < (*root)->data) {
      insert(&(*root)->left, data);
    } else {
      insert(&(*root)->right, data);
    }
  }
}

void inorder(struct Node *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

int main() {
  struct Node *root = NULL;
  int data[] = {15, 10, 20, 8, 12, 17, 25};
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
    insert(&root, data[i]);
  }
  printf("Inorder traversal: ");
  inorder(root);
  printf("\n");
  return 0;
}
