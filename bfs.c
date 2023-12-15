#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list
struct AdjList {
    struct Node* head;
};

// Structure to represent the graph
struct Graph {
    int vertices;
    struct AdjList* array;
};

// Function prototypes
struct Node* createNode(int vertex);
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void displayGraph(struct Graph* graph);
void BFS(struct Graph* graph, int startVertex);

int main() {
    int vertices, edges, i, src, dest, startVertex;

    // Get the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Create a graph with the given number of vertices
    struct Graph* graph = createGraph(vertices);

    // Get edges and add them to the graph
    for (i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Display the graph
    printf("\nGraph representation (adjacency list):\n");
    displayGraph(graph);

    // Get the starting vertex for BFS
    printf("\nEnter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    // Perform BFS starting from the given vertex
    printf("\nBFS traversal starting from vertex %d:\n", startVertex);
    BFS(graph, startVertex);

    return 0;
}

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    int i;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Create an array of adjacency lists
    graph->array = (struct AdjList*)malloc(vertices * sizeof(struct AdjList));

    // Initialize each adjacency list as empty
    for (i = 0; i < vertices; i++)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Add an edge from dest to src (assuming an undirected graph)
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to display the graph
void displayGraph(struct Graph* graph) {
    int i;
    for (i = 0; i < graph->vertices; i++) {
        printf("Adjacency list for vertex %d: ", i);
        struct Node* current = graph->array[i].head;
        while (current != NULL) {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Function to perform Breadth-First Search (BFS)
void BFS(struct Graph* graph, int startVertex) {
    // Create a boolean array to keep track of visited vertices
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; i++)
        visited[i] = false;

    // Create a queue for BFS
    int* queue = (int*)malloc(graph->vertices * sizeof(int));
    int front = -1, rear = -1;

    // Enqueue the starting vertex and mark it as visited
    queue[++rear] = startVertex;
    visited[startVertex] = true;

    while (front != rear) {
        // Dequeue a vertex and print it
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        // Explore adjacent vertices
        struct Node* current = graph->array[currentVertex].head;
        while (current != NULL) {
            int adjacentVertex = current->vertex;
            if (!visited[adjacentVertex]) {
                // Enqueue the adjacent vertex and mark it as visited
                queue[++rear] = adjacentVertex;
                visited[adjacentVertex] = true;
            }
            current = current->next;
        }
    }

    printf("\n");

    // Free allocated memory
    free(visited);
