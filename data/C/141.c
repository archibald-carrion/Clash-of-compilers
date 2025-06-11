// Snippet 1: Longest Common Subsequence (LCS)
#include <stdlib.h> // For malloc, free
#include <string.h> // For strlen (if X and Y were actual strings)

int longest_common_subsequence(int n, int m) {
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

    int result = L[n][m]; // Get the length of LCS

    // Free memory
    for (int i = 0; i <= n; i++) {
        free(L[i]);
    }
    free(L);
    free(X); // Free allocated memory for X and Y
    free(Y);
    return result; // Return the result
}

int main() {
    // Example usage
    longest_common_subsequence(10, 12); // m=10, n=12 (lengths of X and Y)
    return 0;
}