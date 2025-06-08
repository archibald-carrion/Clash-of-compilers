#include <stdlib.h> // Added for malloc and free

// Merge function with inversion count - moved to global scope
// This function merges two sorted subarrays and counts inversions.
// arr[] is the original array
// left, mid, right are indices defining the subarrays: arr[left..mid] and arr[mid+1..right]
int merge_and_count(int *arr, int left, int mid, int right) {
    // Calculate sizes of temporary arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Allocate temporary arrays
    // Check for n1/n2 being zero or negative if array bounds could be problematic
    // For merge sort, left <= mid < right, so n1 >= 1 and n2 >= 1.
    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    // Check for malloc failure
    if (L == NULL || R == NULL) {
        // Handle memory allocation failure (e.g., free successfully allocated parts and exit or return error)
        if (L) free(L);
        if (R) free(R);
        // This error case should ideally propagate up or terminate.
        // For simplicity here, we might just return 0, but this hides an error.
        // A robust solution would involve error codes or exceptions (if in C++).
        exit(EXIT_FAILURE); // Or return an error code if function signature allows
    }

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left, inv_count = 0;
    // Merge the temporary arrays back into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inv_count += (n1 - i); // L[i...n1-1] are all > R[j]
        }
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) arr[k++] = L[i++];
    // Copy the remaining elements of R[], if there are any
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
    return inv_count;
}

// Merge sort function with inversion count - moved to global scope
// arr[] is the array to be sorted
// left and right are the starting and ending indices of the subarray
int merge_sort_and_count(int *arr, int left, int right) {
    int inv_count = 0;
    if (left < right) { // Recursive condition: if there is more than one element
        int mid = left + (right - left) / 2; // Avoids overflow for large left, right
        // Recursively sort and count inversions in left and right subarrays
        inv_count += merge_sort_and_count(arr, left, mid);
        inv_count += merge_sort_and_count(arr, mid + 1, right);
        // Merge the two sorted subarrays and count inversions during merge
        inv_count += merge_and_count(arr, left, mid, right);
    }
    return inv_count;
}

// Snippet 173: Counting Inversions using Merge Sort
void count_inversions() {
    int n = 1000000;  // Array size
    if (n <= 0) return; // Handle non-positive size
    int *arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        // Handle allocation failure
        return;
    }
    // Initialize arr with values here for a meaningful count.
    // For example, to test:
    // for(int i=0; i<n; ++i) arr[i] = n-i; // worst case for inversions

    // Call merge_sort_and_count on the entire array
    // If n=0, n-1 is -1. merge_sort_and_count(arr, 0, -1) will correctly return 0.
    // If n=1, n-1 is 0. merge_sort_and_count(arr, 0, 0) will correctly return 0.
    int inversion_count = merge_sort_and_count(arr, 0, n - 1);
    // Use inversion_count, e.g., print it
    // printf("Number of inversions: %d\n", inversion_count);

    free(arr);
}

int main() {
    count_inversions();
    return 0;
}
