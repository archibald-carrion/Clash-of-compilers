// Snippet 6: Queue Implementation (Enqueue and Dequeue)
#include <stdlib.h>

struct Queue {
    int *arr;
    int front, rear, size, capacity;
};

void enqueue(struct Queue *queue, int value) {
    if (queue->size == queue->capacity) return;
    queue->arr[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
}

int dequeue(struct Queue *queue) {
    if (queue->size == 0) return -1;
    int value = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

void queue_operations() {
    struct Queue queue;
    queue.capacity = 100;
    queue.front = 0;
    queue.rear = 0;
    queue.size = 0;
    queue.arr = (int*) malloc(queue.capacity * sizeof(int));

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    int dequeued = dequeue(&queue);

    free(queue.arr);
}