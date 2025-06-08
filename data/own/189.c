
// Snippet 179: Longest Increasing Subsequence using Dynamic Programming
void longest_increasing_subsequence() {
    int n = 1000;  // Array size
    int *arr = (int*) malloc(n * sizeof(int));
    int *dp = (int*) malloc(n * sizeof(int));

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

    free(arr);
    free(dp);
}
    