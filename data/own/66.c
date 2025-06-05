#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct PriorityQueue {
    int arr[MAX];
    int size;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct PriorityQueue* pq, int idx) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->arr[left] > pq->arr[largest])
        largest = left;
    if (right < pq->size && pq->arr[right] > pq->arr[largest])
        largest = right;

    if (largest != idx) {
        swap(&pq->arr[idx], &pq->arr[largest]);
        heapify(pq, largest);
    }
}

void insert(struct PriorityQueue* pq, int value) {
    if (pq->size == MAX) {
        printf("Priority Queue is full\n");
        return;
    }

    pq->arr[pq->size] = value;
    int i = pq->size;
    pq->size++;

    while (i > 0 && pq->arr[i] > pq->arr[(i - 1) / 2]) {
        swap(&pq->arr[i], &pq->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(struct PriorityQueue* pq) {
    if (pq->size <= 0)
        return -1;

    int root = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    heapify(pq, 0);

    return root;
}

int main() {
    struct PriorityQueue pq;
    pq.size = 0;

    insert(&pq, 10);
    insert(&pq, 20);
    insert(&pq, 5);
    insert(&pq, 15);

    printf("Extracted max: %d\n", extractMax(&pq));
    printf("Extracted max: %d\n", extractMax(&pq));

    return 0;
}
