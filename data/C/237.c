// 237.c
// Operaciones bitwise en un bucle (variación 5)
#include <stdlib.h>

int operaciones_bitwise_var5() {
  unsigned long long* val =
      (unsigned long long*)malloc(sizeof(unsigned long long));
  if (val == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *val = 0x1122334455667788ULL;
  for (long long i = 0; i < 1600000; ++i) {
    *val = *val ^ (*val >> 7);
    *val = *val ^ (*val << 13);
    *val = *val ^ (*val >> 21);
  }

  int resultado = (int)(*val % 256);
  free(val);
  return resultado;
}

int main() {
  operaciones_bitwise_var5();
  return 0;
}
