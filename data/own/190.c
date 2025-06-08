#include <stdlib.h> // For malloc, free
#include <stdio.h>  // For printf (if debugging)
#include <math.h>   // For fabs
#include <time.h>   // For time, srand

// Snippet 180: Matrix Inversion Using Gaussian Elimination
void matrix_inversion(int n_dim) { // Renamed n to n_dim
    if (n_dim <= 0) return;
    double **A = (double**) malloc(n_dim * sizeof(double*));
    double **I = (double**) malloc(n_dim * sizeof(double*)); // Identity matrix, becomes inverse
    
    srand(time(NULL));
    for (int i = 0; i < n_dim; i++) {
        A[i] = (double*) malloc(n_dim * sizeof(double));
        I[i] = (double*) calloc(n_dim, sizeof(double)); // Initialize I with zeros
        I[i][i] = 1.0; // Diagonal elements to 1 for identity
        for(int j=0; j<n_dim; ++j) {
            A[i][j] = (double)(rand() % 100 + 1); // Fill A with random numbers
            // Ensure diagonal dominance or non-singularity for better inversion chances
            if (i==j) A[i][j] += n_dim * 100.0; 
        }
    }

    // Gaussian elimination to transform A to I, applying same ops to I
    for (int i = 0; i < n_dim; i++) {
        // Find pivot
        int pivot_row = i;
        for (int k = i + 1; k < n_dim; k++) {
            if (fabs(A[k][i]) > fabs(A[pivot_row][i])) {
                pivot_row = k;
            }
        }
        // Swap rows if needed
        if (pivot_row != i) {
            double *temp_A = A[i]; A[i] = A[pivot_row]; A[pivot_row] = temp_A;
            double *temp_I = I[i]; I[i] = I[pivot_row]; I[pivot_row] = temp_I;
        }

        // Normalize pivot row
        double pivot_val = A[i][i];
        if (fabs(pivot_val) < 1e-9) { /* Singular matrix, cannot invert (simplified check) */ break; }
        for (int j = i; j < n_dim; j++) A[i][j] /= pivot_val;
        for (int j = 0; j < n_dim; j++) I[i][j] /= pivot_val;

        // Eliminate other rows
        for (int k = 0; k < n_dim; k++) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = i; j < n_dim; j++) A[k][j] -= factor * A[i][j];
                for (int j = 0; j < n_dim; j++) I[k][j] -= factor * I[i][j];
            }
        }
    }


    for (int i = 0; i < n_dim; i++) {
        free(A[i]);
        free(I[i]);
    }
    free(A);
    free(I);
}

int main() {
    matrix_inversion(10); // Invert a 10x10 matrix
    return 0;
}
