#include <stdlib.h> // For malloc, free
#include <time.h> // For srand, time

// Snippet 188: Prim's Algorithm for Minimum Spanning Tree (MST)
void prims_mst() {
    int n = 1000;  // Number of nodes
    int **graph = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*) malloc(n * sizeof(int));
        // Graph should be initialized with edge weights.
        for (int j = 0; j < n; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = (rand() % 100) + 1; // Random weight
            // Or graph[i][j] = 1000000; for many non-edges
        }
    }

    int *key = (int*) malloc(n * sizeof(int));
    int *parent = (int*) malloc(n * sizeof(int));
    int *mst_set = (int*) malloc(n * sizeof(int));

    // Initialize key values and set all nodes as not part of MST
    for (int i = 0; i < n; i++) {
        key[i] = 1000000;  // Large value to simulate infinity
        mst_set[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    // Prims algorithm to find MST
    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!mst_set[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        mst_set[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 1000000 && !mst_set[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(key);
    free(parent);
    free(mst_set);
}

int main() {
    srand(time(NULL));
    prims_mst();
    return 0;
}
