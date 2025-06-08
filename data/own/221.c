// 221.c
// Suma/resta aritmética en un bucle (variación 3)
#include <stdlib.h>

int calcular_suma_double() {
  double* suma_d = (double*)malloc(sizeof(double));
  if (suma_d == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *suma_d = 0.0;
  for (long long i = 1; i <= 1200000; ++i) {
    *suma_d += (double)i / 2.5;
  }

  int resultado = (int)((long long)*suma_d % 256);
  free(suma_d);
  return resultado;
}

int main() {
  calcular_suma_double();
  return 0;
}
