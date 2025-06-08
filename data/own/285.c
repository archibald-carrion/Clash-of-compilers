// 285.c
// Operaciones bitwise en un bucle (variación 12)
#include <stdlib.h>

int operaciones_bitwise_var12() {
  unsigned int* val1 = (unsigned int*)malloc(sizeof(unsigned int));
  unsigned int* val2 = (unsigned int*)malloc(sizeof(unsigned int));
  if (val1 == NULL || val2 == NULL) {
    free(val1);
    free(val2);
    return -1;  // Error en la asignación de memoria
  }

  *val1 = 0x1A2B3C4D;
  *val2 = 0x5E6F7A8B;
  for (long long i = 0; i < 2100000; ++i) {
    *val1 ^= (*val2 >> (i % 8)) + (unsigned int)i;
    *val2 ^= (*val1 << (i % 4)) + (unsigned int)(i * 3);
    if (i % 100 == 0) {
      *val1 = ~(*val1);
      *val2 = ~(*val2);
    }
  }

  int resultado = (int)((*val1 ^ *val2) % 256);
  free(val1);
  free(val2);
  return resultado;
}

int main() {
  operaciones_bitwise_var12();
  return 0;
}
