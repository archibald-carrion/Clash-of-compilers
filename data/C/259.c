// 259.c
// Multiplicación/división en un bucle (variación 8)
#include <stdlib.h>

int multiplicacion_division_var8() {
  double* res = (double*)malloc(sizeof(double));
  if (res == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *res = 1.0;
  for (long long i = 1; i <= 1000000; ++i) {
    if (i % 2 == 0) {
      *res *= (1.0 + 0.000001 * (i % 100));
    } else {
      if (*res > 1.0) *res /= (1.0 + 0.0000005 * (i % 100));
    }
    if (*res > 1e10 || *res < 1e-5 && *res != 0) *res = 1.0;
  }

  int resultado = (int)((long long)*res % 256);
  free(res);
  return resultado;
}

int main() {
  multiplicacion_division_var8();
  return 0;
}
