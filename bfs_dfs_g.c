#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* adjacencyList[MAX_VERTICES];
    int numVertices;
} Graph;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initializeGraph(Graph* graph, int numVertices) {
    int i;
    graph->numVertices = numVertices;
    for (i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
}

void addEdge(Graph* graph, int source, int destination) {
    if (source >= 0 && source < graph->numVertices && destination >= 0 && destination < graph->numVertices) {
        Node* newNode = createNode(destination);
        newNode->next = graph->adjacencyList[source];
        graph->adjacencyList[source] = newNode;

        // For undirected graph, add an edge from destination to source as well
        newNode = createNode(source);
        newNode->next = graph->adjacencyList[destination];
        graph->adjacencyList[destination] = newNode;
    } else {
        printf("Invalid edge!\n");
    }
}

void dfsRecursive(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjacencyList[vertex];
    while (temp != NULL) {
        int adjacentVertex = temp->data;
        if (!visited[adjacentVertex]) {
            dfsRecursive(graph, adjacentVertex, visited);
        }
        temp = temp->next;
    }
}

void dfsTraversal(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = { 0 };
    dfsRecursive(graph, startVertex, visited);
    printf("\n");
}

void bfsTraversal(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = { 0 };
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front != rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        Node* temp = graph->adjacencyList[vertex];
        while (temp != NULL) {
            int adjacentVertex = temp->data;
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = 1;
                queue[rear++] = adjacentVertex;
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

int main() {
    Graph graph;
    initializeGraph(&graph, 6);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 3, 5);
    addEdge(&graph, 4, 5);

    printf("DFS Traversal: ");
    dfsTraversal(&graph, 0);

    printf("BFS Traversal: ");
    bfsTraversal(&graph, 0);

    return 0;
}
