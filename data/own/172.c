
// Snippet 2: Maximum Subarray Sum (Kadane's Algorithm)
void maximum_subarray_sum() {
    int n = 1000000;  // Array size
    int *arr = (int*) malloc(n * sizeof(int));
    int max_sum = arr[0], current_sum = arr[0];

    for (int i = 1; i < n; i++) {
        current_sum = (arr[i] > current_sum + arr[i]) ? arr[i] : current_sum + arr[i];
        max_sum = (max_sum > current_sum) ? max_sum : current_sum;
    }

    free(arr);
}
