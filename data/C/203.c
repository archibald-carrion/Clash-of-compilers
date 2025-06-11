#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Helper functions for merge_sort_optimized, moved to file scope
static void s193_merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

static void s193_merge_sort_recursive(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        s193_merge_sort_recursive(arr, left, mid);
        s193_merge_sort_recursive(arr, mid + 1, right);
        s193_merge(arr, left, mid, right);
    }
}

// Snippet 193: High-Efficiency Sorting using Merge Sort with Optimized Memory Usage
void merge_sort_optimized() {
    int n = 100000;  // Array size, reduced for faster example execution
    int *arr = (int*) malloc(n * sizeof(int));

    // Initialize array with random values
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    // Merge sort function with optimized memory allocation
    // (Actual merge and recursive calls are now to s193_merge and s193_merge_sort_recursive)
    s193_merge_sort_recursive(arr, 0, n - 1);
    
    printf("First 10 elements after sort (if n >= 10):\n");
    for(int i=0; i < (n < 10 ? n : 10); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

int main() {
    srand(time(NULL));
    merge_sort_optimized();
    return 0;
}
