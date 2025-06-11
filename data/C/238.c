// 238.c
// Manipulación de array (variación 4)
#include <stdlib.h>

#define ARRAY_SIZE_238 1536

int manipulacion_array_var4() {
  short* array = (short*)malloc(ARRAY_SIZE_238 * sizeof(short));
  long long* producto_total = (long long*)malloc(sizeof(long long));

  if (array == NULL || producto_total == NULL) {
    free(array);
    free(producto_total);
    return -1;  // Error en la asignación de memoria
  }

  *producto_total = 1;
  for (int k = 0; k < 400; ++k) {
    for (int i = 0; i < ARRAY_SIZE_238; ++i) {
      array[i] = (short)((i * 5 + k * 2) % 30000);
    }
    for (int i = 0; i < ARRAY_SIZE_238;
         i += 2) {  // Accessing alternate elements
      if (array[i] != 0)
        *producto_total = (*producto_total * array[i]) % 1000000007;
      if (*producto_total == 0) *producto_total = 1;
    }
  }

  int resultado = (int)(*producto_total % 256);
  free(array);
  free(producto_total);
  return resultado;
}

int main() {
  manipulacion_array_var4();
  return 0;
}
