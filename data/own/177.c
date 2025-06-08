#include <stdlib.h> // Added for malloc and free

// Moved dfs function outside and modified its signature
void dfs(int node, int n, int **graph, int *visited) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, n, graph, visited); // Pass parameters in recursive call
        }
    }
}

// Snippet 7: Graph DFS (Depth-First Search) Traversal
void dfs_graph() {
    int n = 1000;  // Number of nodes
    int **graph = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*) calloc(n, sizeof(int)); // Changed malloc to calloc to initialize memory to zero
    }

    int *visited = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) { // Initialize visited array
        visited[i] = 0;
    }

    // Example: Start DFS from node 0
    dfs(0, n, graph, visited); // Call the modified dfs function

    free(visited);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
}

int main() {
    dfs_graph();
    return 0;
}
