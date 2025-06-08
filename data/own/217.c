// 217.c
// Operaciones bitwise en un bucle (variación 1)
#include <stdlib.h>

int operaciones_bitwise_var1() {
  unsigned long long* val =
      (unsigned long long*)malloc(sizeof(unsigned long long));
  if (val == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *val = 0xFEDCBA9876543210ULL;
  for (long long i = 0; i < 1500000; ++i) {
    *val &= ~(1ULL << (i % 64));
    *val |= ((i * i) % 0xFFFFFFULL);
  }

  int resultado = (int)(*val % 256);
  free(val);
  return resultado;
}

int main() {
  operaciones_bitwise_var1();
  return 0;
}
