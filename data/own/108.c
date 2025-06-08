#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_VERTICES 5

struct Graph {
    int numVertices;
    int** adj;
};

struct Graph* createGraph(int numVertices);
void dfs(int** graph, int v, bool visited[], int stack[], int* top);
void kosaraju(struct Graph* graph);

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adj = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adj[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

void dfs(int** graph, int v, bool visited[], int stack[], int* top) {
    visited[v] = true;
    for (int i = 0; i < NUM_VERTICES; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(graph, i, visited, stack, top);
        }
    }
    stack[(*top)++] = v;
}

void kosaraju(struct Graph* graph) {
    bool visited[NUM_VERTICES] = {false};
    int stack[NUM_VERTICES];
    int top = 0;

    for (int i = 0; i < NUM_VERTICES; i++) {
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
    struct Graph* graph = createGraph(NUM_VERTICES);
    graph->adj[0][1] = 1;
    graph->adj[1][2] = 1;
    graph->adj[2][0] = 1;
    graph->adj[2][3] = 1;
    graph->adj[3][4] = 1;

    kosaraju(graph);

    return 0;
}
