// Snippet 4: Knapsack Problem using Dynamic Programming
void knapsack() {
    int n = 1000;  // Number of items
    int capacity = 1000;  // Knapsack capacity
    int *weights = (int*) malloc(n * sizeof(int));
    int *values = (int*) malloc(n * sizeof(int));
    int **dp = (int**) malloc((n + 1) * sizeof(int*));

    for (int i = 0; i <= n; i++) {
        dp[i] = (int*) malloc((capacity + 1) * sizeof(int));
    }

    // Knapsack DP algorithm
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) ?
                            (values[i - 1] + dp[i - 1][w - weights[i - 1]]) : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    free(weights);
    free(values);
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
}