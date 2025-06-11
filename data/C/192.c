#include <stdio.h> // Remove this after removing printf

// Matrix multiplication function (for 2x2 matrices)
void multiply_2x2(long long a[2][2], long long b[2][2], long long result_mat[2][2]) {
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
            result_mat[i][j] = temp[i][j];
        }
    }
}

// Snippet 182: Matrix Exponentiation (Matrix Power)
void matrix_exponentiation() {
    // int n = 2; // Matrix size (2x2) // n is implicitly 2
    long long mat[2][2] = {{1, 1}, {1, 0}};
    long long result[2][2] = {{1, 0}, {0, 1}};  // Identity matrix
    long long temp_mat[2][2]; // Temporary matrix for multiplication results
    int exponent = 1000;

    // Perform matrix exponentiation by squaring
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            multiply_2x2(result, mat, temp_mat); // result = result * mat
            for(int i=0; i<2; ++i) for(int j=0; j<2; ++j) result[i][j] = temp_mat[i][j];
        }
        multiply_2x2(mat, mat, temp_mat); // mat = mat * mat
        for(int i=0; i<2; ++i) for(int j=0; j<2; ++j) mat[i][j] = temp_mat[i][j];
        exponent /= 2;
    }

    // Removed printf statement
}

int main() {
    matrix_exponentiation();
    return 0;
}
