// Snippet 2: Floyd-Warshall Algorithm for All-Pairs Shortest Path
#include <stdlib.h> // For malloc, free

void floyd_warshall(int n) {
    int **dist = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dist[i] = (int*) malloc(n * sizeof(int));
    }

    // Initialize distance matrix (simulating a graph)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = 1000000;  // Large number to simulate no path
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(dist[i]);
    }
    free(dist);
}

int main() {
    // Example usage
    floyd_warshall(5); // n=5 (number of vertices)
    return 0;
}