// 268.c
// Operaciones mixtas (variación 7)
#include <stdlib.h>

long long operaciones_mixtas_var7() {
  double* d_val1 = malloc(sizeof(double));
  double* d_val2 = malloc(sizeof(double));
  long long* ll_val = malloc(sizeof(long long));

  if (!d_val1 || !d_val2 || !ll_val) {
    free(d_val1);
    free(d_val2);
    free(ll_val);
    return 0;
  }

  *d_val1 = 123.456;
  *d_val2 = 789.012;
  *ll_val = 9876543210LL;

  for (long long i = 1; i <= 850000; ++i) {
    *d_val1 += (double)((*ll_val) % 1000) / ((i % 10) + 1.0);
    *d_val2 *= (1.0000001 - (double)(i % 100) / 10000000.0);
    *ll_val ^= ((i << (i % 3)) + (long long)(*d_val1));

    if (*d_val1 > 1e9) *d_val1 = i;
    if (*d_val2 < 1e-7 && *d_val2 != 0) *d_val2 = i;
    if (*ll_val < 0) *ll_val = -(*ll_val);
  }

  long long result =
      ((long long)(*d_val1) + (long long)(*d_val2) + (*ll_val)) % 256;
  free(d_val1);
  free(d_val2);
  free(ll_val);
  return result;
}

int main() {
  operaciones_mixtas_var7();
  return 0;
}
