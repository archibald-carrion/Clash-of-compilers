// Snippet 4: Matrix Multiplication with Strassen's Algorithm
#include <stdlib.h> // For malloc, free

// Matrix multiplication with Strassen's Algorithm (simplified for readability)
void strassen(int **A, int **B, int **C, int n) {
    if (n <= 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    // Splitting matrices into sub-matrices (omitted for brevity)
    // Recursive calls to multiply sub-matrices and add them
}

void strassens_matrix_multiply(int n) {
    int **A = (int**) malloc(n * sizeof(int*));
    int **B = (int**) malloc(n * sizeof(int*));
    int **C = (int**) malloc(n * sizeof(int*));

    // Allocate memory for matrices
    for (int i = 0; i < n; i++) {
        A[i] = (int*) malloc(n * sizeof(int));
        B[i] = (int*) malloc(n * sizeof(int));
        C[i] = (int*) malloc(n * sizeof(int));
    }

    strassen(A, B, C, n);

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

int main() {
    // Example usage (n must be a power of 2 for typical Strassen's)
    strassens_matrix_multiply(4); // n=4
    return 0;
}