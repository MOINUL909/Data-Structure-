
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure for the min heap
struct MinHeap {
    struct Node* head;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new element into the min heap
void insert(struct MinHeap* heap, int data) {
    struct Node* newNode = createNode(data);
    if (heap->head == NULL) {
        heap->head = newNode;
    } else {
        struct Node* curr = heap->head;
        struct Node* prev = NULL;
        while (curr != NULL && curr->data < data) {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) {
            newNode->next = heap->head;
            heap->head = newNode;
        } else {
            prev->next = newNode;
            newNode->next = curr;
        }
    }
}

// Function to print the min heap
void printMinHeap(struct MinHeap* heap) {
    struct Node* curr = heap->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct MinHeap heap;
    heap.head = NULL;

    // Inserting the given data into the min heap
    insert(&heap, 15);
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 8);
    insert(&heap, 12);
    insert(&heap, 17);
    insert(&heap, 25);

    // Printing the min heap
    printf("Min Heap: ");
    printMinHeap(&heap);

    return 0;
}
