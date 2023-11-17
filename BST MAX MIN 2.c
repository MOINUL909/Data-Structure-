#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *create_node(int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert_node(struct node *root, int data) {
  if (root == NULL) {
    root = create_node(data);
  } else if (data < root->data) {
    insert_node(root->left, data);
  } else {
    insert_node(root->right, data);
  }
}

void print_inorder(struct node *root) {
  if (root == NULL) {
    return;
  }
  print_inorder(root->left);
  printf("%d\n", root->data);
  print_inorder(root->right);
}

void make_max_heap(struct node *root) {
  if (root == NULL) {
    return;
  }
  make_max_heap(root->left);
  make_max_heap(root->right);
  swap_with_largest(root);
}

void swap_with_largest(struct node *root) {
  if (root->right == NULL) {
    return;
  }
  struct node *largest = root->right;
  while (largest->left != NULL) {
    largest = largest->left;
  }
  swap(root, largest);
}

void make_min_heap(struct node *root) {
  if (root == NULL) {
    return;
  }
  make_min_heap(root->left);
  make_min_heap(root->right);
  swap_with_smallest(root);
}

void swap_with_smallest(struct node *root) {
  if (root->left == NULL) {
    return;
  }
  struct node *smallest = root->left;
  while (smallest->right != NULL) {
    smallest = smallest->right;
  }
  swap(root, smallest);
}

int main() {
  int data[] = {10, 16, 4, 25, 54, 12, 8, 3, 20, 32};
  int n = sizeof(data) / sizeof(data[0]);

  struct node *root = NULL;
  for (int i = 0; i < n; i++) {
    insert_node(root, data[i]);
  }

  printf("Binary search tree:\n");
  print_inorder(root);

  make_max_heap(root);
  printf("\nMax heap:\n");
  print_inorder(root);

  make_min_heap(root);
  printf("\nMin heap:\n");
  print_inorder(root);

  return 0;
}
