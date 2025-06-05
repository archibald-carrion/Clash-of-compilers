#include <stdio.h>

#define N 3

void transposeMatrix(int matrix[N][N], int transpose[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int transpose[N][N];

    printf("Original Matrix:\n");
    printMatrix(matrix);

    transposeMatrix(matrix, transpose);

    printf("Transposed Matrix:\n");
    printMatrix(transpose);

    return 0;
}
