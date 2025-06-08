// Snippet 9: Matrix Exponentiation (Exponentiation by Squaring)

void multiply(long long a[2][2], long long b[2][2]) {
    long long temp[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = temp[i][j];
        }
    }
}

void matrix_exponentiation() {
    long long mat[2][2] = {{1, 1}, {1, 0}};
    long long result[2][2] = {{1, 0}, {0, 1}};  // Identity matrix
    int exponent = 1000;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            multiply(result, mat);
        }
        multiply(mat, mat);
        exponent /= 2;
    }
}

int main() {
    matrix_exponentiation();
    return 0;
}
