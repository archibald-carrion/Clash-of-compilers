#include <stdlib.h> // Added for malloc and free

// Helper function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Optimized partition for Quick Sort - moved to global scope
int partition(int *arr, int low, int high) {
    // Check for invalid range to prevent out-of-bounds access if high is too small
    if (low > high || high < 0) { 
        // Or handle error appropriately, this might indicate an issue with initial call or recursion
        return low; // Or some other indicator of an issue
    }
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Recursive Quick Sort function - moved to global scope
void quick_sort_recursive(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        // Ensure pi is within bounds before recursing
        if (pi > low) { // Check to prevent pi-1 from being out of bounds if pi is low
            quick_sort_recursive(arr, low, pi - 1);
        }
        if (pi < high) { // Check to prevent pi+1 from being out of bounds if pi is high
             quick_sort_recursive(arr, pi + 1, high);
        }
    }
}

// Snippet 172: Large-Scale Quick Sort with Optimized Partition
void quick_sort_optimized() {
    int n = 1000000;  // Array size
    if (n <= 0) return; // Handle non-positive size
    int *arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        // Handle allocation failure
        return;
    }
    
    // Initialize array with some values if needed for testing
    // For example:
    // for(int i=0; i<n; ++i) arr[i] = n - i;


    // partition function was here
    // quick_sort_recursive function was here

    quick_sort_recursive(arr, 0, n - 1);

    free(arr);
}
