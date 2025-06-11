// 218.c
// Manipulación de array (variación 0)
#include <stdlib.h>

#define ARRAY_SIZE_218 1024

int manipulacion_array() {
  int* array = (int*)malloc(ARRAY_SIZE_218 * sizeof(int));
  if (array == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  long long* suma_total = (long long*)malloc(sizeof(long long));
  if (suma_total == NULL) {
    free(array);
    return -1;  // Error en la asignación de memoria
  }

  *suma_total = 0;
  for (int k = 0; k < 500; ++k) {  // Repeat operations multiple times
    for (int i = 0; i < ARRAY_SIZE_218; ++i) {
      array[i] = (i * 7 + k) % 123;
    }
    for (int i = 0; i < ARRAY_SIZE_218; ++i) {
      *suma_total += array[i];
    }
  }

  int resultado = (int)(*suma_total % 256);
  free(array);
  free(suma_total);
  return resultado;
}

int main() {
  manipulacion_array();
  return 0;
}
