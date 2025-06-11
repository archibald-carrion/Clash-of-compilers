// 216.c
// Operaciones bitwise en un bucle (variación 0)
#include <stdlib.h>

int operaciones_bitwise() {
  unsigned int* val = (unsigned int*)malloc(sizeof(unsigned int));
  if (val == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *val = 0xABCDEFFF;
  for (long long i = 0; i < 2000000; ++i) {
    *val ^= (i & 0xFF);
    *val = (*val << 3) | (*val >> (32 - 3));  // Rotate left
  }

  int resultado = (int)(*val % 256);
  free(val);
  return resultado;
}

int main() {
  operaciones_bitwise();
  return 0;
}
