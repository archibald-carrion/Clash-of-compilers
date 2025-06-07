// Snippet 2: Sorting large array using Radix Sort

// Counting sort helper function
void counting_sort(int *arr, int n, int exp) {
    int *output = (int*) malloc(n * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

void radix_sort() {
    int n = 1000000;  // Array size
    int *arr = (int*) malloc(n * sizeof(int));
    int max_val = 1000000;

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        counting_sort(arr, n, exp);
    }

    free(arr);
}