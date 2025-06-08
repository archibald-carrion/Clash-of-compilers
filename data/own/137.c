#include <stdio.h>
#include <stdlib.h>
// Snippet 7: Simulate a Simple Queue using an Array
// Helper functions for queue operations
void enqueue(int *queue, int *rear, int n, int value) {
    if (*rear == n) return;
    queue[(*rear)++] = value;
}

int dequeue(int *queue, int *front, int rear) {
    if (*front == rear) return -1;
    return queue[(*front)++];
}

void simulate_queue() {
    int n = 100000;  // Number of operations
    int *queue = (int*) malloc(n * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        enqueue(queue, &rear, n, i);
    }
    for (int i = 0; i < n; i++) {
        dequeue(queue, &front, rear);
    }

    free(queue);
}

int main() {
    simulate_queue();
    return 0;
}