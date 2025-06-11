// 256.c
// Operaciones mixtas (variación 5)
#include <stdlib.h>

int operaciones_mixtas_var5() {
  double* val_d = malloc(sizeof(double));
  unsigned long long* val_ull = malloc(sizeof(unsigned long long));

  if (!val_d || !val_ull) {
    free(val_d);
    free(val_ull);
    return 0;
  }

  *val_d = 100.0;
  *val_ull = 100ULL;

  for (long long i = 1; i <= 750000; ++i) {
    *val_d += (i % 2 == 0) ? ((*val_d) / ((i % 10) + 1.0))
                           : -((*val_d) * 0.001 * (i % 5));
    if (i % 3 == 0) {
      *val_ull += (unsigned long long)((*val_d) * 0.1) + (i % 7);
    } else {
      *val_ull -= (unsigned long long)((*val_d) * 0.05) + (i % 11);
    }
  }

  int result = (int)((*val_ull) % 256);
  free(val_d);
  free(val_ull);
  return result;
}

int main() {
  operaciones_mixtas_var5();
  return 0;
}
