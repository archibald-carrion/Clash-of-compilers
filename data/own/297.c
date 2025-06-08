// 297.c
// Operaciones bitwise en un bucle (variación 14) - Final type 3
#include <stdlib.h>

int operaciones_bitwise_var14() {
  unsigned long long* pattern =
      (unsigned long long*)malloc(sizeof(unsigned long long));
  if (pattern == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *pattern = 0xF0F0F0F0F0F0F0F0ULL;
  for (long long i = 0; i < 1800000; ++i) {
    *pattern ^= (i << (i % 16));
    *pattern = (*pattern >> (i % 3)) | (*pattern << (64 - (i % 3)));
  }

  int resultado = (int)(*pattern % 256);
  free(pattern);
  return resultado;
}

int main() {
  operaciones_bitwise_var14();
  return 0;
}
