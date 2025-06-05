// Snippet 1: Insertion Sort
void insertion_sort() {
    int n = 1000;
    int *arr = (int*) malloc(n * sizeof(int));

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    free(arr);
}