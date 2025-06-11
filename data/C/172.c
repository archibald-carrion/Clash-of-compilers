#include <stdlib.h> // For malloc, free, rand, srand
#include <limits.h> // For INT_MIN
#include <time.h>   // For time

// Snippet 2: Maximum Subarray Sum (Kadane's Algorithm)
int maximum_subarray_sum(int n_elements) { // Renamed n to n_elements
    int *arr = (int*) malloc(n_elements * sizeof(int));
    srand(time(NULL));
    for(int i=0; i<n_elements; ++i) arr[i] = (rand() % 201) - 100; // Numbers between -100 and 100

    int max_so_far = INT_MIN, current_max = 0;
    if (n_elements <= 0) { // Handle empty or invalid size array
        free(arr);
        return 0; // Or some error indicator
    }

    for (int i = 0; i < n_elements; i++) {
        current_max = current_max + arr[i];
        if (max_so_far < current_max)
            max_so_far = current_max;
        if (current_max < 0)
            current_max = 0;
    }
    free(arr);
    return max_so_far;
}

int main() {
    // Example usage
    maximum_subarray_sum(1000); // Array of 1000 elements
    return 0;
}
