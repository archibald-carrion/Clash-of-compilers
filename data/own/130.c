// Snippet 10: Depth First Search (DFS) in a Graph
// Forward declaration of dfs
void dfs(int v, int n, int **graph, int *visited);

void dfs_graph() {
    int n = 1000;
    int **graph = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*) malloc(n * sizeof(int));
    }

    int *visited = (int*) malloc(n * sizeof(int));

    // Initialize graph and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;  // Assume no edges initially
        }
    }
    
    // Start DFS from vertex 0
    dfs(0, n, graph, visited);

    free(visited);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
}

// Definition of dfs function
void dfs(int v, int n, int **graph, int *visited) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i, n, graph, visited);
        }
    }
}