
// Snippet 180: Matrix Inversion Using Gaussian Elimination
void matrix_inversion() {
    int n = 1000;  // Matrix size
    double **A = (double**) malloc(n * sizeof(double*));
    double **I = (double**) malloc(n * sizeof(double*));

    for (int i = 0; i < n; i++) {
        A[i] = (double*) malloc(n * sizeof(double));
        I[i] = (double*) malloc(n * sizeof(double));
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

    // Free memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(I[i]);
    }
    free(A);
    free(I);
}
    