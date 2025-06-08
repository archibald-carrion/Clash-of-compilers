#include <stdlib.h> // For malloc, free
#include <string.h> // For strlen (if X and Y were actual strings), and memset
#include <time.h>   // For time, srand (to fill X, Y with random chars)

// Snippet 176: Dynamic Programming to solve Longest Common Subsequence (LCS)
int longest_common_subsequence(int n_len, int m_len) { // Renamed n to n_len, m to m_len
    char *X = (char*) malloc(n_len * sizeof(char));
    char *Y = (char*) malloc(m_len * sizeof(char));

    // Initialize X and Y with some characters for the algorithm to work on
    srand(time(NULL));
    for(int i=0; i<n_len; ++i) X[i] = 'A' + (rand() % 26);
    for(int i=0; i<m_len; ++i) Y[i] = 'A' + (rand() % 26);


    int **L = (int**) malloc((n_len + 1) * sizeof(int*));
    for (int i = 0; i <= n_len; i++) {
        L[i] = (int*) malloc((m_len + 1) * sizeof(int));
        // memset(L[i], 0, (m_len + 1) * sizeof(int)); // Initialize row to 0
    }
    
    for (int i = 0; i <= n_len; i++) {
        for (int j = 0; j <= m_len; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = (L[i-1][j] > L[i][j-1]) ? L[i-1][j] : L[i][j-1];
        }
    }
    
    int result = L[n_len][m_len];

    for (int i = 0; i <= n_len; i++) {
        free(L[i]);
    }
    free(L);
    free(X);
    free(Y);
    return result;
}

int main() {
    longest_common_subsequence(50, 60); // LCS of strings of length 50 and 60
    return 0;
}
