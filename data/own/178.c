
// Snippet 8: Binomial Coefficients using Dynamic Programming
void binomial_coefficients() {
    int n = 1000, k = 500;  // Compute C(n, k)
    long long **dp = (long long**) malloc((n + 1) * sizeof(long long*));

    for (int i = 0; i <= n; i++) {
        dp[i] = (long long*) malloc((k + 1) * sizeof(long long));
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= (i < k ? i : k); j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    // C(n, k) is dp[n][k]
    printf("%lld", dp[n][k]);

    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
}
