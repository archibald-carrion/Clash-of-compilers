#include <stdio.h>
#include <stdbool.h>

#define V 5

bool isConnected(int graph[V][V]) {
    int visited[V] = {false};
    int stack[V];
    int top = -1;

    visited[0] = true;
    stack[++top] = 0;

    while (top >= 0) {
        int v = stack[top--];
        for (int i = 0; i < V; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                stack[++top] = i;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

bool isEulerian(int graph[V][V]) {
    if (!isConnected(graph)) return false;

    int oddDegreeCount = 0;
    for (int i = 0; i < V; i++) {
        int degree = 0;
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1) degree++;
        }
        if (degree % 2 != 0) oddDegreeCount++;
    }

    return (oddDegreeCount == 0 || oddDegreeCount == 2);
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    if (isEulerian(graph)) {
        printf("The graph has an Eulerian Path or Circuit.\n");
    } else {
        printf("The graph does not have an Eulerian Path or Circuit.\n");
    }
    return 0;
}
