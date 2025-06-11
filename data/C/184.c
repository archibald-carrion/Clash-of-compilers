// Snippet 174: Finding Strongly Connected Components (Kosaraju's Algorithm)
#include <stdlib.h> // Added for malloc and free

// Forward declarations or define in order of dependency
static void dfs_kosaraju(int u, int n, int **graph, int *visited, int *finish_stack, int *top) {
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
        if (graph[u][v] == 1 && !visited[v]) {
            dfs_kosaraju(v, n, graph, visited, finish_stack, top);
        }
    }
    finish_stack[++(*top)] = u;
}

static void transpose_graph(int **graph, int n) { // Renamed to avoid conflict if other files have 'transpose'
    int **transposed = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        transposed[i] = (int*) malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transposed[i][j] = graph[j][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = transposed[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        free(transposed[i]);
    }
    free(transposed);
}

void kosaraju_scc() {
    int n = 1000;  // Number of vertices
    int **graph = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*) malloc(n * sizeof(int));
        // Assuming graph initialization happens elsewhere or is simplified for snippet
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0; // Example initialization
        }
    }

    int *visited = (int*) malloc(n * sizeof(int));
    int *finish_stack = (int*) malloc(n * sizeof(int));
    int top = -1;

    // Kosaraju's algorithm to find strongly connected components
    for (int i = 0; i < n; i++) {
        visited[i] = 0; // Initialize visited for first DFS pass
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs_kosaraju(i, n, graph, visited, finish_stack, &top);
        }
    }

    transpose_graph(graph, n);

    // Reset visited array for second DFS
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    while (top != -1) {
        int v = finish_stack[top--];
        if (!visited[v]) {
            // For the second DFS pass, the output (SCCs) would typically be collected.
            // The original dfs function is reused here.
            // A separate dfs function or modification might be needed if SCCs are to be printed/stored.
            // For now, just calling dfs_kosaraju as per original structure.
            // Note: The second DFS typically uses the transposed graph and processes nodes in order of finish_stack.
            // The 'top' for the second DFS pass should be managed carefully if dfs_kosaraju modifies it.
            // For simplicity, we'll assume the second DFS is for traversal and doesn't rebuild a finish stack.
            // To avoid modifying 'top' in the second pass for finish_stack, we can pass a dummy 'top' or adjust dfs_kosaraju.
            // However, the original code reuses dfs, implying it's for traversal.
            // The second DFS explores components.
            int dummy_top = -1; // Or pass NULL if dfs_kosaraju handles it, or a different DFS for 2nd pass.
                                // For now, let's assume the original intent was to reuse the same DFS logic.
                                // The second DFS explores components.
            dfs_kosaraju(v, n, graph, visited, finish_stack, &dummy_top); // graph is now transposed
        }
    }

    free(visited);
    free(finish_stack);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
}

int main() {
    kosaraju_scc();
    return 0;
}
