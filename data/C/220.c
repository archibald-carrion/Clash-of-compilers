// 220.c
// Operaciones mixtas (variación 0)
#include <stdlib.h>

int operaciones_mixtas() {
  long long* acc = (long long*)malloc(sizeof(long long));
  if (acc == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *acc = 12345;
  for (long long i = 1; i <= 800000; ++i) {
    *acc += (i % 1000);
    *acc ^= (i << 2);
    if (i % 100 == 0 && *acc != 0) {
      *acc = (*acc / ((i % 10) + 1)) + (i & 0xFF);
    }
  }

  int resultado = (int)(*acc % 256);
  free(acc);
  return resultado;
}

int main() {
  operaciones_mixtas();
  return 0;
}
