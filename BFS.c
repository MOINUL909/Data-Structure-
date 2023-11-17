#include <stdio.h>

struct Node {
  int data;
  struct Node *left, *right;
};

void breadthFirstTraversal(struct Node *root) {
  // Create a queue to store the nodes that have not been visited yet.
  struct Node *queue[1000];
  int front = 0, rear = 0;

  // Add the root node to the queue.
  queue[rear++] = root;

  // While the queue is not empty, do the following:
  while (front < rear) {
    // Remove the first node from the queue.
    struct Node *node = queue[front++];

    // Print the data of the node.
    printf("%d \n", node->data);

    // Add the left and right child nodes of the node to the queue if they are not null.
    if (node->left != NULL) {
      queue[rear++] = node->left;
    }
    if (node->right != NULL) {
      queue[rear++] = node->right;
    }
  }
}

int main() {
  // Create a tree.
  struct Node *root = malloc(sizeof(struct Node));
  root->data = 1;
  root->left = malloc(sizeof(struct Node));
  root->left->data = 2;
  root->right = malloc(sizeof(struct Node));
  root->right->data = 3;
  root->left->left = malloc(sizeof(struct Node));
  root->left->left->data = 4;
  root->left->right = malloc(sizeof(struct Node));
  root->left->right->data = 5;

  // Print the tree in Breadth First traversal order.
  breadthFirstTraversal(root);

  return 0;
}

