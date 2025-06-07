// Snippet 3: Merge Sorted Arrays
// Merge operation
int merge(int *arr1, int *arr2, int *result, int n) {
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
    int n = 100000;  // Array size
    int *arr1 = (int*) malloc(n * sizeof(int));
    int *arr2 = (int*) malloc(n * sizeof(int));
    int *result = (int*) malloc(2 * n * sizeof(int));

    merge(arr1, arr2, result, n);

    free(arr1);
    free(arr2);
    free(result);
}