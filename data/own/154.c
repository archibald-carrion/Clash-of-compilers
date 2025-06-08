// Snippet 4: Heap Sort
#include <stdlib.h> // For malloc, free, rand, srand
#include <time.h>   // For time

// Utility function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// To heapify a subtree rooted with node i which is an index in arr[]
// n is size of heap
void heapify(int *arr, int n, int i) {
    int largest = i;    // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]); // Swap root with largest

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heap_sort(int n_elements) { // Renamed n to n_elements
    int *arr = (int*) malloc(n_elements * sizeof(int));
    srand(time(NULL));
    for(int i=0; i<n_elements; ++i) arr[i] = rand() % (n_elements * 10);


    // Build heap (rearrange array)
    for (int i = n_elements / 2 - 1; i >= 0; i--)
        heapify(arr, n_elements, i);

    // One by one extract an element from heap
    for (int i = n_elements - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
    free(arr);
}

int main() {
    heap_sort(100); // Example: sort an array of 100 elements
    return 0;
}