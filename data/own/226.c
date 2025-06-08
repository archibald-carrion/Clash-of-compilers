// 226.c
// Operaciones bitwise en un bucle (variación 3)
#include <stdlib.h>

int operaciones_bitwise_var3() {
  unsigned long long* val =
      (unsigned long long*)malloc(sizeof(unsigned long long));
  if (val == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *val = 0xAABBCCDDEEFF0011ULL;
  for (long long i = 0; i < 1800000; ++i) {
    *val = (~*val) | (i & 0xFFFFFFULL);
    *val = (*val << 5) | (*val >> (64 - 5));  // Rotate left 5 bits
  }

  int resultado = (int)(*val % 256);
  free(val);
  return resultado;
}

int main() {
  operaciones_bitwise_var3();
  return 0;
}
