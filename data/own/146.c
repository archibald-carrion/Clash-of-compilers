// Snippet 6: Dijkstra's Algorithm for Single-Source Shortest Path
void dijkstra() {
    int n = 1000;  // Number of nodes
    int **graph = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*) malloc(n * sizeof(int));
    }
    int *dist = (int*) malloc(n * sizeof(int));
    int *visited = (int*) malloc(n * sizeof(int));

    // Initialize graph, dist, and visited
    for (int i = 0; i < n; i++) {
        dist[i] = 1000000;  // Set all distances to infinity
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = (i == j) ? 0 : 1000000;
        }
    }

    // Dijkstra's algorithm
    dist[0] = 0;  // Start from node 0
    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 1000000 && dist[u] + graph[u][v] < dist[v]) {
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