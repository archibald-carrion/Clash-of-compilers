// Snippet 7: Quickselect Algorithm for the kth Largest Element
// Helper function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quickselect
int partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

// Recursive function for quickselect
int quickselect_recursive(int *arr, int left, int right, int k) {
    if (left == right) return arr[left];
    int pivot_index = partition(arr, left, right);
    if (k == pivot_index) return arr[k];
    else if (k < pivot_index) return quickselect_recursive(arr, left, pivot_index - 1, k);
    else return quickselect_recursive(arr, pivot_index + 1, right, k);
}

void quickselect() {
    int n = 1000000;  // Array size
    int *arr = (int*) malloc(n * sizeof(int));
    int k = n / 2;  // Find the median

    // Quickselect algorithm
    quickselect_recursive(arr, 0, n - 1, k);

    free(arr);
}