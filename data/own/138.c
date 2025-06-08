// Snippet 8: Counting Sort Algorithm
#include <stdlib.h> // For malloc, calloc, free

void counting_sort(int n, int max_val) {
    int *arr = (int*) malloc(n * sizeof(int));

    int *count = (int*) calloc(max_val + 1, sizeof(int));
    int *output = (int*) malloc(n * sizeof(int));

    // Counting Sort algorithm
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
    // arr is now sorted_arr, so it should be used or returned, not freed here if it's the output.
    // For the purpose of this snippet as a standalone, we'll free it.
    free(arr); 
}

int main() {
    // Example usage
    counting_sort(100, 1000); // n=100, max_val=1000
    return 0;
}