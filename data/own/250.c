// 250.c
// Manipulación de array (variación 6)
#include <stdlib.h>

#define ARRAY_SIZE_250 3072  // Larger array

int manipulacion_array_var6() {
  char* array = (char*)malloc(ARRAY_SIZE_250 * sizeof(char));
  if (array == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  long long* xor_sum = (long long*)malloc(sizeof(long long));
  if (xor_sum == NULL) {
    free(array);
    return -1;  // Error en la asignación de memoria
  }

  *xor_sum = 0;
  for (int k = 0; k < 200; ++k) {
    for (int i = 0; i < ARRAY_SIZE_250; ++i) {
      array[i] = (char)((i * (k + 1)) ^ ((k * k) % 128));
    }
    for (int i = 0; i < ARRAY_SIZE_250; ++i) {
      *xor_sum ^= array[i];
    }
  }

  int resultado = (int)(*xor_sum % 256);
  free(array);
  free(xor_sum);
  return resultado;
}

int main() {
  manipulacion_array_var6();
  return 0;
}
