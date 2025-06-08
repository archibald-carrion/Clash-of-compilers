// Snippet 6: Dijkstra's Algorithm for Shortest Path (with priority queue simulation)
void dijkstra_with_priority_queue() {
    int n = 1000;  // Number of nodes
    int **graph = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*) malloc(n * sizeof(int));
    }

    int *dist = (int*) malloc(n * sizeof(int));
    int *visited = (int*) malloc(n * sizeof(int));

    // Initialize graph
    for (int i = 0; i < n; i++) {
        dist[i] = 1000000;
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = (i == j) ? 0 : rand() % 100 + 1;
        }
    }

    dist[0] = 0;  // Starting node
    // Simple priority queue simulation
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