#include <stdlib.h> // For malloc, free, rand, srand
#include <time.h>   // For time

// Function to merge two subarrays
void merge(int *arr, int left, int mid, int right) {
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

// Recursive function to perform merge sort
void merge_sort_recursive(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_recursive(arr, left, mid);
        merge_sort_recursive(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Snippet 4: Merge Sort for a Large Array
void merge_sort() {
    int n = 1000000;  // Array size
    int *arr = (int*) malloc(n * sizeof(int));

    merge_sort_recursive(arr, 0, n - 1);

    free(arr);
}

void merge_sort_main(int n_elements) { // Renamed from merge_sort to avoid conflict with recursive helper
    int *arr = (int*) malloc(n_elements * sizeof(int));
    srand(time(NULL));
    for(int i=0; i<n_elements; ++i) arr[i] = rand() % (n_elements * 10);

    if (n_elements > 0) {
        merge_sort_recursive(arr, 0, n_elements - 1);
    }
    
    free(arr);
}

int main() {
    merge_sort_main(1000); // Sort an array of 1000 elements
    return 0;
}
