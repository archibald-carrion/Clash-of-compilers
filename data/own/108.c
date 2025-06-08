#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5

struct Graph {
    int V;
    int** adj;
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

void dfs(int graph[V][V], int v, bool visited[], int stack[], int* top) {
    visited[v] = true;
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(graph, i, visited, stack, top);
        }
    }
    stack[(*top)++] = v;
}

void kosaraju(struct Graph* graph) {
    bool visited[V] = {false};
    int stack[V];
    int top = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(graph->adj, i, visited, stack, &top);
        }
    }

    printf("Orden de finalización (no SCCs):\n");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    struct Graph* graph = createGraph(V);
    graph->adj[0][1] = 1;
    graph->adj[1][2] = 1;
    graph->adj[2][0] = 1;
    graph->adj[2][3] = 1;
    graph->adj[3][4] = 1;

    kosaraju(graph);

    return 0;
}
