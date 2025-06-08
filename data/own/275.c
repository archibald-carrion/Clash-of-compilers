// 275.c
// Manipulación de array (variación 11)
#include <stdlib.h>

#define ARRAY_SIZE_275 896  // (1024 - 128)

int manipulacion_array_var11() {
  short* array_a = (short*)malloc(ARRAY_SIZE_275 * sizeof(short));
  short* array_b = (short*)malloc(ARRAY_SIZE_275 * sizeof(short));
  if (array_a == NULL || array_b == NULL) {
    free(array_a);
    free(array_b);
    return -1;  // Error en la asignación de memoria
  }

  long long* dot_product = (long long*)malloc(sizeof(long long));
  if (dot_product == NULL) {
    free(array_a);
    free(array_b);
    return -1;  // Error en la asignación de memoria
  }

  *dot_product = 0;
  for (int iter = 0; iter < 150; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_275; ++i) {
      array_a[i] = (short)((i * (iter + 1)) % 1000 - 500);
      array_b[i] =
          (short)(((ARRAY_SIZE_275 - 1 - i) * (iter + 1)) % 1000 - 500);
    }
    *dot_product = 0;  // Reset for each iteration's calculation
    for (int i = 0; i < ARRAY_SIZE_275; ++i) {
      *dot_product += (long long)array_a[i] * array_b[i];
    }
  }

  int resultado = (int)(*dot_product % 256);
  free(array_a);
  free(array_b);
  free(dot_product);
  return resultado;
}

int main() {
  manipulacion_array_var11();
  return 0;
}
