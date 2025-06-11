// Snippet 8: Counting Sort for large range of values
#include <stdlib.h> // For malloc, calloc, free, rand, srand
#include <time.h>   // For time

void counting_sort_large_range(int n, int max_val) {
    int *arr = (int*) malloc(n * sizeof(int));

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

    free(count);
    // arr is now sorted_arr. For this snippet, we free it.
    free(arr);
}

int main() {
    // Example usage
    counting_sort_large_range(1000, 100000); // n=1000, max_val=100000
    return 0;
}