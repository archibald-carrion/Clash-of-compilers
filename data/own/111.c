
    // Snippet 1: Matrix multiplication (Naive approach)
    void matrix_multiply() {
        int n = 1000;  // Size of the matrix
        int **A, **B, **C;
        
        // Allocate memory
        A = (int**) malloc(n * sizeof(int*));
        B = (int**) malloc(n * sizeof(int*));
        C = (int**) malloc(n * sizeof(int*));
        
        for (int i = 0; i < n; i++) {
            A[i] = (int*) malloc(n * sizeof(int));
            B[i] = (int*) malloc(n * sizeof(int));
            C[i] = (int*) malloc(n * sizeof(int));
        }
        
        // Matrix multiplication
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        // Free memory
        for (int i = 0; i < n; i++) {
            free(A[i]);
            free(B[i]);
            free(C[i]);
        }
        free(A);
        free(B);
        free(C);
    }
    