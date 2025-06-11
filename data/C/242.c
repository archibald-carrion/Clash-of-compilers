// 242.c
// Operaciones mixtas (variación 2)
#include <stdlib.h>

int operaciones_mixtas_var2() {
  unsigned int* acc_ui = (unsigned int*)malloc(sizeof(unsigned int));
  if (acc_ui == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *acc_ui = 98765;
  for (long long i = 1; i <= 1000000; ++i) {
    *acc_ui -= (unsigned int)(i % 2500);
    *acc_ui = (*acc_ui << (i % 3)) | (*acc_ui >> (32 - (i % 3)));
    if (i % 150 == 0) {
      *acc_ui *= ((i % 7) + 2);
    }
  }

  int resultado = (int)(*acc_ui % 256);
  free(acc_ui);
  return resultado;
}

int main() {
  operaciones_mixtas_var2();
  return 0;
}
