#include <stdlib.h> // Added for malloc and free

// Strassen's matrix multiplication algorithm (simplified for readability)
// Moved strassen function to global scope
void strassen(int **A, int **B, int **C, int n) {
    if (n <= 1) {
        // Ensure A, B, C are not NULL and indices are valid if n=0 or n=1
        // For n=1, A[0], B[0], C[0] must be valid pointers to at least one int.
        // The current allocation in strassen_matrix_multiply ensures this if n >= 1.
        // If n could be 0, further checks or different handling would be needed.
        if (n == 1 && A && B && C && A[0] && B[0] && C[0]) { // Basic check for n=1
            C[0][0] = A[0][0] * B[0][0];
        }
        return;
    }
    // Split matrices into sub-matrices and recursively apply Strassen's algorithm
    // Omitted for brevity
    // Note: A complete implementation would require allocating and deallocating
    // memory for sub-matrices or using index-based operations on A, B, C.
}

// Snippet 171: Matrix Multiplication using Strassen's Algorithm (Optimized)
void strassen_matrix_multiply() {
    int n = 512;  // Matrix size
    // Consider n=0 or n=1 edge cases for allocation if they are possible.
    // If n=0, malloc(0 * sizeof(int*)) might return NULL or a unique pointer.
    // If n=1, the base case of strassen will be hit immediately.
    if (n <= 0) return; // Or handle as an error

    int **A = (int**) malloc(n * sizeof(int*));
    int **B = (int**) malloc(n * sizeof(int*));
    int **C = (int**) malloc(n * sizeof(int*));

    // It's good practice to check if malloc succeeded
    if (A == NULL || B == NULL || C == NULL) {
        // Handle allocation failure: free any successfully allocated memory and return/exit
        if (A) free(A); // Note: free(NULL) is safe
        if (B) free(B);
        if (C) free(C);
        return;
    }

    for (int i = 0; i < n; i++) {
        A[i] = (int*) malloc(n * sizeof(int));
        B[i] = (int*) malloc(n * sizeof(int));
        C[i] = (int*) malloc(n * sizeof(int));
        // Further checks for these allocations would be good in production code
        // For simplicity, omitting them here but if any fail, previously allocated memory
        // for A[j], B[j], C[j] (j<i) and A, B, C themselves should be freed.
        // Initialize A and B with values here if needed for a meaningful multiplication
        // For example, fill with random numbers or specific test data.
        // C will be overwritten by strassen, so its initial content doesn't matter.
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
    strassen_matrix_multiply();
    return 0;
}
