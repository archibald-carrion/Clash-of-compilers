// 248.c
// Operaciones bitwise en un bucle (variación 6)
#include <stdlib.h>

int operaciones_bitwise_var6() {
  unsigned int* val_a = (unsigned int*)malloc(sizeof(unsigned int));
  unsigned int* val_b = (unsigned int*)malloc(sizeof(unsigned int));
  if (val_a == NULL || val_b == NULL) {
    free(val_a);
    free(val_b);
    return -1;  // Error en la asignación de memoria
  }

  *val_a = 0xCAFEBABE;
  *val_b = 0xDEADBEEF;
  for (long long i = 0; i < 1900000; ++i) {
    unsigned int temp = *val_a;
    *val_a = *val_b ^ (unsigned int)(i * i);
    *val_b = temp + ((unsigned int)i + 0x9E3779B9);
    *val_a = (*val_a << 7) | (*val_a >> (32 - 7));
  }

  int resultado = (int)((*val_a ^ *val_b) % 256);
  free(val_a);
  free(val_b);
  return resultado;
}

int main() {
  operaciones_bitwise_var6();
  return 0;
}
