#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// New function: Matrix Addition
// Much faster than quicksort for large datasets
void matrix_addition() {
    // Use smaller dimensions for better performance
    int rows = 1000;
    int cols = 1000;
    
    // Allocate memory for matrices
    int **matrix1 = (int**) malloc(rows * sizeof(int*));
    int **matrix2 = (int**) malloc(rows * sizeof(int*));
    int **result = (int**) malloc(rows * sizeof(int*));
    
    if (!matrix1 || !matrix2 || !result) {
        perror("Failed to allocate memory for matrices");
        // Free any allocated memory
        if (matrix1) free(matrix1);
        if (matrix2) free(matrix2);
        if (result) free(result);
        return;
    }
    
    // Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int*) malloc(cols * sizeof(int));
        matrix2[i] = (int*) malloc(cols * sizeof(int));
        result[i] = (int*) malloc(cols * sizeof(int));
        
        if (!matrix1[i] || !matrix2[i] || !result[i]) {
            perror("Failed to allocate memory for matrix row");
            
            // Free previously allocated rows
            for (int j = 0; j <= i; j++) {
                if (matrix1[j]) free(matrix1[j]);
                if (matrix2[j]) free(matrix2[j]);
                if (result[j]) free(result[j]);
            }
            
            // Free main arrays
            free(matrix1);
            free(matrix2);
            free(result);
            return;
        }
    }
    
    // Initialize matrices with random values
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] = rand() % 100;
            matrix2[i][j] = rand() % 100;
        }
    }
    
    // Perform matrix addition
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    // Print a small sample of the result (optional)
    printf("Sample of result matrix (top-left corner):\n");
    for (int i = 0; i < 3 && i < rows; i++) {
        for (int j = 0; j < 3 && j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    // Free all allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);
}

int main() {
    matrix_addition();
    return 0;
}
