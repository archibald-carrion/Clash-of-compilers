// 236.c
// Operaciones bitwise en un bucle (variación 4)
#include <stdlib.h>

int operaciones_bitwise_var4() {
  unsigned int* val = (unsigned int*)malloc(sizeof(unsigned int));
  if (val == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *val = 0xA5A5A5A5;
  for (long long i = 0; i < 2200000; ++i) {
    *val ^= (unsigned int)(i * 31 + 17);
    *val = (*val << 5) | (*val >> (32 - 5));
  }

  int resultado = (int)(*val % 256);
  free(val);
  return resultado;
}

int main() {
  operaciones_bitwise_var4();
  return 0;
}
