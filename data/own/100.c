#include <stdio.h>
#include <stdbool.h>

#define V 4

bool dfs(int graph[V][V], int v, bool visited[], bool recStack[]) {
    if (recStack[v]) return true;
    if (visited[v]) return false;

    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < V; i++) {
        if (graph[v][i] && dfs(graph, i, visited, recStack)) {
            return true;
        }
    }

    recStack[v] = false;
    return false;
}

bool detectCycle(int graph[V][V]) {
    bool visited[V] = {false};
    bool recStack[V] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dfs(graph, i, visited, recStack)) {
            return true;
        }
    }
    return false;
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };

    if (detectCycle(graph)) {
        printf("Graph contains a cycle\n");
    } else {
        printf("Graph does not contain a cycle\n");
    }

    return 0;
}
