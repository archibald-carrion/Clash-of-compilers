// 293.c
// Suma/resta aritmética en un bucle (variación 15) - Final type 1
#include <stdlib.h>

int suma_resta_var15() {
  int* acc = (int*)malloc(sizeof(int));
  if (acc == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *acc = 0;
  for (long long i = 1; i <= 2200000; ++i) {
    *acc += (int)(i % 10) - (int)((i / 10) % 10);
  }

  int resultado = *acc % 256;
  free(acc);
  return resultado;
}

int main() {
  suma_resta_var15();
  return 0;
}
