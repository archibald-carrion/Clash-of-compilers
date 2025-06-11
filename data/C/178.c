#include <stdlib.h> // For malloc, free, calloc
#include <stdio.h>  // For printf

// Snippet 8: Binomial Coefficients using Dynamic Programming
void binomial_coefficients(int n_val, int k_val) { // Renamed n, k
    if (k_val < 0 || k_val > n_val) {
        // printf("Invalid k for n\n"); // Optional print
        return;
    }
    long long **dp = (long long**) malloc((n_val + 1) * sizeof(long long*));
    for (int i = 0; i <= n_val; i++) {
        // dp[i] = (long long*) malloc((k_val + 1) * sizeof(long long));
        // Allocate for min(i, k_val) + 1 elements for dp[i] to save space
        // Or simply k_val + 1 if k_val is the max k we care about for any n.
        // For C(n,k), we need up to k columns.
        dp[i] = (long long*) calloc((k_val + 1), sizeof(long long));
    }

    for (int i = 0; i <= n_val; i++) {
        for (int j = 0; j <= k_val && j <= i; j++) { // j cannot be greater than i, and not greater than k_val
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    // printf("%lld\n", dp[n_val][k_val]); // Printing can be slow

    for (int i = 0; i <= n_val; i++) {
        free(dp[i]);
    }
    free(dp);
}

int main() {
    binomial_coefficients(10, 5); // Calculate C(10, 5)
    binomial_coefficients(20, 10);
    return 0;
}
