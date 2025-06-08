// 264.c
// Manipulación de array (variación 10)
#include <stdlib.h>

#define ARRAY_SIZE_264 192

int manipulacion_array_var10() {
  // Allocate 3D array as contiguous memory
  double* array3d = malloc(ARRAY_SIZE_264 * 4 * 2 * sizeof(double));
  if (!array3d) return 0;

  double* total_sum = malloc(sizeof(double));
  if (!total_sum) {
    free(array3d);
    return 0;
  }

  *total_sum = 0.0;

  for (int iter = 0; iter < 50; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_264; ++i) {
      for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 2; ++k) {
          // Access 3D array using linear indexing
          int index = i * 4 * 2 + j * 2 + k;
          array3d[index] = (double)(i * 0.1 + j * 0.5 + k * 0.25 + iter);
        }
      }
    }
    for (int i = 0; i < ARRAY_SIZE_264; i += 2) {
      for (int j = 0; j < 4; j += 2) {
        for (int k = 0; k < 2; ++k) {
          int index = i * 4 * 2 + j * 2 + k;
          *total_sum += array3d[index];
        }
      }
    }
  }

  int result = (int)((long long)(*total_sum) % 256);
  free(array3d);
  free(total_sum);
  return result;
}

int main() {
  manipulacion_array_var10();
  return 0;
}
