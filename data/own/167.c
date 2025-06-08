// Snippet 7: Quickselect Algorithm for the kth Largest Element
#include <stdlib.h> // For malloc, free, rand, srand
#include <time.h>   // For time

// Utility function to swap two integers
void swap_qs(int *a, int *b) { // Renamed to avoid conflict if other files define swap
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quickselect (similar to Quicksort)
int partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap_qs(&arr[i], &arr[j]);
        }
    }
    swap_qs(&arr[i + 1], &arr[right]);
    return i + 1;
}

// Recursive Quickselect function
int quickselect_recursive(int *arr, int left, int right, int k) {
    if (left == right) return arr[left];
    int pivot_index = partition(arr, left, right);
    if (k == pivot_index) return arr[k];
    else if (k < pivot_index) return quickselect_recursive(arr, left, pivot_index - 1, k);
    else return quickselect_recursive(arr, pivot_index + 1, right, k);
}

int quickselect(int n_elements, int k_val) { // Renamed n to n_elements, k to k_val
    if (k_val <= 0 || k_val > n_elements) return -1; // Invalid k

    int *arr = (int*) malloc(n_elements * sizeof(int));
    srand(time(NULL));
    for(int i=0; i<n_elements; ++i) arr[i] = rand() % (n_elements * 10);

    // k_val is 1-indexed for "kth largest", convert to 0-indexed for "kth smallest" logic if needed
    // Or adjust k for "kth largest" directly: (n - k)th smallest
    int result = quickselect_recursive(arr, 0, n_elements - 1, n_elements - k_val); // for kth largest
    
    free(arr);
    return result;
}

int main() {
    // Example usage: find 5th largest in 100 elements
    quickselect(100, 5); 
    return 0;
}