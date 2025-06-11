// 235.c
// Multiplicación/división en un bucle (variación 5)
#include <stdlib.h>

int calcular_division_var5() {
  double* dividendo = (double*)malloc(sizeof(double));
  double* divisor = (double*)malloc(sizeof(double));

  if (dividendo == NULL || divisor == NULL) {
    free(dividendo);
    free(divisor);
    return -1;  // Error en la asignación de memoria
  }

  *dividendo = 200000000.0;
  *divisor = 1.00000001;
  for (long long i = 0; i < 1200000; ++i) {
    *dividendo = *dividendo / *divisor;
    if (*dividendo < 1.0) *dividendo = 200000000.0;
  }

  int resultado = (int)((long long)*dividendo % 256);
  free(dividendo);
  free(divisor);
  return resultado;
}

int main() {
  calcular_division_var5();
  return 0;
}
