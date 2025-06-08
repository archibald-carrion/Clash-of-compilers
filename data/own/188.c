// Snippet 178: Breadth-First Search (BFS) for Graph Traversal
#include <stdlib.h> // Added for malloc and free

static void bfs_helper(int start, int n, int **graph, int *visited, int *queue) {
    int front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        // Process node here (e.g., print) if needed
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void bfs_graph() {
    int n = 1000;  // Number of nodes
    int **graph = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*) malloc(n * sizeof(int));
        // Assuming graph initialization happens elsewhere or is simplified for snippet
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0; // Example initialization
        }
    }

    int *visited = (int*) malloc(n * sizeof(int));
    int *queue = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform BFS starting from node 0.
    // If the graph can be disconnected, loop through all nodes:
    // for (int i = 0; i < n; i++) {
    //     if (!visited[i]) {
    //         bfs_helper(i, n, graph, visited, queue);
    //     }
    // }
    // For this snippet, assuming BFS from a single source 0 is intended.
    bfs_helper(0, n, graph, visited, queue);

    free(visited);
    free(queue);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
}

int main() {
    bfs_graph();
    return 0;
}
