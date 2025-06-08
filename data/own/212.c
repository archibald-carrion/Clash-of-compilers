// 212.c
// Suma/resta aritmética en un bucle (variación 1)
#include <stdlib.h>

int calcular_resta() {
  long long* resta = (long long*)malloc(sizeof(long long));
  if (resta == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *resta = 1000000;  // Initial value variation
  for (long long i = 1; i <= 500000; ++i) {
    *resta -= i;
  }

  int resultado = (int)(*resta % 256);
  free(resta);
  return resultado;
}

int main() {
  calcular_resta();
  return 0;
}
