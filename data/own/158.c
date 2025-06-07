// Snippet 8: Counting Sort for large range of values
void counting_sort_large_range() {
    int n = 100000;  // Array size
    int *arr = (int*) malloc(n * sizeof(int));
    int max_val = 1000000;  // Range of values

    // Initialize the array
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % max_val;
    }

    // Counting Sort
    int *count = (int*) calloc(max_val + 1, sizeof(int));
    int *output = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    free(arr);
    free(count);
    free(output);
}