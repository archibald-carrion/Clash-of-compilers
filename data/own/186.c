
// Snippet 176: Dynamic Programming to solve Longest Common Subsequence (LCS)
void longest_common_subsequence() {
    int n = 1000, m = 1000;  // Lengths of strings
    char *X = (char*) malloc(n * sizeof(char));
    char *Y = (char*) malloc(m * sizeof(char));

    // LCS DP array
    int **L = (int**) malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        L[i] = (int*) malloc((m + 1) * sizeof(int));
    }

    // Fill the LCS DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }

    // Free memory
    for (int i = 0; i <= n; i++) {
        free(L[i]);
    }
    free(L);
    free(X);
    free(Y);
}
    