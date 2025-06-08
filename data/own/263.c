// 263.c
// Manipulación de array (variación 9)
#include <stdlib.h>
#define ARRAY_SIZE_263 640

long long manipulacion_array_var9() {
  int* array = malloc(ARRAY_SIZE_263 * sizeof(int));
  if (!array) return 0;

  long long* sum_sq_diff = malloc(sizeof(long long));
  if (!sum_sq_diff) {
    free(array);
    return 0;
  }
  *sum_sq_diff = 0;

  for (int iter = 0; iter < 300; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_263; ++i) {
      array[i] = (iter + 1) * (i - ARRAY_SIZE_263 / 2);
    }
    for (int i = 0; i < ARRAY_SIZE_263 - 1; ++i) {
      long long diff = array[i + 1] - array[i];
      *sum_sq_diff += diff * diff;
    }
  }

  long long result = (*sum_sq_diff) % 256;
  free(array);
  free(sum_sq_diff);
  return result;
}

int main() {
  manipulacion_array_var9();
  return 0;
}
