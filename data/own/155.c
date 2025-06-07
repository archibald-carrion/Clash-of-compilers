// Snippet 5: Solving a system of linear equations using Gaussian Elimination
void gaussian_elimination_system() {
    int n = 1000;  // Matrix size
    double **A = (double**) malloc(n * sizeof(double*));
    double *b = (double*) malloc(n * sizeof(double));
    double *x = (double*) malloc(n * sizeof(double));

    // Initialize A and b (random coefficients)
    for (int i = 0; i < n; i++) {
        A[i] = (double*) malloc(n * sizeof(double));
        b[i] = rand() % 1000;
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 1000;
        }
    }

    // Gaussian elimination
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = 0; k < n; k++) {
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