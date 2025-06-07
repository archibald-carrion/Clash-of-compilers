#include <stdio.h>  // For printf
#include <stdlib.h> // For malloc, free, calloc
#include <time.h>   // For srand, time

// Snippet 187: Dynamic Programming to solve Longest Common Subsequence (LCS)
void longest_common_subsequence() {
    int n = 1000, m = 1000;  // Lengths of strings
    char *X = (char*) malloc(n * sizeof(char));
    char *Y = (char*) malloc(m * sizeof(char));

    // Initialize strings with random characters
    srand(time(NULL));
    for(int i=0; i<n; ++i) X[i] = 'a' + (rand() % 26);
    for(int i=0; i<m; ++i) Y[i] = 'a' + (rand() % 26);

    // LCS DP array
    int **L = (int**) malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        L[i] = (int*) calloc((m + 1), sizeof(int)); // Use calloc to initialize elements to 0
    }

    // Fill the LCS DP table
    // L[i][j] will store the length of LCS of X[0..i-1] and Y[0..j-1]
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }
    
    printf("Length of Longest Common Subsequence: %d\n", L[n][m]);

    // Free memory
    for (int i = 0; i <= n; i++) {
        free(L[i]);
    }
    free(L);
    free(X);
    free(Y);
}

int main() {
    longest_common_subsequence();
    return 0;
}
