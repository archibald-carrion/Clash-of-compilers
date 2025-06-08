// 251.c
// Manipulación de array (variación 7)
#define ARRAY_SIZE_251 128
int main() {
  volatile double matrix_a[ARRAY_SIZE_251][ARRAY_SIZE_251];
  volatile double matrix_b[ARRAY_SIZE_251][ARRAY_SIZE_251];
  volatile double result_matrix[ARRAY_SIZE_251][ARRAY_SIZE_251];
  double sum_elements = 0.0;

  for (int iter = 0; iter < 2; ++iter) {  // Small iteration for matrix ops
    for (int i = 0; i < ARRAY_SIZE_251; ++i) {
      for (int j = 0; j < ARRAY_SIZE_251; ++j) {
        matrix_a[i][j] = (double)(i * j + iter + 1) / (ARRAY_SIZE_251 * 1.5);
        matrix_b[i][j] =
            (double)(i + j * 2 - iter + 1) / (ARRAY_SIZE_251 * 1.2);
      }
    }
    for (int i = 0; i < ARRAY_SIZE_251; ++i) {
      for (int j = 0; j < ARRAY_SIZE_251; ++j) {
        result_matrix[i][j] = 0;
        for (int k = 0; k < ARRAY_SIZE_251; ++k) {
          result_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
        }
        sum_elements += result_matrix[i][j];
      }
    }
  }
  return (int)((long long)sum_elements % 256);
}
