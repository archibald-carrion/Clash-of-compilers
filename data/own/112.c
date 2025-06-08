#include <stdio.h>
#include <stdlib.h>

    // Snippet 2: Gaussian elimination
    void gaussian_elimination() {
        int n = 1000;  // Size of the matrix
        double **A, *b, *x;
        
        // Allocate memory
        A = (double**) malloc(n * sizeof(double*));
        b = (double*) malloc(n * sizeof(double));
        x = (double*) malloc(n * sizeof(double));
        
        for (int i = 0; i < n; i++) {
            A[i] = (double*) malloc(n * sizeof(double));
        }
        
        // Gaussian elimination
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double factor = A[j][i] / A[i][i];
                for (int k = i; k < n; k++) {
                    A[j][k] -= factor * A[i][k];
                }
                b[j] -= factor * b[i];
            }
        }
        
        // Back substitution
        for (int i = n - 1; i >= 0; i--) {
            x[i] = b[i];
            for (int j = i + 1; j < n; j++) {
                x[i] -= A[i][j] * x[j];
            }
            x[i] /= A[i][i];
        }

        // Free memory
        for (int i = 0; i < n; i++) {
            free(A[i]);
        }
        free(A);
        free(b);
        free(x);
    }

int main() {
    gaussian_elimination();
    return 0;
}
