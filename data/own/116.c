#include <stdio.h>
#include <stdlib.h>

    // Snippet 6: LU Decomposition for solving linear systems
    void lu_decomposition() {
        int n = 1000;
        double **A, **L, **U;
        
        // Allocate memory
        A = (double**) malloc(n * sizeof(double*));
        L = (double**) malloc(n * sizeof(double*));
        U = (double**) malloc(n * sizeof(double*));
        
        for (int i = 0; i < n; i++) {
            A[i] = (double*) malloc(n * sizeof(double));
            L[i] = (double*) malloc(n * sizeof(double));
            U[i] = (double*) malloc(n * sizeof(double));
        }
        
        // LU Decomposition
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                U[i][j] = A[i][j];
                for (int k = 0; k < i; k++) {
                    U[i][j] -= L[i][k] * U[k][j];
                }
            }
            for (int j = i + 1; j < n; j++) {
                L[j][i] = A[j][i];
                for (int k = 0; k < i; k++) {
                    L[j][i] -= L[j][k] * U[k][i];
                }
                L[j][i] /= U[i][i];
            }
        }

        // Free memory
        for (int i = 0; i < n; i++) {
            free(A[i]);
            free(L[i]);
            free(U[i]);
        }
        free(A);
        free(L);
        free(U);
    }

int main() {
    lu_decomposition();
    return 0;
}
