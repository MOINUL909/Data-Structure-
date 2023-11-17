#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure for an adjacency list node
struct AdjListNode {
    int destination;
    struct AdjListNode* next;
};

// Structure for an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure for a graph
struct Graph {
    int numNodes;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* createAdjListNode(int destination) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->destination = destination;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of nodes
struct Graph* createGraph(int numNodes) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = numNodes;
    graph->array = (struct AdjList*)malloc(numNodes * sizeof(struct AdjList));

    for (int i = 0; i < numNodes; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int source, int destination) {
    struct AdjListNode* newNode = createAdjListNode(destination);
    newNode->next = graph->array[source].head;
    graph->array[source].head = newNode;

    // Uncomment the code below if the graph is directed
    /*
    newNode = createAdjListNode(source);
    newNode->next = graph->array[destination].head;
    graph->array[destination].head = newNode;
    */
}

// Function to perform Depth First Search (DFS)
void DFS(struct Graph* graph, int startNode, int visited[]) {
    visited[startNode] = 1;
    printf("%d ", startNode);

    struct AdjListNode* current = graph->array[startNode].head;
    while (current != NULL) {
        int adjacentNode = current->destination;
        if (visited[adjacentNode] == 0) {
            DFS(graph, adjacentNode, visited);
        }
        current = current->next;
    }
}

int main() {
    int numNodes = 5;
    struct Graph* graph = createGraph(numNodes);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    int startNode = 0;
    int visited[MAX_NODES] = {0};

    printf("Depth First Traversal (DFS): ");
    DFS(graph, startNode, visited);
    printf("\n");

    return 0;
}
