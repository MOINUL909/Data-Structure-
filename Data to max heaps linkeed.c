#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure for the max heap
struct MaxHeap {
    struct Node* head;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new element into the max heap
void insert(struct MaxHeap* heap, int data) {
    struct Node* newNode = createNode(data);
    if (heap->head == NULL) {
        heap->head = newNode;
    } else {
        struct Node* curr = heap->head;
        struct Node* prev = NULL;
        while (curr != NULL && curr->data > data) {
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

// Function to print the max heap
void printMaxHeap(struct MaxHeap* heap) {
    struct Node* curr = heap->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct MaxHeap heap;
    heap.head = NULL;

    // Inserting the given data into the max heap
    insert(&heap, 15);
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 8);
    insert(&heap, 12);
    insert(&heap, 17);
    insert(&heap, 25);

    // Printing the max heap
    printf("Max Heap: ");
    printMaxHeap(&heap);

    return 0;
}
