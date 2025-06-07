// Snippet 6: Matrix Transposition (Large Matrix)
void matrix_transpose() {
    int n = 1000, m = 1000;  // Matrix size
    int **matrix = (int**) malloc(n * sizeof(int*));
    int **transposed = (int**) malloc(m * sizeof(int*));

    for (int i = 0; i < n; i++) {
        matrix[i] = (int*) malloc(m * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
        transposed[i] = (int*) malloc(n * sizeof(int));
    }

    // Matrix transposition
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    for (int i = 0; i < m; i++) {
        free(transposed[i]);
    }
    free(matrix);
    free(transposed);
}