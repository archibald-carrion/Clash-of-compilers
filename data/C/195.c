#include <stdio.h>  // For printf
#include <stdlib.h> // For malloc, free
#include <time.h>   // For srand, time

// DFS for the first pass of Kosaraju's algorithm (fills finish_stack)
void dfs1_kosaraju(int u, int n, int **graph, int *visited, int *finish_stack, int *top) {
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
        if (graph[u][v] == 1 && !visited[v]) {
            dfs1_kosaraju(v, n, graph, visited, finish_stack, top);
        }
    }
    finish_stack[++(*top)] = u;
}

// DFS for the second pass of Kosaraju's algorithm (marks nodes in an SCC)
void dfs2_kosaraju(int u, int n, int **graph, int *visited) {
    visited[u] = 1;
    // In a full implementation, nodes visited here would be part of one SCC
    for (int v = 0; v < n; v++) {
        if (graph[u][v] == 1 && !visited[v]) {
            dfs2_kosaraju(v, n, graph, visited);
        }
    }
}

// Transpose the graph
void transpose_graph(int **graph, int n) {
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

// Snippet 185: Finding Strongly Connected Components (Kosaraju's Algorithm)
void kosaraju_scc() {
    int n = 1000;  // Number of vertices
    int **graph = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*) malloc(n * sizeof(int));
        // Initialize graph with random adjacency data
        for (int j = 0; j < n; j++) {
            graph[i][j] = (rand() % 5 == 0) ? 1 : 0; // Random edges
        }
    }

    int *visited = (int*) malloc(n * sizeof(int));
    int *finish_stack = (int*) malloc(n * sizeof(int));
    int top = -1;
    int scc_count = 0;

    // Initialize visited array for first DFS pass
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Kosaraju's algorithm: First pass - fill finish_stack
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1_kosaraju(i, n, graph, visited, finish_stack, &top);
        }
    }

    transpose_graph(graph, n);

    // Reset visited array for second DFS pass
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Second pass - process nodes in order of decreasing finishing times
    while (top != -1) {
        int v = finish_stack[top--];
        if (!visited[v]) {
            dfs2_kosaraju(v, n, graph, visited);
            scc_count++; // Count SCCs
        }
    }
    
    printf("Number of Strongly Connected Components: %d\n", scc_count);

    free(visited);
    free(finish_stack);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
}

int main() {
    srand(time(NULL));
    kosaraju_scc();
    return 0;
}
