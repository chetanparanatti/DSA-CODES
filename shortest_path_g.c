#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define V 4

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the shortest path from source to destination
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%c ", j + 'A');  // Assuming 'A' is the starting node
        return;
    }

    printPath(parent, parent[j]);
    printf("%c ", j + 'A');
}

// Function to print the shortest distances and paths from source to all vertices
void printSolution(int dist[], int parent[]) {
    printf("Vertex\t Distance\t Path\n");
    for (int i = 0; i < V; i++) {
        printf("%c\t %d\t\t ", i + 'A', dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

// Function that implements Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // Stores the shortest distance from source to vertices
    int visited[V];  // Marks visited vertices
    int parent[V];   // Stores the parent node for each vertex in the shortest path

    // Initialize all distances as infinite and visited as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    parent[src] = -1;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Choose the minimum distance vertex from the set of unvisited vertices
        int u = minDistance(dist, visited);

        // Mark the selected vertex as visited
        visited[u] = 1;

        // Update the distance value of the adjacent vertices of the selected vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it is not visited, there is an edge from u to v,
            // and the total weight of the path from source to v through u is smaller than the current value of dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the shortest distances and paths
    printSolution(dist, parent);
}

int main() {
    // Example graph
    int graph[V][V] = {
        {0, 2, 0, 0},
        {2, 0, 1, 3},
        {0, 1, 0, 4},
        {0, 3, 4, 0}
    };

    int source = 0;  // Source vertex

    dijkstra(graph, source);

    return 0;
}
