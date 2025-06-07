#include <stdio.h>  // For printf
#include <stdlib.h> // For malloc, free, rand, srand
#include <time.h>   // For time

// Snippet 190: Longest Increasing Subsequence using Dynamic Programming
void longest_increasing_subsequence() {
    int n = 1000;  // Array size
    int *arr = (int*) malloc(n * sizeof(int));
    int *dp = (int*) malloc(n * sizeof(int));

    srand(time(NULL)); // Initialize random seed
    // Initialize the array (random numbers)
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    // Longest Increasing Subsequence (LIS) DP solution
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    // Find the maximum length
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > max_length) {
            max_length = dp[i];
        }
    }
    
    printf("Longest increasing subsequence length: %d\n", max_length);

    free(arr);
    free(dp);
}

int main() {
    longest_increasing_subsequence();
    return 0;
}
