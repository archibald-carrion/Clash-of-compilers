#include <stdio.h>
#include <stdlib.h>

#define V 5

struct Graph {
    int V;
    int **adj;
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)malloc(V * sizeof(int));
    }
    return graph;
}

void dfs(int v, struct Graph* graph, bool visited[], int stack[]) {
    visited[v] = true;
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] && !visited[i]) {
            dfs(i, graph, visited, stack);
        }
    }
    stack[v] = 1;
}

void kosaraju(struct Graph* graph) {
    bool visited[V];
    int stack[V];
    for (int i = 0; i < V; i++) visited[i] = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, stack);
        }
    }

    // Print Strongly Connected Components
    for (int i = 0; i < V; i++) {
        if (stack[i]) {
            printf("SCC: %d\n", i);
        }
    }
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
