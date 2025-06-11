// Snippet 7: Largest Contiguous Subarray Sum (Kadane's Algorithm)
#include <stdlib.h> // For malloc, free

int kadane_algorithm(int n) {
    int *arr = (int*) malloc(n * sizeof(int));

    int max_sum = arr[0], current_sum = arr[0];
    for (int i = 1; i < n; i++) {
        current_sum = (arr[i] > current_sum + arr[i]) ? arr[i] : current_sum + arr[i];
        max_sum = (max_sum > current_sum) ? max_sum : current_sum;
    }

    free(arr);
    return max_sum;
}

int main() {
    // Example usage
    kadane_algorithm(10); // n=10 (size of array)
    return 0;
}