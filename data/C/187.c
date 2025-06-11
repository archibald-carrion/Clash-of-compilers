#include <stdlib.h> // For malloc, free, rand, srand
#include <limits.h> // For INT_MAX
#include <stdbool.h> // For bool type
#include <time.h>   // For time

// Snippet 177: Prim's Algorithm for Minimum Spanning Tree (MST)
void prims_mst(int n_vertices) { // Renamed n to n_vertices
    int **graph = (int**) malloc(n_vertices * sizeof(int*));
    for (int i = 0; i < n_vertices; i++) {
        graph[i] = (int*) malloc(n_vertices * sizeof(int));
    }

    int *key = (int*) malloc(n_vertices * sizeof(int));
    bool *mstSet = (bool*) malloc(n_vertices * sizeof(bool));
    // int *parent = (int*) malloc(n_vertices * sizeof(int)); // To store constructed MST

    srand(time(NULL));
    // Initialize graph with random weights (symmetric for undirected graph)
    for (int i = 0; i < n_vertices; i++) {
        for (int j = i; j < n_vertices; j++) {
            if (i == j) graph[i][j] = 0;
            else {
                graph[i][j] = graph[j][i] = rand() % 100 + 1; // Weights 1-100
            }
        }
    }
    

    for (int i = 0; i < n_vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0; // Start with the first vertex
    // parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < n_vertices - 1; count++) {
        int u = -1, min_key = INT_MAX;
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        for (int v = 0; v < n_vertices; v++) {
            if (mstSet[v] == false && key[v] < min_key) {
                min_key = key[v];
                u = v;
            }
        }
        
        if (u == -1) break; // Should not happen in a connected graph

        mstSet[u] = true;

        for (int v = 0; v < n_vertices; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                // parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for (int i = 0; i < n_vertices; i++) {
        free(graph[i]);
    }
    free(graph);
    free(key);
    free(mstSet);
    // free(parent);
}

int main() {
    prims_mst(50); // MST for a graph with 50 vertices
    return 0;
}
