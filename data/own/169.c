// Snippet 9: Merge K Sorted Lists using a Min Heap
#include <stdlib.h> // For malloc, free, rand, srand
#include <stdio.h>  // For printf (if debugging)
#include <limits.h> // For INT_MAX
#include <time.h>   // For time

// Structure for Min Heap Node
typedef struct MinHeapNode {
    int element;   // The element to be stored
    int list_idx;  // Index of the list from which the element is taken
} MinHeapNode;

// Utility function to swap two MinHeapNode pointers
void swap_mh_node(MinHeapNode *a, MinHeapNode *b) { // Renamed to avoid conflict
    MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Min Heapify function
void min_heapify(MinHeapNode heap[], int i, int heap_size) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap_size && heap[left].element < heap[smallest].element) smallest = left;
    if (right < heap_size && heap[right].element < heap[smallest].element) smallest = right;

    if (smallest != i) {
        swap_mh_node(&heap[i], &heap[smallest]);
        min_heapify(heap, smallest, heap_size);
    }
}

// Function to build a Min Heap
void build_min_heap(MinHeapNode heap[], int heap_size) {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        min_heapify(heap, i, heap_size);
    }
}

void merge_k_sorted_lists(int k_lists, int n_elements_per_list) { // Renamed k, n
    int **lists = (int**) malloc(k_lists * sizeof(int*));
    for (int i = 0; i < k_lists; i++) {
        lists[i] = (int*) malloc(n_elements_per_list * sizeof(int));
    }
    
    MinHeapNode *heap = (MinHeapNode*) malloc(k_lists * sizeof(MinHeapNode));
    int *result = (int*) malloc(k_lists * n_elements_per_list * sizeof(int));
    int *list_ptr = (int*) calloc(k_lists, sizeof(int)); // Pointers to current element in each list

    srand(time(NULL));
    // Initialize lists with sorted random numbers
    for (int i = 0; i < k_lists; i++) {
        for (int j = 0; j < n_elements_per_list; j++) {
            lists[i][j] = (j == 0) ? (rand() % 100) : (lists[i][j-1] + rand() % 10 + 1);
        }
        if (n_elements_per_list > 0) {
            heap[i].element = lists[i][0];
            heap[i].list_idx = i;
        }
    }
    
    int heap_size = (n_elements_per_list > 0) ? k_lists : 0;
    if (heap_size > 0) build_min_heap(heap, heap_size);

    int count = 0;
    while (heap_size > 0) {
        MinHeapNode root = heap[0];
        result[count++] = root.element;

        list_ptr[root.list_idx]++;
        if (list_ptr[root.list_idx] < n_elements_per_list) {
            heap[0].element = lists[root.list_idx][list_ptr[root.list_idx]];
            // heap[0].list_idx remains the same
        } else { // If list is exhausted, replace root with last element and reduce heap size
            heap[0] = heap[heap_size - 1];
            heap_size--;
        }
        if (heap_size > 0) min_heapify(heap, 0, heap_size);
    }


    for (int i = 0; i < k_lists; i++) {
        free(lists[i]);
    }
    free(lists);
    free(heap);
    free(result);
    free(list_ptr);
}

int main() {
    // Example usage
    merge_k_sorted_lists(5, 100); // 5 lists, each with 100 elements
    return 0;
}