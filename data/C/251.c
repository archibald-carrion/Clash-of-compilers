// 251.c
// Manipulación de array (variación 7)
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE_251 128

// Función auxiliar con la lógica principal
int run_logic_251() {
  double (*matrix_a)[ARRAY_SIZE_251];
  double (*matrix_b)[ARRAY_SIZE_251];
  double (*result_matrix)[ARRAY_SIZE_251];
  double sum_elements = 0.0;

  // Asignación dinámica
  matrix_a = malloc(ARRAY_SIZE_251 * sizeof(double[ARRAY_SIZE_251]));
  matrix_b = malloc(ARRAY_SIZE_251 * sizeof(double[ARRAY_SIZE_251]));
  result_matrix = malloc(ARRAY_SIZE_251 * sizeof(double[ARRAY_SIZE_251]));

  if (matrix_a == NULL || matrix_b == NULL || result_matrix == NULL) {
    // Manejo de error de asignación de memoria
    if (matrix_a) free(matrix_a);
    if (matrix_b) free(matrix_b);
    if (result_matrix) free(result_matrix);
    return -1;  // O algún código de error apropiado
  }

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

  // Liberar memoria
  free(matrix_a);
  free(matrix_b);
  free(result_matrix);

  return (int)((long long)sum_elements % 256);
}

int main() {
  int result = run_logic_251();
  // Opcional: imprimir resultado para depuración
  // printf("Resultado de run_logic_251: %d\\n", result);
  return 0;
}
