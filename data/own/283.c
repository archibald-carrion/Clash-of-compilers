// 283.c
// Multiplicación/división en un bucle (variación 12)
#include <stdlib.h>

int multiplicacion_division_var12() {
  double* val = (double*)malloc(sizeof(double));
  if (val == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *val = 1.000000001;
  for (long long i = 1; i <= 950000; ++i) {
    *val *= (1.0 + (double)((i % 10) - 5) / 100000.0);
    if (*val < 0.5 || *val > 2.0)
      *val = 1.000000001 + (double)(i % 10) / 10000.0;
  }

  int resultado = (int)((long long)(*val * 1000.0) % 256);
  free(val);
  return resultado;
}

int main() {
  multiplicacion_division_var12();
  return 0;
}
