#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 6

void bfs(int graph[V][V], int start) {
    bool visited[V] = {false};
    int queue[V];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front != rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < V; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {0, 1, 0, 0, 1, 1},
        {1, 1, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };

    printf("BFS starting from node 0: ");
    bfs(graph, 0);
    printf("\n");

    return 0;
}
