#include <stdio.h>

#define N 3

void multiplySparseMatrices(int mat1[N][N], int mat2[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[N][N] = {
        {1, 0, 0},
        {0, 0, 3},
        {4, 0, 5}
    };

    int mat2[N][N] = {
        {0, 6, 0},
        {7, 0, 0},
        {0, 8, 9}
    };

    int result[N][N];
    multiplySparseMatrices(mat1, mat2, result);

    printf("Result of multiplication:\n");
    printMatrix(result);
    return 0;
}
