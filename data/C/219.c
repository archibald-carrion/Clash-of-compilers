// 219.c
// Manipulación de array (variación 1)
#include <stdlib.h>

#define ARRAY_SIZE_219 512

int manipulacion_array_var1() {
  long long* array = (long long*)malloc(ARRAY_SIZE_219 * sizeof(long long));
  if (array == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  for (int iter = 0; iter < 200; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_219; ++i) {
      array[i] = i * i + iter * 3;
    }
    for (int i = ARRAY_SIZE_219 - 1; i >= 0; --i) {
      if (i > 0) array[i - 1] += array[i] % (iter + 17);
    }
  }

  int resultado = (int)(array[0] % 256);
  free(array);
  return resultado;
}

int main() {
  manipulacion_array_var1();
  return 0;
}
