#include <stdio.h>

#define MOD 1000000007
#define N 2

void multiplyMatrices(long long A[N][N], long long B[N][N]) {
    long long result[N][N] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = result[i][j];
        }
    }
}

void power(long long A[N][N], int n) {
    long long result[N][N] = {{1, 0}, {0, 1}};
    while (n > 0) {
        if (n % 2 == 1) {
            multiplyMatrices(result, A);
        }
        multiplyMatrices(A, A);
        n /= 2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = result[i][j];
        }
    }
}

int main() {
    long long A[N][N] = {{1, 1}, {1, 0}};
    int n = 10;

    power(A, n);

    printf("Matrix after raising to power %d:\n", n);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%lld ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
