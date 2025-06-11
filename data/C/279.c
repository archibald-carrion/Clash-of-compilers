// 279.c
// Operaciones mixtas (variación 8)
#include <stdlib.h>

#define MIX_ARR_279 48

int operaciones_mixtas_var8() {
  double* arr_d = malloc(MIX_ARR_279 * sizeof(double));
  if (!arr_d) return 0;

  unsigned int* val_ui = malloc(sizeof(unsigned int));
  if (!val_ui) {
    free(arr_d);
    return 0;
  }

  for (int k = 0; k < MIX_ARR_279; ++k) arr_d[k] = (double)k / 3.0 + 0.1;
  *val_ui = 0xCAFEF00D;

  for (long long i = 0; i < 700000; ++i) {
    int idx = i % MIX_ARR_279;
    arr_d[idx] =
        arr_d[idx] * (1.00001 - (double)((*val_ui) % 1000) / 2000000.0) +
        (double)(i % 10) / 10.0;
    *val_ui ^= (unsigned int)(arr_d[idx] * 100.0 + i);
    *val_ui = ((*val_ui) << (i % 5)) | ((*val_ui) >> (32 - (i % 5)));
    if (arr_d[idx] > 1e6) arr_d[idx] = (double)(i % 100);
  }

  int result = (int)((*val_ui) % 256);
  free(arr_d);
  free(val_ui);
  return result;
}

int main() {
  operaciones_mixtas_var8();
  return 0;
}
