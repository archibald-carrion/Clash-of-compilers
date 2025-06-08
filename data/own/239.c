// 239.c
// Manipulación de array (variación 5)
#include <stdlib.h>

#define ARRAY_SIZE_239 768

int manipulacion_array_var5() {
  float* array = (float*)malloc(ARRAY_SIZE_239 * sizeof(float));
  float* max_val = (float*)malloc(sizeof(float));

  if (array == NULL || max_val == NULL) {
    free(array);
    free(max_val);
    return -1;  // Error en la asignación de memoria
  }

  *max_val = 0.0f;
  for (int iter = 0; iter < 250; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_239; ++i) {
      array[i] = (float)(i * i - iter * 5) / ((i % 10) + 1.0f);
    }
    *max_val = array[0];
    for (int i = 1; i < ARRAY_SIZE_239; ++i) {
      if (array[i] > *max_val) *max_val = array[i];
    }
  }

  int resultado = (int)((long long)*max_val % 256);
  free(array);
  free(max_val);
  return resultado;
}

int main() {
  manipulacion_array_var5();
  return 0;
}
