// 231.c
// Operaciones mixtas (variación 1)
#include <stdlib.h>

int operaciones_mixtas_var1() {
  double* acc_d = (double*)malloc(sizeof(double));
  if (acc_d == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *acc_d = 789.123;
  for (long long i = 1; i <= 900000; ++i) {
    *acc_d += (double)(i % 123) / 3.14;
    if (((int)i % 200) == 0) {
      *acc_d *= 0.99;
    }
    if (*acc_d > 1e10)
      *acc_d = 789.123;
    else if (*acc_d < 1e-5 && *acc_d != 0)
      *acc_d = 1.0;
  }

  int resultado = (int)((long long)*acc_d % 256);
  free(acc_d);
  return resultado;
}

int main() {
  operaciones_mixtas_var1();
  return 0;
}
