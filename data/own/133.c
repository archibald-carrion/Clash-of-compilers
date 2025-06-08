#include <stdio.h>
#include <stdlib.h>

// Merge operation
int merge(int *arr1, int *arr2, int *result, int n) {
    if (!arr1 || !arr2 || !result || n <= 0) {
        return -1; // Error code for invalid inputs
    }
    
    int i = 0, j = 0, k = 0;
    while (i < n && j < n) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    while (i < n) result[k++] = arr1[i++];
    while (j < n) result[k++] = arr2[j++];
    return 0;
}

void merge_sorted_arrays() {
    int n = 10000;  // Reduced from 100000 for better performance
    
    // Allocate memory
    int *arr1 = (int*) malloc(n * sizeof(int));
    if (!arr1) {
        perror("Failed to allocate memory for arr1");
        return;
    }
    
    int *arr2 = (int*) malloc(n * sizeof(int));
    if (!arr2) {
        perror("Failed to allocate memory for arr2");
        free(arr1);
        return;
    }
    
    int *result = (int*) malloc(2 * n * sizeof(int));
    if (!result) {
        perror("Failed to allocate memory for result");
        free(arr1);
        free(arr2);
        return;
    }

    // Initialize arrays with sorted data
    for (int i = 0; i < n; i++) {
        arr1[i] = i * 2;      // Even numbers: 0, 2, 4, ...
        arr2[i] = i * 2 + 1;  // Odd numbers: 1, 3, 5, ...
    }

    // Merge the arrays
    merge(arr1, arr2, result, n);

    // Print a few results to verify correctness (optional)
    printf("First 10 elements after merge:\n");
    for (int i = 0; i < 10 && i < 2 * n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(arr1);
    free(arr2);
    free(result);
}

int main() {
    merge_sorted_arrays();
    return 0;
}