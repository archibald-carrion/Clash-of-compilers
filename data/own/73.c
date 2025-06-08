#include <stdio.h>
#include <stdlib.h>

#define V 4
#define E 5

struct Edge {
    int u, v, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

int findParent(int parent[], int i) {
    if (parent[i] == i) return i;
    return findParent(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskal(struct Graph* graph) {
    struct Edge result[V];
    int e = 0;
    int parent[V], rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    for (int i = 0; i < graph->E && e < V - 1; i++) {
        struct Edge next_edge = graph->edge[i];
        int x = findParent(parent, next_edge.u);
        int y = findParent(parent, next_edge.v);

        if (x != y) {
            result[e++] = next_edge;
            unionSet(parent, rank, x, y);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < e; i++) {
        printf("%d - %d: %d\n", result[i].u, result[i].v, result[i].weight);
    }
}

int main() {
    struct Graph graph = {V, E, (struct Edge[]){{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}}};
    kruskal(&graph);
    return 0;
}
