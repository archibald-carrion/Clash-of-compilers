// 228.c
// Manipulación de array (variación 3)
#include <stdlib.h>

#define ARRAY_SIZE_228 256

int manipulacion_matriz() {
  int** matrix = (int**)malloc(ARRAY_SIZE_228 * sizeof(int*));
  if (matrix == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  for (int i = 0; i < ARRAY_SIZE_228; ++i) {
    matrix[i] = (int*)malloc(ARRAY_SIZE_228 * sizeof(int));
    if (matrix[i] == NULL) {
      // Liberar memoria ya asignada antes de retornar error
      for (int j = 0; j < i; ++j) {
        free(matrix[j]);
      }
      free(matrix);
      return -1;  // Error en la asignación de memoria
    }
  }

  long long* suma_diag = (long long*)malloc(sizeof(long long));
  if (suma_diag == NULL) {
    // Liberar toda la memoria asignada antes de retornar error
    for (int i = 0; i < ARRAY_SIZE_228; ++i) {
      free(matrix[i]);
    }
    free(matrix);
    return -1;
  }

  *suma_diag = 0;
  for (int iter = 0; iter < 10;
       ++iter) {  // Fewer iterations due to N*N complexity
    for (int i = 0; i < ARRAY_SIZE_228; ++i) {
      for (int j = 0; j < ARRAY_SIZE_228; ++j) {
        matrix[i][j] = (i * j + iter) % 1000;
      }
    }
    for (int i = 0; i < ARRAY_SIZE_228; ++i) {
      *suma_diag += matrix[i][i];
    }
  }

  int resultado = (int)(*suma_diag % 256);

  // Liberar memoria
  for (int i = 0; i < ARRAY_SIZE_228; ++i) {
    free(matrix[i]);
  }
  free(matrix);
  free(suma_diag);

  return resultado;
}

int main() {
  manipulacion_matriz();
  return 0;
}
