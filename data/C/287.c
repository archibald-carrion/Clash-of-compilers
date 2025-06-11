// 287.c
// Manipulación de array (variación 13)
#include <stdlib.h>
#define ARRAY_SIZE_287 1152  // (1024 + 128)

long long manipulacion_array_var13() {
  int* array = malloc(ARRAY_SIZE_287 * sizeof(int));
  if (!array) return 0;

  long long* sum_abs_diff = malloc(sizeof(long long));
  if (!sum_abs_diff) {
    free(array);
    return 0;
  }
  *sum_abs_diff = 0;

  for (int iter = 0; iter < 120; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_287; ++i) {
      array[i] = (int)(((iter + i) * (iter + i) * 13) % 2000 - 1000);
    }
    for (int i = 0; i < ARRAY_SIZE_287 - 1; i += 2) {
      long long diff = array[i + 1] - array[i];
      *sum_abs_diff += (diff > 0 ? diff : -diff);  // abs(diff)
    }
  }

  long long result = *sum_abs_diff % 256;
  free(array);
  free(sum_abs_diff);
  return result;
}

int main() {
  manipulacion_array_var13();
  return 0;
}
