#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define V 5

struct Graph {
  int numVertices;
  int** adj;
};

struct Graph* createGraph(int numV) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices = numV;
  graph->adj = (int**)malloc(numV * sizeof(int*));
  for (int i = 0; i < numV; i++) {
    graph->adj[i] = (int*)malloc(numV * sizeof(int));
    for (int j = 0; j < numV; j++) {
      graph->adj[i][j] = 0;
    }
  }
  return graph;
}

// Utilidad para llenar el stack con el orden de finalización
void fillOrder(
    int v, struct Graph* graph, bool visited[], int stack[], int* top) {
  visited[v] = true;
  for (int i = 0; i < graph->numVertices; i++) {
    if (graph->adj[v][i] && !visited[i]) {
      fillOrder(i, graph, visited, stack, top);
    }
  }
  stack[(*top)++] = v;
}

// Transpone el grafo
struct Graph* transpose(struct Graph* graph) {
  struct Graph* gT = createGraph(graph->numVertices);
  for (int i = 0; i < graph->numVertices; i++) {
    for (int j = 0; j < graph->numVertices; j++) {
      gT->adj[j][i] = graph->adj[i][j];
    }
  }
  return gT;
}

// DFS simple para imprimir SCC
void dfsUtil(int v, struct Graph* graph, bool visited[]) {
  visited[v] = true;
  printf("%d ", v);
  for (int i = 0; i < graph->numVertices; i++) {
    if (graph->adj[v][i] && !visited[i]) {
      dfsUtil(i, graph, visited);
    }
  }
}

void kosaraju(struct Graph* graph) {
  bool visited[V] = { false };
  int stack[V];
  int top = 0;

  // 1. Llenar el stack con el orden de finalización
  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      fillOrder(i, graph, visited, stack, &top);
    }
  }

  // 2. Transponer el grafo
  struct Graph* gT = transpose(graph);

  // 3. DFS en el grafo transpuesto según el orden del stack
  for (int i = 0; i < V; i++)
    visited[i] = false;

  printf("Strongly Connected Components:\n");
  for (int i = top - 1; i >= 0; i--) {
    int v = stack[i];
    if (!visited[v]) {
      dfsUtil(v, gT, visited);
      printf("\n");
    }
  }

  // Liberar memoria del grafo transpuesto
  for (int i = 0; i < V; i++)
    free(gT->adj[i]);
  free(gT->adj);
  free(gT);
}

int main() {
  struct Graph* graph = createGraph(V);
  graph->adj[0][1] = 1;
  graph->adj[1][2] = 1;
  graph->adj[2][0] = 1;
  graph->adj[2][3] = 1;
  graph->adj[3][4] = 1;

  kosaraju(graph);

  // Liberar memoria del grafo original
  for (int i = 0; i < V; i++)
    free(graph->adj[i]);
  free(graph->adj);
  free(graph);

  return 0;
}
