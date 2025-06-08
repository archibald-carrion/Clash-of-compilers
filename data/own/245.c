// 245.c
// Suma/resta aritmética en un bucle (variación 8)
#include <stdlib.h>

int suma_resta_var8() {
  double* resta_d = (double*)malloc(sizeof(double));
  if (resta_d == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *resta_d = 500000.0;
  for (long long i = 1; i <= 700000; ++i) {
    *resta_d -= (double)i / ((i % 10) + 1.1);
  }

  int resultado = (int)((long long)*resta_d % 256);
  free(resta_d);
  return resultado;
}

int main() {
  suma_resta_var8();
  return 0;
}
