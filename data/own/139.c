// Snippet 9: Insertion into a Max Heap
#include <stdlib.h> // For malloc, free

// Helper function for insertion into max heap
void insert(int *heap, int *size, int value) {
    (*size)++;
    heap[*size - 1] = value;
    int i = *size - 1;
    
    // Fix the max heap property
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void max_heap_insertion(int n, int val) {
    int *heap = (int*) malloc(n * sizeof(int));
    int size = 0;

    for (int i = 0; i < n; i++) {
        insert(heap, &size, i);
    }
    insert(heap, &size, val); // Insert the additional value

    free(heap);
}

int main() {
    // Example usage
    max_heap_insertion(10, 55); // n=10 (initial heap size), insert value 55
    return 0;
}