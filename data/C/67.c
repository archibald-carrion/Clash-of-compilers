#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // <-- Agregado

struct FibonacciNode {
    int key;
    struct FibonacciNode* left;
    struct FibonacciNode* right;
    struct FibonacciNode* child;
    int degree;
    bool marked;
};

struct FibonacciHeap {
    struct FibonacciNode* min;
};

struct FibonacciHeap* createHeap() {
    struct FibonacciHeap* heap = (struct FibonacciHeap*)malloc(sizeof(struct FibonacciHeap));
    heap->min = NULL;
    return heap;
}

void insert(struct FibonacciHeap* heap, int key) {
    struct FibonacciNode* node = (struct FibonacciNode*)malloc(sizeof(struct FibonacciNode));
    node->key = key;
    node->degree = 0;
    node->left = node->right = node;
    node->child = NULL;
    node->marked = false;

    if (heap->min == NULL) {
        heap->min = node;
    } else {
        heap->min->right->left = node;
        node->right = heap->min->right;
        heap->min->right = node;
        node->left = heap->min;
        if (node->key < heap->min->key) {
            heap->min = node;
        }
    }
}

int extractMin(struct FibonacciHeap* heap) {
    if (heap->min == NULL)
        return -1;

    struct FibonacciNode* minNode = heap->min;
    int minKey = minNode->key;

    if (minNode->child != NULL) {
        // Fusionar los hijos en la lista raíz
        struct FibonacciNode* child = minNode->child;
        struct FibonacciNode* start = child;
        do {
            struct FibonacciNode* next = child->right;
            // Insertar el hijo en la lista raíz
            child->left = heap->min;
            child->right = heap->min->right;
            heap->min->right->left = child;
            heap->min->right = child;
            // Desmarcar el hijo
            child->marked = false;
            child = next;
        } while (child != start);
    }

    if (minNode->right == minNode) {
        heap->min = NULL;
    } else {
        minNode->left->right = minNode->right;
        minNode->right->left = minNode->left;
        heap->min = minNode->right;
    }

    free(minNode);
    return minKey;
}

int main() {
    struct FibonacciHeap* heap = createHeap();

    insert(heap, 10);
    insert(heap, 2);
    insert(heap, 5);
    insert(heap, 8);

    printf("Extracted min: %d\n", extractMin(heap));
    printf("Extracted min: %d\n", extractMin(heap));

    return 0;
}
