// 243.c
// Operaciones mixtas (variación 3)
#include <stdlib.h>

#define ARRAY_SIZE_243 64

int operaciones_mixtas_var3() {
  float* arr = (float*)malloc(ARRAY_SIZE_243 * sizeof(float));
  if (arr == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  float* sum_f = (float*)malloc(sizeof(float));
  if (sum_f == NULL) {
    free(arr);
    return -1;  // Error en la asignación de memoria
  }

  *sum_f = 0.0f;
  for (int i = 0; i < ARRAY_SIZE_243; ++i) arr[i] = (float)i / 2.0f;

  for (long long iter = 0; iter < 80000; ++iter) {
    int idx = iter % ARRAY_SIZE_243;
    arr[idx] += (float)(iter % 13) * 0.8f;
    arr[idx] -= (float)((iter + 30) % 23) * 0.5f;
    if (arr[idx] < 0.0f) arr[idx] = 0.0f;
    if (iter % 5 == 0) *sum_f += arr[idx];
    if (*sum_f > 1e6f) *sum_f = 0.0f;
  }

  int resultado = (int)((long long)*sum_f % 256);
  free(arr);
  free(sum_f);
  return resultado;
}

int main() {
  operaciones_mixtas_var3();
  return 0;
}
