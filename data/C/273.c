// 273.c
// Operaciones bitwise en un bucle (variación 10)
#include <stdlib.h>

int operaciones_bitwise_var10() {
  unsigned int* flags = (unsigned int*)malloc(sizeof(unsigned int));
  if (flags == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *flags = 0xAAAAAAAA;
  for (long long i = 0; i < 2400000; ++i) {
    int bit_pos = i % 32;
    if ((i / 32) % 2 == 0)
      *flags |= (1U << bit_pos);  // Set bit
    else
      *flags &= ~(1U << bit_pos);          // Clear bit
    if (i % 100 == 0) *flags = ~(*flags);  // Toggle all bits
  }

  int resultado = (int)(*flags % 256);
  free(flags);
  return resultado;
}

int main() {
  operaciones_bitwise_var10();
  return 0;
}
