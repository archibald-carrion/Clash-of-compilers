#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 6

void dfs(int graph[V][V], int v, bool visited[], int stack[], int* top) {
    visited[v] = true;
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(graph, i, visited, stack, top);
        }
    }
    stack[(*top)++] = v;
}

void topologicalSort(int graph[V][V]) {
    bool visited[V] = {false};
    int stack[V];
    int top = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited, stack, &top);
        }
    }

    printf("Topological Sort: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    topologicalSort(graph);

    return 0;
}
