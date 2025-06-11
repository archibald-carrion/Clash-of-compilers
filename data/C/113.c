#include <stdio.h>
#include <stdlib.h>

    // Snippet 3: Jacobi iteration for solving Ax = b
    void jacobi_iteration() {
        int n = 1000;
        double **A, *b, *x, *x_new;
        
        // Allocate memory
        A = (double**) malloc(n * sizeof(double*));
        b = (double*) malloc(n * sizeof(double));
        x = (double*) malloc(n * sizeof(double));
        x_new = (double*) malloc(n * sizeof(double));
        
        for (int i = 0; i < n; i++) {
            A[i] = (double*) malloc(n * sizeof(double));
        }

        // Jacobi iteration
        for (int iter = 0; iter < 1000; iter++) {
            for (int i = 0; i < n; i++) {
                x_new[i] = b[i];
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        x_new[i] -= A[i][j] * x[j];
                    }
                }
                x_new[i] /= A[i][i];
            }
            
            // Swap x and x_new
            double *temp = x;
            x = x_new;
            x_new = temp;
        }

        // Free memory
        for (int i = 0; i < n; i++) {
            free(A[i]);
        }
        free(A);
        free(b);
        free(x);
        free(x_new);
    }

int main() {
    jacobi_iteration();
    return 0;
}
