// Snippet 9: Longest Increasing Subsequence (Dynamic Programming)
#include <stdlib.h> // For malloc, free, rand, srand
#include <time.h>   // For time

int longest_increasing_subsequence(int n_elements) { // Renamed n to n_elements
    int *arr = (int*) malloc(n_elements * sizeof(int));
    int *lis = (int*) malloc(n_elements * sizeof(int));
    srand(time(NULL));
    for(int i=0; i<n_elements; ++i) {
        arr[i] = rand() % 10000;
        lis[i] = 1; // Initialize LIS values for all indexes as 1
    }


    for (int i = 1; i < n_elements; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }

    int max_lis = 0;
    if (n_elements > 0) { // Handle empty array case
        max_lis = lis[0];
        for (int i = 1; i < n_elements; i++) {
            if (lis[i] > max_lis)
                max_lis = lis[i];
        }
    }
    

    free(arr);
    free(lis);
    return max_lis;
}

int main() {
    // Example usage
    longest_increasing_subsequence(100); // n=100 (size of array)
    return 0;
}