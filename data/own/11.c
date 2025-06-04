#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void generateMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10;
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

int determinant(int matrix[N][N], int n) {
    int det = 1;
    int i, j, k;
    for (i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            for (j = i + 1; j < n; j++) {
                if (matrix[j][i] != 0) {
                    for (k = 0; k < n; k++) {
                        int temp = matrix[i][k];
                        matrix[i][k] = matrix[j][k];
                        matrix[j][k] = temp;
                    }
                    det *= -1;
                    break;
                }
            }
        }
        det *= matrix[i][i];
        for (j = i + 1; j < n; j++) {
            float ratio = (float)matrix[j][i] / matrix[i][i];
            for (k = i; k < n; k++) {
                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
    }
    return det;
}

int main() {
    srand(time(0));
    int matrix[N][N];
    generateMatrix(matrix);

    printf("Generated Matrix:\n");
    printMatrix(matrix);

    int det = determinant(matrix, N);
    printf("Determinant of the matrix: %d\n", det);

    return 0;
}
