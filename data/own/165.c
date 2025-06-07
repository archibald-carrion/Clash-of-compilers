// Snippet 5: Matrix Chain Multiplication
void matrix_chain_multiplication() {
    int n = 100;  // Number of matrices
    int *dims = (int*) malloc((n + 1) * sizeof(int));
    int **dp = (int**) malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        dp[i] = (int*) malloc(n * sizeof(int));
    }

    // Fill dims with random values representing matrix dimensions
    for (int i = 0; i <= n; i++) {
        dims[i] = rand() % 100 + 1;
    }

    // Matrix chain multiplication DP algorithm
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = 1000000;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    free(dims);
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
}