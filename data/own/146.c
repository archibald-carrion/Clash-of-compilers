// Snippet 6: Dijkstra's Algorithm for Single-Source Shortest Path
#include <stdlib.h> // For malloc, free
#include <limits.h> // For INT_MAX

void dijkstra(int n, int src) {
    int **graph = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*) malloc(n * sizeof(int));
    }
    int *dist = (int*) malloc(n * sizeof(int));
    int *visited = (int*) malloc(n * sizeof(int));

    // Initialize graph, dist, and visited
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;  // Set all distances to infinity
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    // Dijkstra's algorithm
    dist[src] = 0;  // Start from source node
    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(dist);
    free(visited);
}

int main() {
    // Example usage
    dijkstra(5, 0); // n=5 vertices, source vertex 0
    return 0;
}