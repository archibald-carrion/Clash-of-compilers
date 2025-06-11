// 267.c
// Operaciones mixtas (variación 6)
#include <stdlib.h>
#define MIX_ARR_267 32

unsigned long long operaciones_mixtas_var6() {
  unsigned int* arr = malloc(MIX_ARR_267 * sizeof(unsigned int));
  if (!arr) return 0;

  for (int k = 0; k < MIX_ARR_267; ++k) arr[k] = k * k + 0xBADF00D;

  unsigned long long* result_ull = malloc(sizeof(unsigned long long));
  if (!result_ull) {
    free(arr);
    return 0;
  }
  *result_ull = 0;

  for (long long i = 0; i < 600000; ++i) {
    int idx = i % MIX_ARR_267;
    arr[idx] = (arr[idx] << 3) | (arr[idx] >> 29);  // Rotate
    arr[idx] ^= (unsigned int)(i * 1234567UL);
    if ((i % 5) == 0) {
      *result_ull += arr[idx];
    } else {
      if (*result_ull > arr[idx]) *result_ull -= arr[idx];
    }
    if ((i % 101) == 0 && arr[idx] != 0) {  // Infrequent division
      *result_ull /= (arr[idx] % 10 + 1);
    }
  }

  unsigned long long result = (*result_ull) % 256;
  free(arr);
  free(result_ull);
  return result;
}

int main() {
  operaciones_mixtas_var6();
  return 0;
}
