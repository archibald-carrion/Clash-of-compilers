#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Snippet 198: Finding the Longest Increasing Subsequence in an Array (LIS)
void longest_increasing_subsequence() {
    int n = 1000;  // Array size
    int *arr = (int*) malloc(n * sizeof(int));
    int *dp = (int*) malloc(n * sizeof(int));

    // Initialize the array with random values
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    // DP solution for Longest Increasing Subsequence (LIS)
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    int lis_length = 0;
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            if (dp[i] > lis_length) {
                lis_length = dp[i];
            }
        }
    }
    printf("Length of LIS: %d\n", lis_length);

    free(arr);
    free(dp);
}

int main() {
    srand(time(NULL));
    longest_increasing_subsequence();
    return 0;
}
