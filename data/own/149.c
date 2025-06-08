// Snippet 9: Matrix Inversion (Using Gaussian Elimination)
#include <stdlib.h> // For malloc, free
#include <stdio.h>  // For printf (if debugging)
#include <math.h>   // For fabs

void matrix_inversion(int n) {
    double **A = (double**) malloc(n * sizeof(double*));
    double **I = (double**) malloc(n * sizeof(double*));
    double **A_inv = (double**) malloc(n * sizeof(double*));

    for (int i = 0; i < n; i++) {
        A[i] = (double*) malloc(n * sizeof(double));
        I[i] = (double*) malloc(n * sizeof(double));
        A_inv[i] = (double*) malloc(n * sizeof(double));
    }

    // Initialize matrix A and identity matrix I
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            I[i][j] = (i == j) ? 1.0 : 0.0;  // Identity matrix
        }
    }

    // Perform Gaussian elimination (simplified)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = 0; k < n; k++) {
                A[j][k] -= factor * A[i][k];
                I[j][k] -= factor * I[i][k];
            }
        }
    }

    // Copy the result to A_inv
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A_inv[i][j] = I[i][j];
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(I[i]);
        free(A_inv[i]);
    }
    free(A);
    free(I);
    free(A_inv);
}

int main() {
    // Example usage
    matrix_inversion(3); // n=3 (size of matrix)
    return 0;
}