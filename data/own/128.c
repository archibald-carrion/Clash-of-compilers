// Snippet 8: Bubble Sort
void bubble_sort() {
    int n = 1000;
    int *arr = (int*) malloc(n * sizeof(int));

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    free(arr);
}