#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4

void bfs(int graph[V][V], int src, int dest) {
    bool visited[V];
    int distance[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        distance[i] = -1;
    }

    visited[src] = true;
    distance[src] = 0;

    int queue[V], front = 0, rear = 0;
    queue[rear++] = src;

    while (front != rear) {
        int node = queue[front++];
        for (int i = 0; i < V; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                distance[i] = distance[node] + 1;
                queue[rear++] = i;
                if (i == dest) {
                    printf("Shortest path from %d to %d is %d\n", src, dest, distance[i]);
                    return;
                }
            }
        }
    }

    printf("No path from %d to %d\n", src, dest);
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    bfs(graph, 0, 3);
    return 0;
}
