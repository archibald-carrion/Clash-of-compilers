// 225.c
// Operaciones bitwise en un bucle (variación 2)
#include <stdlib.h>

int operaciones_bitwise_var2() {
  unsigned int* val = (unsigned int*)malloc(sizeof(unsigned int));
  if (val == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *val = 0x12345678;
  for (long long i = 0; i < 2500000; ++i) {
    *val = (*val >> 1) ^ ((i % 255) << 24);
  }

  int resultado = (int)(*val % 256);
  free(val);
  return resultado;
}

int main() {
  operaciones_bitwise_var2();
  return 0;
}
