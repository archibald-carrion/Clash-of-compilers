// Snippet 5: Matrix Chain Multiplication
#include <stdlib.h> // For malloc, free, rand, srand
#include <limits.h> // For INT_MAX
#include <time.h>   // For time

int matrix_chain_multiplication(int n_matrices) { // Renamed n to n_matrices
    if (n_matrices <= 0) return 0;
    int *dims = (int*) malloc((n_matrices + 1) * sizeof(int)); // Dimensions array: p0, p1, ..., pn
    
    // dp[i][j] = Minimum number of scalar multiplications needed to compute the matrix A[i]A[i+1]...A[j]
    // where A[i] is of dimension dims[i-1] x dims[i]
    int **dp = (int**) malloc(n_matrices * sizeof(int*));
    for (int i = 0; i < n_matrices; i++) {
        dp[i] = (int*) malloc(n_matrices * sizeof(int));
        for(int j=0; j<n_matrices; ++j) dp[i][j] = 0; // Initialize
    }
    
    srand(time(NULL));
    for (int i = 0; i <= n_matrices; i++) { // Fill n_matrices+1 dimensions
        dims[i] = rand() % 100 + 1;
    }

    // L is chain length.
    for (int L = 2; L <= n_matrices; L++) {
        for (int i = 0; i <= n_matrices - L; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                // q = cost/scalar multiplications
                int q = dp[i][k] + dp[k+1][j] + dims[i] * dims[k+1] * dims[j+1];
                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }
    
    int result = 0;
    if (n_matrices > 0) result = dp[0][n_matrices-1];

    for (int i = 0; i < n_matrices; i++) {
        free(dp[i]);
    }
    free(dp);
    free(dims);
    return result;
}

int main() {
    // Example usage
    matrix_chain_multiplication(10); // 10 matrices to chain multiply
    return 0;
}